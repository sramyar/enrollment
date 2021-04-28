// -------------------------------
// Dictionary ADT:
//
// -------------------------------

#include <stdlib.h>		// for built-in malloc that returns void *
#include "Dictionary.h"
#include <string.h>
#include<stdio.h>
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
        int index = hash(e->key, D->slots);
        node_t* cue = &(D->hash_table[index]);
        while (cue->next != NULL){
            cue = cue->next;
        }
        cue->next = new_node;
        new_node->prev = cue;
        new_node->next = NULL;

        //insertList(&head, new_node);
        //D->hash_table[index] = *new_node;
        //printf("\n\t\tADDING COURSE %s at index:%d\n",head->key, index);
        //printf("\n\t\tADDING COURSE %s at index:%d\n",(D->hash_table[index]).key, index);
        //printList(head);
        D->size++;
        return 0;
        
        /*
        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        node_t* head = find(D, e->key);
        printf("\n\thead key is:%s\n",D->hash_table[hash(e->key,D->slots)].key);
        memcpy(head->key, e->key, 5);
        printf("\n\tsegfalter\n");
        head->value = e->value;
        int index = hash(e->key, D->slots);
        
        insertList(&head, new_node);
        //printf("\n\t\tADDING COURSE %s at index:%d\n",head->key, index);
        //printList(head);
        D->size++;

        return 0;
        */
    }
}



// -------------------------------
// TODO: implement delete
// delete( D, *e ) -- deletes (*e)->value from the dictionary.
// If (*e).key does not exist in D, return an error code of -1.
// Update the size of D, and return 0.
// This is basically CHAINED-HASH-DELETE on page 258 of CLRS.
// -------------------------------

//int delete(dictionary* D, element* e)
int delete(dictionary* D, char* key)
{
    node_t* node = find(D, key);
    if(strncmp(node->key,key,5) != 0){
        printf("\nNo element with key %s\n",key);
        return -1;
    }
    node_t* cue = &(D->hash_table[hash(key,D->slots)]);
	node_t* x;
	while(cue->next != NULL){
		if(strncmp(cue->next->key, key, 5) == 0){
			x = cue->next;
			cue->next = x->next;
			//printf("\n\tI'M HERE\n");
			if(x->next != NULL) x->next->prev = cue;
			//printf("\n\tI'M HERE\n");
			free(x);
			//printf("\n\tPTR TO NXT %s\n",cue->key);
			//printf("\n\t___________PRINTING DICS\n");
			//print(&CourseDict);
			printf("\nElement with key %s removed\n",key);
			return 0;
		}
		else cue = cue->next;
	}
    return -1;
    /*
    node_t* x = find(D, e->key);
    if(x == NULL){
        printf("\nElement not in dictionary\n");
        return -1;
    }
    else{
        node_t* head = &(D->hash_table[hash(e->key, D->slots)]);
        deleteList(&head, x);
        D->size--;
        return 0;
    }
    */
    /*
    node_t* head = &(D->hash_table[hash(e->key,D->slots)]);
    if(head == NULL) return -1;
    else{
        node_t* x = find(D, e->key);
        deleteList(&head, x);
        D->size--;
        return 0;
    }
    */
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
    /*
    int index = hash(k,D->slots);
    node_t* head = &(D->hash_table[index]);
    //printf("\nCalling findList for head KEY:%s\n",head->key);
    node_t* x = findList(head, k);
    //printf("\n\t head is %p and x is %p\n",head, x);
    return x;
    */
    int index = hash(k,D->slots);
    node_t* cue = &(D->hash_table[index]);

    while(cue->next != NULL){
        if (strncmp(cue->next->key, k, 5) == 0) return cue->next;
        cue = cue->next;
    }
    return NULL;

}


// -------------------------------
// TODO: implement print
// print( dictionary D ) -- prints the dictionary.
// Specifically, it looks at the non-empty slots of the hash table,
// and prints the key field of each node in the list.
// -------------------------------

void print(dictionary* D)
{
    node_t* head;
    for (int i = 0; i < D->slots; i++)
    {
        head = &(D->hash_table[i]);
        //printf("\n\t slot %d key is %s\n",i, head->key);
        printList(head);
        //if(head != NULL) printf("\n\tindex %d actually has it\n",i);
    }
    
}


 
// -------------------------------
//
// -------------------------------

// -------------------------------
//
// -------------------------------
