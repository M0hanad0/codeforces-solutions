#include <iostream>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  size_t weight;
  std::cin >> weight;

  std::cout << (weight > 2 && weight % 2 == 0 ? "YES" : "NO") << std::endl;

  return 0;
}
