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
    queue<TreeNode*>q;
    int length=0,maxVal=INT_MIN;
    int maxLevelSum(TreeNode* root) {
        
        q.push(root);
        if(root->left == NULL && root->right ==NULL)
            return 1;
        int ans =0;
        while(!q.empty())
        {
            int n= q.size();
            int sum =0;

            while(n--)
            {
              TreeNode* temp = q.front();
              q.pop();
              sum+=temp->val;
              if(temp->left)
                q.push(temp->left);
              if(temp->right)
                q.push(temp->right);
              
            }
            length++;
            if(sum > maxVal)
            {
              maxVal=sum;
              ans = length;
            }
        }
        return ans;
    }
};