//sorting array elements using bubble sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define size 150000


int bsort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	
}

void main()
{
	int a[size];
	int n,i,j,temp;
	time_t start,end;
	bool arr[size]={0};
	int count=0;

	printf("Enter number of array elements\n");
	scanf("%d",&n);

	printf("Enter array elements one by one\n");

	srand(time(0));	

	for(i=0;i<n;i++)
	{	a[i]=rand()%140000+1;
		if(!arr[a[i]])
			{arr[a[i]]=1;
				count++;}
		else
			i--;
		
	}
	/*for(i=0;i<n;i++)
		scanf("%d",&a[i]);*/
	printf("Array elements before sorting\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	
	start=clock();
	bsort(a,n);
	end=clock();

	printf("Array elements after sorting\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);

	double timet;
	timet=(double)(end-start)/CLOCKS_PER_SEC;

	printf("\nTime:%lf\n",timet);
	printf("\nNUmber:%d\n",count);
}
