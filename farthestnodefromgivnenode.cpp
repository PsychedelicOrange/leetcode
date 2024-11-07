/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
int getheight(TreeNode* root)
{
    int height =0;
    queue<TreeNode*> q;
    if(root)
        q.push(root);
    while(!q.empty())
    {
        height++;
        int len = q.size();
        for(int i=0;i<len;i++)
        {
            TreeNode* n = q.front();q.pop();
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
    }
    return height;
}
bool getpath(vector<TreeNode*>* path ,TreeNode* node,int term)
{
    path->push_back(node);
    if(!node)
        return false;
    if(node->val == term)
        return true;
    if(getpath(path,node->left,term)||getpath(path,node->right,term))
        return true;
    path->pop_back();
    return false;
}
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<TreeNode*> path ;
        getpath(&path,root,start);
        int psize = path->size();
        vector<int> maxdist(psize);
        maxdist[psize-1] = 1;
        int i = psize - 1;
         if(path[i-1]->left == path[i])
            {
                maxdist[i-1] = max(maxdist[i]-getheight(path[i-1]->left),maxdist[i]+getheight(path[i-1]->right));  
            }
            if(path[i-1]->right == path[i])
            {
                maxdist[i-1] = max(maxdist[i]-getheight(path[i-1]->right),maxdist[i]+getheight(path[i-1]->left)); 
            }
        
        for(int i=psize-2; i>0;i--)
        {
            if(path[i-1]->left == path[i])
            {
                maxdist[i-1] = max(maxdist[i],(psize()-1)-(i-1)+getheight(path[i-1]->right));
            }
            if(path[i-1]->left == path[i])
            {
                maxdist[i-1] = max(maxdist[i],(psize()-1)-(i-1)+getheight(path[i-1]->right));
            }
    }
        return maxdist[0];
};
}