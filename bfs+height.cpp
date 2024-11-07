#include <iostream>
#include <queue>
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
    // bfs 
    queue<node*> q;
    q.push(root);
    int height= 0 ;
    while(!q.empty())
    {
        height++;
        int len = q.size();
        for(int i =0 ; i< len;i ++)
        {
            node* n = q.front();q.pop();
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        cout << endl;
    }
    cout << "Height of tree is " << height;
}