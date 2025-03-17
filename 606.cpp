// jai shree ram
class Solution {
    string f(TreeNode*node) {
        if(node == NULL) {
            return "";
        }
        string t = to_string(node -> val);
        if(node -> left == NULL && node -> right == NULL) {
            return t;
        }
        string left = (node -> left) ? '(' + f(node -> left) + ')': "()";
        string right = (node -> right) ? '(' + f(node -> right) + ')': "";
        return t + left + right;
    }
public:
    string tree2str(TreeNode* root) {
        return f(root);
    }
};
