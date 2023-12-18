/*
PROBLEM STATEMENT:  For given expression eg. a-b*c-d/e+f construct inorder sequence and traverse it using postorder
traversal (non-recursive) and delete the entire tree.
*/
#include<iostream>
#include<string.h>
using namespace std;

class node
{
	public:
		char data;
		node *left, *right;
		node(){
			left=right=NULL;
		}
};
class expressionTree{
	public: 
		node *root;
		expressionTree()
		{
			root=NULL;
		}
		void create(string str);
		void nonrec_postOrder(node *temp);
		int priority(char ch);
};
class stack
{
	public:
		int top;
		node *arr[10];
		stack(){
			top=-1;
		}
		void push(node *data)
		{
			arr[++top]=data;
		}
		node* pop()
		{
			return(arr[top--]);
		}
		node* Top()
		{
			return(arr[top]);
		}
		int isEmpty()
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}
};
int expressionTree::priority(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 0;
		case '*':
		case '/':
			return 1;
		case '^':
			return 2;
	}
}
void expressionTree::create(string str)
{
	stack operand_stk,operator_stk;
	int i=0;
	char ch;
	while(str[i]!='\0')
	{
		ch=str[i];
		node *temp=new node();
		temp->data=ch;
		if(isalpha(ch))
		{
			operand_stk.push(temp);
		}
		else
		{
			if(operator_stk.isEmpty())
				operator_stk.push(temp);
			else
				if(priority(ch)>priority(operator_stk.Top()->data))
					operator_stk.push(temp);
				else
				{
					while(!operator_stk.isEmpty() && priority(ch)<=operator_stk.Top()->data)
					{
						node *oper=operator_stk.pop();
						oper->right=operand_stk.pop();
						oper->left=operand_stk.pop();
						operand_stk.push(oper);
					}
					operator_stk.push(temp);
				}
		}
		i++;
	}
	while(!operator_stk.isEmpty())
	{
		node *oper=operator_stk.pop();
		oper->right=operand_stk.pop();
		oper->left=operand_stk.pop();
		
		operand_stk.push(oper);
	}
	root=operand_stk.pop();
}
void expressionTree::nonrec_postOrder(node *temp)
{
	if(root==NULL)
		cout<<"\nEmpty..";
	else
	{
		stack s1,s2;
		s1.push(temp);
		while(!s1.isEmpty())
		{
			node *temp=s1.pop();
			s2.push(temp);
			if(temp->left)
				s1.push(temp->left);
			if(temp->right)
				s1.push(temp->right);
		}
		while(!s2.isEmpty())
		{
			node *temp=s2.pop();
			cout<<" "<<temp->data;
		}
	}
}
int main()
{
	expressionTree e;
	char str[10];
	int ch;
	do
	{
		cout<<"\n_______________________________________________";
		cout<<"\n\t[1] Create Expression Tree\n\t[2] Non recursive Postorder Traversal \n\t[3] Exit";
		cout<<"\n_______________________________________________";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter expression : ";
				cin>>str;
				e.create(str);
			break;
			
			case 2:
				cout<<"\nNon Recursive PostOrder Traversal is : \n";
				e.nonrec_postOrder(e.root);
			break;
			
			case 3:
			break;
			
			default:
				cout<<"\nWrong choice...";
			break;
		}
	}while(ch!=3);
	return 0;
}
