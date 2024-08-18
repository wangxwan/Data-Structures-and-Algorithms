# include <vector>
# include <iostream>
# include <cstdio>
# include <regex>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int result = 0;
        int leftSide = 0;
        int basket1 = -1, basket2 = -1;
        int count1 = 0, count2 = 0;
        for (int rightSide = 0; rightSide < fruits.size(); rightSide++) {
            if (basket1 == -1 || basket1 == fruits[rightSide]) {
                basket1 = fruits[rightSide];
                count1++;
            } else if (basket2 == -1 || basket2 == fruits[rightSide]) {
                basket2 = fruits[rightSide];
                count2++;
            } else {
                while(count1 != 0 && count2 != 0) {
                    if (basket1 == fruits[leftSide]) {
                        count1--;
                    } else if (basket2 == fruits[leftSide]) {
                        count2--;
                    }
                    leftSide++;
                }
                if (count1 == 0) {
                    basket1 = fruits[rightSide];
                    count1++;
                } else {
                    basket2 = fruits[rightSide];
                    count2++;
                }
            }
            result = max(result, rightSide - leftSide + 1);
        }
        return result;
    }
};

int main()
{
    while(cin.good()) {
        printf("fruits = ");
        vector<int> fruits;
        string input;
        getline(cin, input);
        regex pattern("[0-9]+");
        smatch result;
        while(regex_search(input, result, pattern)) {
            fruits.push_back(stoi(result[0]));
            input = result.suffix().str();
        }
        Solution obj;
        printf("%d\n", obj.totalFruit(fruits));
    }
    return 0;
}