# include <unordered_set>
# include <cstdio>
using namespace std;

class Solution {
public:
    int squareSum(int n) {
        int sum = 0;
        while(n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> sum;
        while(true) {
            n = squareSum(n);
            if (n == 1) return true;
            if (sum.find(n) != sum.end()) return false;
            sum.insert(n);
        }
    }
};

int main()
{
    while(true) {
        printf("n = ");
        int n;
        if (scanf("%d", &n) != 1) break;
        Solution obj;
        if (obj.isHappy(n)) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    return 0;
}