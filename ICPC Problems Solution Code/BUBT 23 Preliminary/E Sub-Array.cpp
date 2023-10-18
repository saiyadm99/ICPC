#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  for(int i=1; i<=t; i++){
    int n;
    cin >> n;

    vector<long long> v(n);
    for(int i=0; i<n; i++){
      cin >> v[i];
    }

    long long ans = 0;
    
    for(int i=0; i<n-1; ){
      int ind = i+1;
      for(int j=i+1; j<n; j++){
        ind = j;
        if(v[i] != v[j]) break;
      }

      if(ind<n && v[i] != v[ind]){
        ans += (n - ind) * (ind - i); 
      }
     i = ind;
    }
    cout << "Case " << i <<": "<< ans <<"\n";
  }
}