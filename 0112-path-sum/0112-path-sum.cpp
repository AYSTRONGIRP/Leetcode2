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
    bool helper(TreeNode* root, int targetSum , int sum){
        if(root==NULL)
            return false;
            
        if(root->left==NULL && root->right==NULL)
            return (sum+root->val)==targetSum;
        
        return helper(root->left,targetSum ,root->val+sum) || helper(root->right,targetSum ,root->val+sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;

        return helper(root,targetSum ,0);
    }
};