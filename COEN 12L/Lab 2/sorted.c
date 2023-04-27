/*

Filename: sorted.c
Created by: Mulia Widjaja (Noble)
Date: 10/8/2022

Description:
Create a new data strucuture type called "set" for a sorted data set.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "set.h"

struct set{
	int count;
	int length;
	char **data;
};

SET *createSet(int maxElts) {
	SET *sp;
	
	sp = malloc(sizeof(SET));
	assert(sp != NULL);
	
	// Allocation of Memory for an array of maxElts number of pointers to a character
	sp->data = malloc(sizeof(char *) * maxElts);
	assert(sp->data != NULL);
	
	sp->count = 0;
	sp->length = maxElts;
	
	return sp;
};

void destroySet(SET *sp) {
	int num = 0;
	while (num < sp->count) {
		free(sp->data[num]);
		num++;
	}
	
	
};

int numElements(SET *sp) {
	return sp->count;
};


// Big-O-Notation (Search/Find): O(log n)
static int search(SET *sp, char *elt, bool *found){
	int low = 0;
	int mid = 0;
	int high = sp->count - 1;
    int cmp;

	while (low <= high) {
		mid = (high + low) / 2;
		cmp = strcmp(sp->data[mid], elt);
		
		if (cmp < 0) {
			low = mid + 1;
		}
	
		else if (cmp > 0) {
			high = mid - 1;
		}
	
		else {
			*found = true;
			return mid;
		}
		
	}
	
	*found = false;
	return low;
	
}

// Big-O-Notation (Insert): O(n)
void addElement(SET *sp, char *elt) {
	bool found;
	int index = search(sp, elt, &found);

	if (!found) {
		int arrayShiftIndex = sp->count+1;
		while (arrayShiftIndex > index) {
			sp->data[arrayShiftIndex] = sp->data[arrayShiftIndex-1];
			arrayShiftIndex--;
		}

		sp->data[index] = strdup(elt);
		sp->count++;
	}
	
};


// Big-O-Notation (Index Known): O(n)
void removeElement(SET *sp, char *elt) {
	bool found;
	int index = search(sp, elt, &found);

	if (found) {
		free(sp->data[index]);
		int arrayShiftIndex = index;
		
		while (arrayShiftIndex < sp->count) {
			sp->data[arrayShiftIndex] = sp->data[arrayShiftIndex+1];
			arrayShiftIndex++;
		}

		sp->count--;
	}
};


// Big-O-Notation (Search/Find): O(n)
char *findElement(SET *sp, char *elt) {
	bool found;
	int index = search(sp, elt, &found);
	if (!found) {return NULL;}
	else {return sp->data[index];}
};


char **getElements(SET *sp) {
	int size = sizeof(char *) * sp->count;
	char **ValueOfSet = malloc(size);
	return memcpy(ValueOfSet, sp->data, size);
};

