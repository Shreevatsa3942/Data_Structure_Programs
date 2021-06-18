/*Program: Queue using Singly Linked list */
//Name:Shreevatsa
//Reg No:200970093
//Modified Date:18-06-2021

#include<iostream>
using namespace std;

class Node{
public:
	string data;
	Node *next;
	//constructor to initialze the values
	Node(string data){
		this->data = data;
		next = NULL;
	}
};

class queue{
    Node* rear,*front;
    int size;
public:
    queue(){
        rear=front=NULL;
        size=0;
    }
    void enqueue(string ele){
        Node* newNode = new Node(ele);
        size++;
        cout<<"\nElement "<<newNode->data<<" inserted";
        if(rear == NULL){
            rear=front=newNode;
            return;
        }
        //initially rear->next is null before moving rear to the next node
        //we have to set the address of next node in rear node then initialize
        //rear=newnode;
        rear->next = newNode;
        rear=newNode;
    }
    void dequeue(){
        if(front == NULL){
            cout<<"\nQueue is empty!!";
            return;
        }
        size--;
        Node* temp = front;
        //create temp node initialize with front node
        //front->next contains address of next node move to next node and 
        //delete temp node
        front = front->next;
        cout<<"\nElement "<<temp->data<<" deleted!";
        delete(temp);
    }
    int sizeQueue(){
        return size;
    }
};
int main(){
    queue q;
    q.enqueue("43");
    q.enqueue("67");
    q.enqueue("90");
    q.enqueue("87");

    cout<<"\nNumber of elements : "<<q.sizeQueue();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    cout<<endl;
    return 0;
}