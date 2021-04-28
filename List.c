#include <string.h>
#include<stdio.h>
#include "List.h"

// -----------------------------
// Returns ptr to node with matching key, else returns NULL
// -----------------------------
node_t *findList( node_t *head, char *key )
{

	node_t *ptr;
	//printf("\n\tnow key is:%s\n",ptr->key);
	ptr = head;
	while( ptr != NULL )
	{
		//printf("\n\tWHILE now key is:%s\n",ptr->key);
		if (strncmp(ptr->key,key,5) == 0){
			return ptr;
		}
		else    ptr = ptr->next;
	}
	
	return( NULL );
	
}

// -----------------------------
// Returns ptr to node with matching key, else returns NULL
// -----------------------------
void insertList( node_t **head, node_t *new )
{	
	// insert new node as head of list
	if (*head == NULL)
	    {	*head = new;
		(*head)->next = NULL;
		(*head)->prev = NULL;
	    }
	else{	new->next  = *head;
		(*head)->prev = new;
		new->prev  = NULL;
		*head      = new;
	    }
	//printf("\n\thead now has key:%s\n",(*head)->key);
	
	/*
	if(*head == NULL){
		*head = new;
		(*head)->next = NULL;
		(*head)->prev = NULL;
	}
	else{
		(*head)->next = new;
		new->prev = *head;
		new->next = NULL;
	}
	*/
}

// -----------------------------
// Deletes node pointed to by del from the list.
// You can assume that del points to a node in the list.
// -----------------------------
void deleteList( node_t **head, node_t *del )
{
	if(*head == del){
		*head = del->next;
	}
	else{
		del->prev->next = del->next;
		if (del->next != NULL) del->next->prev = del->prev;
	}

	//TODO: destruct node
}

// -----------------------------
// Prints key field of each node in the list starting at head.
// -----------------------------
void printList( node_t *head )
{
	if(head == NULL) return;
	node_t* cue = head;
	printf("\n\t>>PRINTING LIST>>");
	while (cue != NULL)
	{
		printf("%s\t",cue->key);
		cue = cue->next;
	}
	printf("\n");

}

