/*
PROBLEM STATEMENT: A book consists of chapters, chapters consist of sections and sections consist of subsections. 
Construct a tree and print the nodes. Find the time and space requirements of your method. 
*/
#include<iostream>
using namespace std;

class node{
	public:
		string name;
		int ch_cnt;
		node *child[10];
		
};

class BookTree{
	public:
		node* createTree();
		void displayTree(node*);		
		node *root;
		BookTree()
		{
			root=NULL;
		}
};
node* BookTree::createTree()
{
	int chapters;
	root=new node();
	cout<<"\nEnter the name of Book : ";
	cin>>root->name;
	cout<<"\nEnter number of chapters in book : ";
	cin>>chapters;
	root->ch_cnt=chapters;
	for(int i=0;i<chapters;i++)
	{
		root->child[i]=new node;
		cout<<"\nEnter the name of chapter "<<i+1<<" : ";
		cin>>root->child[i]->name;
		
		cout<<"\nEnter the sections in chapter "<<root->child[i]->name<<" : ";
		cin>>root->child[i]->ch_cnt;
		for(int j=0;j<root->child[i]->ch_cnt;j++)
		{
			root->child[i]->child[j]=new node;
			cout<<"\nEnter the name of Section "<<j+1<<" from chapter "<<root->child[i]->name<<" : ";
			cin>>root->child[i]->child[j]->name;
		}
	}
	return root;
}
void BookTree::displayTree(node *root)
{
	int tch;
	tch=root->ch_cnt;
	if(root!=NULL)
	{
		cout<<"\n\n-----------------------BOOK HIERARCHY-----------------------\n\n";
		cout<<"\n Book Title : "<<root->name;
		for(int i=0;i<tch;i++)
		{
			cout<<"\n\n\t Chapter "<<(i+1)<<" name : ";
			cout<<root->child[i]->name;
			for(int j=0;j<root->child[i]->ch_cnt;j++)
			{
				cout<<"\n\t\t"<<root->child[i]->child[j]->name;
			}
		}
	}
	cout<<"\n\n";
}
int main()
{
	int ch;
	BookTree bt;
	node *root;
	do
	{
		cout<<"\n______________________________________________\n";
		cout<<"\n\t [1] Create Book Hierarchy\n\t [2] Display Book Hierarchy";
		cout<<"\n______________________________________________\n";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		if(ch==1)
		{
			root=bt.createTree();
		}
		if(ch==2){
			bt.displayTree(root);
		}
		cout<<"\nPress 1 to continue : ";
		cin>>ch;
	}while(ch==1);
	return 0;
}
