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

TreeNode* bst(vector<int> preorder,int bound,int& i)
{
if(i==preorder.size()||preorder[i]>bound)
return NULL;
TreeNode* node=new TreeNode(preorder[i++]);
node->left=bst(preorder,node->val,i);
node->right=bst(preorder,bound,i);
return node;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return bst(preorder,INT_MAX,i);
    }
};