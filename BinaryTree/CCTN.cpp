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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        int leftTree = 0, rightTree = 0;
        while(leftNode) {
            leftTree++;
            leftNode = leftNode->left;
        }
        while(rightNode) {
            rightTree++;
            rightNode = rightNode->right;
        }
        if (leftTree == rightTree) return (2 << leftTree) - 1;
        int leftNum = countNodes(root->left);
        int rightNum = countNodes(root->right);
        return 1 + leftNum + rightNum;
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
        int result = obj.countNodes(root);
        printf("%d\n", result);
    }
    return 0;
}