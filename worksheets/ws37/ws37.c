/*
Complete the implementation of the HashTableBag based on these ideas. The initial size
of the table is here fixed at 17. The data field tablesize holds the size of the table. The
table should be resized if the load factor becomes larger than 0.75. Because the table
contains pointers, the field in the struct is declared as a pointer to a pointer, using the
double star notation. The variable count should represent the number of elements in the
table. The macro HASH is used to compute the hash value. The calculation of the hash
index is performed using long integers. The reason for this is explored in Chapter 12. */

struct openHashTable {
	TYPE ** table;
	int tablesize;
	int count;
};

// Included with WS
void initOpenHashTable (struct openHashTable * ht, int size) {
	int i;
	assert (size > 0);
	ht->table = (TYPE *) malloc(size * sizeof(TYPE *));
	assert(ht->table != 0);
	for (i = 0; i < size; i++) {
		ht->table[i] = 0; /* initialize empty */
	}
	ht->tablesize = size;
	ht->count = 0;
}

// Included with WS
int openHashTableSize (struct openHashTable *ht) { 
	return ht->count; 
}


void openHashTableAdd (struct openHashTable * ht, TYPE *newValue) {
	int idx;
	/* Make sure we have space and under the load factor threshold*/
	if ((ht->count / (double) ht->tablesize) > 0.75)
		_resizeOpenHashTable(ht);
	ht->count++;
	idx = HASH(newValue) % ht->tablesize;
	/* To be safe, use only positive arithmetic. % may behave very differently on diff
	implementations or diff languages . However, you can do the following to deal with a
	negative result from HASH */
	if (idx < 0) 
		idx += ht->tablesize;
	// Included with WS up to this point

	// Check the idx to see if it points to null; if not, move forward and try again
	while (ht->table[idx] != NULL) {
		idx++;
	}
	ht->table[idx] = newValue; // store the value into the index - we found it.
	ht->count++;
}

// TODO: Write this
void openHashTableBagContains (struct openHashTable *ht, TYPE testValue) {
	int idx;
	idx = HASH(newValue) % ht->tablesize;
	if (idx < 0) 
		idx += ht->tablesize;

	// Search starting at index and move forward until we find the value
	// Since our table is never 100% full, this SHOULD be safe (it doubles in size at 75% capacity)
	while (ht->table[idx] != NULL) {
		if (ht->table[idx] == testValue) {
			return 1; // true
		}
		idx++;
	}
	return 0;
}	

// TODO: Write this
void _resizeOpenHashTable (struct openHashTable *ht) {
	// NOTE: Could we change this... make a new HashTable
	// with the size twice the original, then read each value in the original
	// , make a new node, re-hash, and call add for every element?
	// I think that woudl work... probably rewrite the below code.

	int i;
	int newSize = ht->tableSize * 2;
	TYPE** newTable = (TYPE *) malloc(newSize * sizeof(TYPE *));
	TYPE** tempTable = (TYPE *) malloc(newSize * sizeof(TYPE *));
	assert(newTable != 0);
	assert(tempTable != 0);

	// copy to a temp array
	for (i = 0; i < ht->tablesize; i++) {
		tempTable[i] = ht->data[i];
	}

	// make the ht point to new table, free old table
	TYPE** garbage = ht->table;
	ht->table = newTable;
	ht->tablesize = newSize;
	free(garbage);
	
	// rehash everything into new array
	for (i = 0; i < ht->tablesize; i++) {
		if (ht->data[i] != NULL) {
			openHashTableAdd(ht, tempTable[i]);
		}
	}
	free(tempTable);
}}