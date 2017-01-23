
//06. Implement insertion Sort function

#include <stdio.h>

void print_array(int arr[], int n);
void insertion_sort(int arr[], int n);

int main(void)
{
	int arr[8] = {23 ,67, 12, 89, 43, 21, 75, 93};
	printf("Before Sorting : ");
	print_array(arr, 8);

	insertion_sort(arr, 8);

	printf("After Sorting  : ");
	print_array(arr, 8);
	return 0;
}

// print array
void print_array(int arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%5d", arr[i]);
	printf("\n");
}

// insertion sort function
void insertion_sort(int arr[], int n)
{
	int i, j;
	int temp;
	for(i=1; i<n; i++)
	{
		temp = arr[i];
		for(j=i-1; j>=0 && arr[j] > temp; j--)
			arr[j+1] = arr[j];
		arr[j+1] = temp;
	}
}
