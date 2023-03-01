#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

const double EPSILON = 1e-9;
const int INF = 1 << 29;

typedef long long ll;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for (size_t i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)

inline bool EQ(double a, double b) { return fabs(a - b) < EPSILON; }
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int &n, int b) { n |= two(b); }
inline void unset_bit(int &n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
  int res = 0;
  while (n && ++res)
    n -= n & (-n);
  return res;
}

template <class T> void chmax(T &a, const T &b) { a = max(a, b); }
template <class T> void chmin(T &a, const T &b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  const int matrix_rows = 5, matrix_cols = 5;

  FOR(row, 1, matrix_rows) {
    FOR(col, 1, matrix_cols) {
      bool n;
      cin >> n;

      if (n) {
        cout << std::abs(row - 3) + std::abs(col - 3) << "\n";
        return 0;
      }
    }
  }

  return 1;
}
