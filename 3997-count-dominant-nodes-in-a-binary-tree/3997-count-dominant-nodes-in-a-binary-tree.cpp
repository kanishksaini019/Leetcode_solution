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
int maxx(TreeNode* root,int &cnt)
{
    if(root==NULL)
    return INT_MIN;
  int l=  maxx(root->left,cnt);
    int r=maxx(root->right,cnt);
    if(root->val>=l&&root->val>=r)
    {
        cnt++;
    }
    return max(root->val,max(l,r));
}
    int countDominantNodes(TreeNode* root) {
     int cnt=0;
     maxx(root,cnt);
     return cnt;
       
        }
    };
