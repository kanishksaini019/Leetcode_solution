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
    int widthOfBinaryTree(TreeNode* root)
     {

    queue<pair<TreeNode*,long long>>q; 
    long long maxi=0;
    q.push({root,0});
    long long last=-1;
       while(!q.empty())
       {
    int n=q.size();
    auto p=q.front();
    long long first=p.second;
    for(int i=0;i<n;i++)
    {
        auto p=q.front();
        q.pop();
        last=p.second-first;
        TreeNode* ro=p.first;
        long long currid=2*last+1;
        long long currid2=2*last+2;
        if(ro->left!=NULL)
        q.push({ro->left,currid});
        if(ro->right!=NULL)
        q.push({ro->right,currid2});
    }
    maxi=max(maxi,last+1);
       }
       return maxi;
    }
};