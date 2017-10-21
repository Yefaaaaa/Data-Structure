/*

Author: Yefa Mai
Created at: 10/20/2017
Purpose: Only for demo

*/
#include <iostream>

using namespace std;
void heapStart(auto ar[], int n);
void heapsort_min(auto ar[], int sIze);
void heapsort_max(auto ar[], int sIze);
void print(auto ar[], int sIze);
void maxHeap(auto ar[], int sIze, int i);
void minHeap(auto ar[], int sIze, int i);

int main()
{
    int choice;
    cout<<"Integer sort: 1"<<endl;
    cout<<"Charter sort: 2"<<endl;
    cout<<"Exit the program: 0"<<endl;
    cout<< "Please select what you want to sort: ";cin>>choice;cout<<endl;

    switch(choice){
    case 1:{
        // Integer sort
        int n; // n is number of elements
        cout<<"Enter how many elements you want to input: ";
        cin>>n;
        int ar[n];
        for(int i=0; i<n; i++){
            cout<< "Please enter the number in to the heap: ";
            cin>>ar[i];
        }
        heapStart(ar,n);
        }
        break;
    case 2:{
        // Charter sort
        int n; // n is number of elements
        cout<<"Enter how many elements you want to input: ";
        cin>>n;
        char ar[n];
        for(int i=0; i<n; i++){
            cout<< "Please enter the number in to the heap: ";
            cin>>ar[i];
        }
        heapStart(ar,n);
        }
        break;
    case 0:
        cout << "See you next time"<<endl;
        return 0;
    default:
        cout<<"Please pick an vaild choice"<<endl;
        return main();
    }
    return 0;
}
void heapStart(auto ar[],int n){
    // heap sort
    int sIze = n;
    heapsort_min(ar,sIze);
    cout<<"after heap minSort: ";
    print(ar,sIze);
    cout<<endl;
    heapsort_max(ar,sIze);
    cout<<"after heap maxSort: ";
    print(ar,sIze);
    cout<<endl;
}

void heapsort_max(auto ar[], int sIze){
    int i;
    for (i=sIze/2-1;i>=0;i--){
        maxHeap(ar,sIze,i);
    }
    for (i=sIze-1; i>=0;i--){
        swap(ar[0],ar[i]);
        maxHeap(ar,i,0);
    }
}

void heapsort_min(auto ar[], int sIze){
    int i;
    for (i=sIze/2-1;i>=0;i--){
        minHeap(ar,sIze,i);
    }
    for (i=sIze-1; i>=0;i--){
        swap(ar[i],ar[0]);
        minHeap(ar,i,0);
    }
}


void maxHeap(auto ar[], int sIze, int i){
    int parent = i;  // parent
    int left = 2*i +1;  // left child
    int right = 2*i +2; // right child
    // Is left-child is greater than parent
    if(left<sIze && (int)ar[left]> (int)ar[parent])
        parent = left;

    // Is right-child is greater than parent
    if(right<sIze && (int)ar[right]>(int) ar[parent])
        parent = right;

    // if parent was not i
    if(parent != i){
        swap(ar[i],ar[parent]);
        maxHeap(ar,sIze,parent);
    }
}

void minHeap(auto ar[], int sIze, int i){
    int parent = i;  // parent
    int left = 2*i +1;  // left child
    int right = 2*i +2; // right child
    // Is right-child is greater than parent
    if(right<sIze && (int)ar[right]< (int)ar[parent])
        parent = right;

    // Is left-child is greater than parent
    if(left<sIze && (int)ar[left]< (int)ar[parent])
        parent = left;

    // if parent was not i
    if(parent != i){
        swap(ar[i],ar[parent]);
        maxHeap(ar,sIze,parent);
    }
}

void print(auto ar[], int sIze){
    for(int i= 0; i<sIze; i++){
    cout<<ar[i]<<" ";
    }
}
