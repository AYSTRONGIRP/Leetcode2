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
    int ans = 0 ;
    void dfs(TreeNode *root , string s){
        if(root==NULL){
            // ans+=
            return ; 
        }

        if(root->left== NULL && root->right== NULL){
            int num = 0 ;
            s+=to_string(root->val);
            int n = s.size();
            cout<<s<<endl;
            for(int i = n-1 ; i>=0 ; i--){
                if(s[i]=='1')
                    num+= pow(2,n-i-1);
            }
            ans+=num;
        }
        dfs(root->left,s+to_string(root->val));
        dfs(root->right,s+to_string(root->val));
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root,"");
        return ans ;
    }
};