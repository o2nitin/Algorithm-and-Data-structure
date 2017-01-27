// Write a code for bfs() and dfs() for binary search tree
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node_t;

node_t *root = NULL;

node_t* create_node(int val);
void add_node(int val);
node_t* dfs(int val);
node_t* bfs(int val);

#define MAX 128

typedef struct stack
{
	node_t* arr[MAX];
	int top;
}stack_t;

void s_init(stack_t *s);
void s_push(stack_t *s, node_t* val);
node_t* s_pop(stack_t *s);
node_t* s_peek(stack_t *s);
int s_empty(stack_t *s);

typedef struct queue
{
	node_t* arr[MAX];
	int front, rear;
}queue_t;

void q_init(queue_t *s);
void q_push(queue_t *s, node_t* val);
node_t* q_pop(queue_t *s);
node_t* q_peek(queue_t *s);
int q_empty(queue_t *s);


int main(void)
{
	int key;
	node_t *trav;

	add_node(50);
	add_node(25);
	add_node(75);
	add_node(15);
	add_node(40);
	add_node(60);
	add_node(90);
	add_node(10);
	add_node(35);
	add_node(45);
	add_node(55);
	add_node(70);
	add_node(85);
	add_node(95);

	printf("\nenter the number to be searched : ");
	scanf("%d", &key);

	trav = dfs(key);
	if(trav==NULL)
		printf("DFS : element not found!\n");
	else
		printf("DFS : element found : %d\n", trav->data);

	trav = bfs(key);
	if(trav==NULL)
		printf("BFS : element not found!\n");
	else
		printf("BFS : element found : %d\n", trav->data);
	return 0;
}


node_t* create_node(int val)
{
	node_t *newnode = (node_t*) malloc(sizeof(node_t));
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
void add_node(int val)
{
	node_t *newnode, *trav;
	newnode = create_node(val);
	if(root==NULL)
		root = newnode;
	else
	{
		trav = root;
		while(1)
		{
			if(val < trav->data)
			{
				if(trav->left==NULL)
				{
					trav->left = newnode;
					break;
				}
				trav = trav->left;
			}
			else
			{
				if(trav->right==NULL)
				{
					trav->right = newnode;
					break;
				}
				trav = trav->right;			
			}
		}
	}
}

node_t* dfs(int val)
{
	node_t *cur;
	stack_t s;
	printf("DFS : searching in order :\n");
	s_init(&s);
	s_push(&s, root);
	while(!s_empty(&s))
	{
		cur = s_pop(&s);
		printf("%d\n", cur->data);
		if(val == cur->data)
			return cur;
		if(cur->right!=NULL)
			s_push(&s, cur->right);
		if(cur->left!=NULL)
			s_push(&s, cur->left);
	}
	return NULL;
}

node_t* bfs(int val)
{
	node_t *cur;
	queue_t q;
	printf("BFS : searching in order :\n");
	q_init(&q);
	q_push(&q, root);
	while(!q_empty(&q))
	{
		cur = q_pop(&q);
		printf("%d\n", cur->data);
		if(val == cur->data)
			return cur;
		if(cur->left!=NULL)
			q_push(&q, cur->left);
		if(cur->right!=NULL)
			q_push(&q, cur->right);
	}
	return NULL;
}


void s_init(stack_t *s)
{
	s->top = -1; 
}
void s_push(stack_t *s, node_t* val)
{
	s->arr[++s->top] = val;
}
node_t* s_pop(stack_t *s)
{
	return s->arr[s->top--]; 
}
node_t* s_peek(stack_t *s)
{
	return s->arr[s->top];
}
int s_empty(stack_t *s)
{
	return s->top == -1;
}


void q_init(queue_t *s)
{
	s->front = -1; 
	s->rear = -1; 
}
void q_push(queue_t *s, node_t* val)
{
	s->arr[++s->front] = val;
}
node_t* q_pop(queue_t *s)
{
	return s->arr[++s->rear]; 
}
node_t* q_peek(queue_t *s)
{
	return s->arr[s->rear+1];
}
int q_empty(queue_t *q)
{
	return q->front == q->rear;
}
