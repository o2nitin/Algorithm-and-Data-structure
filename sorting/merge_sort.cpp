//08. to implement merge sort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8
#define SWAP(a,b,type) {type t=a; a=b; b=t;}

void merge_sort(int a[], int left, int right);
void display_array(int *arr);



int main( void )
{
	int a[SIZE] = {80, 40, 20, 50, 70, 30, 10, 60};

	printf("\n\n\t Array before sort:	");
	display_array(a);

	merge_sort(a, 0, SIZE-1);

	printf("\n\n\t Array after sort:	");
	display_array(a);
	
	return 0;

}//end of main function


void merge_sort(int a[], int left, int right)
{
	int cnt=right-left+1, mid=(left+right)/2; 
	int i=left, j=mid+1, k=0;
	int *tmp;

	if(left>=right)
		return;
	merge_sort(a, left, mid);
	merge_sort(a, mid+1, right);
	tmp = (int*)malloc(cnt*sizeof(int));
	
	while(i<=mid && j<=right)
	{
		tmp[k++] = a[i] < a[j] ? a[i++] : a[j++];
	}

	while(i<=mid)
	{
		tmp[k++] = a[i++];
	}

	while(j<=right)
	{
		tmp[k++] = a[j++];
	}

	memcpy(a+left, tmp, cnt*sizeof(int));
	free(tmp);

}//end of merge_sort function


void display_array(int *arr)
{
	int i;

	printf("\n\n\t The array is :: ");

	for( i = 0 ; i < SIZE ; i++ )
	{
		printf("%4d",arr[i]);

	}//end of for loop

}//end of display function











