#include <iostream>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
        next = nullptr;
    } 
};
// insert list 
Node* insert(Node* root, int term)
{
    root->next = new Node(term);
    return root;
}
void print_list(Node* root)
{
    while(root!= nullptr)
    {
        cout << root->val << " ";
        root = root -> next ;
    }
}
Node* delete_list(Node* root, int term)
{
    Node * temp = root ;
    if(root->val == term)
    {
        temp = root->next ;
        delete root;
        return temp;
    }
    while(temp->next)
    {
        if(temp->next->val == term)
        {
            Node* temp2 = temp->next->next;
            delete temp->next ;
            temp->next = temp2;
            return root;
        }
    }
}
int main()
{
    // linked list 
    Node* root= new Node(10);
    root = insert(root, 1);
    root = delete_list(root, 1);
    root = insert(root ,2);
    print_list(root);
}