/*

Filename: count.c
Created by: Mulia Widjaja (Noble)
Date: 9/21/2022

Find 

*/

#include <stdio.h>

#define Max_Word_Length 30

int main( int argc, char *argv[] )  {

// Definitions of Essential Variables
FILE *fileIO = fopen(argv[1], "r");

if (fileIO && argc == 2) {

// Seeking files to the end and tell the final location
char buffer[Max_Word_Length+1];

int totalWords = 0;
while (fscanf(fileIO, "%s", buffer) == 1) {totalWords++;}

printf("%d total words\n\n", totalWords);

}

else if (argc > 2) {
printf("\nError: Arguments entered were too much.\n\n");
}

else if (argc == 1) {
printf("\nError: Arguments entered were not enough.\n\n");
}

else {
printf("\nError: File does not exist.\n\n");
}

}

