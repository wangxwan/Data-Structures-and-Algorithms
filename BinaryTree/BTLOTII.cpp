# include <vector>
# include <queue>
# include <algorithm>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int count = q.size();
            vector<int> level;
            while(count--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                level.push_back(node->val);
            }
            result.push_back(level);
        }
        reverse(result.begin(), result.end());
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
        vector<vector<int>> result = obj.levelOrderBottom(root);
        printf("[");
        for (int i = 0; i < result.size(); i++) {
            printf("[");
            for (int j = 0; j < result[i].size(); j++) {
                printf("%d", result[i][j]);
                if (j != result[i].size() - 1) {
                    printf(",");
                }
            }
            printf("]");
            if (i != result.size() - 1) {
                printf(",");
            }
        }
        printf("]\n");
    }
    return 0;
}