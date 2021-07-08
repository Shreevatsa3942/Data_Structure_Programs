/*Program: Program to Search an Element in an array using different 
        searching techniques like Linear Search or Binary Search
 */
//Name:Shreevatsa
//Reg No:200970093
//Modified Date:04-07-2021

#include<iostream>
using namespace std;
void insertion_Sort(int[],int);
int Linear_Search(int[],int,int);
int Binary_Search(int[],int,int,int);

int main(){
    cout<<"\nEnter the size of the array : ";
    int size; 
    cin>>size;
    int arr[size];
    cout<<"\nEnter the array elements : ";
    for(int i=0;i<size;i++)
        cin>>arr[i];
    //insertion_Sort(arr,size);
    cout<<"\nEnter the element to be searched : ";
    int ele;
    cin>>ele;

    cout<<"\n-----Search Methods-----\n";
    cout<<"\n1.Linear Search\n2.Binary Search\nEnter your Choice: ";
    int ch;
    cin>>ch;

    switch(ch)
    {
    case 1:
        int val;
        val = Linear_Search(arr,size,ele);
        if(val != -1)
            cout<<"\nElement Exist at position : "<<val;
        else 
            cout<<"\nElement Does not Exist!!";
        break;
    case 2:
        int flag;
        flag = Binary_Search(arr,ele,0,size);
        if(flag != -1)
            cout<<"\nElement Exist ";
        else
            cout<<"\nElement Does not Exist";
        break;
    
    default:cout<<"\nInvalid Choice !!";
        break;
    }
    cout<<endl;
    return 0;
}

int Linear_Search(int arr[],int n,int ele){
    for(int i=0;i<n;i++){
        if(ele == arr[i])
            return i;
    }
    return -1;
}

int Binary_Search(int arr[],int ele,int start,int end){
    insertion_Sort(arr,end);
    cout<<"\nArray After sorting : ";
    for(int i=0;i<end;i++)
    cout<<arr[i]<<" ";
    end -= 1;
    int mid = -1;
    while(start <= end){
        mid = (start + end)/2;
        /*cout<<mid<<" "<<arr[mid]<<endl;*/
        if(arr[mid] == ele)
            return mid;
        else if(arr[mid] < ele)
            start = mid+1;
        else
            end = mid-1;
    }
    return -1;
}
void insertion_Sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int j=i-1;
        while(j >= 0 && arr[j] > curr){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] =  curr;   

    }
    
}