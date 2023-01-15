
class Solution {
public:
    int ans=0;

    pair<int,int>solve(TreeNode*root){
        if(root==NULL)return {0,0};

        pair<int,int>left=solve(root->left);
        int left_sum=left.first;
        int left_size=left.second;

        pair<int,int>right=solve(root->right);
        int right_sum=right.first;
        int right_size=right.second;

        int sum=left_sum+right_sum+root->val;
        if(sum/(1+left_size+right_size)==root->val){
            ans++;
        }
        return {sum,(1+left_size+right_size)};


    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
        
    }
};
