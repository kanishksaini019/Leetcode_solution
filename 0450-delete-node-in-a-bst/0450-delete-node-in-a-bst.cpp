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
TreeNode* rightmost(TreeNode* root)
{
    while(root)
    {
        if(root->right)
        root=root->right;
        else return root;
    }
    return root;
}
TreeNode* helper(TreeNode* node)
{
   if(node->left==NULL)
   return node->right;
 else if(node->right==NULL)
 return node->left;
 TreeNode* rc=node->right;
 TreeNode* lrc=rightmost(node->left);
 lrc->right=rc;
 return node->left;

}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        return NULL;
        TreeNode* curr=root;
        if(curr->val==key)
     return helper(curr);
        while(root)
        {
    if(root->val>key)
            {
             if(root->left!=NULL&&root->left->val==key)
             {
                root->left=helper(root->left);
             }
             else
             {
                root=root->left;
             }
            }
            else
            {
                if(root->right!=NULL&&root->right->val==key)
                {
                    root->right=helper(root->right);
                }
                else
                {
                    root=root->right;
                }
            }
        }
        return curr;
    }
};