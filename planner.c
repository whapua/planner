#include <stdio.h>
#include <unistd.h>
#include <string.h>

void printHelp();
void createFile(char []);

void main(int argc, char *argv[])
{
	int opt;
	char filename[30];

	strcpy(filename, argv[argc - 1]);
	while((opt = getopt(argc, argv, "hc")) != -1)
	{
		switch(opt)
		{
			case 'h':
				printHelp();
				break;
			case 'c':
				createFile(argv[argc-1]);
				break;
			case '?':
				printf("unknown option: %c\n", optopt);
				break;
		}
	}
	for(; optind < argc - 1; optind++) {
		printf("unknown arguments: %s\n", argv[optind]);
	}
	return;
}

void printHelp()
{
	printf("Usage: planner [options] file\n");
	printf("Options:\n");
	printf(" -h	Displays this information\n");
	printf(" -c	Create new datafile\n");
	return;
}

void createFile(char filename[])
{
	FILE *fileWriter;
	fileWriter = fopen(filename, "w");
	fprintf(fileWriter, "0,0,0,0,0,0,0");
	fclose(fileWriter);
	printf("Created %s\n", filename);
	return;
}
