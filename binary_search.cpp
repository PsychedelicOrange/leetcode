#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {0,12,33,45,56,122,432,444,696,1000};
    int sterm = 33;
    int result = -1;
    int begin= 0,end =9,mid;
    while(begin <= end)
    {
        mid =(begin + end )/ 2;
        if(arr[mid] == sterm)
        {
            result = mid ;break;
        }
        else if ( arr[mid] > sterm)
        {
            end = mid - 1;
        }
        else if ( arr[mid] < sterm)
        {
            begin = mid + 1;
        }
    }
    cout << result ;
}