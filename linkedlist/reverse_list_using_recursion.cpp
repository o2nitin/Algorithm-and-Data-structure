//To reverse the singly linear linked list without using recursive function

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
void reverse_list( list_t* list );


int main( void )
{
	list_t list;

	system("cls");

	init_list( &list );

	add_last( &list, 10);
	add_last( &list, 20);
	add_last( &list, 30);
	add_last( &list, 40);
	add_last( &list, 50);
	

	if( !list_empty( &list) )
	{
		display_list( &list);
	}
	else
	{
		printf("\n\n\t List is empty...");
	}
	


	reverse_list(&list);
	
	printf("\n\n\t Reverse list is:	");
	display_list(&list);

	printf("\n\n");
	return 0;
}


void reverse_list( list_t* list )
{
	node_t* t1 = list->head;
	node_t* t2 = t1->next;
	node_t* t3 = NULL;

	t1->next = NULL;

	while( t2 != NULL )
	{
		t3 = t2->next;

		t2->next = t1;

		t1 = t2;
		t2 = t3;
	}

	list->head = t1;
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


