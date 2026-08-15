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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      vector<vector<int>>v;
      queue<pair<TreeNode*,pair<int,int>>>q;
      q.push({root,{0,0}});
      while(!q.empty())
      {
        auto p=q.front();
        q.pop();
     int row=p.second.first;
       int col=p.second.second;
      TreeNode* data=p.first;
      v.push_back({col,row,data->val});
      if(data->left!=NULL)
      q.push({data->left,{row+1,col-1}});
      if(data->right!=NULL)
      q.push({data->right,{row+1,col+1}});
      }
      vector<vector<int>>ans;
      sort(v.begin(),v.end());
      int curr=v[0][0];
      vector<int>temp;
      for(auto it:v)
      {
        int col=it[0];
       if(curr==col)
       {
temp.push_back(it[2]);
       }
       else
       {
        curr=col;
        ans.push_back(temp);
        temp.clear();
        temp.push_back(it[2]);
       }
      }
      ans.push_back(temp);  
      return ans;
    }
};