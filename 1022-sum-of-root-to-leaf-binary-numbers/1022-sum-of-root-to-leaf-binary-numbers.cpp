#include<bits/stdc++.h>
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
    int sumRootToLeaf(TreeNode* root) {
        vector<int> ans(1,0);
       
        rootToLeaf(root,"" , ans);
        return ans[0];
    }
    
    void rootToLeaf(TreeNode* root, string currentPath, vector<int> &ans){
        if(root->left ==NULL && root->right == NULL){
            currentPath +=to_string(root->val);
            ans[0] += stoi(currentPath, 0, 2);
            
            return;
        }
        
       
        if(root->left != NULL){
            rootToLeaf(root->left, currentPath + to_string(root->val), ans);
        }
        
        if(root->right != NULL){
            rootToLeaf(root->right, currentPath+ to_string(root->val) , ans);
        }
        
        return;
    }
};