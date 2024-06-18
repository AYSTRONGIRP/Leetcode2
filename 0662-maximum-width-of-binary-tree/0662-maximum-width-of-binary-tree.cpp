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
    // int ans = 0 ;
    // int rmax =INT_MIN ;
    // int lmin = INT_MAX ;

    // void widthOfBinaryTreeUtil(TreeNode* root , int width) {
    //     if(root==NULL)
    //         return ;
        
    //     if(width>rmax)
    //         rmax=width;
        
    //     if(width<lmin)
    //         lmin=width;
        
    //     widthOfBinaryTreeUtil(root->left,width-1);
    //     widthOfBinaryTreeUtil(root->right,width+1);

    // }
    int widthOfBinaryTree(TreeNode* root) {
       
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});

        long long diff = INT_MIN;
        while(!q.empty()){
            int k = q.size();
            long long minl = INT_MAX;

            for(int i = 0 ; i < k ; i++){
                auto it = q.front();
                q.pop();
                minl = min(minl,it.second);
                
                if(it.first->left)
                    q.push({it.first->left,2*(it.second-minl) +1});

                if(it.first->right)
                    q.push({it.first->right,2*(it.second-minl) +2});

                if(minl!=it.second){
                    diff = max(diff,it.second-minl+1);
                    cout<<it.second << " -- " <<minl <<endl;
                    cout<<"diff"<<diff<<endl;
                }
                else{
                    if(diff<1)
                        diff = 1 ;
                }

            }
        }
        return diff;
    }
};