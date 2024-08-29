# include <vector>
# include <string>
# include <cstdio>
# include <iostream>
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
    void findPath(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val);
        if (!cur->left && !cur->right) {
            result.push_back(path);
        }
        if (cur->left) findPath(cur->left, path + "->", result);
        if (cur->right) findPath(cur->right, path + "->", result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        findPath(root, path, result);
        return result;
    }
};


int main()
{
    while(true) {
        printf("root = ");
        string input;
        if (!getline(cin, input)) break;
        stringstream ss(input.substr(1, input.size() - 2));
        string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
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
        Solution obj;
        vector<string> result = obj.binaryTreePaths(root);
        printf("[");
        for (int i = 0; i < result.size(); i++) {
            printf("\"%s\"", result[i].c_str());
            if (i != result.size() - 1) printf(",");
        }
        printf("]\n");
    }
    return 0;
}