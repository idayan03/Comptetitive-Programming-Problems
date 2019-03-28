#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector<int> sieve(int n) {
  vector<bool> primes(sqrt(2147483648));
  fill(primes.begin(), primes.end(), true);

  for (int p = 2; p * p <= sqrt(2147483648); p++) {
    if (primes[p]) {
      for (int i = p * 2; i <= sqrt(2147483648); i += p) {
        primes[i] = false;
      }
    }
  }

  vector<int> ret;
  for (int i = 2; i < primes.size(); i++) {
    if (primes[i]) {
      ret.push_back(i);
    }
  }

  return ret;
}

vector<int> get_prime_factors(int n, vector<int> primes) {
  vector<int> prime_factors;
  int temp_n = n;
  for (int i = 0; i < primes.size(); i++) {
    while (temp_n % primes[i] == 0) {
      prime_factors.push_back(primes[i]);
      temp_n /= primes[i];
    }
  }

  if (prime_factors.size() == 1) {
    prime_factors.push_back(1);
  } else if (temp_n > 1) {
    temp_n = prime_factors[prime_factors.size() - 1];
    prime_factors.push_back(temp_n);
  }

  return prime_factors;
}

int main () {
  int n;
  int c = 1;
  vector<int> primes = sieve(n);
  while (cin >> n) {
    if (n == 0) {
      return 0;
    }

    if (n == 1) {
      cout << "Case " << to_string(c) << ": " << to_string(n + 1) << endl;
      c++;
    } else if (n == 2147483647) {
      cout << "Case " << to_string(c) << ": " <<  to_string(2147483647 + 1) << endl;
      c++;
    } else {

      vector<int> prime_factors = get_prime_factors(n, primes);

      map<int, int> factors_count;
      for (int i = 0; i < prime_factors.size(); i++) {
        if (factors_count.find(prime_factors[i]) == factors_count.end()) {
          factors_count.insert(pair<int, int>(prime_factors[i], 1));
        } else {
          map<int, int>::iterator it = factors_count.find(prime_factors[i]);
          it->second += 1;
        }
      }

      int result = 0;
      map<int, int>::iterator it;
      for (it = factors_count.begin(); it != factors_count.end(); it++) {
        int factor = 1;
        for (int i = 0; i < it->second; i++) {
          factor *= it->first;
        }

        result += factor;
      }
      cout << "Case " << to_string(c) << ": " << to_string(result) << endl;
      c++;
    }
  }
  return 0;
}
