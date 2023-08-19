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

    pair<int , int> diameter(TreeNode* root){
        if(root == NULL)
        {
            pair<int,int>p = make_pair(0,0);
            return p;
            
        }

        pair<int,int> left = diameter(root->left);
        pair<int,int>right = diameter(root->right);

        int ans1 = left.first;
        int ans2 = right.first;

        int ans3 = left.second + right.second;

        pair<int,int> ans;
        ans.first = max(ans1 , max(ans2,ans3));
        ans.second = max(left.second , right.second) +1;

        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
     return diameter(root).first;
    }
};