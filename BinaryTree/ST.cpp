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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (!p || !q || p->val != q->val) return false;
        bool isSameLeft = isSameTree(p->left, q->left);
        bool isSameRight = isSameTree(p->right, q->right);
        return (isSameLeft && isSameRight);
    }
};

int main()
{
    while(true) {
        printf("p = ");
        string input;
        if (!getline(cin, input)) break;
        TreeNode* p = NULL;
        if (input != "[]") {
            stringstream ss(input.substr(1, input.size() - 2));
            string token;
            queue<TreeNode*> q1;
            getline(ss, token, ',');
            p = new TreeNode(stoi(token));
            q1.push(p);
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

        printf("q = ");
        if (!getline(cin, input)) break;
        TreeNode* q = NULL;
        if (input != "[]") {
            stringstream ss(input.substr(1, input.size() - 2));
            string token;
            queue<TreeNode*> q2;
            getline(ss, token, ',');
            q = new TreeNode(stoi(token));
            q2.push(q);
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
        if (obj.isSameTree(p, q)) {
            printf("true\n");
        } else printf("false\n");
    }
    return 0;
}