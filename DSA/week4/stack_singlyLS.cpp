/*Program to perform stack operation using singly linked list*/
//Name:Shreevatsa
//Regno: 200970093
//Modified Date:04-06-2021
#include<iostream>
#include<string>
using namespace std;

class Node{
public:
	string data;
	Node *next;

	//constructor to initialze the values
	Node(string data){
		this->data = data;
		next=NULL;
	}
};
class stack{
	Node *head;
	int size;
public:
	stack(){
		head=NULL;
		size=0;
	}
	bool isEmpty(){
		return size == 0;
	}
	void push(string ele){
		Node *n = new Node(ele);
		n->next = head;
		head = n;
		size++;
		cout<<"\n--Size of the stack : "<<size<<" ----";
		cout<<"\n value "<<ele<<" pushed to the stack";
	}
	string pop(){
		string value = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
		return value;
	}
	string top(){
		if(!isEmpty())
			return head->data;
		else
			return NULL;
	}
	void display(){
		Node* t=head;
		cout<<"\n";
		if(!isEmpty())
		{
			while(t->next != NULL){
				cout<<" "<<t->data;
				t=t->next;
			}
			cout<<" "<<t->data;
		}
		else
			cout<<"Stack is Empty!!";
		
	}
};
int main(){

	stack s;
	string value;
	do{
		cout<<"\n----Stack operations-----\n";
		cout<<"\n1.Insert an element\n2.Delete an element\n3.Display elements\n4.Exit\nEnter your Choice: ";
		int ch;
		cin>>ch;
		switch(ch){
			case 1:
				
				cout<<"\nEnter a value :";
				cin>>value;
				s.push(value);
				break;
			case 2:
				if(!s.isEmpty())
					cout<<"\n "<<s.pop()<<" Popped"<<endl;
				else
					cout<<"\nstack is empty!";
				break;
			case 3:
				cout<<"\n----Elements-----\n";
				s.display();
				break;
			case 4:
				exit(0);
				break;
			default:cout<<"\nInvalid Choice";
		}
		
	}while(1);
	
	cout<<"\n";
	return 0;
}
