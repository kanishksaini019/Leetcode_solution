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
bool isleaf(TreeNode* node)
{
    if(node==NULL)
    return false;
    if((node->left==NULL)&&(node->right==NULL))
    return true;
    else
    return false;
}
void sumo(TreeNode* root,int& sum)
{
    if(root==NULL)
    return;
    if(isleaf(root->left)==true)
    sum+=root->left->val;
    sumo(root->left,sum);
    sumo(root->right,sum);
}
    int sumOfLeftLeaves(TreeNode* root) {
    int sum=0;
    if(root==NULL)
    return 0;
    sumo(root,sum);
    return sum;
    }
};