# include <iostream>
# include <vector>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> land(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> land[i][j];
        }
    }

    vector<int> horizontal;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += land[i][j];
        }
        horizontal.push_back(sum);
    }
    vector<int> vertical;
    sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += land[j][i];
        }
        vertical.push_back(sum);
    }

    int minDiff = INT_MAX;
    for (int i : horizontal) {
        minDiff = min(minDiff, abs(horizontal.back() - i - i));
    }
    for (int i : vertical) {
        minDiff = min(minDiff, abs(vertical.back() - i - i));
    }
    printf("%d\n", minDiff);
    return 0;
}