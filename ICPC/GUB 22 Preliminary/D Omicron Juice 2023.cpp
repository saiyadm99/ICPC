//#include <bits/stdc++.h>
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

string sol(){
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  if(a == b && b == c) return "Peaceful";
  if((a<k && b<k) || (a<k && c<k) || (b<k && c<k)) return "Fight";
  
  if((a/k + b/k + c/k)%3 == 0 && a%k == b%k && b%k == c%k){
    return "Peaceful";
  }else{
    return "Fight";
  }
}

int main(){
  int t;
  cin >> t;
  for(int i=1; i<=t; i++){
    cout << "Case " << i << ": " << sol() <<"\n";
  }
}


// Old Version
/* 
  int main(){
    int t;
    cin >> t;
    for(int i=1; i<=t; i++){
      long long a, b, c, k;
      cin >> a >> b >> c >> k;
  
      long long aa = a/k;
      long long bb = b/k;
      long long cc = c/k;
  
      long long sum = aa + bb + cc;
  
      long long am = a%k;
      long long bm = b%k;
      long long cm = c%k;
  
      if(a==b && b == c){
        cout <<"Case "<<i<<": Peaceful\n";
      }else{
        if(am == bm && bm == cm){
          if((a<k && b<k) || (a<k && c<k) || (b<k && c<k)){
            cout <<"Case "<<i<<": Fight\n";
          }else{
            if(sum%3 == 0){
            cout <<"Case "<<i<<": Peaceful\n";
            }else{
              cout <<"Case "<<i<<": Fight\n";
            }
          }
        }else{
          cout <<"Case "<<i<<": Fight\n";
        }
      }
    }
  }

*/
