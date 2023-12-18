/*You have a business with several offices; you want to lease phone lines to connect them
up with each other; and the phone company charges different amounts of money to
connect different pairs of cities. You want a set of lines that connects all your offices with
a minimum total cost. Solve the problem by suggesting appropriate data structures.*/

#include<iostream>
using namespace std;

class tree
{
	int a[20][20],u,v,n,i,j,e,w,visited[20];
	public:
		void input();
		void display();
		void minimum();
};

void tree::input()
{
	cout<<"\nEnter the no. of nodes: ";
	cin>>n;

	for(i=0;i<n;i++)
	{
		visited[i]=0;
		for(j=0;j<n;j++)
		{
			a[i][j]=999;
		}
	}

	cout<<"\nEnter the no. of edges: ";
	cin>>e;

	for(i=0;i<e;i++)
	{
		cout<<"\n______________________________________";
		cout<<"\nEnter the edges in pair (u,v): ";
		cin>>u>>v;
		cout<<"\nEnter the phone company charges for this connection:  ";
		cin>>w;
		a[u][v]=a[v][u]=w;
	}
}

void tree::display()
{
	cout<<"\nAdjacency matrix:";
	for(i=0;i<n;i++)
	{
		cout<<endl;
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<"   ";
		}
		cout<<endl;
	}
}

void tree::minimum()
{
	int p=0,q=0,total=0,min;
	visited[0]=1;
	min=999;
	for(int count=0;count<(v-1);count++)
	{
		for(i=0;i<n;i++)
		{
			if(visited[i]==1)
			{
				for(j=0;j<n;j++)
				{
					if(visited[j]!=1)
					{
						if(min > a[i][j])
						{
							min=a[i][j];
							p=i;
							q=j;
						}
					}
				}
			}
		}
		visited[p]=1;
		visited[q]=1;
		total=total+min;
	}
	cout<<"\nMinimum cost connection is "<<(p)<<" -> "<<(q)<<"  with charge : "<<min<< endl;
	cout<<"\nThe minimum total cost of connections of all branches is: "<<total<<endl;
}

int main()
{
	int ch;
	tree t;
	t.input();
	t.display();
	t.minimum();
	return 0;
}
