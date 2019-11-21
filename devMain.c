#include "shell.h"

/**
*
*
*
*
*/

int main(void)
{
	char *hardcoded[] = {"ls", "-la"};

	runComm(*hardcoded);
	return (0);
}
