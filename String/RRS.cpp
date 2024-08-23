# include <cstdio>
# include <iostream>
# include <string>
using namespace std;

void reverse(string& s, int left, int right) {
    while(left < right) {
        swap(s[left++], s[right--]);
    }
}

int main()
{
    int k;
    scanf("%d", &k);
    string s;
    cin >> s;
    reverse(s, 0, s.size() - 1);
    reverse(s, 0, k - 1);
    reverse(s, k, s.size() - 1);
    printf("%s", s.c_str());
    return 0;
}