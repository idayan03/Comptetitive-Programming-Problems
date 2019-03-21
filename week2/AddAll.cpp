#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n == 0) {
      break;
    }

    priority_queue<int, vector<int>, greater<int> > q;

    int num;
    for (unsigned i = 0; i < n; i++) {
      cin >> num;
      q.push(num);
    }

    int total = 0, cost = 0;
    while (q.size() > 1) {
      total = q.top();
      q.pop();
      total += q.top();
      q.pop();
      cost += total;
      q.push(total);
    }

    cout << cost << endl;
  }
}
