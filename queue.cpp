//Author name: Shreevatsa
//Registration number: 200970093
//Date of creation:07-05-2021
//Program:Queue using Array
#include<iostream>
using namespace std;

template <class T>
class queue{
	
	T arr[100];
	int size,front,rear;
public:

	queue(int size=0){
        front=rear=0;
		this->size=size;
	}
    int operations(){
		cout<<"\n1.Insert an Element into the queue\n2.Deleting Element from the queue\n3.Display\n4.Exit\n";
		cout<<"\nEnter your choice: ";
		int ch;
		cin>>ch;
		return Conditional_operations(ch);	
	}
	int Conditional_operations(int x){
		switch(x){
			case 1:
				cout<<"\n----Enqueue Operation-----\n";
				cout<<"Enter an element: \n";
				T ele;
				cin>>ele;
				this->Enqueue(ele);
				break;
			case 2:
				cout<<"\n----Dequeue Operation-----\n";
				this->Dequeue();	
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
    void Enqueue(T val){
		if(size-1 == rear){
            cout<<"\nQueue is Full:\n";
            return;
        }
        else{
            if(front == -1)
            {
                front=0;
            }
                

            arr[rear]=val;
            cout<<"\nElement "<<val<<" inserted into the queue";
            rear++;
        }
	}
	void Dequeue(){
        if(front == -1 || front > rear){
            cout<<"\nQueue is Underflow:\n";
            return;
        }
        else{
            cout<<"\nElement "<<arr[front]<<" deleted from the queue";
            front++;
        }
	}
	void display(){
        if(front == -1){
            cout<<"Queue is empty :"<<endl;
        }
        else{

		    cout<<"\n--------Queue Elements--------\n";
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
	}
};
int main(){

	int size,ch;
	cout<<"\n----Integer Array----\n";
	cout<<"\nEnter the size of the integer array : ";
	cin>>size;
	

	queue <int>q1(size);
	do{	
		int flag=q1.operations();
		if(flag == 0)
			break;
	}while(1);

	cout<<"\n-----Charecter Array-----\n";
	cout<<"\nEnter the size of the Charecter array : ";
	cin>>size;

	queue <char>q2(size);
	do{	
		int flag=q2.operations();
		if(flag == 0)
			break;
	}while(1);

	return 0;
}
