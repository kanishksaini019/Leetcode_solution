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
void path(TreeNode* root,vector<int>& sumo,int sum)
{
   if(root==NULL)
   return;
   sum+=root->val;
   if(root->left==NULL&&root->right==NULL){
   sumo.push_back(sum);
   return;
   }
   path(root->left,sumo,sum);
   path(root->right,sumo,sum);
}
    bool hasPathSum(TreeNode* root, int targetSum) {
    vector<int>sumo;
    int sum=0;
    path(root,sumo,sum); 
    int n=sumo.size();
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        if(sumo[i]==targetSum)
        {
            flag=true;
        }
    }
   if(flag)
   return true;
   else
   return false;
    }
};