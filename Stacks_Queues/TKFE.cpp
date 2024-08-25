# include <vector>
# include <unordered_map>
# include <queue>
# include <cstdio>
# include <iostream>
# include <regex>
using namespace std;

class Solution {
public:
    class MyMinHeap{
    public:
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto n : nums) {
            freq[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyMinHeap> pq;
        for (auto nums_freq: freq) {
            pq.push(nums_freq);
            if (pq.size() > k) pq.pop();
        }
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pq.top().first;
            pq.pop();
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
        if (! scanf("%d", &k)) break;
        getline(cin, input);
        Solution obj;
        vector<int> result = obj.topKFrequent(nums, k);
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