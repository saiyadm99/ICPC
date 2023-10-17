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
#include <cstring> 
using namespace std;
const int N = 1e3+10;
const int INF = 1e9 + 10;

int sol(){
  int n;
  cin >> n;
  vector<int> v(n+1);
  vector<int> colorArr(n+1);
  vector<vector<int>> g(n+1);
  for(int i=1; i<=n; i++){
    cin >> v[i];
  }

  for(int i=1; i<n; i++){
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  queue<vector<int>> q;
  q.push({1, 0, 0});
  while(!q.empty()){
    int ver = q.front()[0];
    int color = q.front()[1];
    int parent = q.front()[2];
    colorArr[ver] = color; 
    q.pop();

    for(auto it : g[ver]){
      if(it == parent) continue;
      q.push({it, color ? 0 : 1, ver});
    }
  }

  int zeroSum = 0, oneSum = 0, zeroCt = 0, oneCt = 0;
  for(int i=1; i<=n; i++){
    if(colorArr[i] == 0){
      zeroSum += v[i];
      zeroCt++;
    }else{
      oneSum += v[i];
      oneCt++;
    }
  }

  int mxSum = -1, indx = 0;

  for(int i=1; i<=n; i++){
    int sumZ = v[i] * zeroCt - zeroSum;
    int sumO = v[i] * oneCt - oneSum;
    int sum = 0;
    if(colorArr[i] == 0){
      sum = sumZ - sumO;
    }else {
      sum = sumO - sumZ;
    }

    if(sum > mxSum){
      mxSum = sum;
      indx = i;
    }
  }
  return indx;
}

int main(){
  int t;
  cin >> t;
  for(int i=1; i<=t; i++){
    cout << "Case " << i << ": " << sol() <<"\n";
  }
  return 0;
}