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

	int size;
	
	size=6;

	queue <int>q1(size);
    //Inserting elements into the queue
	q1.Enqueue(2);
    q1.Enqueue(4);
    q1.Enqueue(6);
    q1.Enqueue(8);
    q1.Enqueue(56);
    q1.Enqueue(9);
    
    //Deleting elements from the queue

    q1.Dequeue();
    q1.Dequeue();
    q1.display();
	cout<<"\n-----Charecter Array-----\n";
    size=6;
	queue <char>q2(size);

    //Enqueueing elements into the queue
	q2.Enqueue('a');
    q2.Enqueue('g');
    q2.Enqueue('h');
    q2.Enqueue('j');
    q2.Enqueue('k');
    q2.Enqueue('b');
    q2.Enqueue('m');
    
    
    //Dequeueping elements from the queue

    q2.Dequeue();
    q2.Dequeue();
    q2.display();
	return 0;
}
