#include <stdio.h>
#include "isort.h"
#include <string.h>

void shift_element(int *arr, int i)
{
	int t = *(arr + i);
	for (int v = i; v > 0; v--)
	{
		*(arr + v) = *(arr + v - 1);
	}
	*(arr) = t;
}

void insertion_sort(int *arr, int arrLen)
{
	for (int i = 0; i < arrLen; i++)
	{
		if (*(arr + i) > *(arr + i + 1))
		{
			shift_element(arr, i + 1);
		}
		for (int j = 0; j < i; j++)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				int temp = *(arr + i);
				*(arr + i) = *(arr + i + 1);
				*(arr + i + 1) = temp;
			}
		}
	}
}

int main(int argc, char const *argv[]){
	
	int arr[SIZE] = {0};
	printf("Choose %d numbers to sort:\n", SIZE);
	for (int i = 0; i < SIZE; i++){
		scanf("%d", arr + i);
	}
	insertion_sort(arr, SIZE);
	for (int i = 0; i < SIZE; i++){
		printf("%d,", *(arr + i));
	}

	return 0;
}
