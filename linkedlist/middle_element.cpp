// Program to find middle element/ node of the singly linked list(by traversing only once ).

/*
	Note: 	to count no. of nodes we can add one more member into the list_t structure, count
		and increment the count by one whenever we are adding the node into the list, and decrement the count by 		one whenever we delete the node from the list.
		so instead of using count_node function we can use that count varibale to check wheather no. of nodes in 		the list are odd or even.

	
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
int count_nodes( list_t* list );

node_t* find_middle_node( list_t* list );


int main( void )
{
	list_t list;
	node_t* middle = NULL;
	int no_of_nodes = 0;

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
	

	no_of_nodes = count_nodes(&list);

	if( no_of_nodes > 2 && ( no_of_nodes % 2 ) != 0 )
	{
		middle = find_middle_node( &list );
		printf("\n\n\t middle node is:	%d",middle->data);
	}
	else
	{
		printf("\n\n\t we can not find the middle node");
	}


	printf("\n\n");
	return 0;
}

int list_empty( list_t* list )
{
	return ( list->head == NULL );
}

int count_nodes( list_t* list )
{
	int cnt = 0;
	node_t *trav = list->head;

	while( trav != NULL )
	{
		cnt++;
		trav = trav->next;
	}

	return cnt;
}

