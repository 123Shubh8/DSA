/*
PROBLEM STATEMENT:  Represent a given graph using adjacency matrix/ list to perform DFS and using list to perform BFS. 
Use the map of the area around the college as the graph. Identify the prominent land marks as nodes and perform DFS and BFS 
*/
#include<iostream>
using namespace std;
class stack
{
	public:
		int arr[10];
		int top;
		stack()
		{
			top=-1;
		}
		void push(int data)
		{
			arr[++top]=data;
		}
		int pop(){
			int n=arr[top];
			top--;
			return n;
		}
		int isEmpty(){
			if(top==-1){
				return 1;
			}
			return 0;
		}
};


int main()
{
	int visited[10];
	int u,v,n,ch,g[10][10];
	stack s;
	cout<<"\nEnter number of nodes : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			g[i][j]=0;
		}
	}
	do
	{
		cout<<"\nEnter edges in pair(u,v) : ";
		cin>>u>>v;
		g[u][v]=1;
		g[v][u]=1;
		cout<<"\nDo you want to enter new edge (Press 1) : ";
		cin>>ch;
	}while(ch==1);
	
	cout<<"\nMatrix is :\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<" "<<g[i][j];
		}
		cout<<"\n";
	}
	
	cout<<"\nEnter the starting vertex : ";
	cin>>u;
	cout<<"\n---------------DFS Traversal----------------\n";
	s.push(u);
	while(!s.isEmpty())
	{
		v=s.pop();
		if(visited[v]==0)
		{
			visited[v]=1;
			cout<<"\t"<<v;
		}
		for(int j=n-1;j>0;j--)
		{
			if(g[v][j]==1 && visited[j]==0)
			{
				s.push(j);
			}
		}
	}
	cout<<"\n\n";
	return 0;
}
