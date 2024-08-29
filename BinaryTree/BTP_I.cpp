# include <vector>
# include <string>
# include <stack>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        stack<TreeNode*> sTree;
        stack<string> sStr;
        sTree.push(root);
        sStr.push(to_string(root->val));
        while(!sTree.empty()) {
            TreeNode* cur = sTree.top();
            sTree.pop();
            string path = sStr.top();
            sStr.pop();
            if (!cur->left && !cur->right) {
                result.push_back(path);
            }
            if (cur->right) {
                sTree.push(cur->right);
                sStr.push(path + "->" + to_string(cur->right->val));
            }
            if (cur->left) {
                sTree.push(cur->left);
                sStr.push(path + "->" + to_string(cur->left->val));
            }
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