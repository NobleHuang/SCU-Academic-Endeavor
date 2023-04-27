/*

Filename: list.c
Created by: Mulia Widjaja (Noble)
Date: 11/5/2022

Constructing a linked list along with its functions

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "list.h"

// Big-O-Notation: O(1)
struct list{
	int count;
	struct node *head;
	int (*compare)();
};

// Big-O-Notation: O(1)
struct node{
	void *data;
	struct node *next;
	struct node *prev;
};

// Big-O-Notation: O(1)
LIST *createList(int (*compare)()) {
	struct list *lp;
	
	lp = malloc(sizeof(struct list));
	
	lp->head = malloc(sizeof(struct node));
	lp->head->prev = lp->head;
	lp->head->next = lp->head;
	lp->compare = compare;
	lp->count = 0;
	
	return lp;
}

// Big-O-Notation: O(n)
void destroyList(LIST *lp) {
	struct node *iter, *temp;
	
	iter = lp->head;
	
	while (iter != lp->head) {
		temp = iter->next;

		free(temp);
		iter = temp;
	}
	
	free(lp);
}

// Big-O-Notation: O(1)
int numItems(LIST *lp) {
	return lp->count;
}

// Big-O-Notation: O(1)
void addFirst(LIST *lp, void *item) {
	struct node *dummy;
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = item;
	lp->count++;
	dummy = lp->head;
	newNode->prev = dummy;
	newNode->next = dummy->next;
	
	dummy->next->prev = newNode;
	dummy->next = newNode;
}

// Big-O-Notation: O(1)
void addLast(LIST *lp, void *item) {
	struct node *dummy;
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = item;
	lp->count++;
	dummy = lp->head;
	newNode->prev = dummy->prev;
	newNode->next = dummy;
	
	dummy->prev->next = newNode;
	dummy->prev = newNode;
}

// Big-O-Notation: O(1)
void *removeFirst(LIST *lp) {
	struct node *dummy;
	struct node *deletingNode;
	
	dummy = lp->head;
	lp->count--;
	deletingNode = dummy->next;
	dummy->next = deletingNode->next;

	deletingNode->next->prev = dummy;
	
	void *dataDeleted = deletingNode->data;
	
	free(deletingNode);
	
	return dataDeleted;
}

// Big-O-Notation: O(1)
void *removeLast(LIST *lp) {
	lp->count--;
	
	struct node *dummy;
	struct node *deletingNode;
	
	dummy = lp->head;
	deletingNode = dummy->prev;
	dummy->prev = deletingNode->prev;

	deletingNode->prev->next = dummy;
	
	void *dataDeleted = deletingNode->data;
	
	free(deletingNode);
	
	return dataDeleted;
}

// Big-O-Notation: O(1)
void *getFirst(LIST *lp) {
	assert(lp != NULL);
	return lp->head->next->data;
}

// Big-O-Notation: O(1)
void *getLast(LIST *lp) {
	assert(lp != NULL);
	return lp->head->prev->data;
}

// Big-O-Notation: O(n)
void removeItem(LIST *lp, void *item) {
	struct node *iter;
	
	for (iter = lp->head->next; iter != lp->head; iter = iter->next) {
		if ((*lp->compare)(iter->data, item) == 0) {
			iter->next->prev = iter->prev;
			iter->prev->next = iter->next;
			
			lp->count--;
			free(iter);
			
			break;
		}
	}
}

// Big-O-Notation: O(n)
void *findItem(LIST *lp, void *item) {
	struct node *iter;
	
	for (iter = lp->head->next; iter != lp->head; iter = iter->next) {
		if ((*lp->compare)(iter->data, item) == 0) {
			return iter->data;
		}
	}
	
	return NULL;
}

// Big-O-Notation: O(n)
void *getItems(LIST *lp) {
	struct node *iter;
	
	int j=0;
	
	void **ValueOfSet = malloc(sizeof(void *) * lp->count);
	
	for (iter = lp->head->next; iter != lp->head; iter = iter->next) {
		ValueOfSet[j++] = iter->data;
	}
	
	return ValueOfSet;
}
