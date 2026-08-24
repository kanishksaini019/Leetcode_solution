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
void inor(vector<int>& inorder,map<int,int>& mpp)
{
int n=inorder.size();
for(int i=0;i<n;i++)
{
    mpp[inorder[i]]=i;
}
}
TreeNode* constr(vector<int>& inorder,int inst,int ined, vector<int>& postorder,int postst,int posted,map<int,int>& mpp)
{
    if(inst>ined||postst>posted)
    return NULL;
    TreeNode* root=new TreeNode(postorder[posted]);
    int inroot=mpp[postorder[posted]];
    int no=inroot-inst;
    TreeNode* left=constr(inorder,inst,inroot-1,postorder,postst,postst+no-1,mpp);
    TreeNode* right=constr(inorder,inroot+1,ined,postorder,postst+no,posted-1,mpp);
    root->left=left;
    root->right=right;
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      map<int,int>mpp;
      inor(inorder,mpp);
      return constr(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);  
    }
};