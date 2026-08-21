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
int ans(TreeNode* root)
{
    int hrow=-1;
    int lcol=INT_MAX;
    int val=-1;
    queue<pair<TreeNode*,pair<int,int>>>p;
    p.push({root,{0,0}});
     vector<int>ans;
     while(!p.empty())
     {
        auto q=p.front();
        p.pop();
        int row=q.second.first;
        int col=q.second.second;
      if(row>hrow)
      {
        hrow=row;
        lcol=col;
        val=q.first->val;
      }
    
      if(q.first->left!=NULL)
      p.push({q.first->left,{row+1,col-1}});
if(q.first->right!=NULL)
p.push({q.first->right,{row+1,col+1}});
     }
     return val;
}
    int findBottomLeftValue(TreeNode* root) {
    int oo=   ans(root); 
    return oo;
    }
};