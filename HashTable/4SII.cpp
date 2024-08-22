# include <vector>
# include <unordered_map>
# include <cstdio>
# include <iostream>
# include <regex>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int, int> ijSum;
        for (auto i : nums1) {
            for (auto j : nums2) {
                ijSum[i + j]++;
            }
        }
        for (auto k : nums3) {
            for (auto l : nums4) {
                if (ijSum.find(0 - k - l) != ijSum.end()) {
                    count += ijSum[0 - k - l];
                }
            }
        }
        return count;
    }
};

vector<int> strToArr(string input) {
    vector<int> nums;
    regex pattern("-?[0-9]+");
    smatch result;
    while(regex_search(input, result, pattern)) {
        nums.push_back(stoi(result[0]));
        input = result.suffix().str();
    }
    return nums;
}

int main()
{
    while(true) {
        printf("nums1 = ");
        string input;
        if (!getline(cin, input)) break;
        vector<int> nums1 = strToArr(input);
        printf("nums2 = ");
        if (!getline(cin, input)) break;
        vector<int> nums2 = strToArr(input);
        printf("nums3 = ");
        if (!getline(cin, input)) break;
        vector<int> nums3 = strToArr(input);
        printf("nums4 = ");
        if (!getline(cin, input)) break;
        vector<int> nums4 = strToArr(input);
        Solution obj;
        int result = obj.fourSumCount(nums1, nums2, nums3, nums4);
        printf("%d\n", result);
    }
    return 0;
}