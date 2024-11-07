#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<int> enqueue( int data , stack<int> first)
{
    first.push(data);
    return first;
}
stack<int> dequeue( stack<int> first)
{
    stack<int> second;
    while(!first.empty())
    {
        second.push(first.top());first.pop();
    }
        
    second.pop();
    while(!second.empty())
    {
        first.push(second.top());second.pop();
    }
    return first;
}
void print(stack<int> first)
{
    stack<int> second;
    while(!first.empty())
    {
        second.push(first.top());first.pop();
    }
    cout <<second.top();
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  stack <int> first;
    first = enqueue(42,first);
    first = dequeue(first);
    first = enqueue(14,first);
    print(first);
    return 0;
}
