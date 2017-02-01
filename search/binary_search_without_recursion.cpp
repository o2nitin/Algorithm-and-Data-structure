//10. Program to implement Binary Search without using recursion

#include<stdio.h>

#define SIZE 8

int binary_search(int *arr, int key);

int main( void )
{
	int arr[SIZE] = { 1,2,3,4,5,6,7,8};
	int key;

	printf("\n\n\t Enter the key to search:	");
	scanf("%d",&key);

	if( binary_search(arr,key) )
	{
		printf("\n\n\t %d is found in the array",key);
	}
	else
	{
		printf("\n\n\t %d is not found in the array",key);
	}


	return 0;

}//end of main function

int binary_search(int *arr, int key)
{
	int left = 0;
	int right = SIZE-1;
	int mid;


	while( left <= right )
	{	
		mid = (left + right) / 2;

		if( key == arr[mid])
			return 1;

		if( key < arr[mid] )
			right = mid-1;
		else
			left = mid+1;

	}//end of while

	return 0;

}//end of binary_search function