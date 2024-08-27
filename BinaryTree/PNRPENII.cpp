# include <iostream>
# include <queue>
# include <cstdio>
# include <string>
# include <sstream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int count = q.size();
            Node* pre = NULL;
            while(count--) {
                Node* cur = q.front();
                q.pop();
                if (pre) pre->next = cur;
                pre = cur;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return root;
    }
};

int main()
{
    while(true) {
        printf("root = ");
        string input;
        if (!getline(cin, input)) break;
        Node* root = NULL;
        if (input != "[]") {
            stringstream ss(input.substr(1, input.size() - 2));
            string token;
            queue<Node*> q;
            getline(ss, token, ',');
            root = new Node(stoi(token));
            q.push(root);
            while(!q.empty()) {
                Node* cur = q.front();
                q.pop();
                if (getline(ss, token, ',')) {
                    if (token != "null") {
                        cur->left = new Node(stoi(token));
                        q.push(cur->left);
                    }
                } else break;
                if (getline(ss, token, ',')) {
                    if (token != "null") {
                        cur->right = new Node(stoi(token));
                        q.push(cur->right);
                    }
                } else break;
            }
        }
        Solution obj;
        Node* head = obj.connect(root);
        queue<Node*> q;
        if (head) q.push(head);
        printf("[");
        while(!q.empty()) {
            int count = q.size();
            while(count--) {
                Node* cur = q.front();
                q.pop();
                printf("%d", cur->val);
                if (cur->next == NULL) {
                    printf(",#");
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                if (!q.empty()) {
                    printf(",");
                }
            }
        }
        printf("]\n");
    }
    return 0;
}