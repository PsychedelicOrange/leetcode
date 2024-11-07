#include <iostream>
using namespace std;
void merge(int* arr, int l,int m, int r)
{
    // copy arr[l,m] and arr[m+1,r] to separate arrays;
    int sizel = m-l+1, sizer = r-m;
    int * arrl = new int[sizel];
    int * arrr = new int[sizer];
    for(int i =0 ; i < sizel; i ++)
    {
        arrl[i] = arr[i+l]  ;
    }
    for(int i = 0 ; i < sizer ; i++)
    {
        arrr[i] = arr[m+1+i];
    }
    int il =0 ,ir = 0,i=l;
    while(il < sizel && ir < sizer)
    {
        if( arrr[ir] < arrl[il])
        {
            arr[i++] = arrr[ir++] ;
        }
        else 
        {
            arr[i++] = arrl[il++] ;
        }
    }
    while(il < sizel)
    {
        arr[i++] = arrl[il++];
    }
    while(ir < sizer)
    {
        arr[i++] = arrr[ir++];
    }
    delete [] arrl;
    delete [] arrr;
}
void mergesort(int* arr,int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = l + ( r - l )/2 ;
    mergesort(arr,l,mid);
    mergesort(arr,mid + 1,r);
    merge(arr,l,mid,r);
}
int main ()
{
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;
    mergesort(arr,0,n-1);
    for(int i=0 ; i < 7 ; i++)
    {
        cout << arr[i] << " ";
    }
}