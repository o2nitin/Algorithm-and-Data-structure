// 07. to implement quick sort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8
#define SWAP(a,b,type) {type t=a; a=b; b=t;}

void quick_sort(int a[], int left, int right);
void display_array(int *arr);


int main( void )
{
	int a[SIZE] = {50, 80, 20, 40, 70, 30, 10, 60};
	
	printf("\n\n\t Array before sort: ");
	display_array(a);

	quick_sort(a, 0, SIZE-1);

	printf("\n\n\t Array after sort: ");
	display_array(a);
	
	return 0;

}//end of main function

void quick_sort(int a[], int left, int right)
{
	int i = left, j = right;
	
		
	if(left >= right)
		return;
	
	while(i < j)
	{
		while(i<=right && a[i]<=a[left])
		{
			i++;
		
		}

		while(a[j]>a[left])
		{
			j--;
		}

		if(i < j)
		{
			SWAP(a[i], a[j], int);
		}
	}
	SWAP(a[left], a[j], int);


	quick_sort(a, left, j-1);
	quick_sort(a, j+1, right);

}//end of quick_sort function



void display_array(int *arr)
{
	int i;

	printf("\n\n\t The array is :: ");

	for( i = 0 ; i < SIZE ; i++ )
	{
		printf("%4d",arr[i]);

	}//end of for loop

}//end of display function











