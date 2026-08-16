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
void path(TreeNode* root,vector<string>& pa,string s)
{
    if(root==NULL)
    return;
 s=s+to_string(root->val);
     if(root->left==NULL&&root->right==NULL){
        pa.push_back(s);
     return;
     }
     s=s+"->";
if(root->left!=NULL)
    path(root->left,pa,s);
if(root->right!=NULL)
    path(root->right,pa,s);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>pa;
        string s="";
        path(root,pa,s);
        return pa;
    }
};