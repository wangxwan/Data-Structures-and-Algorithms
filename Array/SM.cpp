# include <vector>
# include <iostream>
# include <cstdio>
# include <string>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size(), m = matrix[0].size();
        int direction = 1;
        int left = 0, right = m - 1, top = 0, bottom = n - 1;
        while(result.size() < m * n) {
            switch(direction) {
                case 1:
                    for (int i = left; i <= right; i++) {
                        result.push_back(matrix[top][i]);
                    }
                    top++;
                    direction = 2;
                    break;
                
                case 2:
                    for (int i = top; i <= bottom; i++) {
                        result.push_back(matrix[i][right]);
                    }
                    right--;
                    direction = 3;
                    break;
                
                case 3:
                    for (int i = right; i >= left; i--) {
                        result.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                    direction = 4;
                    break;
                
                case 4:
                    for (int i = bottom; i >= top; i--) {
                        result.push_back(matrix[i][left]);
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
        printf("matrix = ");
        vector<vector<int>> matrix;
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
                    matrix.push_back(row);
                    row.clear();
                }
            }
        }
        Solution obj;
        vector<int> result = obj.spiralOrder(matrix);
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