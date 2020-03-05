#include<stdio.h>
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
void print_matrix(int size,int a[size][size])	//print the matrix
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			printf(" %d ",a[i][j]);
		printf("\n");
	}	
}

void floyd(int size,int a[size][size])	//Applying warshall algo
{
	int i,j,k;
	int n=size;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[i][j] = min(a[i][j],(a[i][k] + a[k][j]));
				
	//printf("\n");
	//print_matrix(size,r);
	// making use of by reference changes in array *************************
		
}
void main()
{
	int size;
	printf("Enter the size of the initial matrix(how many elements) \t : ");
	scanf("%d",&size);
	int a[size][size];
	int i,j;
	//input adjacency matrix
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			scanf("%d",&a[i][j]);
	printf("\n\n");
	print_matrix(size,a);	//print initial adjacency matrix
	
	floyd(size,a);
	// making use of by reference changes in array ************************* making use of by reference changes in array
	printf("\n Final Solution\n");
	print_matrix(size,a);	//print final adjacency matrix
}
