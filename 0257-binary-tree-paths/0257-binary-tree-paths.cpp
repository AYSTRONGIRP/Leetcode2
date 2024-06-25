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

    void dfs(vector<string> & ans,TreeNode *root , string s){
        
        if(root==NULL)
            return ;

        if(root->left==NULL && root->right==NULL){
            ans.push_back(s+"->"+to_string(root->val));
            return ;
        }
        dfs(ans,root->left,s+"->"+to_string(root->val));

        dfs(ans,root->right,s+"->"+to_string(root->val));

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans ; 


        if(root->left==NULL && root->right==NULL){
            ans.push_back(to_string(root->val));
            return ans;
        }
        dfs(ans,root->left,to_string(root->val));
        dfs(ans,root->right,to_string(root->val));

        return ans;
    }
};