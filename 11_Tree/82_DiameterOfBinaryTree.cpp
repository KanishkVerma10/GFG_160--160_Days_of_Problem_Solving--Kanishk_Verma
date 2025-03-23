// Diameter of a Binary Tree

// Given a binary tree, the diameter (also known as the width) is defined as the number of edges on the longest path between two leaf nodes in the tree. 
// This path may or may not pass through the root. Your task is to find the diameter of the tree.

class Solution {
  public:
    int height(Node* root, int & ans){
        if(root == NULL){
            return 0;
        }
        
        // height of left subtree
        int left = height(root->left, ans);
        
        //height of right subtree
        int right = height(root->right, ans);
        
        ans = max(ans, left+right);
        
        return max(left, right) + 1;
    }
    
    int diameter(Node* root) {
        int ans = 0;
        height(root, ans);
        return ans;
    }
};
