//Program to sort the singly linear linked list

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

void add_first( list_t* list, int data );
void display_list( list_t* list );


int main( void )
{
	list_t list;


	system("clear");

	init_list( &list );

	add_first( &list, 14);
	add_first( &list, 3);
	add_first( &list, 27);
	add_first( &list, 88);
	add_first( &list, 15);

	
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

void add_first( list_t* list, int data )
{
	node_t* newnode = create_node( data );

	if( list->head == NULL )
	{
		list->head = newnode;
		list->tail = newnode;
	}
	else
	{
		newnode->next = list->head->next;
		list->head = newnode;

	}//end of else

}//end of add_first function

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


void sort_list(list_t* list)
{
	node_t *t1,*t2,*t3,*t;
	int flag = 1;
	int comp = 0;
	int it = 0;
	int temp;

	for( t = list->head ; t != NULL ; t= t->next );

	for( t1 = list->head ; t1 != NULL && flag == 1; t1 = t1->next )
	{
		flag = 0;
		it++;

		for( t2 = list->head ; t2 != t ; t2 = t2->next )
		{
			comp++;

			if( t2->data > t2->next->data )
			{
				flag = 1;
				temp = t2->data;
				t2->data = t2->next->data;
				t2->next->data = temp;

			}//end of if

			t3 = t2;
		}//end of inner for loop

		t = t3;

	}//end of outer for loop

	printf("\n\n\t No. of Iterations  = %d",it);
	printf("\n\n\t No. of Comparisons = %d",comp);


}//end of sort_list function
