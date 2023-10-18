// https://bapsoj.org/contests/icpc-preliminary-dhaka-site-2023-mock/problems/B
// I solve this after the contest. Don't know it will accept or not.
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long k, k2, ct = 0, a, b;
bool ans = false;

void sol(int n, int p, vector<long long> &v){
  if(n<p) return;

  for(int i=1; i<=p; i++){
    if(k - v[n-i]>1){
      k = k - v[n-i] - 1;
      ct = ct + v[n-i] + 1;
      continue;
    }else{
      ct++;
      k--;
      if(ct == k2){
        ans = true;
        a = n;
        b = n-i;
        break;
      }
      sol(n-i, p, v);
      break;
    }
    cout << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  for(int i=1; i<=t; i++){
    int n, p;
    cin >> n >> p >> k;
    k2 = k; ct = 0; ans = false;
    vector<long long> v(n+2, 0);
    
    for(int i=p; i<=n; i++){
      v[i] = p;
      for(int j=1; j<=p; j++){
        if(i-j>=p){
          v[i] += v[i-j];
        }else{
          break;
        }
      }
    }

    sol(n, p, v);
    if(ans){
      cout << "Case "<< i <<": "<< a <<" "<< b <<"\n";
    }else{
      cout << "Case "<< i <<": "<< "Invalid"<<"\n";
    }
  }
}
