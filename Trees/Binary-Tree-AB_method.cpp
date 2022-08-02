#include <iostream> 
using namespace std;

int partition(int* arr, int l , int h){
    //cout<<"in Partition";
    int pivot = arr[l];
    int temp;
    int i = l , j = h;
    while(i<j){
        while(arr[i]<= pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    
    return j;
}


void quickSort(int* a , int  l ,int  h ){
    //cout<<"In QuickSort"<<endl;
    if(l<h){
        //cout<<"In Loop"<<endl;
        int j = partition(a , l , h);
        //cout<<j<<endl;
        quickSort(a, l, j-1);
        quickSort(a,j+1,h);
    }
}
int main() {
    // Write C++ code here
    int arr[6] = {2,4,1,3,9};
    
    //cout<<"Running"<<endl;
    quickSort(arr , 0 , 5);
    for(auto it : arr )
        cout<<it<<" ";
    return 0;
}