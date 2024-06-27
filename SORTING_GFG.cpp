#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for (int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swapped=true;
                }
        }
        if(swapped==false){
            break;
        }
    }
};

void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(arr[min_index],arr[i]);
    }
};

void insertionSort(int arr[],int n){
    
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
};

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bubbleSort(arr,n);
    cout<<endl;
    selectionSort(arr,n);
    cout<<endl;
    insertionSort(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}