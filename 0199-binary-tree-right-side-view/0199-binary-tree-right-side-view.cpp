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
void right(TreeNode* root,vector<int>& ds,int level)
{
    if(root==NULL)
    return;
    if(level==ds.size())
    ds.push_back(root->val);
    right(root->right,ds,level+1);
    right(root->left,ds,level+1);
}
    vector<int> rightSideView(TreeNode* root) {
       int level=0;
       vector<int>ds;
       right(root,ds,level);
       return ds; 
    }
};