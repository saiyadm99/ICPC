//https://algo.codemarshal.org/contests/dhaka-22/problems/I
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long dfs(long long k, long long n){
  if(k==1) return 1;
  if(k==2 || k==3) return 2;
  if(k==4) return 4;
  if(k==n) return n;

  if(k <= n/2){
    return dfs(k, n/2);
  }else{
    return dfs(k - n/2, n/2) * 2;
  }
} 

long long sol(){
  long long k, n;
  scanf("%lld %lld", &k, &n);

  long long row = 4;
  for(int i=0; i<n; i++){
    row = row*2;
  }

  if(k>row) return -1;
  return dfs(k, row);
}

int main() {
  int t;
  scanf("%d", &t);
  for(int i=1; i<=t; i++){
    printf("Case %d: %lld\n", i, sol());
  }
}

