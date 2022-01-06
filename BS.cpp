#include <iostream>
using namespace std;
//Implementation Binary Search using Recursive function with C++

//Binary Search Function
int BS(int arr[],int low,int high,int key){
    if(high>=1){
       int mid=(low+high)/2;
       if(key==arr[mid]){
           return mid;//if key is in middle return mid
       }else if(key<=arr[mid]){
           return BS(arr,low,mid-1,key);//if key is less than middle element//program needs to find in left side
       }else{
           return BS(arr,mid+1,high,key);//if key is greater than middle element//program needs to find in right side
       }
    } else{
        return -1;
    }
}

int main() {
    int n=0;
    int key=0;
    cout<<"Enter number of elements to store in array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        //User input elements must be sorted order
        cout<<"Enter elements into array"<<endl;
        cin>>arr[i];
    }
    cout<<"Enter element to find"<<endl;
    cin>>key;
    int result= BS(arr,0,n-1,key);
    if (result == -1) {
        cout << "Element is not present in array";
    } else {
        cout << "Element is present at index " << result;
    }
    return 0;
}
