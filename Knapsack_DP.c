#include<stdio.h>
int max(int a,int b)
{
 if(a>b)
  return a;
 else
  return b;
}
// Dynamic programming problem using bottom up approach
// m : capacity of knapsack (no of col)
// n : no of items (no of rows)
// w : weights of items
// p : profits of items

void knapsack(int m,int n,int w[],int p[])
{
    int v[100][200],x[10],i,j,sum=0;

    // make 0th row of the table as 0
    for(i = 0;i<=m;i++)
        v[0][i]=0;
    
    // for other rows starting from 1
    for(i = 1;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(j>=w[i])
                v[i][j] = max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
            else
                v[i][j] = v[i-1][j];
        }
    }

    //make x zero for all items
    for(i=1;i<=n;i++)
        x[i] = 0;

    //backtrack to get the items involved
    i=n;
    j=m;

    while(i>0 && j>0)
    {
        if(v[i][j]!=v[i-1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        i--;
    }

    //printing result
    printf("\n The Optimal set of items is :- \n");
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
        {
            printf(" %d\t",i);
            sum += p[i];
        }
    }
    printf("\n Total Profit = %d\n",sum);
}

void main()
{
    int w[10],p[10],m,n,i;
    printf("\nEnter no. of items\t:");
    scanf("%d",&n);
    printf("\nEnter the weights of the items\t:");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    
    printf("\nEnter profits for each item\t:");
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    printf("\nEnter the capacity of knapsack\t:");
    scanf("%d",&m);

    knapsack(m,n,w,p);
}