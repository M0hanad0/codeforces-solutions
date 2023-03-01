#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)

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
