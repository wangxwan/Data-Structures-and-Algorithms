# include <vector>
# include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        if (root == NULL) return result;
        s.push(root);
        while(!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            result.push_back(cur->val);
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
        queue<TreeNode*> q;
        stringstream ss(input.substr(1, input.size() - 2));
        string token;
        TreeNode* root = NULL;
        getline(ss, token, ',');
        if (input != "[]") {
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
        vector<int> result = obj.preorderTraversal(root);
        printf("[");
        for (int i = 0; i < result.size(); i++) {
            printf("%d", result[i]);
            if (i != result.size() - 1) {
                printf(",");
            }
        }
        printf("]\n");
    }
    return 0;
}