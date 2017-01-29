// Program13,14: delete_first(), delete_last() and display_list() functions

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;

}NODE;


typedef struct
{
	NODE *head;
	NODE *tail;

}LIST;



//function declarations

void add_at_last(LIST *list,int ele);
void delete_at_first(LIST *list);
void delete_at_last(LIST *list);
NODE *create_node(int ele);
void display_list(LIST *list);
void init_list(LIST *list);

int main( void )
{
	LIST list;
	init_list(&list);

	add_at_last(&list,10);
	add_at_last(&list,20);
	add_at_last(&list,30);
	add_at_last(&list,40);
	add_at_last(&list,50);
	
	display_list(&list);

	//delete_at_first(&list);
	delete_at_last(&list);

	display_list(&list);



	return 0;
}




void add_at_last(LIST *list,int ele)
{
	NODE *newnode = create_node(ele);

	if( list->head == NULL )
	{
		list->head = newnode;
		list->tail = newnode;
	}
	else
	{
		newnode->prev = list->tail;
		list->tail->next = newnode;
		list->tail = newnode;
	}


}

void delete_at_first(LIST *list)
{
	if( list->head->next == NULL )
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		NODE *temp = list->head;
		list->head = temp->next;
		list->head->prev = NULL;

		free(temp);
	}

}

void delete_at_last(LIST *list)
{
	if( list->head->next == NULL )
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		NODE *temp = list->tail;
		
		list->tail->prev->next = NULL;
		list->tail = list->tail->prev;
		free(temp);

	}

}

void delete_at_position(LIST *list,int pos)
{
	if( pos == 1 )
	{
		delete_at_first(list);
	}
	else
	if( pos == count_nodes(list))
	{
		delete_at_last(list);

	}
	else
	{
		NODE *trav = list->head;
		NODE *temp;
		int i = 1;

		while( i < pos-1 )
		{
			trav = trav->next;
			i++;
		}

		temp = trav->next;

		trav->next = temp->next;
		temp->next->prev = trav;
		free(temp);
	}
}

NODE *create_node(int ele)
{
	NODE *temp = (NODE *)malloc(sizeof(NODE));
	temp->data = ele;
	temp->next = NULL;
	temp->prev = NULL;

	return temp;

}


void display_list(LIST *list)
{
	NODE *trav = list->head;

	printf("\n\n\t FORWARD  :: ");
	while( trav != NULL )
	{
		printf("%4d",trav->data);
		trav=trav->next;
	}


	printf("\n\n\t BACKWARD :: ");
	trav = list->tail;

	while( trav != NULL )
	{
		printf("%4d",trav->data);
		trav = trav->prev;
	}



}

void init_list(LIST *list)
{
	list->head = NULL;
	list->tail = NULL;
}

