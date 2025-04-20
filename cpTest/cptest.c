#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>


#define SIZE	100

int main(int argc, char* argv[]){
	char buff[SIZE];

	if(argc != 3){
		printf("Usage: <./cptest> <source_file> <destination_file>\n");
		exit(-1);
	}
	

	int inputFd = open(argv[1], O_RDONLY);
	if(inputFd < 0){
		printf("ERROR: can't open %s file\n", argv[1]);
	        exit(-2);
	 }


	int outputFlags = O_CREAT | O_WRONLY ;
	

	int outputFd = open(argv[2], outputFlags, 0644);

	if(outputFd < 0){
		printf("ERROR: can't open %s file\n", argv[2]);
		exit(-3);
	}

	int numRead;
	while((numRead = read(inputFd, buff, SIZE)) > 0){
		if(write(outputFd, buff, numRead) != numRead){
			printf("ERROR: couldn't write whole buffer\n");
			exit(-4);
		}
	}


	close(inputFd);
	close(outputFd);

	return 0;

}



