#include <stdio.h>
// n vertices and m Edges
int adj[20][20], n,m, q[20],visited[20];
//edge representation
struct edge
{
	int s,d;
};
struct edge e[20];
// Function to create Adjacency Matrix

void createadjmatrix( struct edge e[])
{
    int i,j,x,y;
	// Initialise all value to this Adjacency matrix to zero
    for ( i = 0; i < n ; i++) {
  
        for (j = 0; j < n ; j++) {
            adj[i][j] = 0;
        }
    }
  
    // Traverse the array of Edges
    for (i = 0; i < m; i++) 
	{
        // Find X and Y of Edges as source and destination of the edges
         x = e[i].s;
        y = e[i].d;
       // Update value to 1
        adj[x][y] = 1;
        adj[y][x] = 1;//not required in case of directed graph
   }
    for (i = 0; i < n ; i++) 
   {
   		 for (j = 0; j < n ; j++) 
		    printf("%d ", adj[i][j]);
         printf("\n");
    }
        
    }
  void dft(int v)
{
       int i;
       for (i=0;i<n;i++)                                // check all the vertices in the graph
       {
               if(adj[v][i] != 0 && visited[i] == 0) // adjacent to v and not visited
              {
                       visited[i]=1;          // mark the vertex visited
                       printf("%d  ",i);
                       dft(i);
              }
      }
}
int flag=0;
void dfs(int v,int c)
{
    if(c==v)
    {
        flag=1;
        printf("\nElement is found");
        return;
    }
    
       int i;
       
       for (i=0;i<n;i++)                                // check all the vertices in the graph
       {
               if(adj[v][i] != 0 && visited[i] == 0) // adjacent to v and not visited
              {
                       visited[i]=1; 
                       if(i==c)
                       {
                            flag=1;
                            printf("\nElement is found");
                            return;
                       }         
                       dfs(i,c);
              }
      
    }
}
 
int main()
{
  int i, j,v;
  char ch='y';
  m=0;i=0;
  printf("Enter no of vertices: ");
  scanf("%d", &n);
  
 while(ch=='y')
 {
   	printf("Enter source of edge: ");
   	scanf("%d", &e[i].s);
   	printf("Enter destination of edge: ");
   	scanf("%d", &e[i].d);
    printf("do you want to add edges: ");
    fflush(stdin);
    scanf("%c", &ch);
    m=m+1;
    i++;
  }
  // Function call to create Adjacency Matrix
    createadjmatrix(e);
    for (i=0;i<n;i++)                   // mark all the vertices as not visited
    {
        visited[i]=0;
    }
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
   printf("\n DFS traversal is:\n");
    visited[v]=1; // mark the starting vertex as visited
    printf("%d   ",v);
    dft(v);
    for(i=0;i<n;i++)
        visited[i]=0;
    int c;
    printf("\nEnter the element you want to search ");
    scanf("%d",&c);
    dfs(v,c);
    if(flag==0)
        printf("\nElement not found ");

   }