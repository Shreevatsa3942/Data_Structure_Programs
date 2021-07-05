/*Program: Program to perform operations on Binary Search Tree */
//Name:Shreevatsa
//Reg No:200970093
//Modified Date:25-06-2021
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
	node(int value)
	{
		data=value;
		left=NULL;
		right=NULL;
	}
};
node* insert(node *head,int data)
{
	if(head==NULL)
	{
		cout<<data<<" inserted to bst\n";
		return (new node(data));
	}
	else if(data<(head->data))
	{
		(head->left)=insert((head->left),data);
	}
	else
	{
		(head->right)=insert((head->right),data);
	}
	return head;
}
void preorder(node *head)
{
		if(head==NULL)
		{
			return;
		}
		cout<<(head->data)<<"   ";
		preorder((head->left));
		preorder((head->right));
}
void inorder(node *head)
{
		if(head==NULL)
		{
			return;
		}
		inorder((head->left));
		cout<<(head->data)<<"   ";
		inorder((head->right));
}
void postorder(node *head)
{
		if(head==NULL)
		{
			return;
		}
		postorder((head->left));
		postorder((head->right));
		cout<<(head->data)<<"   ";
}
int search(node *head,int data)
{
	if(head==NULL)
	{
		return 0;
	}
	if(data==(head->data))
	{
		return 1;
	}
	else if(data<(head->data))
	{
		return search((head->left),data);
	}
	else
	{
		return search((head->right),data);
	}
}
int main()
{
	node *root=NULL;
	int ch;
	do
	{
		cout<<"binary search tree (bst) :\n";
		cout<<"1:insert\t2:search\t3:preorder\t4:inorder\t5:postorder\n0 : exit \tchoice :";
		cin>>ch;
		switch(ch)
		{
		case 0:cout<<"\t\tthank you\n";
		       break;
		case 1:{
			       int value;
			       cout<<"enter key value to be added to bst : ";
			       cin>>value;
			       root=insert(root,value);
		       }
		       break;
		case 2:{

			       int value,status;
			       cout<<"enter key value to be searched in bst : ";
			       cin>>value;
			       status=search(root,value);
			       if(status==1)
			       {
					cout<<value<<" found in bst\n";
			       }
			       else
			       {
				       cout<<"sorry "<<value<<" not found in bst\n";
			       }
		       }
		       break;
		case 3: if(root!=NULL)
			{
		       		cout<<"pre-order traversal : ";
				preorder(root);
				cout<<endl;
			}
			else
			{
				cout<<"no elements in bst\n";
			}
			break;
		case 4: if(root!=NULL)
			{
		       		cout<<"in-order traversal : ";
				inorder(root);
				cout<<endl;
			}
			else
			{
				cout<<"no elements in bst\n";
			}
			break;
		case 5: if(root!=NULL)
			{
		       		cout<<"post-order traversal : ";
				postorder(root);
				cout<<endl;
			}
			else
			{
				cout<<"no elements in bst\n";
			}
			break;
		default:cout<<"invalid choice\n";break;
		}
		cout<<"----------------------------------------------------\n";
	}while(ch!=0);
	return 0;
}