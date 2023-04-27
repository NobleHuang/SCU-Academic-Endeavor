#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeBodies(int arr[], int leftHand, int middleHand, int rightHand, char *words[]) {
    int i, j, k;
    int n1 = middleHand - leftHand + 1;
    int n2 = rightHand - middleHand;
 
    int *leftBody = malloc(sizeof(int) * n1);
	int *rightBody = malloc(sizeof(int) * n2);
 
    char **leftWords = malloc(sizeof(char*) * n1);
	char **rightWords = malloc(sizeof(char*) * n2);
 
    for (i = 0; i < n1; i++) {leftWords[i] = malloc(sizeof(char)*30);}
    for (j = 0; j < n2; j++) {rightWords[j] = malloc(sizeof(char)*30);}
 
    for (i = 0; i < n1; i++) {leftBody[i] = arr[leftHand + i]; strcpy(leftWords[i], words[leftHand + i]);}
    for (j = 0; j < n2; j++) {rightBody[j] = arr[middleHand + 1 + j]; strcpy(rightWords[j], words[middleHand + 1 + j]);}
 
    i = 0; j = 0;
    k = leftHand;
    while (i < n1 && j < n2) {
        if (leftBody[i] <= rightBody[j]) {arr[k] = leftBody[i]; strcpy(words[k], leftWords[i]); i++;}
        else {arr[k] = rightBody[j]; strcpy(words[k], rightWords[j]); j++;}
        k++;
    }
 
    while (i < n1) {arr[k] = leftBody[i]; strcpy(words[k], leftWords[i]); i++; k++;}
 
    while (j < n2) {arr[k] = rightBody[j]; strcpy(words[k], rightWords[j]); j++; k++;}
	
	free(leftBody);
	free(rightBody);
	
	free(leftWords);
	free(rightWords);
}
 
void sortViaMerge(int presorted[], int leftHand, int rightHand, char *words[]) {
	if (leftHand < rightHand) {
		int midHand = (leftHand+rightHand)/2;
		sortViaMerge(presorted, leftHand, midHand, words);
		sortViaMerge(presorted, midHand+1, rightHand, words);
		mergeBodies(presorted, leftHand, midHand, rightHand, words);
	}
	
	else {return;}
}


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
 
    sortViaMerge(num, 0, size, words);

	for (index=0; index <= size; index++) {
		printf("%d %s\n", num[index], words[index]);
	}
	free(num);
	free(words);
	
    // Closing the file
    fclose(fileIO);
}

/*int main(int argc, char** argv)
{
	printf("%s%d%s", "You have entered ", argc, " arguments:\n");

	printf("%s\n", argv[1]);

	return 0;
}*/

