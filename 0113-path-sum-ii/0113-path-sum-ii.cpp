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

class Solution {
public:
    void dfs(TreeNode *root , vector<vector<int>>& ans ,vector<int> temp , int sum , int target ){
        if(root==NULL){
            return ;
        }
        temp.push_back(root->val);

        if(root->left==NULL && root->right==NULL){
            if(sum+root->val==target)
                ans.push_back(temp);
            return ;
        }
        dfs(root->left,ans,temp,sum+root->val, target);
        dfs(root->right,ans,temp,sum+root->val, target);


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans ;
        if(root==NULL)
            return ans;
            
        if(root->left==NULL && root->right==NULL){
            if(root->val == targetSum)
                ans.push_back({root->val});
            return ans;
        }

        dfs(root,ans,vector<int>(),0, targetSum);


        return ans ;
    }
};