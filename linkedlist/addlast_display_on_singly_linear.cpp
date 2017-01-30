//12. Program to implement add_last and display_list functions of singly linear linked list

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


int main( void )
{
	list_t list;


	system("clear");

	init_list( &list );

	add_last(&list,10);
	add_last(&list,20);
	add_last(&list,30);
	add_last(&list,40);
	add_last(&list,50);
	
	
	if( !list_empty( &list) )
	{
		display_list( &list);
	}
	else
	{
		printf("\n\n\t List is empty...");
	}
	
	printf("\n\n");
	return 0;

}//end of main function


int list_empty( list_t* list )
{
	return ( list->head == NULL );

}//end of list_empty function

void init_list( list_t* list )
{
	list->head = list->tail = NULL;

}//end of init_list function

node_t* create_node( int data )
{
	node_t* temp = malloc( sizeof(node_t) );

	temp->data = data;
	temp->next = NULL;

	return temp;

}//end of create_node function


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

}//end of display_list function
