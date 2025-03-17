// jai shree ram

/*

1. find total no. of nodes
2. find address of node x
3. find number of nodes on left and right side

*/

class Solution {
    TreeNode *X;
    void dfs(TreeNode* root , int &c , int x) {
        if(root == NULL)
            return;
        if(root -> val == x) {
            X = root;
        }
        c++;
        dfs(root -> left , c , x);
        dfs(root -> right , c , x);
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int total = 0;
        int c = 0;
        dfs(root , c , x);
        total = c;
        int left = 0;
        int right = 0;
        int s = 0;
        dfs(X->left , left , x);
        dfs(X->right , right , x);
        if(total - left < left || total - right < right || total - left - right - 1 > left + right + 1) {
            return true;
        }
        return false;
    }
};
