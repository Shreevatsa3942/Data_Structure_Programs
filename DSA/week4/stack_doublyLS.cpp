#include<iostream>
using namespace std;
class Node{
public:
	string data;
	Node *prev;
	Node *next;
	//constructor to initialze the values
	Node(string data){
		this->data = data;
		prev= NULL;
		next = NULL;
	}
};
class stack{
	Node *head;
	Node *temp;
	int size;
public:
	stack(){
		head = NULL;
		temp = NULL;
		size = 0;
	}
	void push(string ele){
		Node *newNode = new Node(ele);
		size++;
		if(size == 1){
			head = newNode;
			temp = newNode;
			newNode->next = NULL;
			newNode->prev = NULL;
		}
		else{
			newNode->prev = temp;
			temp->next = newNode;
			newNode->next = NULL;
			temp = newNode;
		}
		cout<<"\n"<<temp->data<<" Pushed Successfully";

	}
	string pop(){
		string value = temp->data;
		Node* t = temp;
		delete temp;
		temp = t->prev;
		temp->next = NULL;
		return value;
	}
	bool isEmpty(){
		return (size == 0);
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
	string topElement(){

		return (isEmpty()?"EMPTY!!":temp->data);
	}
};
int main(){
    // stack s;
	// s.push("3");
	// s.push("5");
	// s.push("7");
	// s.push("98");
	// s.display();

	// cout<<"\nElement "<<s.pop()<<" Popped";
	// s.display();
	// cout<<"\nElement "<<s.pop()<<" Popped";
	// s.display();
	// cout<<endl;
	stack s;
	string value;
	do{
		cout<<"\n----Stack operations-----\n";
		cout<<"\n1.Insert an element\n2.Delete an element\n3.Display elements\n4.Display Top Element\n5.Exit\nEnter your Choice: ";
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
				//top element 
				cout<<"\n Top Element "<<s.topElement()<<endl;
				break;
			case 5:
				exit(0);
				break;
			default:cout<<"\nInvalid Choice";
		}
		
	}while(1);
	
	cout<<"\n";
	
	return 0;
}