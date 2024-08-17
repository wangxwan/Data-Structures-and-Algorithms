# include <cstdio>

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while(left <= right) {
            int middle = left + ((right - left) / 2);
            if (middle < double(num) / double(middle)) {
                left = middle + 1;
            } else if (middle > double(num) / double(middle)) {
                right = middle - 1;
            } else return true;
        }
        return false;
    }
};

int main()
{
    while(true) {
        printf("num = ");
        int num;
        if (scanf("%d", &num) != 1) {
            break;
        }
        Solution obj;
        if (obj.isPerfectSquare(num)) {
            printf("true\n");
        } else printf("false\n");
    }
    return 0;
}