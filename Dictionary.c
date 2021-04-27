// -------------------------------
// Dictionary ADT:
//
// -------------------------------

#include <stdlib.h>		// for built-in malloc that returns void *
#include "Dictionary.h"
#include <string.h>

// -------------------------------
// TODO: implement create
// create( D, n ) -- creates a dictionary with n slots
// Initializes slots to n, and size to 0.
// -------------------------------

void create(dictionary *D, int n)
{
    D->slots = n;
    D->size = 0;
    D->hash_table = calloc(n, sizeof(node_t));
    for (int i = 0; i < n; i++) {
        memcpy( D->hash_table[i].key, "", 5 );
        D->hash_table[i].value = NULL;
        D->hash_table[i].next = NULL;
        D->hash_table[i].prev = NULL;
    }   
}


// -------------------------------
// TODO: implement insert
// insert( D, *e ) -- inserts element (*e).key:(*e)->value into the dictionary.
// First, make sure that (*e).key does not exist in D yet.
// If it does, return an error code of -1.
// Otherwise, update the size of D, and return 0.
// This is basically CHAINED-HASH-INSERT on page 258 of CLRS.
// -------------------------------

int insert(dictionary* D, element* e)
{
    if(find(D, e->key) != NULL) return -1;
    else{

        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        memcpy(new_node->key, e->key, 5);
        new_node->value = e->value;
        node_t* head = &(D->hash_table[hash(e->key, D->slots)]);
        insertList(&head, new_node);

        D->size++;

        return 0;
    }
}



// -------------------------------
// TODO: implement delete
// delete( D, *e ) -- deletes (*e)->value from the dictionary.
// If (*e).key does not exist in D, return an error code of -1.
// Update the size of D, and return 0.
// This is basically CHAINED-HASH-DELETE on page 258 of CLRS.
// -------------------------------

int delete(dictionary* D, element* e)
{
    node_t* head = &(D->hash_table[hash(e->key,D->slots)]);
    if(head == NULL) return -1;
    else{
        node_t* x = find(D, e->key);
        deleteList(&head, x);
        D->size--;
        return 0;
    }
}



// -------------------------------
// ??????????? return node 
// TODO: implement find
// find( D, k ) -- returns pointer to the value of the element whose key is k from dictionary D.
// If k is not found in D, then return NULL.
// -------------------------------

// void* find(dictionary* D, char* k)
// {
//     int index = hash(convert(k),D->slots);
//     node_t* head = &(D->hash_table[index]);
//     node_t* x = findList(&head, k);
//     if(x == NULL) return NULL;
//     else return x->value;
// }


node_t* find(dictionary* D, char* k)
{
    int index = hash(k,D->slots);
    node_t* head = &(D->hash_table[index]);
    node_t* x = findList(head, k);
    return x;
}


// -------------------------------
// TODO: implement print
// print( dictionary D ) -- prints the dictionary.
// Specifically, it looks at the non-empty slots of the hash table,
// and prints the key field of each node in the list.
// -------------------------------




 
// -------------------------------
//
// -------------------------------

// -------------------------------
//
// -------------------------------
