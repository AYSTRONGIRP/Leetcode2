/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int count = 0 ;
        queue<Node*>q ;
        if(!root)
            return count;
            
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            for(int i = 0 ; i < k; i++){
                int n = q.front()->children.size();
                for(int j = 0 ; j< n ;j++){
                    q.push(q.front()->children[j]);
                }             
                q.pop();
            }
            count++;
        }
        return count;
    }
};