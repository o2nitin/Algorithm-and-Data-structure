//09. Implement binary search algorithm using recursion. 

#include <stdio.h>

void print_array(int arr[], int n);
int bin_search_rec(int arr[], int key, int left, int right);

int main(void)
{
	int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
	int index, key;
	print_array(arr, 8);

	printf("\nenter the number to be searched : ");
	scanf("%d", &key);

	index = bin_search_rec(arr, key, 0, 8-1);
	if(index==-1)
		printf("element not found!\n");
	else
		printf("element found at index : %d\n", index);
	return 0;
}

int bin_search_rec(int arr[], int key, int left, int right)
{
	int mid, index;
	if(left > right)	// terminating condition
		return -1;
	mid = (left + right) / 2;
	if(arr[mid]==key)	// compare middle element
		return mid;		// return index if matching
	
	if(key < arr[mid])	// search in left partition
		index = bin_search_rec(arr, key, left, mid-1);
	else				// search in right partition
		index = bin_search_rec(arr, key, mid+1, right);
	return index;
}

void print_array(int arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%5d", arr[i]);
	printf("\n");
}

