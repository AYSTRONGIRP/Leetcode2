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
    bool findTarget(TreeNode* root, int k) {
        TreeNode* curr = root ;
        stack<TreeNode*> st ;
        map<int,int>hash;

        while(curr!=NULL || !st.empty()){
            if(curr){
                st.push(curr);
                curr= curr->left;
            }
            else{
               TreeNode* parent = st.top();
               if(hash.find(k-parent->val)!=hash.end())
                    return true;
               cout<<parent->val<<' ';
                hash[parent->val]++;
                st.pop();
               
            //    if(parent->left==curr){
                    curr=parent->right;
            //    }
            //    curr = parent-> 
            }
        }
        return false;
    }
};