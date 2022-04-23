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
    bool isSymmetric(TreeNode* root) {
        return equal(root->left, root->right);
    }
    
    bool equal(TreeNode* p, TreeNode* q){
        if(p == NULL && q==NULL){
            return true;
        }
        if((p==NULL ) || ( q==NULL)){
            return false;
        }
        
        if(p->val != q->val){
            return false;
        }
        bool leftStruct = equal(p->left, q->right);
        bool rightStruct = equal(q->left, p->right);
            
        return leftStruct && rightStruct;
    }
};