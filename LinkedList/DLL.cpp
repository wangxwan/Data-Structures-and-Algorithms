# include <cstdio>
# include <string>
# include <iostream>
# include <vector>
# include <regex>
using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val) : val(val), next(nullptr){}
    };

private:
    ListNode* dummyHead;
    int listSize;

public:
    MyLinkedList() {
        dummyHead = new ListNode(0);
        listSize = 0;
    }
    
    int get(int index) {
        if (index >= listSize) return -1;
        ListNode* cur = dummyHead;
        while(index--) {
            cur = cur->next;
        }
        return cur->next->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        listSize++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = dummyHead;
        while(cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        listSize++;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= listSize) {
            ListNode* newNode = new ListNode(val);
            ListNode* cur = dummyHead;
            while(index--) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            listSize++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < listSize) {
            ListNode* cur = dummyHead;
            while(index--) {
                cur = cur->next;
            }
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            listSize--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    while(true) {
        string inputOper, inputPara;
        if (!getline(cin, inputOper)) break;
        if (!getline(cin, inputPara)) break;

        regex regexOper("[A-Za-z]+");
        smatch resultOper;
        vector<string> operations;
        while(regex_search(inputOper, resultOper, regexOper)) {
            operations.push_back(resultOper[0].str());
            inputOper = resultOper.suffix();
        }

        vector<int> parameters;
        string number;
        for(char c : inputPara) {
            if (isdigit(c)) {
                number += c;
            } else if (!number.empty()) {
                parameters.push_back(stoi(number));
                number.clear();
            }
        }

        MyLinkedList* obj = new MyLinkedList();
        int indexPara = 0;
        vector<string> returnResult(operations.size(), "null");
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "MyLinkedList") {
                continue;
            } else if (operations[i] == "get") {
                returnResult[i] = to_string(obj->get(parameters[indexPara++]));
            } else if (operations[i] == "addAtHead") {
                obj->addAtHead(parameters[indexPara++]);
            } else if (operations[i] == "addAtTail") {
                obj->addAtTail(parameters[indexPara++]);
            } else if (operations[i] == "addAtIndex") {
                int index = parameters[indexPara++];
                int val = parameters[indexPara++];
                obj->addAtIndex(index, val);
            } else if (operations[i] == "deleteAtIndex") {
                obj->deleteAtIndex(parameters[indexPara++]);
            }
        }

        printf("[");
        for (int i = 0; i < returnResult.size(); i++) {
            printf("%s", returnResult[i].c_str());
            if (i != returnResult.size() - 1) {
                printf(", ");
            }
        }
        printf("]\n");
        operations.clear();
        parameters.clear();
        returnResult.clear();
    }
    return 0;
}