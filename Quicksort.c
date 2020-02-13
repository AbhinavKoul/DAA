#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int position(int a[],int low,int high)	//returns pivot position
{
	int temp;
	int pivot= a[low];
	int i = low;
	int j = high+1;
	// partition arrays in 2 parts
	while(i<=j)
	{
		do{
			i++;
		}while(a[i] <= pivot);
		
		do{
			j--;
		}while(a[j] > pivot);
		//partition not completed, swap a[i] ans a[j]
		if(i < j)
		{	
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}		
	}	
	// partition completed, swap a[j] and pivot
	temp = a[low];
	a[low] = a[j];
	a[j] = temp;
	//return pivot position
	return j;
}
void quicksort(int a[],int low,int high)
{
	int mid;
	if(low < high)
	{
		mid = position(a,low,high);
		quicksort(a,low,mid-1);		//left side partiton sort
		quicksort(a,mid+1,high);	//right hand partition sort
	}
}
void main()
{	int size;
	printf("\nEnter size of array\t:");
	scanf("%d",&size);
	int a[size],i;
	//take inputs
	for(i=0;i<size;i++)
		a[i] = rand()%100;
	//inititaLIze clock varuiables
	clock_t start,end;	//to store initial and final state of the clock
	double time;	// to store total time
	//start clock timer(initial state of clock)
	start = clock();
	//sorting
	quicksort(a,0,size-1);
	//end clock timer(final state of clock)	
	end = clock();
	// calculating time
	time =(double)(end-start)/CLOCKS_PER_SEC;
	printf("\nSorted array is :\n");
	for(i=0;i<size;i++)
		printf("%d   ",a[i]);
	printf("\nTime taken :%f \n",time);
}
