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
    bool compare(TreeNode* root_sub, TreeNode* subRoot) {
        if (!root_sub && !subRoot) return true;
        else if (!root_sub || !subRoot || root_sub->val != subRoot->val) return false;
        return (compare(root_sub->left, subRoot->left) && compare(root_sub->right, subRoot->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (compare(cur, subRoot)) return true;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return false;
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
            queue<TreeNode*> q1;
            getline(ss, token, ',');
            root = new TreeNode(stoi(token));
            q1.push(root);
            while(!q1.empty()) {
                TreeNode* cur = q1.front();
                q1.pop();
                if (getline(ss, token, ',')) {
                    if (token != "null") {
                        cur->left = new TreeNode(stoi(token));
                        q1.push(cur->left);
                    }
                } else break;
                if (getline(ss, token, ',')) {
                    if (token != "null") {
                        cur->right = new TreeNode(stoi(token));
                        q1.push(cur->right);
                    }
                } else break;
            }
        }

        printf("subRoot = ");
        if (!getline(cin, input)) break;
        TreeNode* subRoot = NULL;
        if (input != "[]") {
            stringstream ss(input.substr(1, input.size() - 2));
            string token;
            queue<TreeNode*> q2;
            getline(ss, token, ',');
            subRoot = new TreeNode(stoi(token));
            q2.push(subRoot);
            while(!q2.empty()) {
                TreeNode* cur = q2.front();
                q2.pop();
                if (getline(ss, token, ',')) {
                    if (token != "null") {
                        cur->left = new TreeNode(stoi(token));
                        q2.push(cur->left);
                    }
                } else break;
                if (getline(ss, token, ',')) {
                    if (token != "null") {
                        cur->right = new TreeNode(stoi(token));
                        q2.push(cur->right);
                    }
                } else break;
            }
        }

        Solution obj;
        if (obj.isSubtree(root, subRoot)) {
            printf("true\n");
        } else printf("false\n");
    }
    return 0;
}