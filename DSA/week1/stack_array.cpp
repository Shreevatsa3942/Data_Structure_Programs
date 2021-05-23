//Author name: Shreevatsa
//Registration number: 200970093
//Date of creation:07-05-2021
//Program:Stack using Array
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
    void push(T val){
		
		if(top>=size-1)
		{
			cout<<"\nStack Overflow:\n\n";
			
		}
		else{
			top++;
			arr[top]=val;
			cout<<val<<" Pushed into the stack\n\n";
		}
		
	}
	void pop(){

		if(top == -1){
			cout<<"\nstack underflow:\n\n";
		}
			
		else{
			cout<<"\nElement "<<arr[top]<<" popped from the stack:\n\n";
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

	int size;
	
	size=6;

	stack <int>s1(size);
    //pushing elements into the stack
	s1.push(2);
    s1.push(4);
    s1.push(6);
    s1.push(8);
    s1.push(56);
    s1.push(9);
    
    //popping elements from the stack

    s1.pop();
    s1.pop();

    s1.display();
	cout<<"\n-----Charecter Array-----\n";
    size=6;
	stack <char>s2(size);

    //pushing elements into the stack
	s2.push('a');
    s2.push('g');
    s2.push('h');
    s2.push('j');
    s2.push('k');
    s2.push('b');
    s2.push('m');
    
    
    //popping elements from the stack

    s2.pop();
    s2.pop();
    s2.display();
	return 0;
}

