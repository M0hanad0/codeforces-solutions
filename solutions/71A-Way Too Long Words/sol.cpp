#include <iostream>
#include <sstream>

bool too_long(const std::string &str) { return str.length() > 10; }
std::string abbr(const std::string &str) {
  std::ostringstream os;
  os << str[0] << str.length() - 2 << str[str.length() - 1];
  return os.str();
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif

  size_t words_count = 0;
  std::cin >> words_count;

  for (size_t i = 0; i < words_count; i++) {
    std::string word;
    std::cin >> word;
    std::cout << (too_long(word) ? abbr(word) : word) << "\n";
  }
  return 0;
}
