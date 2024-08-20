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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next && cur->next->next) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            ListNode* tmpNext = cur->next->next;
            cur->next->next = tmp;
            tmp->next = tmpNext;
            cur = tmp;
        }
        return dummyHead->next;
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
        ListNode* result = obj.swapPairs(dummyHead->next);
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