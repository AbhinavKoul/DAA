//sorting array elements using bubble sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble_sort(int a[],int size)
{
	int i,j,temp;
	for(i=0;i<size-1;i++)
		for(j=0;j<size-1-i;j++)
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
}

void main()
{
	int i,size;
	printf("Enter the Size of array\t:");
	scanf("%d",&size);
	int arr[size];
	//input elements
	for(i=0;i<size;i++)
		arr[i] = rand()%100;
	//initializing clock variables
	clock_t start,end;
	double time;
	start = clock();
	bubble_sort(arr,size);
	end = clock();
	time = (double)(end-start)/CLOCKS_PER_SEC; 
	printf("Sorted arrat is\n:");
	for(i=0;i<size;i++)	
		printf("%d    ",arr[i]);
	printf("\ntime taken : %f",time); 

}