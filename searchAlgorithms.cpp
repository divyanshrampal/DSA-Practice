#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

void generateArray(int arr[], int size){
    for(int i=0;i<size;i++){
      arr[i] = rand()%100;  //Generate number between 0 to 99
    }
}

void dislayArray(int arr[], int size){
    for(int i=0;i<size;i++)
      cout<<arr[i]<<" ";
}

int linearSearch(int arr[], int size, int x){
    for(int i = 0; i<size; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int si, int ei, int x){
    if(si >= ei)
        return -1;
    int mid = (si + ei)/2;
    if(arr[mid] == x)
        return mid;
    if(arr[mid] > x)
       return binarySearch(arr, si, mid-1, x);
    else
       return binarySearch(arr, mid+1 , ei, x);
}

int main(){
    int n;

    cout<<" Enter the size of the array = ";
    cin>>n;
    int arr[n];
    generateArray(arr,n);
    cout<<" Input array : ";
    dislayArray(arr, n);
    int x;
    cout<<"\n\n Enter the element to find in the array = ";
    cin>>x;
    int option;
    cout<<"\n Select the search algorithm you want to use :";
    cout<<"\n 1. Linear Search"<<"\n 2. Binary Search";
    cout<<"\n\n Enter your choice : ";
    cin>>option;
    int found = -1;
    switch(option){
        case 1: found = linearSearch(arr, n, x);
                if(found != -1)
                   cout<<"\n Element found at index "<<found;
                else
                   cout<<"\n Element not found ";
                break;

        case 2: sort(arr, arr + n);
                cout<<" Sorted array : ";
                dislayArray(arr, n);
                found = binarySearch(arr, 0, n-1, x);
                if(found != -1)
                   cout<<"\n Element found at index "<<found<<" in the sorted array";
                else
                   cout<<"\n Element not found ";
                break;
        default: cout<<" Invalid choice ! ";
                 exit(0);
    }
    cout<<"\n\n This program was made by Lavanya Narang IT-B 71\n\n\n\n";
}
