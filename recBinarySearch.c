#include<stdio.h>
int binarySearch(int arr[],int low,int high,int key){
    if(low>high)
        return -1;
    int mid = low + (high-low)/2;
    if(arr[mid]==key)
       return mid;
    else if(arr[mid]<key)
       return binarySearch(arr,mid+1,high,key);
    else
       return binarySearch(arr,low,mid-1,key);
}

int main(){
    int arr[] = {10,20,32,43,56,67,73,78,90,91};
    int high = sizeof(arr)/sizeof(arr[0]);
    printf("%d element is present at index %d",73,binarySearch(arr,0,high,73));

}