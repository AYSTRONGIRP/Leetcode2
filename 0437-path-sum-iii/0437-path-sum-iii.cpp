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

//  bool helper(TreeNode* root, int targetSum , int sum){
//         if(root==NULL)
//             return false;
            
//         if(root->left==NULL && root->right==NULL)
//             return (sum+root->val)==targetSum;
        
//         return helper(root->left,targetSum ,root->val+sum) || helper(root->right,targetSum ,root->val+sum);
//     }
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if(root==NULL)
//             return false;

//         return helper(root,targetSum ,0);
//     }

class Solution {
public:
    int count = 0  ;
    void helper(TreeNode* root, long long targetSum , vector<long long> temp){
        if(root==NULL)
          return ;
        
        if(root->val==targetSum)
            count++;

        int k = temp.size();
        cout<<k<<endl;

        for(int i = 0 ; i<k ;i++){
            temp[i]+=root->val;

            if(temp[i]==targetSum)
                count++;
            // if(temp[i]>targetSum)
        }

        temp.push_back(root->val);

        helper(root->left,targetSum ,temp);
        helper(root->right,targetSum ,temp);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;

        if(root->left==NULL && root->right==NULL){
            // ans.push_back(to_string(root->val));
            // return ans;

            if(root->val==targetSum)
                return 1;
        }

        helper(root,targetSum ,vector<long long>());

        return count;
    }
};