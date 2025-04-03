// Spirally traversing a matrix

// You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.

vector<int> spirallyTraverse(vector<vector<int> > &mat){
    int m = mat.size();
    int n = mat[0].size();
    
    vector<int> ans;
    
    int left = 0, right = n-1, top = 0, bottom = m-1;
    
    while(top <= bottom && left <= right){
        // print top row from left to right
        for(int i=left; i<= right; i++){
            ans.push_back(mat[top][i]);
        }
        top++;
        
        // print right column from top to bottom
        for(int i=top; i<= bottom; i++){
            ans.push_back(mat[i][right]);
        }
        right--;
        
        // print bottom row from right to left
        if(top <= bottom){
            for(int i=right; i>= left; i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        
        // print left column from bottom to top
        if(left <= right){
            for(int i=bottom; i>= top; i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    
    return ans;
}
