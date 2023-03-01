#include <iostream>
using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  size_t rows, cols;
  cin >> rows >> cols;

  cout << (rows * cols) / 2 << "\n";

  return 0;
}
