// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) rationalsequence3
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d", arr[_i]);                    \
      }                                           \
    }                                             \
    putchar('\n');                                \
  }
#define PBS(n, len) /*Print a bitset*/ \
  {                                    \
    for (int _i = 0; _i < len; ++_i) { \
      putchar(n % 2 + '0');            \
      n /= 2;                          \
    }                                  \
    putchar('\n');                     \
  }
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
typedef long long ll;
using namespace std;

// Tells the factors to reach in the tree.
int dir[40];

int main() {
  int p;
  GET(p);
  while (p--) {
    int k;
    ll n;
    GET(k);
    scanf("%lld", &n);
    printf("%d ", k);

    // Find the results when dividing by 2
    memset(dir, 0, sizeof(dir));
    int size;
    for (size = 0; n > 0; ++size) {
      dir[size] = n;
      n /= 2;
    }

    ll p = 1, q = 1;
    for (int i = size - 1; i > 0; --i) {
      if (dir[i - 1] == 2 * dir[i]) {
        q = p + q;
      } else {
        p = p + q;
      }
    }
    printf("%lld/%lld\n", p, q);
  }
  return 0;
}
