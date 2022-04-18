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
    int maxDepth(TreeNode* root) {
     return height(root);   
    }
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftAns = 1+ height(root->left);
        int rightAns = 1+height(root->right);
        
        int ans = max(leftAns, rightAns);
        return ans;
    }
};