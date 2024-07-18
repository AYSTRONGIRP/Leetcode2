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
    vector<int> getDistances(TreeNode* root, int dist){

        if(root==NULL)
            return {};

        if(root->left == NULL && root->right == NULL)
            return {1};

        vector<int> l ;
        l = getDistances(root->left, dist);
        vector<int> r = getDistances(root->right, dist);

        for(auto& it : l) {
            int more = upper_bound(r.begin(), r.end(), dist - it) - r.begin();
            // cout<<more<<endl;
            ans += more;
            it++;
        }
        
        for(auto& it : r) {
            it++;
        }

        l.insert(l.end(), r.begin(), r.end());
        sort(l.begin(),l.end());
        return l;
    }

    int countPairs(TreeNode* root, int distance) {
        
        getDistances(root, distance);
        return ans;
    }
};
