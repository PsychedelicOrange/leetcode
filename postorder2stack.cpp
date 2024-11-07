#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class node
{public:
    int val;
    node* left;
    node* right;
    node(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
int main()
{
    node* root =new node(1);
    root->right = new node(3);
    root->right->right = new node (6);
    root->right->left = new node (10);
    root->left = new node(5);
    root->left->right = new node(4);
    root->left->right->left = new node(9);
    root->left->right->right = new node(2);

    stack<node*> s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        node* n= s1.top();s1.pop();
        s2.push(n);
        if(n->left)
            s1.push(n->left);
        if(n->right)
            s1.push(n->right);
    }
    while(!s2.empty())
    {
        cout<< " "<< s2.top()->val;s2.pop();
    }
}