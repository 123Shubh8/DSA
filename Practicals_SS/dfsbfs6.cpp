/*
Experiment 13 : Represent a given grapg using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. 
                Use the map of the area around the college as a graph. Identify the prominent land marks as nodes and perform DFS and BFS on that.
Adjacency Matrix : using adj matrix -BFS(Que)
*/


#include<iostream>
using namespace std;

class queue{
  public:
    int f,r;
    int arr[10];
    queue()
    {
      f=r=-1;
    }   
    void enqueue(int data) 
    {
      if(f==-1)
        f++;
      r++;
      arr[r]=data;
    }
    int dequeue()
    {
      int x;
      x=arr[f];
      f++;
      return x;
    }
    int isEmpty()
    {
      if((f==-1)||f>r)
        return 0;
      else      
        return 1;
    }
    void bfs();
};
void queue::bfs()
{  
}
class stack
{
   int top;
   int A[10];
   public:
   stack()
   {
      top=-1;
    }
    
   int empty()
   {
      if (top ==-1)
         return 1;
      else 
         return 0;
    } 
    
    int full()
    {
       if (top>=A[10])
         return 1;
       else
         return 0;
     }
    void push(int e1)
    {
      
      A[++top]= e1;
      
     }
     int pop()
     {
       int s=A[top];
       top--;
       return s;
      
       }
    void dfs();
  };
              
class node
{
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
/*void BFS(int n,node *G[])
{
    int visited[10];
    queue q;
    int s,v;
    node *p;
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    cout<<"\nEnter the starting vertex : ";
    cin>>s;
    cout<<"\n\nBFS TRAVERSAL :\n";
    cout<<"\t"<<s;
    visited[s]=1;
    
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
}*/
void stack:: dfs(){
  int n, e;
   int e1,e2;
   int G[10][10];
   int visited[10];

   cout<<"Enter number of nodes"<<endl;
   cin>>n;
   for(int i=0;i<n;i++)
   {
   visited[i]=0;
   }
      
   cout<<"Enterthe number of edges"<<endl;
   cin>>e;
   
   for(int i=0;i<n;i++)
      {
         for(int j=0;j<n;j++)
         {
            G[i][j]=0;
         }
         
      }
  for(int i=0;i<e;i++)
      {
            cout<<"Enter edge (e1,e2)"<<endl;
            cin>>e1>>e2;
            G[e1][e2]=1;
            G[e2][e1]=1;
      }
    for(int a=0;a<n;a++)
  {
      for(int b=0;b<n;b++)
      {
         cout<<G[a][b];
       }
       cout<<endl;
   }
   stack st;
   //st.push(e1);
   //void DFS()
   //{
      cout<<"please enter starting vertex";
      cin>>e1;
         st.push(e1);
     
   
      while(!st.empty())
      {
         int v;
         v=st.pop();
         if(visited[v]==0)
         {
            visited[v]=1;
            cout<<v<<" ";
         }
         cout<<endl;
      
      
      for(int j=n-1;j>=0;j--)
         {
            if (G[v][j]==1 && visited[j]==0)
            {
               st.push(j);
               }
               }
     }
}
int main()
{
  
   int que[10],n,i,e,u,v,s,v1;
    int visited[10];
    node *G[10],*p;
    queue q;
    node n1;
    stack sd;
    cout<<"DFS Traversal!!!"<<endl;
    sd.dfs();
    cout<<"BFS Traversal!!!"<<endl;
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
        cout<<"\nEnter edge in pair : ";
        cin>>u>>v;
        n1.insert(u,v,G);
        n1.insert(v,u,G);
    }
    
  //  BFS(n,G);

   /* for(p=G[0];p!=NULL;p=p->next)
                cout<<p->data<<"->";*/
    
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    cout<<"\nEnter the starting vertex : ";
    cin>>s;
    cout<<"\n\nBFS TRAVERSAL :\n";
    cout<<"\t"<<s;
    visited[s]=1;
    
    q.enqueue(s);
    while(q.isEmpty() != 0)
    {
        v1=q.dequeue();
        
        for(p=G[v1];p!=NULL;p=p->next)
        {
            if(visited[p->data]==0)
            {
                q.enqueue(p->data); 
                visited[p->data]=1;
            cout<<"\t"<<p->data;
            }
        }
    } 
    return 0;
}


// Enter number of vertices : 5
// Enter number of edges : 6
// EDGES :
// 1 2
// 1 3
// 2 3
// 2 4
// 3 4
// 4 5
// The adjacency matrix of the graph is : 
// 0 1 1 0 0
// 1 0 1 1 0
// 1 1 0 1 0
// 0 1 1 0 1
// 0 0 0 1 0
// Enter initial vertex : 1
// The BFS of the Graph is
// 1
// 2 
// 3 
// 4 
// 5 
// Enter initial vertex : 1
// The DFS of the Graph is
// 1
// 3 
// 4 
// 5 
// 2 
