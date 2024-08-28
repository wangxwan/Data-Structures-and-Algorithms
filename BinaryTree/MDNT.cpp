# include <vector>
# include <queue>
# include <string>
# include <cstdio>
# include <iostream>
# include <sstream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        int depth = 0;
        for (int i = 0; i < root->children.size(); i++) {
            depth = max(depth, maxDepth(root->children[i]));
        }
        return depth + 1;
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
            stringstream ss(input.substr(1, input.size()- 2));
            string token;
            getline(ss, token, ',');
            root = new Node(stoi(token));
            queue<Node*> q;
            q.push(root);
            getline(ss, token, ',');
            while(!q.empty()) {
                Node* cur = q.front();
                q.pop();
                if (getline(ss, token, ',')) {
                    while(token != "null") {
                        Node* child = new Node(stoi(token));
                        cur->children.push_back(child);
                        q.push(child);
                        if (!getline(ss, token, ',')) break;
                    }
                }
            }
        }
        Solution obj;
        int result = obj.maxDepth(root);
        printf("%d\n", result);
    }
    return 0;
}