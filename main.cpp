#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using ql = queue<ll>;

ll n, w, l;
ql Q;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> w >> l;
  for (auto i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    Q.push(x);
  }

  ql on_bridge{};
  for (auto i = 0; i < w; ++i) {
    on_bridge.push(0);
  }

  ll now_load = 0;
  ll ans = 0;
  while (!on_bridge.empty()) {
    now_load -= on_bridge.front();
    on_bridge.pop();

    if (!Q.empty()) {
      if (now_load + Q.front() <= l) {
        now_load += Q.front();
        on_bridge.push(Q.front());
        Q.pop();
      } else {
        on_bridge.push(0);
      }
    }

    ++ans;
  }

  cout << ans;

  return 0;
}