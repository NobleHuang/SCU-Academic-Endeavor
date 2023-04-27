#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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

// Big-O-Notation (Search/Find): O(n)
static int search(SET *sp, char *elt){
	int num = 0;
	while (num < sp->count) {
		if (strcmp(sp->data[num], elt) == 0) {
			return num;
		}
		num += 1;
	}

	return -1;
	
}

// Big-O-Notation (Insert): O(1)
void addElement(SET *sp, char *elt) {
	int index = search(sp, elt);
	if (index == -1) {sp->data[sp->count] = strdup(elt); sp->count++;}
	
};

// Big-O-Notation (Index Known): O(1)
void removeElement(SET *sp, char *elt) {
	int index = search(sp, elt);
	if (index != -1) {free(sp->data[index]); sp->data[index] = sp->data[--sp->count];}
};


// Big-O-Notation (Search/Find): O(n)
char *findElement(SET *sp, char *elt) {
	int index = search(sp, elt);
	if (index == -1) {return NULL;}
	else {return sp->data[index];}
};


char **getElements(SET *sp) {
	int size = sizeof(char *) * sp->count;
	char **ValueOfSet = malloc(size);
	return memcpy(ValueOfSet, sp->data, size);
};

