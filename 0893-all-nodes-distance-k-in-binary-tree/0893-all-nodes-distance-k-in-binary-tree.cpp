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
    vector<int> ans ;
    void getParent(TreeNode* root, TreeNode* target, map<TreeNode*,TreeNode*>&parent){
        if(root == NULL )
            return ;
        if(root->left)
        parent[root->left]=root;
        if(root->right)
        parent[root->right]=root;

        getParent(root->left,target,parent);
        getParent(root->right,target,parent);

    }

    void atDistance(TreeNode* root,int k,TreeNode* prev){
        if(k==0 && root){
            cout<<root->val<<"k"<<k <<endl;
            ans.push_back(root->val);
            return ;}
        if(root==NULL)
            return;
        
        cout<<root->val<<"k out"<<k <<endl;
        if(prev!=root->left)
        atDistance(root->left,k-1,prev);
        if(prev!=root->right)
        atDistance(root->right,k-1,prev);

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        map<TreeNode*,TreeNode*>parent;
        
        getParent(root,target,parent);

        TreeNode *temp=target;
        TreeNode *prev=target;

        

        for(int i = k ; i >=0 ;i--){
            atDistance(temp,i,prev);
            cout<<temp->val<<"entry"<<prev->val<<endl;
            prev = temp;
            temp = parent[temp];
            if(temp==NULL)
                break;
        }

        return ans;
    }
};