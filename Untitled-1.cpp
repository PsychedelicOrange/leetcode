#include <iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> a {1,3,7};
    vector<int> b {3,4};
    vector<int> c(5);
    int i=0,j=0,k=0;
    int an = 3, bn= 2;
    while (i < an && j < bn)
    {
        if(a[i] <= b[j])
        {
            c[k++] = a[i++];
        }
        else 
        {
            [j++] = c[k++];
        }
    }
}