# include <cstdio>
# include <iostream>
# include <regex>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode* i = fast;
                ListNode* j = head;
                while(i != j) {
                    i = i->next;
                    j = j->next;
                }
                return i;
            }
        }
        return NULL;
    }
};

int main()
{
    while(true) {
        printf("head = ");
        string input;
        if (!getline(cin, input)) break;
        string number;
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        regex pattern("-?[0-9]+");
        smatch match;
        while(regex_search(input, match, pattern)) {
            ListNode* newNode = new ListNode(stoi(match[0]));
            cur->next = newNode;
            cur = cur->next;
            input = match.suffix().str();
        }
        ListNode* head = dummyHead->next;
        delete dummyHead;
        printf("pos = ");
        int pos;
        scanf("%d", &pos);
        getline(cin, input);
        ListNode* tail = cur;
        cur = head;
        int index;
        if (pos != -1) {
            index = 0;
            while(pos--) {
                cur = cur->next;
                index++;
            }
            tail->next = cur;
        }
        Solution obj;
        ListNode* result = obj.detectCycle(head);
        if (result && result == cur) {
            printf("tail connects to node index %d\n", index);
        } else if (!result) {
            printf("no cycle\n");
        }
    }
    return 0;
}