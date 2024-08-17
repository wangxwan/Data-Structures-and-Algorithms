# include <cstdio>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        while(left <= right) {
            int middle = left + ((right - left) / 2);
            if (middle < x / middle) {
                left = middle + 1;
            } else if (middle > x / middle) {
                right = middle - 1;
            } else {
                return middle;
            }
        }
        return right;
    }
};

int main()
{
    while(true) {
        printf("x = ");
        int x;
        if (scanf("%d", &x) != 1) {
            break;
        }
        Solution obj;
        printf("%d\n", obj.mySqrt(x));
    }
    return 0;
}