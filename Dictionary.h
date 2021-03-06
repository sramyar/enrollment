// -------------------------------
// Dictionary ADT:
// 
// -------------------------------

#include "HashTable.h"


typedef struct {
	char		key[5];		// key for dictionary element
	void*		value;		// generic pointer to value of dictionary element
	}		element;	// key:value pair of dictionary elements


typedef struct {
	int		slots;		// total number of slots in hash table
	int		size;		// number of elements currently in dictionary
	node_t		*hash_table;	// hash_table is array of pointers to node_t
	}		dictionary;	// dictionary is maintained as a hash table.


// -------------------------------
// Function headers
// -------------------------------

// -------------------------------
// create( D, n ) -- creates a dictionary with n slots
// -------------------------------
void create( dictionary* D, int n );


// -------------------------------
// insert( D, *e ) -- inserts element (*e).key:(*e)->value into the dictionary.
// -------------------------------
int insert( dictionary* D, element *e );


// -------------------------------
// delete( D, *e ) -- deletes (*e)->value from the dictionary.
// -------------------------------
//int delete( dictionary* D, element *e );
int delete( dictionary* D, char *key );


// -------------------------------
// find( D, k ) -- returns pointer to the value of the element whose key is k from dictionary D.
// -------------------------------
//void *find( dictionary* D, char *k );

node_t *find( dictionary* D, char *k );


// -------------------------------
// print( dictionary D ) -- prints the dictionary.
// -------------------------------
void print( dictionary* D );

