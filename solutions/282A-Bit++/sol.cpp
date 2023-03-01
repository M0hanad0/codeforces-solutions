#include <cassert>
#include <iostream>
#include <optional>
using namespace std;

#define REP(i, n) for (size_t i = 0; i < (n); i++)

enum struct Statement { INCREMENT, DECREMENT };

std::optional<Statement> parse_statement(const std::string &str) {
  if (str == "++X" || str == "X++")
    return Statement::INCREMENT;
  if (str == "--X" || str == "X--")
    return Statement::DECREMENT;
  return {};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int x = 0;

  size_t statements_count;
  cin >> statements_count;

  REP(_, statements_count) {
    std::string line;
    cin >> line;

    auto statement = parse_statement(line);

    if (statement) {
      switch (statement.value()) {
      case Statement::INCREMENT:
        ++x;
        break;
      case Statement::DECREMENT:
        --x;
        break;
      default: {
        assert(false && "Unreachable");
      }
      }
    }
  }

  cout << x << "\n";

  return 0;
}
