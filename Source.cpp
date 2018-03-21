#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE 1024

int main(int argc, char* argv[]) {
	char* InputFileName = argv[1];
	FILE* InputFile;
	fopen_s(&InputFile, InputFileName, "rb");
	if (!InputFile) {
		perror("Input file opening failed");
		return EXIT_FAILURE;
	}
	size_t i;
	int j;
	int mask;
	unsigned char InputChars[BUFF_SIZE];
	do {
		size_t ReadCounter = fread(InputChars, sizeof InputChars[0], BUFF_SIZE, InputFile);
		for (i = 0; i < ReadCounter; i++) {
			mask = 1;
			for (j = 0; j < 8; j++) {
				if (InputChars[i] & mask) {
					printf("1");
				}
				else
				{
					printf("0");
				}
				mask = mask << 1;
			}
		}
	} while (!feof(InputFile));
	return 0;
}