# include <cstdio>
# include <string>
# include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* slowIndex = dummyHead;
        ListNode* fastIndex = dummyHead;
        while(n--) {
            fastIndex = fastIndex->next;
        }
        while(fastIndex && fastIndex->next) {
            fastIndex = fastIndex->next;
            slowIndex = slowIndex->next;
        }
        ListNode* tmp = slowIndex->next;
        slowIndex->next = tmp->next;
        delete tmp;
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main()
{
    while(true) {
        printf("head = ");
        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;
        string input;
        if (!getline(cin, input)) break;
        string number;
        for (auto c : input) {
            if (isdigit(c)) {
                number += c;
            } else {
                if (!number.empty()) {
                    ListNode* newNode = new ListNode(stoi(number));
                    number.clear();
                    cur->next = newNode;
                    cur = cur->next;
                }
            }
        }
        printf("n = ");
        int n;
        scanf("%d", &n);
        getline(cin, input);
        Solution obj;
        ListNode* result = obj.removeNthFromEnd(dummyHead->next, n);
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