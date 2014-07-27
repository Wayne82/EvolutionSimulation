// Random select evolution
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

size_t random_select_evolution_iterations(const char* final_generation)
{
	if (final_generation == NULL)
	{
		printf("Final generation can't be empty.\n");
		return 0;
	}

	// Get length of the final generation
	size_t len = strlen(final_generation);
	if (len == 0)
	{
		printf("Final generation can't be empty. \n");
	}

	// Initialize firsth generation
	char* generations = (char*)malloc( (len+1) * sizeof(char) );
	*(generations+len) = '\0';
	for (size_t i=0; i<len; ++i)
	{
		*(generations+i) = (char)(rand()%26 + 'A');
	}

	// Start random selection and evolute...
	size_t iterations = 0;
	while (1)
	{
		int in_progress = 0;
		for (size_t i=0; i<len; ++i)
		{
			if (*(generations+i) != *(final_generation+i))
			{
				*(generations+i) = (char)(rand()%26 + 'A');
				in_progress = 1;
			}
		}

		if (!in_progress)
			break;

		iterations++;
		// Out put each generation ...
		//printf("Generation %zu: %s \n", iterations, generations);
	}

	free(generations);
	return iterations;
}

void call_random_select_evolution_iterations(size_t times)
{
	if (times == 0)
		return;

	// Get input string, which will be the final generation.
	printf("Please input a uppercase string less than 255 characters: \n");
	char buffer[256];
	scanf("%255s", buffer);

	// Check input string are all uppercase, otherwise exit.
	char* s = buffer;
	while (*s != '\0')
	{
		if (*s<'A' || *s>'Z')
		{
			printf("Please input uppercase string. \n");
			return;
		}
		s++;
	}

	// Run random select evolution given times
	srand((unsigned int)time(NULL));
	size_t sum = 0;
	for (size_t i=0; i<times; ++i)
	{
		sum += random_select_evolution_iterations(buffer);
	}
	float ave = sum * 1.0f/times;
	printf("It needs %.2f generations on average over %zu times to evolute. \n", ave, times);

}