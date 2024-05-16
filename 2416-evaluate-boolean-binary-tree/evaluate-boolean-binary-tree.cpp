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
    bool evaluateTree(TreeNode* root) {
        bool result;

        if(root->left == nullptr && root->right==nullptr)
            return root->val;
        


         if(root->val == 2){
           result =  evaluateTree(root->left) || evaluateTree(root->right);
         }
         else
         {
             result =  evaluateTree(root->left) && evaluateTree(root->right);
         }
         return result;
         }
        

};