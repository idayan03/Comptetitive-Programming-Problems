#include <iostream>
#include <bitset>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> split_number(int);

vector<int> split_number(int num) {
    vector<int> result;
    bitset<32> x(num);

    vector<int> a_indices;
    vector<int> b_indices;

    bool a_or_b = 0; // 0 for a and 1 for b

    for (size_t i = 0; i < x.size(); i++) {
        if (x[i] == 1 && a_or_b == 0) {
            a_indices.push_back(i);
            a_or_b = 1;
        } else if (x[i] == 1 && a_or_b == 1) {
            b_indices.push_back(i);
            a_or_b = 0;
        }
    }

    bitset<32> a_bit;
    bitset<32> b_bit;

    for (size_t i = 0; i < a_indices.size(); i++) {
        a_bit[a_indices[i]] = 1;
    }

    for (size_t i = 0; i < b_indices.size(); i++) {
        b_bit[b_indices[i]] = 1;
    }

    int a = (int) (a_bit.to_ulong());
    int b = (int) (b_bit.to_ulong());
    result.push_back(a);
    result.push_back(b);

    return result;
}

int main(int argc, char *argv[]) {
    int n;
    while (cin >> n) {
      if (n == 0) {
        break;
      }

      vector<int> result = split_number(n);
      cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}
