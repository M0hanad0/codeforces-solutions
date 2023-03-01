#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define REP(i, n) for (size_t i = 0; i < (n); i++)

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  vector<int> scores;
  size_t particpiants_count, cutoff;
  cin >> particpiants_count >> cutoff;

  REP(_, particpiants_count) {
    int score;
    cin >> score;

    scores.push_back(score);
  }

  auto advancing_participants =
      std::count_if(std::begin(scores), std::end(scores), [&](auto score) {
        return score > 0 && score >= scores[cutoff - 1];
      });

  cout << advancing_participants << "\n";

  return 0;
}
