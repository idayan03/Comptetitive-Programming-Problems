#include <iostream>
#include <vector>
#include <string>

using namespace std;

int min_moves(vector<int> set) {
    int sum_of_elements = 0;
    for (unsigned i = 0; i < set.size(); i++) {
        sum_of_elements += set[i];
    }

    vector<int> new_vec;
    int height = sum_of_elements / set.size();
    for (unsigned i = 0; i < set.size(); i++) {
        int moves_needed = height - set[i];
        new_vec.push_back(moves_needed);
    }

    int min_moves = 0;
    for (unsigned i = 0; i < new_vec.size(); i++) {
        if (new_vec[i] > 0) {
            min_moves += new_vec[i];
        }
    }
    return min_moves;
}

int main() {
    vector<vector<int> > sets;
    int input;

    while (cin >> input) {
        if (input == 0) {
            break;
        }

        vector<int> set;
        int stack;
        for (unsigned i = 0; i < input; i++) {
            cin >> stack;
            set.push_back(stack);
        }

        sets.push_back(set);
    }

    for (unsigned i = 0; i < sets.size(); i++) {
        cout << "Set #" << i + 1 << endl;
        cout << "The minimum number of moves is " << min_moves(sets[i]) << "." << endl;
        cout << endl;
    }

    return 0;
}
