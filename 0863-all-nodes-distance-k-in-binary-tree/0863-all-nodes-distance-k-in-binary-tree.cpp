/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& mpp)
{
    if(root==NULL)
    return;
    if(root->left!=NULL)
    {
        mpp[root->left]=root;
        parent(root->left,mpp);
    }
   if(root->right!=NULL)
    {
        mpp[root->right]=root;
        parent(root->right,mpp);
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        parent(root,mpp);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int level=0;
        while(!q.empty())
        {
            int n=q.size();
            if(level==k)
            break;
            for(int i=0;i<n;i++)
            {
            TreeNode* front=q.front();
            q.pop();
            if(front->left&&!visited[front->left])
            {
                q.push(front->left);
                visited[front->left]=true;
            }
            if(front->right&&!visited[front->right])
            {
                q.push(front->right);
                visited[front->right]=true;
            }
            if(mpp[front]&&!visited[mpp[front]])
            {
           q.push(mpp[front]);
           visited[mpp[front]]=true;
            }
            }
            level++;
      }
      vector<int>ans;
      while(!q.empty())
      {
        ans.push_back(q.front()->val);
        q.pop();
      }
      return ans;
        }

    };
