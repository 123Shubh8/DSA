/*
PROBLEM STATEMENT:  Dictionary stores keywords & its meanings. Provide facility for adding new keywords, deleting keywords,
 updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how
 many maximum comparisons may require for finding any keyword. Use Binary Search Tree for implementation.
*/
#include<iostream>
#include<cstring.h>
using namespace std;
class node
{
	public:
		string key,mean;
		node *left,*right;
		node()
		{
			left=NULL;
			right=NULL;
		}
};
class dict{
	public:
		node *root;
		dict()
		{
			root=NULL;
		}
		node* create();
		void display(node*);
		int search(node*,string);
		void insert(node *,node*);
		int update(node*,string);
};
node* dict::create()
{
	node *temp;
	int ch;
	do
	{
		temp=new node;
		cout<<"\nEnter keyword : ";
		cin>>temp->key;
		cout<<"\nEnter meaning : ";
		cin>>temp->mean;
		if(root==NULL)
		{
			root=temp;
		}
		else
			insert(root,temp);
			
		cout<<"\n________________________________";
		cout<<"\nEnter 1 to add more records : ";
		cin>>ch;
	}while(ch==1);
	return root;
}
void dict::insert(node* root,node* temp)
{
	if(strcmp(temp->key,root->key)<0)
	{
		if(root->left==NULL)
		{
			root->left=temp;
		}
		else
		{
			insert(root->left,temp);
		}
	}
	else
	{
		if(root->right==NULL)
			root->right=temp;
		else
			insert(root->right,temp);
	}
	return;
}
void dict::display(node *root)
{
	if(root!=NULL)
	{
		display(root->left);
		cout<<"\n\t"<<root->key<<"\t\t "<<root->mean;
		display(root->right);
	}
	return;
}
int dict::search(node *root,string k)
{
	int c=0;
	while(root!=NULL)
	{
		c++;
		if(strcmp(k,root->key)==0)
		{
			cout<<"\n Meaning for keyword "<<root->key<<" is : "<<root->mean;
			return 1;
		}
		if(strcmp(k,root->key)<0)
		{
			root=root->left;
		}
		if(strcmp(k,root->key)>0)
		{
			root=root->right;
		}
	}
	return -1;
}
int dict::update(node *root,string k)
{
	while(root!=NULL)
	{
		if(strcmp(k,root->key)==0)
		{
			cout<<"\nEnter new meaning for keyword "<<root->key<<" : ";
			cin>>root->mean;
			return 1;
		}
		if(strcmp(k,root->key)<0)
			root=root->left;
		
		if(strcmp(k,root->right)>0)
			root=root->right;
	}
	return -1;
}

int main()
{
	int ch;
	dict d;
	string key;
	node *root;
	do
	{
		cout<<"\n_______________________________________________";
		cout<<"\n\t[1] Create BST\n\t[2] Display \n\t[3] Search\n\t[4] Update \n\t[5] Exit";
		cout<<"\n_______________________________________________";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				root=d.create();
			break;
			
			case 2:
				cout<<"\n\tKeyword \t Meaning";
				cout<<"\n_______________________________";
				d.display(root);
			break;
			
			case 3:
				cout<<"\nEnter keyword to search : ";
				cin>>key;
				d.search(root,key);
			break;
			
			case 4:
				cout<<"\nEnter keyword to search : ";
				cin>>key;
				d.update(root,key);
			break;
			
			case 5:
			break;
			
			default:
				cout<<"\nWrong choice...";
			break;
		}
	}while(ch!=5);
}
