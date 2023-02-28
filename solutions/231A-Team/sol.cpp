#include <iostream>

using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int problems_count;
  cin >> problems_count;

  size_t problems = 0;
  REP(_, problems_count) {
    bool p, v, t;
    cin >> p >> v >> t;

    if (p + v + t >= 2)
      problems++;
  }
  cout << problems << "\n";

  return 0;
}
