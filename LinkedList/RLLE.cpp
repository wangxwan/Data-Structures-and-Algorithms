# include <cstdio>
# include <iostream>
# include <regex>
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main()
{
    while(true) {
        printf("head = ");
        ListNode* head = nullptr;
        ListNode* cur;
        string input;
        if (!getline(cin, input)) break;
        regex pattern("[0-9]+");
        smatch result;
        while(regex_search(input, result, pattern)) {
            if (head == nullptr) {
                head = new ListNode(stoi(result[0]));
                cur = head;
            } else {
                cur->next = new ListNode(stoi(result[0]));
                cur = cur->next;
            }
            input = result.suffix().str();
        }
        printf("val = ");
        int val;
        scanf("%d", &val);
        getline(cin, input);
        Solution obj;
        head = obj.removeElements(head, val);
        cur = head;
        printf("[");
        while(cur != nullptr) {
            printf("%d", cur->val);
            cur = cur->next;
            if (cur != nullptr) {
                printf(",");
            }
        }
        printf("]\n");
    }
}