// Tree Boundary Traversal

// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

// Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child 
// when traversing. Do not include leaf nodes in this section.

// Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

// Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer 
// the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

class Solution {
  public:
    void traverseLeft(Node* root, vector<int> &ans){
        //base case
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left, ans);
        }
        else{
            traverseLeft(root->right, ans);
        }
    }
    
    void traverseLeaf(Node* root, vector<int> &ans){
        //base case
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    void traverseRight(Node* root, vector<int> &ans){
        //base case
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        
        if(root->right){
            traverseRight(root->right, ans);
        }
        else{
            traverseRight(root->left, ans);
        }
        
        //wapas aagye
        ans.push_back(root->data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        //left part print
        traverseLeft(root->left, ans);
        
        //traverse Leaf Nodes
        
        //left subtree
        traverseLeaf(root->left, ans);
        //right subtree
        traverseLeaf(root->right, ans);
        
        //right part print
        traverseRight(root->right, ans);
        
        return ans;
    }
};
