/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        string s="";
        if(root==NULL)
        {
            s="#";
            return s;
        }
           queue<TreeNode*>q;
           q.push(root);
           
           while(!q.empty())
           {
            TreeNode* node=q.front();
            if(node==NULL)
            {
                s.append("#,");
                q.pop();
                continue;
            }
            else
            {
                s.append(to_string(node->val)+',');
                q.pop();
            }     
           q.push(node->left);
           q.push(node->right);
           }
           return s;

    }

   
    TreeNode* deserialize(string data) {
    if(data.length()==0)
    return NULL;   
vector<string>v;
string temp="";
for(int i=0;i<data.length();i++)
{
    if(data[i]==',')
    {
        v.push_back(temp);
        temp="";
    }
    else
    {
        temp+=data[i];
    }
}
if(temp!="")
{
v.push_back(temp);
}
if(v[0]=="#")
return NULL;
TreeNode* node=new TreeNode(stoi(v[0]));
int i=1;
queue<TreeNode*>q;
q.push(node);
while(!q.empty())
{
TreeNode* temp=q.front();
q.pop();
if(v[i]=="#")
{
    temp->left=NULL;
}
else
{
    TreeNode* newnode=new TreeNode(stoi(v[i]));
    q.push(newnode);
    temp->left=newnode;
}
i++;
if(v[i]=="#")
{
    temp->right=NULL;
}
else
{
    TreeNode* newnode=new TreeNode(stoi(v[i]));
    q.push(newnode);
    temp->right=newnode;
}
i++;
}
return node;
}
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));