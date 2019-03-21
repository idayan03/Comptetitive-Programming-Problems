#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int remove_ld(string *str) {
    if (str->length() == 1) {
        return 0;
    }

    str->erase(0, 1);
    return 1;
}

int stringLD(vector<string> input) {
    int count = 0;

    while (1) {
      vector<int> removed;
      for (unsigned i = 0; i < input.size(); i++) {
        removed.push_back(remove_ld(&input[i]));
      }

      if (find(removed.begin(), removed.end(), 0) != removed.end()) {
          break;
      }

      bool contains_dup = 0;
      for (unsigned i = 0; i < input.size() - 1; i++) {
          for (unsigned j = i + 1; j < input.size(); j++) {
              if (!input[i].compare(input[j])) {
                  contains_dup = 1;
              }
          }
      }

      if (contains_dup) {
          break;
      }

      count++;
    }
    return count;
}

int main() {
    vector<vector<string> > inputs;

    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        string str;
        vector<string> words;
        for (unsigned i = 0; i < n; i++) {
            cin >> str;
            words.push_back(str);
        }

        inputs.push_back(words);
    }

    for (unsigned i = 0; i < inputs.size(); i++) {
        cout << stringLD(inputs[i]) << endl;
    }
}
