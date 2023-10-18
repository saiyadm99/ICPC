#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
using namespace std;
const int N = 1e3+10;
const int INF = 1e9 + 10;

const int MAX_LIMIT = 1000; // Adjust this limit as needed

// Function to generate prime numbers using Sieve of Eratosthenes
vector<int> generatePrimes() {
  vector<bool> isPrime(MAX_LIMIT + 1, true);
  vector<int> primes;

  for (int p = 2; p * p <= MAX_LIMIT; ++p) {
    if (isPrime[p]) {
      for (int i = p * p; i <= MAX_LIMIT; i += p) {
        isPrime[i] = false;
      }
    }
  }

  for (int p = 2; p <= MAX_LIMIT; ++p) {
    if (isPrime[p]) {
      primes.push_back(p);
    }
  }
  return primes;
}

// Function to find prime factors using precomputed primes
set<int> primeFactor(const vector<int>& v, const vector<int>& primes) {
  set<int> st;
  for (int i = 0; i < v.size(); i++) {
    int n = v[i];
    for (int prime : primes) {
      if (prime * prime > n) break;
      while (n % prime == 0) {
        st.insert(prime);
        n /= prime;
      }
    }
    if (n > 1) {
      st.insert(n);
    }
  }
  return st;
}

int findGCD(const vector<int>& numbers) {
  int result = numbers[0];
  for (int i = 1; i < numbers.size(); i++) {
    result = __gcd(result, numbers[i]);
  }
  return result;
}

bool isDividable(int n, vector<int>& v){
  for(int i=0; i<v.size(); i++){
    if(v[i] % n != 0) return false;
  }
  return true;
}

string sol(vector<int> primes){
  int n;
  cin >> n;
  vector<int> v1(n), v2(n);
  for(int i=0; i<n; i++){
    cin >> v1[i];
  }
  for(int i=0; i<n; i++){
    cin >> v2[i];
  }
  string s1 = "Yes", s2 = "Yes";
  set<int> st1 = primeFactor(v1, primes);
  set<int> st2 = primeFactor(v2, primes);

  // Check if set2 is a subset of set1
  bool isSubset = includes(st1.begin(), st1.end(), st2.begin(), st2.end());
  if(!isSubset) s1 = "No";

  int gcd = findGCD(v1);
  set<int> stGcd = primeFactor({gcd}, primes);
  for(auto it : stGcd){
    while(isDividable(it, v1)){
      for(int i=0; i<n; i++){
        v1[i] = v1[i] / it;
      }
    }

    while(isDividable(it, v2)){
      for(int i=0; i<n; i++){
        v2[i] = v2[i] / it;
      }
    }
  }

  for(int i=0; i<n; i++){
    if(v1[i] != v2[i]){
      s2 = "No";
      break;
    }
  }
  return s1 +" "+ s2;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  vector<int> primes = generatePrimes();
  for(int i=1; i<=t; i++){
    cout << "Case " << i << ": " << sol(primes) <<"\n";
  }
}


// Without sieve algorithm "Not Accepted" - TLE..
/*
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
using namespace std;
const int N = 1e3+10;
const int INF = 1e9 + 10;

set<int> primeFactor(int s, vector<int> v){
  set<int> st;
  for(int i=0; i<s; i++){
    int n = v[i];

    while (n % 2 == 0) {
      st.insert(2);
      n /= 2;
    }

    // Check for odd prime factors from 3 to the square root of n
    for (int i = 3; i*i <= n; i += 2) {
      while (n % i == 0) {
        st.insert(i);
        n /= i;
      }
    }

    // If n is still greater than 1, it's a prime factor
    if (n > 1) {
      st.insert(n);
    }
  }  
  return st;
}

int findGCD(const vector<int>& numbers) {
  int result = numbers[0];
  for (int i = 1; i < numbers.size(); i++) {
    result = __gcd(result, numbers[i]);
  }
  return result;
}

bool isDividable(int n, vector<int>& v){
  for(int i=0; i<v.size(); i++){
    if(v[i] % n != 0) return false;
  }
  return true;
}

string sol(){
  int n;
  cin >> n;
  vector<int> v1(n), v2(n);
  for(int i=0; i<n; i++){
    cin >> v1[i];
  }
  for(int i=0; i<n; i++){
    cin >> v2[i];
  }
  string s1 = "Yes", s2 = "Yes";
  set<int> st1 = primeFactor(n, v1);
  set<int> st2 = primeFactor(n, v2);

  // Check if set2 is a subset of set1
  bool isSubset = includes(st1.begin(), st1.end(), st2.begin(), st2.end());
  if(!isSubset) s1 = "No";

  int gcd = findGCD(v1);
  set<int> stGcd = primeFactor(1, {gcd});
  for(auto it : stGcd){
    while(isDividable(it, v1)){
      for(int i=0; i<n; i++){
        v1[i] = v1[i] / it;
      }
    }

    while(isDividable(it, v2)){
      for(int i=0; i<n; i++){
        v2[i] = v2[i] / it;
      }
    }
  }

  for(int i=0; i<n; i++){
    if(v1[i] != v2[i]){
      s2 = "No";
      break;
    }
  }
  return s1 +" "+ s2;
}

int main(){
  int t;
  cin >> t;
  for(int i=1; i<=t; i++){
    cout << "Case " << i << ": " << sol() <<"\n";
  }
}
*/