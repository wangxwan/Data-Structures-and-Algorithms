# include <vector>
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
    void traversal(TreeNode* cur, vector<int>& result) {
        if (cur == NULL) return;
        traversal(cur->left, result);
        traversal(cur->right, result);
        result.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
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
            queue<TreeNode*> q;
            stringstream ss(input.substr(1, input.size() - 2));
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
        vector<int> result = obj.postorderTraversal(root);
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