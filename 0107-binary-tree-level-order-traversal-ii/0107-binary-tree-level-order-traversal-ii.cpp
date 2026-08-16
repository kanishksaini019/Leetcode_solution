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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL)
        return {};
        q.push(root);
        vector<int>level;
        vector<vector<int>>ans;
        
        while(!q.empty())
        {
            vector<int>level;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto p=q.front();
        level.push_back(p->val);
        q.pop();
        if(p->left!=NULL)
        q.push(p->left);
        if(p->right!=NULL)
        q.push(p->right);
            }
            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};