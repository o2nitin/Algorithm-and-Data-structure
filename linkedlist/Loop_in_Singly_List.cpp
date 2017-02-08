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

int  is_loop(list_t *list)
{
	node_t* t1 = list->head;
	node_t* t2 = list->head;

	while( t1->next->next != NULL )
	{
		if( t1->next != NULL )
			t1 = t1->next->next;

		if( t2->next != NULL )
			t2 = t2->next;
		
		if( t1 == t2 )
		{
			return 1;
		}


		if( t1->next == NULL || t2->next == NULL )
			break;

		// for self loop

		if( t2 == t2->next )
			break;
	}

	return 0;

}

void create_loop(list_t *list,int data)
{
	node_t* newnode = create_node( data );
	node_t* trav = list->head;
	
	
	while( trav->next->next != NULL )
		trav = trav->next;

	newnode->next = trav;
	list->tail->next = newnode;

}


int list_empty( list_t* list )
{
	return ( list->head == NULL );
}


void init_list( list_t* list )
{
	list->head = list->tail = NULL;
}

node_t* create_node( int data )
{
	node_t* temp = malloc( sizeof(node_t) );

	temp->data = data;
	temp->next = NULL;

	return temp;
}

void add_last( list_t* list, int data )
{
	node_t* newnode = create_node( data );

	if( list->head == NULL )
	{
		list->head = newnode;
		list->tail = newnode;
	}
	else
	{
		list->tail->next = newnode;
		list->tail = newnode;
	}//end of else

}//end of add_last function

void display_list( list_t* list )
{
	node_t* trav = list->head;

	printf("\n\n\t List is : HEAD -> ");

	while( trav != NULL )
	{

		printf("%d -> ",trav->data);
		trav = trav->next;
	}

	printf(" NULL ");
}
