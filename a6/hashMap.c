/*
Author: Shawn S Hillyer
Class: CS 261-400
Date: 02/21/2016
Assignment 6
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{  
	/*write this*/
	assert(ht != NULL);
	int i;
	struct hashLink * current = NULL, * next = NULL;

	for (i = 0; i < capacity(ht); i++) {
		current = ht->table[i];
		while (current != NULL) {
			next = current->next; // handle to move forward after deleting current

			// Free the hashLink's key and the hashLink itself
			if (current->key != NULL)
				free(current->key);
			current->key = NULL;
			// NOTE: the ValueType def ins hashMap.h defines value as type int, cannot call free without breaking program
			// free((void *)current->value); // This line ALWAYS causes a segfault, commenting out
			if (current != NULL)
				free(current);
			current = next;
		}
	}		
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/* 
Resizes the hash table to be the size newTableSize 
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	/*write this*/
	assert(ht != NULL);

	int i;
	struct hashLink * current = NULL;  // iterator

	// Make a new hashMap of the new size to rehash all values into
	struct hashMap *tempHashMap = createMap(newTableSize);
	assert(tempHashMap != NULL);

	// Iterate over all buckets and rehash everything into the newTable
	for (i = 0; i < capacity(ht); i++) {
		current = ht->table[i];
		while (current != NULL) {
			insertMap(tempHashMap, current->key, current->value);
			current = current->next;
		}
	}

	// copy all of the tempHashMap values into the original and free the temp
	ht->table = tempHashMap->table;
	ht->tableSize = tempHashMap->tableSize;
	// Can't delete tempHashMap or we'll be freeing memory now referenced by table... best solution??
	// deleteMap(tempHashMap);  
	tempHashMap = NULL; // so at least avoid dangling it!
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".
 
 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.
 
 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  
	/*write this*/	
	assert(ht != NULL);
	
	// TODO: RESIZE IF NEEDED!
	if (tableLoad(ht) >= LOAD_FACTOR_THRESHOLD) {
		_setTableSize(ht, capacity(ht)*2);
	}

	// Conditionally hash the key
	int hashIndex;
	if (HASHING_FUNCTION == 1)
		hashIndex = stringHash1(k) % capacity(ht);
	if (HASHING_FUNCTION == 2)
		hashIndex = stringHash2(k) % capacity(ht);
	if (hashIndex < 0)
		hashIndex += ht->tableSize; // get the absolute value
	

	struct hashLink* current = ht->table[hashIndex];

	// If bucket is empty, then key doesn't exist yet, just add it
	if (ht->table[hashIndex] == NULL) {
		struct hashLink * newLink = (struct hashLink *)malloc(sizeof(struct hashLink));
		newLink->key = k;
		newLink->value = v;
		newLink->next = NULL;

		// Update table to point to the new link and increment count
		ht->table[hashIndex] = newLink;  // sets table[hashIndex] to the newLink
		ht->count++;
	}

	// else bucket has at least one hashLink, check them  already exists -- replace hashLink->value with the new value
	else {
		while (current != NULL) {
			if (strcmp(current->key, k) == 0) {
				// free((void*)current->value); // tried it -- causes crashing
				current->value = v;
				return;
			} 
			if (current->next == NULL) {
				// We've reacched end of chain without finding value, add it to end
				struct hashLink * newLink = (struct hashLink *)malloc(sizeof(struct hashLink));
				newLink->key = k;
				newLink->value = v;
				newLink->next = NULL;
				current->next = newLink;
				ht->count++;
				return;
			}
			current = current->next;
		}
	}
}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.
 
 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.
 
 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{ 
	/*write this*/
	assert(ht != NULL);
	
	// Conditionally hash the key
	int hashIndex;
	if (HASHING_FUNCTION == 1)
		hashIndex = stringHash1(k) % ht->tableSize;
	if (HASHING_FUNCTION == 2)
		hashIndex = stringHash2(k) % ht->tableSize;
	if (hashIndex < 0) {
		hashIndex += ht->tableSize; // get the absolute value
	}

	// Make an hashLink iterator and check every node in the list at table[hashIndex] until found or null
	struct hashLink * current = ht->table[hashIndex];

	while (current != NULL) {
		if (strcmp(current->key, k) == 0)
			return &current->value;
		current = current->next;
	}

	// If we reach this point then value not found, return NULL as indicated
	return NULL;
}

/*
 a simple yes/no if the key is in the hashtable. 
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{  
	/*write this*/
	assert(ht != NULL);

	// Conditionally hash the key
	int hashIndex;
	if (HASHING_FUNCTION == 1) {
		hashIndex = stringHash1(k) % ht->tableSize;
	}
	if (HASHING_FUNCTION == 2) {
		hashIndex = stringHash2(k) % ht->tableSize;
	}
	if (hashIndex < 0) {
		hashIndex += ht->tableSize; // get the absolute value
	}

	// Make an hashLink iterator and check every node in the list at table[hashIndex] until found or null
	struct hashLink * current = ht->table[hashIndex];
		while (current != NULL) {
		if (strcmp(current->key, k) == 0) {
			return 1;
		}
		current = current->next;
	}
	return 0;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{  
	/*write this*/
	assert(ht != NULL);	

	// Conditionally hash the key
	int hashIndex;
	if (HASHING_FUNCTION == 1) {
		hashIndex = stringHash1(k) % ht->tableSize;
	}
	if (HASHING_FUNCTION == 2) {
		hashIndex = stringHash2(k) % ht->tableSize;
	}
	if (hashIndex < 0) {
		hashIndex += ht->tableSize; // get the absolute value
	}

	struct hashLink * current = ht->table[hashIndex];
	struct hashLink * previous = NULL;
	
	// If the current is an empty bucket then key won't be found, just exit
	if (current == NULL) {
		return;
	}
	 // If not, we have at least one node in bucket. Can safely Iterate
	 // over the links (if any), traversing until we find the key *or* end of chain (key doesn't exist)
	while (current != NULL && (strcmp(current->key, k) != 0)) {
		previous = current;
		current = current->next;
	}
	
	// if previous points to null still, then first node contained key. Free, relink, decrement
	if ((strcmp(current->key, k) == 0) && previous == NULL) {
		ht->table[hashIndex] = current->next;
		free(current);
		ht->count--;
	}
	// else if match, we point previous->next to current->next + Free, decrement
	else if (strcmp(current->key, k) == 0) {
		previous->next = current->next;
		free(current);
		ht->count--;
	}
	// node wasn't found in hashLink chain, return out (explicit for readability only)
	else if (current == NULL) {
		return; 
	}

}

/*
 returns the number of hashLinks in the table
 */
int size(struct hashMap *ht)
{  
	assert(ht != NULL);
	return ht->count;
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{  
	assert(ht != NULL);
	return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{  
	assert(ht != NULL);
	int numEmpty = 0;
	int i;

	for (i = 0; i < capacity(ht); i++) {
		if (ht->table[i] == NULL)
			numEmpty++;
	}
	return numEmpty;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)
 
 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{  
	assert(ht != NULL);
	return( (double)size(ht) / (double)capacity(ht) );
}


void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;	
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {		
			printf("\nBucket Index %d -> ", i);		
		}
		while(temp != 0){			
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;			
		}		
	}
}


