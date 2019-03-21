#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> d_pairs(string str, int d_dist) {
  vector<string> pairs;
  for (unsigned i = 0; i < str.length(); i++) {
    if (i + d_dist + 1 < str.length()) {
        string d_pair = "";
        d_pair += str[i];
        d_pair += str[i + d_dist + 1];
        pairs.push_back(d_pair);
    }
  }
  return pairs;
}

bool hasDuplicates(vector<string> vec_strings) {
  for (unsigned i = 0; i < vec_strings.size(); ++i) {
    for (unsigned j = i + 1; j < vec_strings.size(); ++j) {
        if (!vec_strings[i].compare(vec_strings[j]))
            return true;
    }
  }
  return false;
}

void isSurprising(string input_str) {
  unsigned j = 0;
  while (j < input_str.length()) {
    vector<string> pairs = d_pairs(input_str, j);

    if (hasDuplicates(pairs)) {
      cout << input_str << " is NOT surprising." << endl;
      return;
    }
    j++;
  }

  cout << input_str << " is surprising." << endl;
}

int main() {
    vector<string> inputs;
    string str;
    while (cin >> str) {
        if (str.compare("*") == 0) {
            break;
        }
        inputs.push_back(str);
    }

    for (unsigned i = 0; i < inputs.size(); i++) {
        isSurprising(inputs[i]);
    }
    return 0;
}
