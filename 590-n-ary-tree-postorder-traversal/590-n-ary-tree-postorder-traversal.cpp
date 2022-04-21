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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        post(root, ans);
        return ans;
        
    }
    void post(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        vector<Node*> currentNode= root->children;
        
        for(Node* currentChild : currentNode){
            post(currentChild, ans);
        }
        
        ans.push_back(root->val);
        return;
    }
};