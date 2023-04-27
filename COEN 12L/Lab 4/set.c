/*

Filename: set.c
Created by: Mulia Widjaja (Noble)
Date: 11/5/2022

Constructing a set containing several linked lists along with its functions

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "list.h"
#include "set.h"

// Big-O-Notation: O(1)
struct set{
	int count;
	int length;
	LIST** lists;
	int (*compare)();
	unsigned (*hash)();
};

// Big-O-Notation: O(n)
SET *createSet(int maxElts, int (*compare)(), unsigned (*hash)()) {
	SET *sp;
	
	sp = malloc(sizeof(SET));
	
	sp->count = 0;
	sp->length = maxElts/20;

	sp->lists = malloc(sizeof(LIST*) * sp->length);
	assert(sp != NULL);

	sp->compare = compare;

	int i;
	for (i=0; i<sp->length; i++){
		sp->lists[i] = createList(compare);
	};
	
	sp->hash = hash;
	
	return sp;
}

// Big-O-Notation: O(n)
void destroySet(SET *sp) {

	int i;
	for (i=0; i<sp->length; i++){
		destroyList(sp->lists[i]);
	};

	free(sp->lists);
	free(sp);
	
}

// Big-O-Notation: O(1)
int numElements(SET *sp) {
	return sp->count;
}

// Big-O-Notation: O(n), calling findItem
void addElement(SET *sp, void *elt) {
	int i = (*sp->hash)(elt) % sp->length;
	if (!findItem(sp->lists[i], elt)) {
		addLast(sp->lists[i], elt);
		sp->count++;
	}
}

// Big-O-Notation: O(n), calling findItem
void removeElement(SET *sp, void *elt) {
	int i = (*sp->hash)(elt) % sp->length;
	if (findItem(sp->lists[i], elt)) {
		removeItem(sp->lists[i], elt);
		sp->count--;
	}
}


// Big-O-Notation: O(n), calling findItem
void *findElement(SET *sp, void *elt) {
	int i = (*sp->hash)(elt) % sp->length;
	return findItem(sp->lists[i], elt);
}


// Big-O-Notation: O(n), spIndex loop
void *getElements(SET *sp) {
	int j;
	int size = sizeof(void *) * sp->count;
	void **ValueOfSet = malloc(size);
	void **itemToGet;

	int spIndex;
	for (spIndex=0, j=0; spIndex < sp->length; spIndex++){
		itemToGet = getItems(sp->lists[spIndex]);
		
		int loopSize = numItems(sp->lists[spIndex]);
		memcpy(ValueOfSet+j, itemToGet, sizeof(void *) * loopSize);
		
		j += loopSize;
		
		free(itemToGet);
	}
	
	return ValueOfSet;
}
