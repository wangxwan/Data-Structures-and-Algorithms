# include <vector>
# include <queue>
# include <cstdio>
# include <iostream>
# include <regex>
# include <limits>
using namespace std;

class Solution {
private:
    class MyQueue{
    public:
        deque<int> q;

        void push(int val) {
            while(!q.empty() && q.back() < val) {
                q.pop_back();
            }
            q.push_back(val);
        }

        void pop(int val) {
            if (!q.empty() && q.front() == val) {
                q.pop_front();
            }
        }

        int front() {
            return q.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue q;
        vector<int> result;
        int i = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                q.push(nums[i]);
            } else {
                q.pop(nums[i - k]);
                q.push(nums[i]);
            }
            if (i >= k - 1) result.push_back(q.front());
        }
        return result;
    }
};

int main()
{
    while(true) {
        printf("nums = ");
        string input;
        if (!getline(cin, input)) break;
        regex pattern("-?[0-9]+");
        smatch match;
        vector<int> nums;
        while(regex_search(input, match, pattern)) {
            nums.push_back(stoi(match[0]));
            input = match.suffix().str();
        }
        printf("k = ");
        int k;
        scanf("%d", &k);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Solution obj;
        vector<int> result = obj.maxSlidingWindow(nums, k);
        printf("[");
        for (int i = 0; i < result.size(); i++) {
            printf("%d", result[i]);
            if (i != result.size() - 1) {
                printf(",");
            }
        }
        printf("]\n");
    }
    return 0;
}