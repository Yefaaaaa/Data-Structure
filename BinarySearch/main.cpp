// Author Yefa Mai
#include <stdio.h>
#include <iostream>

// Binary Search only use in the array is sorted.

#define ARRAY_SIZE 20

using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  return mid;

        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);

        return binarySearch(arr, mid+1, r, x);
    }

    return -1;
}

int main(void)
{
    // Entry the array
    cout<<"This is a demo to try Binary Search."<<endl;
    cout<<"Array has to be sorted."<<endl;
    int arr[ARRAY_SIZE];
    int n = 0;
    int temp;
    bool checkInt;
    do
    {
        cout<<"Entry non number to stop entry number."<<endl;
        cout<<"Entry number (less than ARRAY_SIZE ) to array: ";
        cin >> temp;
        checkInt = cin.fail();
        cin.clear();
        cin.ignore();
        if (!checkInt)
        {
            arr[n]= temp;
            n++;
        }

    }
    while(!checkInt);

    int temp_num;
    // sort the array
    for(int i = 0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[i])
            {
                temp_num = arr[j];
                arr[j] = arr[i];
                arr[i] = temp_num;
            }
        }
    }
    // Array looks like
    cout<<"The array is: ";
    for(int i = 0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;

    // Entry the target number
    int x;
    checkInt= false;
    do{
    if(checkInt) cout<<"Please enter a valid number."<<endl;
    cout<<"Entry the target number: ";
    cin>>x;
    checkInt = cin.fail();
    cin.clear();
    cin.ignore();
    }while(checkInt);

    // Search starts
    int result = binarySearch(arr, 0, n-1, x);
    (result == -1)? printf("Element is not present in array")
    : printf("Element is present at index %d", result);
    return 0;
}
