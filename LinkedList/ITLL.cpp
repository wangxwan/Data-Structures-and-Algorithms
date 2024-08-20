# include <cstdio>
# include <iostream>
# include <string>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* headLong = headA;
        ListNode* headShort = headB;
        ListNode* curLong = headA;
        ListNode* curShort = headB;
        int lengthDiff = 0;
        while(curLong && curShort) {
            curLong = curLong->next;
            curShort = curShort->next;
        }
        if (curLong == nullptr) {
            swap(curLong, curShort);
            swap(headLong, headShort);
        }
        while(curLong) {
            curLong = curLong->next;
            lengthDiff++;
        }
        curLong = headLong;
        curShort = headShort;
        while(lengthDiff--) {
            curLong = curLong->next;
        }
        while(curLong) {
            if (curLong == curShort) {
                return curLong;
            } else {
                curLong = curLong->next;
                curShort = curShort->next;
            }
        }
        return NULL;
    }
};

int main()
{
    while(true) {
        printf("intersectVal = ");
        int intersectVal;
        if (scanf("%d", &intersectVal) != 1) break;
        string input;
        getline(cin, input);
        printf("listA = ");
        string inputA;
        if (!getline(cin, inputA)) break;
        string number;
        ListNode* dummyHeadA = new ListNode(0);
        ListNode* curA = dummyHeadA;
        for (auto c : inputA) {
            if (isdigit(c)) {
                number += c;
            } else {
                if (!number.empty()) {
                    ListNode* newNode = new ListNode(stoi(number));
                    curA->next = newNode;
                    curA = curA->next;
                    number.clear();
                }
            }
        }

        printf("listB = ");
        string inputB;
        if (!getline(cin, inputB)) break;
        printf("skipA = ");
        int skipA;
        if (scanf("%d", &skipA) != 1) break;
        printf("skipB = ");
        int skipB;
        if (scanf("%d", &skipB) != 1) break;
        ListNode* dummyHeadB = new ListNode(0);
        ListNode* curB = dummyHeadB;
        int count = 0;
        for (auto c : inputB) {
            if (isdigit(c)) {
                number += c;
            } else {
                if (!number.empty()) {
                    ListNode* newNode = new ListNode(stoi(number));
                    curB->next = newNode;
                    curB = curB->next;
                    number.clear();
                    if (++count == skipB) {
                        break;
                    }
                }
            }
        }

        curA = dummyHeadA;
        if (intersectVal) {
            while(skipA--) {
                curA = curA->next;
            }
            curB->next = curA->next;
        }

        Solution obj;
        ListNode* result = obj.getIntersectionNode(dummyHeadA->next, dummyHeadB->next);
        if (result) {
            printf("Intersected at '%d'\n", result->val);
        } else {
            printf("No intersection\n");
        }
    }
    return 0;
}