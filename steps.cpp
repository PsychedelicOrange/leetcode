#include <iostream>
#include <vector>
using namespace std;
int findc(int n,vector<int>&c)
{
    if(c[n] == -1)
        return findc(n-1,c)+findc(n-2,c);
    else
        return c[n];
}
int climbStairs(int n) {
    vector<int> c(n+1,-1);
    c[0]=0;
    c[1]=1;
    c[2]=2;
    return findc(n,c);
}
int main()
{
    cout << climbStairs(44);
}