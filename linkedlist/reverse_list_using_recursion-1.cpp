//To implement recursive function for reversing the singly linear linked list

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

void rec_reverse_list( list_t* list, node_t* t1, node_t* t2 );

int main( void )
{
	list_t list;

	system("clear");

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
	
	rec_reverse_list(&list,list.head,list.head->next);

	printf("\n\n\t Reverse list is:	");
	display_list(&list);

	printf("\n\n");
	return 0;
}

void rec_reverse_list( list_t* list, node_t* t1, node_t* t2 )
{
	if( t1 == list->head )
	{
		t1->next = NULL;
	}

	if( t2 == NULL )
	{
		list->head = t1;
		return;
	}
	else
	{
		node_t* t3 = t2->next;
		t2->next = t1;
		rec_reverse_list(list,t2,t3);
	}
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
