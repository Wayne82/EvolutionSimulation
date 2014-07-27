// main function of evolution simulation

#include <stdlib.h>
#include <stdio.h>
// Includes the evolution functions
#include "RandomSelectEvolution.h"

int press_q_to_exit()
{
	printf("Press 'q' to exit or [Enter] to continue.\n");

	// Flush
	char ch;
	do
	{
 	   ch = fgetc ( stdin );	
	}while ( ch != EOF && ch != '\n' );

	ch = fgetc(stdin);
	if (ch == 'q' || ch == 'Q')
		return 1;

	printf("\n");
	return 0;
}

int main(int argc, char const *argv[])
{
	do
	{
		// Test random select evolution
		call_random_select_evolution_iterations(10000);


		// Press q to exit, otherwise continue.
		if (press_q_to_exit())
			break;

	}while(1);

	return 0;
}