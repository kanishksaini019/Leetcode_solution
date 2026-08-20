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
public:
void parent(TreeNode* root,TreeNode* &res,unordered_map<TreeNode*,TreeNode*> &mpp,int start)
{
    if(root==NULL)
    return;
    if(root->val==start)
    res=root;
    
    if(root->left!=NULL){
    mpp[root->left]=root;
    parent(root->left,res,mpp,start);
    }
    if(root->right!=NULL)
    {
        mpp[root->right]=root;
        parent(root->right,res,mpp,start);
    }
}
int bfs(TreeNode* root,TreeNode* target,unordered_map<TreeNode*,TreeNode*>mpp)
{
 int max=0;
 queue<TreeNode*>q;
 map<TreeNode*,bool>vis;
 q.push(target);
 vis[target]=true;
 while(!q.empty())
 {
    int n=q.size();
    int f=0;
    for(int i=0;i<n;i++)
    {
        TreeNode* fo=q.front();
        q.pop();
        if(fo->left!=NULL&&!vis[fo->left])
        {
         vis[fo->left]=true;
         f=1;
         q.push(fo->left);
        }
        if(fo->right!=NULL&&!vis[fo->right])
        {
            vis[fo->right]=true;
            f=1;
            q.push(fo->right);
        }
        if(mpp[fo]!=NULL&&!vis[mpp[fo]])
        {
            vis[mpp[fo]]=true;
            f=1;
            q.push(mpp[fo]);
        }
    }
    if(f)
    max++;
 }
 return max; 
}
    int amountOfTime(TreeNode* root, int start) {
      TreeNode* res;
      unordered_map<TreeNode*,TreeNode*>mpp;
      TreeNode* target;
      parent(root,res,mpp,start);
     target=res;
    int n=  bfs(root,target,mpp);
return n;
    }
};