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
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";

        queue<pair<TreeNode*,string>> q;

        // cout<<(int)'0'<<endl;
        q.push({root,string(1, char(root->val + 97))});
        string s = "'";
        while(!q.empty()){
            int k = q.size();
            for(int i =0 ; i < k ; i++){
                if(q.front().first->left==NULL && q.front().first->right == NULL){
                    if(s!="'")
                    s = min(s,q.front().second);
                    else
                    s=q.front().second;
                }
                if(q.front().first->left)
                    q.push({q.front().first->left, string(1, char(q.front().first->left->val + 97))+q.front().second});

                if(q.front().first->right)
                    q.push({q.front().first->right, string(1, char(q.front().first->right->val + 97))+q.front().second});
                q.pop();
            } 
            // if(s!="'")
            //     return s ;

        }

        return s ;
    }
};