/*
PROBLEM STATEMENT:  Represent a given graph using adjacency matrix/ list to perform DFS and using list to perform BFS. 
Use the map of the area around the college as the graph. Identify the prominent land marks as nodes and perform DFS and BFS
*/
#include<iostream>
using namespace std;

class queue{
	public:
		int arr[10];
		int f,r;
		queue()
		{
			f=r=-1;
		}
		void enqueue(int n){
			if(f==-1)
				f++;
			r++;
			arr[r]=n;
		}
		int dequeue()
		{
			int n=arr[f];
			f++;
			return n;
		}
		int isEmpty()
		{
			if(f==-1)
				return 1;
			return 0;
		}
};

class node{
	public:
		int data;
		node *next;
		
		void insert(int u,int v,node *G[])
		{
			node *p=new node();
			p->data=v;
			p->next=NULL;
			if(G[u]==NULL)
			{
				G[u]=p;
			}
			else
			{
				node *q;
				for(q=G[u];q->next!=NULL;q=q->next);
				q->next=p;
			}
		}
};

void BFS(int n,node *G[])
{
	queue q;
	int visited[10],s,v;
	node *p;
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	cout<<"\nEnter the starting vertex : ";
	cin>>s;
	cout<<"\n\n-------------BFS Traversal--------------------\n";
	visited[s]=1;
	cout<<"\t"<<s;
	q.enqueue(s);
	while(!q.isEmpty())
	{
		v=q.dequeue();
		for(p=G[v];p!=NULL;p=p->next)
		{
			if(visited[p->data]==0)
			{
				q.enqueue(p->data);
				visited[p->data]=1;
				cout<<"\t"<<p->data;
			}
		}
	}
}

int main()
{
	int n,u,v,e;
	node *G[10];
	node n1;
	cout<<"\nEnter number of nodes : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		G[i]=NULL;
	}
	cout<<"\nEnter number of edges : ";
	cin>>e;
	for(int i=0;i<e;i++)
	{
		cout<<"\nEnter edge in pair (u,v) : ";
		cin>>u>>v;
		n1.insert(u,v,G);
		n1.insert(v,u,G);
	}
	BFS(n,G);
	cout<<"\n\n";
	return 0;
}
