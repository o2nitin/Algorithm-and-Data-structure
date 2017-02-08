//  How to find loop in the singly linked list

/*
	NOTE: 	This program not checks all possible cases, still it will definitly help you for remaining task
		
		
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node_t;

typedef struct
{
	node_t* head;
	node_t* tail;

}list_t;


//function declarations
int list_empty( list_t* list ) ;
void init_list( list_t* list );
node_t* create_node( int data );
void add_last( list_t* list, int data );
void display_list( list_t* list );

void create_loop(list_t *list,int data);
int  is_loop(list_t *list);


int main( void )
{
	list_t list;
	node_t* middle = NULL;
	int no_of_nodes = 0;

	system("cls");

	init_list( &list );

	add_last( &list, 10);
	add_last( &list, 20);
	add_last( &list, 30);
	add_last( &list, 40);
	add_last( &list, 50);
	
	// for checking wheather there is loop exists or not first we have to create loop
	create_loop(&list,60);

	
	if( is_loop(&list) )
	{
		printf("\n\t loop exists");
	}
	else
	{
		printf("\n\t loop does not exists");
	}
	

	printf("\n\n");
	return 0;
}

