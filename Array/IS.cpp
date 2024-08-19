# include <cstdio>
# include <vector>
# include <iostream>
# include <string>
using namespace std;

int main()
{
    printf("array = ");
    vector<int> array;
    string input;
    string number;
    getline(cin, input);
    for (char c : input) {
        if (isdigit(c)) {
            number += c;
        } else if (c == ',' || c == ']') {
            array.push_back(stoi(number));
            number.clear();
        }
    }
    vector<int> sum;
    int presum = 0;
    for (int i : array) {
        presum += i;
        sum.push_back(presum);
    }
    int a, b;
    while(scanf("%d%d", &a, &b) == 2) {
        if (a == 0) {
            printf("%d\n", sum[b]);
        } else {
            printf("%d\n", sum[b] - sum[a - 1]);
        }
    }
    return 0;
}