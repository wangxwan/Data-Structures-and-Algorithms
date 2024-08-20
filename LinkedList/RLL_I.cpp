# include <cstdio>
# include <iostream>
# include <string>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* aft;
        while(cur) {
            aft = cur->next;
            cur->next = pre;
            pre = cur;
            cur = aft;
        }
        return pre;
    }
};

int main()
{
    while(true) {
        printf("head = ");
        string input;
        if (!getline(cin, input)) break;
        string number;
        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;
        for (auto c : input) {
            if (isdigit(c)) {
                number += c;
            } else {
                if (!number.empty()) {
                    ListNode* newNode = new ListNode(stoi(number));
                    cur->next = newNode;
                    cur = cur->next;
                    number.clear();
                }
            }
        }
        Solution obj;
        ListNode* result = obj.reverseList(dummyHead->next);
        printf("[");
        while(result) {
            printf("%d", result->val);
            result = result->next;
            if (result) {
                printf(",");
            }
        }
        printf("]\n");
    }
    return 0;
}