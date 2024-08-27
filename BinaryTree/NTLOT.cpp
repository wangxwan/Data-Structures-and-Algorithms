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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int count = q.size();
            vector<int> level;
            while(count--) {
                Node* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for (auto node : cur->children) {
                    q.push(node);
                }
            }
            result.push_back(level);
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
        vector<vector<int>> result = obj.levelOrder(root);
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