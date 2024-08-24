# include <queue>
# include <string>
# include <iostream>
# include <regex>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int count = q.size() - 1;
        while(count--) {
            q.push(q.front());
            q.pop();
        }
        int result = q.front();
        q.pop();
        return result;
    }
    
    int top() {
        int result = this->pop();
        q.push(result);
        return result;
    }
    
    bool empty() {
        if (q.empty()) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
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
        MyStack* obj = new MyStack();
        int indexPara = 0;
        printf("[");
        for (int i = 0; i < operations.size(); i++) {
            if (i != 0) printf(", ");
            if (operations[i] == "MyStack") {
                printf("null");
            } else if (operations[i] == "push") {
                obj->push(parameters[indexPara++]);
                printf("null");
            } else if (operations[i] == "pop") {
                printf("%d", obj->pop());
            } else if (operations[i] == "top") {
                printf("%d", obj->top());
            } else if (operations[i] == "empty") {
                if (obj->empty()) printf("true");
                else printf("false");
            }
        }
        printf("]\n");
    }
    return 0;
}