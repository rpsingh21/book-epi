// problem
// Find all prime number which is less then n

#include <deque>
#include <iostream>
#include <vector>

using std::cout;
using std::deque;
using std::endl;
using std::vector;

vector<int> GeneratePrimes(int n) {
  vector<int> primes;
  deque<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p < n; ++p) {
    if (is_prime[p]) {
      primes.push_back(p);
      for (int i = p; i <= n; i += p) {
        is_prime[i] = false;
      }
    }
  }
  return primes;
}

int main(int argc, char* argv[]) {
    vector<int> v = GeneratePrimes(20);
    for (int i=0;i<v.size();i++)
        cout << v[i] << '\n';
  return 0;
}

// Time complexity = O(nloglog(n))
