// Construct Tree from Inorder & Preorder
  
// Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.

// Note: The output is written in postorder traversal.

// Examples:

// Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
// Output: [8, 7, 6, 1]


class Solution{
    // Recursive function to build the binary tree.
    Node *buildTreeRecur(unordered_map<int,int> &mp, vector<int> &preorder, int &preIndex, int left, int right) {
    
        // For empty inorder array, return null
        if (left > right)
            return nullptr;
    
        int rootVal = preorder[preIndex];
        preIndex++;
    
        // create the root Node
        Node *root = new Node(rootVal);
    
        // find the index of Root element in the in-order array.
        int index = mp[rootVal];
    
        // Recursively create the left and right subtree.
        root->left = buildTreeRecur(mp, preorder, preIndex, left, index - 1);
        root->right = buildTreeRecur(mp, preorder, preIndex, index + 1, right);
    
        return root;
    }
    
    // Function to construct tree from its inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    	
      	// Hash map that stores index of a root element in inorder array
      	unordered_map<int,int> mp;
      	for (int i = 0; i < inorder.size(); i++) 
          	mp[inorder[i]] = i;
      
      	int preIndex = 0;
        Node *root = buildTreeRecur(mp, preorder, preIndex, 0, inorder.size() - 1);
    
        return root;
    }
};
