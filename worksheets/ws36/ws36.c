/* ws36

Complexities table:

containsKey():   O(N). Since this is an unordered dynamic array (presumably),
 we just havev to search until its found (according to the worksheet).

 get() : O(N), since we have to search until we find the value and it might be at the end
 put() : O(N)... same reason
 remove() : O(N)... same as our remove operation in a dynArray

 The interesthing thing about this implementation is basically, its just a freaking
 regular bag where the objects stored have a key added to them as well. So that's all
 that is happening.

************************************************************************/
# ifndef DYARRAYDICTH
# define DYARRAYDICTH
/*
dynamic array dictionary interface file
*/
# ifndef KEYTYPE
# define KEYTYPE char *
# endif
# ifndef VALUETYPE
# define VALUETYPE double
# endif

struct association {
	KEYTYPE key;
	VALUETYPE value;
};

# define TYPE struct association *
# include "dyArray.h"

/* dictionary */
VALUETYPE dyArrayDictionaryGet (struct dyArray * dy, KEYTYPE key);
void dyArrayDictionaryPut (struct dyArray * dy, KEYTYPE key, VALUETYPE val);
int dyArrayDictionaryContainsKey (struct dyArray * da, KEYTYPE key);
void dyArrayDictionaryRemoveKey (struct dyArray * da, KEYTYPE key);

# endif
/************************************************************************/

# include "dyArrayDictionary.h"
# include "dyArrayDictionary.c"

// WRITEME: 
/*finds and places the value associated with key in valptr */
void dyArrayDictionaryGet (struct dynArr *da, KEYTYPE key, VALUETYPE *valptr) {
	int i;
	for (i = 0; i < da->size; i++) {
		if (EqKey(da->data[i]->key, key)) {
			valptr = da->data[i]->value;
			return;
		}
	}
	// If not found, just returns and valptr will still point to (presumably!) null
}


// This was provided
void dyArrayDictionaryPut (struct dynArr *da, KEYTYPE key, VALUETYPE val) {
	struct association * ap;
	// these seems kind of stupid to iterate over the structure once to see if it exists AND a second time to remove it...
	if (dyArrayDictionaryContainsKey(da, key))
		dyArrayDictionaryRemove(da, key);  
	ap = (struct association *) malloc(sizeof(struct association));
	assert(ap != 0);
	ap->key = key;
	ap->value = val;
	dyArrayAdd(da, ap);
}


// WRITEME: 
int dyArrayDictionaryContainsKey (struct dynArr *da, KEYTYPE key) {
	int i;
	for (i = 0; i < da->size; i++) {
		if (EqKey(da->data[i]->key, key)) {
			return 1; // true
		}
	}
	return 0; // false
}


// WRITEME: 
void dyArrayDictionaryRemove (struct dynArr *da, KEYTYPE key) {
	int i;
	// iterate over every element until we find the key, then remove it (this will
	// almost always result in a shift)
	for (i = 0; i < da->size; i++) {
		if (EqKey(da->data[i]->key, key)) {
			dyArrayRemoveAt(i); // use function written weeks ago... why reinvent the wheel
			return;
		}
	}
}