#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int size;
void main()
{
	int i;
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
	mergesort(arr,0,size-1);
	end = clock();
	time = (double)(end-start)/CLOCKS_PER_SEC; 
	printf("Sorted arrat is\n:");
	for(i=0;i<size;i++)	
		printf("%d    ",arr[i]);
	printf("\ntime taken : %f",time); 

}
void mergesort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = (low+high)/2;
		mergesort(a,low,mid);	//sort 1st half
		mergesort(a,mid+1,high);//sort 2nd half
	    combine(a,low,mid,high);//combine both the half
	}
}
void combine(int a[],int low,int mid,int high)
{
	int i,j,k,c[size];
	//initializing variables
	//new array
	k = low; 
	//previous array
	i = low;
	j = mid +1;
	
	while(i <= mid && j <= high)
	{
		if(a[i] <= a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++];
	}
	while(i<= mid)
		c[k++] = a[i++];
	while(j<=high)
		c[k++] = a[j++];
	for(k=low;k<=high;k++)
		a[k] = c[k];
			
}
