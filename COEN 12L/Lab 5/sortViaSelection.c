#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *value1, int *value2) {
	int value3;
	
	value3 = *value1;
	*value1 = *value2;
	*value2 = value3;
}


void swapNames(char *value1, char *value2) {
	char *value3 = malloc(sizeof(char)*30);
	
	strcpy(value3, value1);
	strcpy(value1, value2);
	strcpy(value2, value3);
}


void sortViaSelection(int presorted[], char **words, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		int minBox = i;
		
		int j;
		for (j = i + 1; j < size + 1; j++)
		{if (presorted[j] < presorted[minBox]) {minBox = j;}}
		
		swap(&presorted[minBox], &presorted[i]);
		swapNames(words[minBox], words[i]);
	}
}

// Initial time in initialTime

// Execution main() function
// Driver code
int main(int argc, char** argv)
{
    FILE* fileIO;
 
    // Opening file in reading mode
	char** fileName = argv[1];

    fileIO = fopen(fileName, "r");
	
	int index = 0;
	
	int maxSize = 10000000;

	int* num = malloc(sizeof(int) * maxSize);
	char** words = malloc(sizeof(char*) * maxSize);
	
	int i;
	for (i=0; i < maxSize; i++) {
		words[i] = malloc(sizeof(char)*30);
	}
	
	int size = 0;
	i = 0;
	while (!feof(fileIO)) {
		fscanf(fileIO, "%d %s", &num[i], words[i]);
		//printf("%d %s\n", &num[i], words[i]);
		//printf("%d %d\n", i, size);
		i++;
		size++;
	}
	size--;
	
	//fseek (fileIO, 0, SEEK_END);

	//char fileCont[ftell(fileIO)];

    if (NULL == fileIO) {
        printf("file can't be opened \n");
    }
 
    sortViaSelection(num, words, size);

	for (index=0; index <= size; index++) {
		printf("%d %s\n", num[index], words[index]);
	}
	free(num);
	free(words);
	
    // Closing the file
    fclose(fileIO);
}


// Final Time

// Final-Initial 
