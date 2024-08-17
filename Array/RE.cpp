# include <vector>
# include <iostream>
# include <cstdio>
# include <regex>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++]= nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main()
{
    while(cin.good()) {
        printf("nums = ");
        vector<int> nums;
        string input;
        getline(cin, input);
        regex pattern("-?[0-9]+");
        smatch result;
        while(regex_search(input, result, pattern)) {
            nums.push_back(stoi(result[0]));
            input = result.suffix().str();
        }
        printf("val = ");
        int val;
        scanf("%d", &val);
        getline(cin, input);
        Solution obj;
        int size = obj.removeElement(nums, val);
        printf("%d, nums = [", size);
        for (int i = 0; i < nums.size(); i++) {
            if (i < size) {
                printf("%d", nums[i]);
            } else {
                printf("_");
            }
            if (i != nums.size() - 1) {
                printf(",");
            }
        }
        printf("]\n");
        nums.clear();
    }
    return 0;
}
