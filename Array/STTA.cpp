# include <vector>
# include <cstdio>
# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        vector<int> result;
        if (array.empty()) return result;
        int m = array[0].size(), n = array.size();
        int direction = 1;
        int left = 0, right= m - 1, top = 0, bottom = n - 1;
        while(result.size() < m * n) {
            switch(direction) {
                case 1:
                    for (int i = left; i <= right; i++) {
                        result.push_back(array[top][i]);
                    }
                    top++;
                    direction = 2;
                    break;

                case 2:
                    for (int i = top; i <= bottom; i++) {
                        result.push_back(array[i][right]);
                    }
                    right--;
                    direction = 3;
                    break;

                case 3:
                    for (int i = right; i >= left; i--) {
                        result.push_back(array[bottom][i]);
                    }
                    bottom--;
                    direction = 4;
                    break;

                case 4:
                    for (int i = bottom; i >= top; i--) {
                        result.push_back(array[i][left]);
                    }
                    left++;
                    direction = 1;
                    break;
            }
        }
        return result;
    }
};

int main()
{
    while(true) {
        printf("array = ");
        vector<vector<int>> array;
        string input;
        if (!getline(cin, input)) break;
        vector<int> row;
        string number;
        for (char c : input) {
            if (isdigit(c)) {
                number += c;
            } else if (c == ',' || c == ']') {
                if (!number.empty()) {
                    row.push_back(stoi(number));
                    number.clear();
                }
                if (c == ']' && !row.empty()) {
                    array.push_back(row);
                    row.clear();
                }
            }
        }
        Solution obj;
        vector<int> result = obj.spiralArray(array);
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