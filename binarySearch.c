#include<stdio.h>
int binarySearch(int *arr,int n,int key){
    int low = 0;
    int high = n-1;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            low = mid+1;
        else 
            high = mid-1;
    }

    return -1;
}
int main(){
    int arr[] = {12,34,56,78,89,90,92,100};
    printf("%d",binarySearch(arr,8,92));
}