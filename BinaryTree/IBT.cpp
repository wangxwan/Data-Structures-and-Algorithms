# include <cstdio>
# include <iostream>
# include <string>
# include <sstream>
# include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left, root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};


int main()
{
    while(true) {
        printf("root = ");
        string input;
        if (!getline(cin, input)) break;
        TreeNode* root = NULL;
        if (input != "[]") {
            stringstream ss(input.substr(1, input.size() - 2));
            string token;
            getline(ss, token, ',');
            root = new TreeNode(stoi(token));
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();
                if (getline(ss, token, ',')) {
                    if (token != "null") {
                        cur->left = new TreeNode(stoi(token));
                        q.push(cur->left);
                    }
                } else break;
                if (getline(ss, token, ',')) {
                    if (token != "null") {
                        cur->right = new TreeNode(stoi(token));
                        q.push(cur->right); 
                    }
                } else break;
            }
        }
        queue<TreeNode*> q2;
        Solution obj;
        root = obj.invertTree(root);
        if (root) q2.push(root);
        printf("[");
        while(!q2.empty()) {
            TreeNode* cur = q2.front();
            q2.pop();
            printf("%d", cur->val);
            if (cur->left) q2.push(cur->left);
            if (cur->right) q2.push(cur->right);
            if (!q2.empty()) printf(",");
        }
        printf("]\n");
    }
    return 0;
}