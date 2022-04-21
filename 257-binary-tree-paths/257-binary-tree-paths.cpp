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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        path(root, "", ans);
        return ans;
    }
    
    void path(TreeNode* root, string currentPath, vector<string> &ans){
        
        // if(root == NULL){
        //     return;
        // }
        if(root->left == NULL && root->right == NULL){
            currentPath += to_string(root->val);
            ans.push_back(currentPath);
            return;
        }
        
       
        // path(root->left, currentPath + to_string(root->val) +"->", ans);
        // path(root->right,currentPath + to_string(root->val)+"->" , ans);
       if(root->left != NULL){
            path(root->left, currentPath + to_string(root->val)+"->", ans);
        }
        
        if(root->right != NULL){
            path(root->right, currentPath+ to_string(root->val)+"->" , ans);
        }

    } 
};