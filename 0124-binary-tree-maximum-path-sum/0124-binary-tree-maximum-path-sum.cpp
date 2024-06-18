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
    int maxi = INT_MIN ; 
    int maxPathSum(TreeNode* root) {
        int temp = maxPathSumUtil(root);

        return maxi;
    }

    int maxPathSumUtil(TreeNode* root) {
        if(root== NULL)
            return 0 ;
        int lt = maxPathSumUtil(root->left);
        int rt = maxPathSumUtil(root->right);

        if(root->left && root->right){
            maxi = max(maxi , lt+rt+root->val); 
            maxi = max(maxi, rt);
            maxi = max(maxi, lt);
            maxi = max(maxi, lt+root->val);
            maxi = max(maxi, rt+root->val);
        }else if(root->left){
            maxi = max(maxi, lt+root->val);
            maxi = max(maxi, lt);
        }else if(root->right){
            maxi = max(maxi, rt+root->val);
            maxi = max(maxi, rt);
        }
        
        maxi = max(maxi, root->val);
        
        return max(root->val,max(rt+root->val,lt+root->val));
    }
};