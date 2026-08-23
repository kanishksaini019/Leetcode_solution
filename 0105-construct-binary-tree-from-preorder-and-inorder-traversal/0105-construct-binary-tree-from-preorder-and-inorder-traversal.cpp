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
void in(vector<int>& preorder, vector<int>& inorder,map<int,int> &mpp)
{
    int n=preorder.size();
    for(int i=0;i<n;i++)
    {
        mpp[inorder[i]]=i;
    }
}
TreeNode* constr(vector<int>& preorder,int prest,int prend, vector<int>& inorder,int inst,int ined,map<int,int> &mpp)
{
    if(prest>prend||inst>ined)
    return NULL;
    TreeNode* root=new TreeNode(preorder[prest]);
    int inroot=mpp[preorder[prest]];
    int no=mpp[preorder[prest]]-inst;
   TreeNode* left= constr(preorder,prest+1,prest+no,inorder,inst,inroot-1,mpp);
    TreeNode* right=constr(preorder,prest+no+1,prend,inorder,inroot+1,ined,mpp);
    root->left = left;
root->right = right;
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        in(preorder,inorder,mpp);
      return constr(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);  
    }
};