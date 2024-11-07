#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class Node 
{public:
    int val ;
    Node * left;
    Node * right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
Node* insert(Node* root,int term)
{
    Node* temp = root ;
    while(temp)
    {
        if(temp->val > term)
        {
            if(temp->left)
                temp= temp->left;
             else
            {
                temp->left = new Node(term);
                return root;
            }
        }
        else
        { 
            if(temp->right)
                temp= temp->right;
            else
            {
                temp->right = new Node(term);
                return root;
            }
                
        }
    }
}
void inorder(Node* temp)
{
    if(!temp)
        return;
    inorder(temp->left);
    cout << temp->val <<" ";
    inorder(temp->right);
}
void preorder(Node* temp)
{
    if(!temp)
        return;
    cout << temp->val << " ";
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(Node* temp)
{
    if(!temp)
        return;
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->val << " ";
}
void levelorder(Node* temp)
{
    queue<Node*> q;
    q.push(temp);
    while(!q.empty())
    {  
        Node* temp2 = q.front();q.pop();
        cout << temp2->val << " ";
        if(temp2->left)
            q.push(temp2->left);
        if(temp2->right)
            q.push(temp2->right);
    }   
}
int main()
{
    Node* root = new Node(10);
    insert(root,1);
    insert(root,3);
    insert(root,12);
    insert(root,2);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
}