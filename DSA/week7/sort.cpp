/*Program: Program to sort the elements in an array using sortion 
            Algorithms like Bubble sort,Selection Sort,Insertion Sort,
            Exchange Sort */
//Name:Shreevatsa
//Reg No:200970093
//Modified Date:04-07-2021

#include<iostream>
using namespace std;

void bubble_sort(int[],int);
void selection_sort(int[],int);
void insertion_sort(int[],int);
void exchange_sort(int[],int);
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void display(int arr[],int n){
    cout<<"\nAfter Sorting : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    cout<<"\nEnter the size : ";
    int size;
    cin>>size;
    int arr[size];
    cout<<"\nEnter array Elements : ";
    for(int i=0;i<size;i++)
        cin>>arr[i];
    cout<<"\n----Sorting Methods---\n1.Bubble sort\n2.Selection Sort\n3.Insertion Sort\n4.Exchange Sort\nEnter your Choice : ";
    int ch;
    cin>>ch;
    switch (ch)
    {
    case 1:cout<<"\n------Bubble Sort------\n";
        bubble_sort(arr,size);
        break;
    case 2:cout<<"\n------Selection Sort------\n";
        selection_sort(arr,size);
        break;
    case 3:cout<<"\n------Insertion Sort------\n";
        insertion_sort(arr,size);
        break;
    case 4:cout<<"\n------Exchange Sort------\n";
        exchange_sort(arr,size);
        break;
    default: cout<<"\nInvalid Choice\n";
        break;
    }
    cout<<endl;
    return 0;
}
void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
    display(arr,n);
}
void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min])
                min = j;
        }
        swap(arr[i],arr[min]);  

    }
    display(arr,n);
}
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int j=i-1;
        while(j >= 0 && arr[j] > curr){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] =  curr;   

    }
    display(arr,n);
}
void exchange_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
            if(arr[j] < arr[i])
                swap(arr[i],arr[j]);
    }
    display(arr,n);
}