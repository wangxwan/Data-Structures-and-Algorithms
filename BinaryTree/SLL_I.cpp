# include <stack>
# include <queue>
# include <string>
# include <cstdio>
# include <iostream>
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
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        if (root == NULL) return result;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            if (cur->left && !cur->left->left && !cur->left->right) {
                result += cur->left->val;
            }
            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
        }
        return result;
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
            queue<TreeNode*> q;
            string token;
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
        int result = obj.sumOfLeftLeaves(root);
        printf("%d\n", result);
    }
    return 0;
}