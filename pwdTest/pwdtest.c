
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define size 1024

int main(int argc, char* argv[])
{

        char buff[size];

	if (getcwd(buff, size) == NULL)
	{ 
		printf("ERROR: can't print current working directory\n");
		exit(-1);
	}

	int buffLen = strlen(buff);

	if (write(1, buff, buffLen) < 0)
	{
		printf("ERROR: in writing pwd\n");
		exit(-2);
	}
	printf("\n");

	return 0;
}
