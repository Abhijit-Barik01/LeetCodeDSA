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
    int maxD;
    unordered_map<int,int>mp;
    void Depth(TreeNode* root,int d)
    {   
        if(root == NULL)
            return;
        
        mp[root->val]=d;
        maxD =max(maxD,d);
        Depth(root->left,d+1);
        Depth(root->right,d+1);
    }

    TreeNode* findLCA(TreeNode* root)
    {
        if(root == NULL || mp[root->val]== maxD)
            return root;
         TreeNode* l= findLCA(root->left);
         TreeNode* r= findLCA(root->right);

         if(l != NULL && r !=NULL)
            return root;

        if( l!= NULL)
            return l;
        

    return r;
        
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        Depth(root,0);
        return findLCA(root);
        
    }
};