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
        return height(root);
    }
    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int ans = 0;
        
        for(auto x : root->children){
            ans = max(ans, height(x));
        }
        
        return 1+ans;
    }
};