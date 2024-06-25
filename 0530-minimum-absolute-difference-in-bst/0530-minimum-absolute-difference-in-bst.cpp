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
    int mini = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL){
            return 0 ;
        }
        int prev = -1;

        TreeNode* curr = root;
        stack<TreeNode*>st ; 
        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode *temp = st.top();
                st.pop();
                if(prev!=-1)
                    mini = min(mini, temp->val-prev);
                prev=temp->val;

                curr=temp->right;
            }
        }
        return mini;
    }
};