# include <cstdio>
# include <iostream>
# include <string>
# include <queue>
# include <sstream>
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
    int height(TreeNode* cur) {
        if (cur == NULL) return 0;
        int leftHeight = height(cur->left);
        int rightHeight = height(cur->right);
        if (leftHeight == -1 || rightHeight == -1) return -1;
        if (abs(leftHeight - rightHeight) > 1) return -1;
        else return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) == -1 ? false : true;
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
            queue<TreeNode*> q;
            getline(ss, token, ',');
            root = new TreeNode(stoi(token));
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
        Solution obj;
        if (obj.isBalanced(root)) {
            printf("true\n");
        } else printf("false\n");
    }
    return 0;
}