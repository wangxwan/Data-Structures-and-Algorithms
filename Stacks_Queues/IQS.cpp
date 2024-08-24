# include <stack>
# include <iostream>
# include <string>
# include <regex>
using namespace std;

class MyQueue {
public:
    stack<int> stackIn;
    stack<int> stackOut;

    MyQueue() {
        
    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
        int result = this->peek();
        stackOut.pop();
        return result;
    }
    
    int peek() {
        if (stackOut.empty()) {
            while(!stackIn.empty()) {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        return stackOut.top();
    }
    
    bool empty() {
        if (stackIn.empty() && stackOut.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
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
            operations.push_back(resultOper[0]);
            inputOper = resultOper.suffix().str();
        }
        vector<int> parameters;
        string number;
        for (auto c : inputPara) {
            if (isdigit(c)) {
                number += c;
            } else {
                if (!number.empty()) {
                    parameters.push_back(stoi(number));
                    number.clear();
                }
            }
        }
        MyQueue* obj = new MyQueue();
        int indexPara = 0;
        printf("[");
        for (int i = 0; i < operations.size(); i++) {
            if (i != 0) printf(", ");
            if (operations[i] == "MyQueue") {
                printf("null");
            } else if (operations[i] == "push") {
                obj->push(parameters[indexPara++]);
                printf("null");
            } else if (operations[i] == "pop") {
                printf("%d", obj->pop());
            } else if (operations[i] == "peek") {
                printf("%d", obj->peek());
            } else if (operations[i] == "empty") {
                if (obj->empty()) {
                    printf("true");
                } else {
                    printf("false");
                }
            }
        }
        printf("]\n");
        operations.clear();
        parameters.clear();
    }
    return 0;
}