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
#define LL long long
using namespace std;
const int N = 1e3+10;
const int INF = 1e9 + 10;

long long sol(){
  long long n, k;
  cin >> n >> k;

  vector<int> v(n), v1(n), v2(n);

  for(int i=0; i<n; i++){
    cin >> v[i];
  }

  v1[0] = v[0];
  for(int i=1; i<n; i++){
    v1[i] = v[i] + v1[i-1];
  }

  v2[0] = v1[0] + v[0];
  for(int i=1; i<n; i++){
    v2[i] = v[i] + max(v1[i], v2[i-1]);
  }

  long long d = v2[n-1] - v1[n-1];
  long long ans = v1[n-1] + d * (k-1);
  return ans;
}

int main(){
  int t;
  cin >> t;
  for(int i=1; i<=t; i++){
    cout << "Case " << i << ": " << sol() <<"\n";
  }
}

// Case 1: Peaceful
// Case 2: Fight