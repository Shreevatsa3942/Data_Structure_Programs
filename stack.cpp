#include<iostream>
using namespace std;

template <class T>
class stack{
	
	T arr[100];
	int size,top=-1;
public:
	stack(int size=0){
		this->size=size;
	}
	int operations(){
		cout<<"\n1.Push an Element into the stack\n2.Pop an Element from the stack\n3.Display\n4.Exit\n";
		cout<<"\nEnter your choice: ";
		int ch;
		cin>>ch;
		return Conditional_operations(ch);	
	}
	int Conditional_operations(int x){
		switch(x){
			case 1:
				cout<<"\n----Push Operation-----\n";
				cout<<"Enter an element: \n";
				T ele;
				cin>>ele;
				this->push(ele);
				break;
			case 2:
				cout<<"\n----Pop Operation-----\n";
				this->pop();	
				break;
			case 3:
				this->display();
				break;
			case 4:
				cout<<"\n----Exit-----\n";
				return 0;
			default:
				cout<<"\nInvalid choice:\n";

		}
	}

	void push(T val){
		
		if(top>=size-1)
		{
			cout<<"\nStack Overflow:\n\n";
			
		}
		else{
			top++;
			arr[top]=val;
			cout<<" 1 Element Pushed successfully\n\n";
		}
		
	}
	void pop(){

		if(top == -1){
			cout<<"\nstack underflow:\n\n";
		}
			
		else{
			cout<<"\nElement "<<arr[top]<<" popped:\n\n";
			top--;
		}
	}
	void display(){
		cout<<"\n--------Stack Elements--------\n";
		if(top>=0){
			for(int i=top;i>=0;i--)
				cout<<arr[i]<<" ";
			cout<<"\n";
		}
		else
			cout<<"\n-----Stack is empty------";
	}
};
int main(){

	int size,ch;
	cout<<"\n----Integer Array----\n";
	cout<<"\nEnter the size of the integer array : ";
	cin>>size;
	

	stack <int>s1(size);
	do{	
		int flag=s1.operations();
		if(flag == 0)
			break;
	}while(1);

	cout<<"\n-----Charecter Array-----\n";
	cout<<"\nEnter the size of the integer array : ";
	cin>>size;

	stack <char>s2(size);
	do{	
		int flag=s2.operations();
		if(flag == 0)
			break;
	}while(1);

	return 0;
}

