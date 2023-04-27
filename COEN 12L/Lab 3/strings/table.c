#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "set.h"
#include <stdbool.h>

struct set{
	int count;
	int length;
	char **data;
	char *flags;
};

static unsigned strhash(char *s)
{
	unsigned hash = 0;
	while (*s != '\0')
		hash = 31 * hash + *s++;
	return hash;
}

// Big-O-Notation (Search/Find): O(n)
static int search(SET *sp, char *elt, bool *found){
	int a = -1;
	int index;
	index = strhash(elt)%sp->length;
	int num;
	int ind;
	for (num = 0; num < sp->length; num++) {
		ind = (num + index) % sp->length;
		if (sp->flags[ind] == 'F') {
			if (strcmp(sp->data[ind], elt) == 0) {
				*found = true;
				return ind;
			}
		}
		
		else if (sp->flags[ind] == 'D') {
			if (a == -1) {a = ind;}
		}
		
		else if (sp->flags[ind] == 'E') {
	               *found = false;
			if (a != -1) {return a;}
			else {return ind;}
		}
		
		
	}
	
	*found = false;
	return a;
	
}

// Big-O-Notation: O(n)
SET *createSet(int maxElts) {
	SET *sp;
	
	sp = malloc(sizeof(SET));
	assert(sp != NULL);
	
	// Allocation of Memory for an array of maxElts number of pointers to a character
	sp->data = malloc(sizeof(char *) * maxElts);
    sp->flags = malloc(sizeof(char *) * maxElts);
	assert(sp->data != NULL);
	
	sp->count = 0;
	sp->length = maxElts;
	int i;
	for (i = 0; i < maxElts; i++){
		sp->flags[i]='E';
    }
	return sp;
}

// Big-O-Notation: O(n)
void destroySet(SET *sp) {
	int num ;

	for (num = 0; num < sp->length; num++) {
		if (sp->flags[num] == 'F'){
			free(sp->data[num]);}
		
	}
	free(sp->flags);
	free(sp->data);
	free(sp);
	
	
}

// Big-O-Notation: O(1)
int numElements(SET *sp) {
	return sp->count;
}



// Big-O-Notation (Insert): O(1)
void addElement(SET *sp, char *elt) {
	// declare variables
	assert (sp != NULL && elt != NULL);
	bool found;
	int index = search(sp, elt, &found);
	if (!found){
		assert(sp->count < sp->length);
		
	
		sp->data[index] = strdup(elt);
		sp->flags[index] = 'F';
		sp->count++;
	}
}

// Big-O-Notation (Index Known): O(1)
void removeElement(SET *sp, char *elt) {
	// declare variables
	assert (sp != NULL && elt != NULL);
	bool found;
	int index = search(sp, elt, &found);
	if (found){
		assert(sp->count < sp->length);
	
		free(sp->data[index]);
		sp->flags[index] = 'D';
		sp->count--;
	}
}


// Big-O-Notation (Search/Find): O(n)
char *findElement(SET *sp, char *elt) {
	bool found;
	int index = search(sp, elt, &found);
	if (!found) {return NULL;}
	else {return sp->data[index];}
}


// Big-O-Notation (Search/Find): O(n)
char **getElements(SET *sp) {
	int size = sizeof(char *) * sp->count;
	char **ValueOfSet = malloc(size);
	int i;
	int j = 0;
	for (i=0; i < sp->length; i++) {
		if (sp->flags[i] == 'F') {ValueOfSet[j] = strdup(sp->data[i]);j++;}
	}
	return ValueOfSet;
}

