/*Program: Queue using Doubly Linked list */
//Name:Shreevatsa
//Reg No:200970093
//Modified Date:18-06-2021
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
        rear->next = newNode;
        newNode->prev = rear;
        rear=newNode;
    }
    void dequeue(){
        
        if(front == NULL){
            cout<<"\nQueue is empty!!";
            return;
        }
        Node* temp = front;
        if(size == 1){
            front = NULL;
            rear = NULL;
        }
        else{
        front = front->next;
        front->prev = NULL;
        }
        cout<<"\nElement "<<temp->data<<" deleted!";
        delete(temp);
        size--;
    }
    int sizeQueue(){
        return size;
    }
    void display(){
        if(front!=NULL){

			cout<<"\n----QUEUE----\n";
			cout<<" front -> ";
			for(Node*i=front;i!=rear;i=i->next)
			{
				cout<<" "<<i->data<<" , ";
			}
			cout<<rear->data<<" <-rear\n";
	    }
	    else{
		    cout<<"\nEMPTY!!\n";
	    }
    }
};
int main(){
    queue q;
    q.enqueue("43");
    q.enqueue("67");
    q.enqueue("90");
    q.enqueue("87");

    cout<<"\nNumber of elements : "<<q.sizeQueue();
    //q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    cout<<endl;
    return 0;
}