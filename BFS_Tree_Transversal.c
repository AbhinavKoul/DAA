#include<stdio.h>
#include<string.h>
void BFS(int source,int a[20][20],int visited[20],int size)
{
    // initialize queue
    int queue[20],front,rear,u,v;
    //update variables
    front = 0;
    rear = -1;

    queue[++rear] = source;
    //start loop until the queue is empty
    while(front<=rear)
    {
        //pop out from queue
        u = queue[front++];
        // find all neigbors of that node which are not visited and mark them visited
        for(v=1;v<=size;v++)
        {
            if((a[u][v]==1)&&(visited[v]==0))
            {
                queue[++rear] = v;
                visited[v] = 1;
            }
        }
    }

}
void main()
{
    int n,a[20][20],i,j,visited[20],source;
    //take nesssasary inputs
    printf("\n Enter no. of vertices \t :");
    scanf("%d",&n);
    printf("\n Enter Adjacency Matrix \t : \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    //mark all as unvisiteed
    for(i=1;i<=n;i++)
        visited[i] = 0;
    
    //ask for statring node and askmark it as visited
    printf("\n Enter source node\t:");
    scanf("%d",&source);

    visited[source] = 1;

    //Call BFS
    BFS(source,a,visited,n);
    // using by reference call by default of the array fn call

    for(i =1;i<=n;i++)
    {
        if(visited[i]!=0)
            printf("\nNode %d is reachable",i);
        else
            printf("\n Node %d is not reachable",i);
        
    }

}