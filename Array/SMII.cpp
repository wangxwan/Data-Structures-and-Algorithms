# include <vector>
# include <cstdio>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int count = 1;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int direction = 1;
        while(count <= n * n) {
            switch(direction) {
                case 1:
                    for (int i = left; i <= right; i++) {
                        result[top][i] = count++;
                    }
                    top++;
                    direction = 2;
                    break;
                
                case 2:
                    for (int i = top; i <= bottom; i++) {
                        result[i][right] = count++;
                    }
                    right--;
                    direction = 3;
                    break;
                
                case 3:
                    for (int i = right; i >= left; i--) {
                        result[bottom][i] = count++;
                    }
                    bottom--;
                    direction = 4;
                    break;
                
                case 4:
                    for (int i = bottom; i >= top; i--) {
                        result[i][left] = count++;
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
        printf("n = ");
        int n;
        if (scanf("%d", &n) != 1) break;
        Solution obj;
        vector<vector<int>> result = obj.generateMatrix(n);
        printf("[");
        for (int i = 0; i < n; i++) {
            printf("[");
            for (int j = 0; j < n; j++) {
                printf("%d", result[i][j]);
                if (j != n - 1) {
                    printf(",");
                }
            }
            printf("]");
            if (i != n - 1) {
                printf(",");
            }
        }
        printf("]\n");
        result.clear();
    }
    return 0;
}