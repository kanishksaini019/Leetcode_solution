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
 class Solution
 {
 class bstiterator
 {
    public:
    stack<TreeNode* >st;
    bool reverse=true;
    bstiterator(TreeNode* node,bool isreverse)
    {
reverse=isreverse;
pushall(isreverse,node);
    }
    int next()
    {
        TreeNode* top=st.top();
        st.pop();
        if(reverse)
       pushall(reverse,top->left);
        else
        pushall(reverse,top->right);
        return top->val;
    }
    void pushall(bool reverse,TreeNode* node)
    {
while(node)
{
    if(reverse){
    st.push(node);
    node=node->right;
    }
    else {
    st.push(node);
    node=node->left;
    }
}
    }
 };
public:
    bool findTarget(TreeNode* root, int k) {
      bstiterator l(root,false);
      bstiterator r(root,true);
      int i=l.next();
      int j=r.next();
      while(i<j)
      {
        if(i+j==k)
        {
            return true;
        }
        else if(i+j>k)
        {
            j=r.next();
        }
        else
        {
            i=l.next();
        }
      }
      return false;
    }
};