

struct hlink {
	TYPE value;
	struct hlink *next;
};

struct hashTable {
	struct hlink ** table;
	int tablesize;
	int count;
};


// WRITE ME
// Note -- this is basically same as ws7 for an open has table because
// the entire table should be pointing to null, however, it is a table of
// struct hlink nodes, not TYPE
void initHashTable (struct hashTable * ht, int size) {
	int i;
	assert(size > 0);

	ht->table = (struct hlink *) malloc(size * sizeof(struct hlink *));
	assert(ht->table != NULL);

	// Make all nodes point to null
	for (i = 0; i < size; i++) {
		ht->table[i] = NULL;
	}
	ht->tablesize = size;
	ht->count = 0;

}

// PROVIDED
int hashTableSize (struct hashTable * ht) { 
	return ht->count; 
}


// PROVIDED -- I added some comments
void hashTableAdd (struct hashTable *ht, TYPE newValue) {
// compute hash value to find the correct bucket
	int hashIndex = HASH(val) % ht->tablesize;
	if (hashIndex < 0) {
		hashIndex += ht->tablesize; // get the absolute value
	}
	
	// make a newLink to store value. Make it the new head of
	// the list at that index and increment count
	struct hlink * newLink = (struct hlink *) malloc(sizeof(struct hlink));
	assert(newLink);
	
	newLink->value = newValue; 
	newLink->next = ht->table[hashIndex];
	ht->table[hashIndex] = newLink; /* add to bucket */
	ht->count++;

	// Resize hash table if fills up (>8.0 load factor)
	if ((ht->count / (double) ht->tablesize) > 8.0) {
		_resizeHashTable(ht);
	}
}


// WRITE THIS
int hashTableContains (struct hashTable * ht, TYPE testElement) {
	int hashIndex = HASH(val) % ht->tablesize;
	if (hashIndex < 0) {
		hashIndex += ht->tablesize; // get the absolute value
	}
	// Make an hlink pointer and check every node in the list at hashIndex
	struct hlink * iter = ht->table[hashIndex];
	while (iter != NULL) {
		if (iter->value == testElement) 
			return 1;
		search = iter->next;
	}
	return 0;
}

// WRITE THIS
void hashTableRemove (struct hashTable * ht, TYPE testElement) {
	int hashIndex = HASH(val) % ht->tablesize;
	if (hashIndex < 0) {
		hashIndex += ht->tablesize; // get the absolute value
	}
	// Make an hlink pointer and check every node in the list at hashIndex
	struct hlink * iter = ht->table[hashIndex];
	struct hlink * prior = iter;

	while (iter != NULL) {
		// if favlue found
		if (iter->value == testElement) {
			// handle case where we are at the first link
			if (iter == ht->table[hashIndex]){
				ht->table[hashIndex] = iter->next;
				free(iter);
				iter = NULL;
			} 
			// otherwise, should be able to make prior->next point to iter->next
			else {
				prior->next = iter->next;
				free(iter);
				iter = NULL;
			}
		} else {
			prior = iter;
			iter = iter->next;
		}
	}
}



// WRITE THIS
void resizeTable (struct hashTable *ht) {
	int i = 0;

	struct hastTable* newHt = (struct hashTable *) malloc(sizeof(struct hashTable));
	assert(newHt != NULL);
	initHashTable(newHt, ht->tablesize * 2));

	// iterate over every value of ht, read the value, and use it to rehash into the new hash table
	struct hLink * iter = ht->table[i];

	while (i < ht->tablesize) {
		// traverse the list stored in this particular index of table
		while (iter != NULL) {
			hashTableAdd(newHt, iter->value);
			hashTableRemove(ht, iter->value); // because we need to free the memory for every real node in the old table
			iter = iter->next;
		}
		// go to next index of table
		iter = ht->table[++i];
	}

	// free memory and point to new table, update size etc.
	for (i = 0; i < ht->tablesize; i++) {
		if (ht->table[i] != NULL) {
			free(ht->table[i]);
			ht->table[i] = NULL;
		}
	}

	ht->table = newTable;
	ht->size++;
	ht->tablesize *= 2;
}

