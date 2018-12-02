/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string.h>
#include <math.h>
int counter = 1;

int myInsert(int val, string s, TreeNode *n){
    if(s.length() == 1){
        if(s[0] == '0'){
            n->left = new TreeNode(val);
        } else {
            n->right = new TreeNode(val);
        }
        return n->val;
    } else {
        if(s[0] == '0'){
            return myInsert(val, s.substr(1), n->left);
        } else if(s[0] == '1'){
            return myInsert(val, s.substr(1), n->right);
        }
    }
}

int initCounter(TreeNode *n){
    int ans = 1;
    if(n -> left != NULL)
        ans += initCounter(n->left);
    if(n->right != NULL)
        ans += initCounter(n->right);
    return ans;
}

class CBTInserter {
public:
    TreeNode *root;
    CBTInserter(TreeNode* root) {
        this->root = root;
        counter = initCounter(root);
    }

    int insert(int v) {
        string s = "";//convert to binary
        int oriV = ++counter;
        while(oriV > 0){
            if(oriV % 2)
                s = '1' + s;
            else
                s = '0' + s;
            oriV /= 2;
        }
        return myInsert(v, s.substr(1), root);
    }

    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
