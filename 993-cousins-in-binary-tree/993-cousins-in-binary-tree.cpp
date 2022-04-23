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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> parents(2,0);
        vector<int> level(2,0);
        
        findParentLevel(root, -1, 0, x, y, parents, level);
        return parents[0]!=parents[1] && level[0] == level[1];

        
    }
    
    void findParentLevel(TreeNode* root, int currentParent, int currentLevel,int x, int y, vector<int> &parents, vector<int> &level){
        if(root == NULL){
            return;
        }
        
        if(parents[0] != 0 && parents[1]!=0){
            return;
        }
        
        if(root->val == x){
            parents[0] = currentParent;
            level[0] = currentLevel;
        }
         if(root->val == y){
            parents[1] = currentParent;
            level[1] = currentLevel;
        }
        
        findParentLevel(root->left, root->val, currentLevel+1,x, y, parents, level);
        findParentLevel(root->right, root->val, currentLevel+1,x, y, parents, level);

        
        
        
    }
};