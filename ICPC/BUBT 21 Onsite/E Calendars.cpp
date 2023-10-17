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

int main(){
  int nc;
  cin >> nc;
  vector<vector<int>> v(nc+1);
  vector<int> sumArr(nc+1);

  for(int i=1; i<=nc; i++){
    int p, sum = 0;
    cin >> p;
    v[i].push_back(p);
    for(int j=0; j<p; j++){
      int x;
      cin >> x;
      sum += x;
      v[i].push_back(x);
    }
    sumArr[i] = sum;
  }

  int q;
  cin >> q;

  for(int i=0; i<q; i++){
    int cal1, cal2, dd, mm, yy;
    cin >> cal1 >> cal2 >> dd >> mm >> yy;

    int day1 = sumArr[cal1] * (yy-1);
    for(int j=1; j<mm; j++){
      day1 += v[cal1][j];
    }
    day1 += dd;
    int yy2 = (day1 + sumArr[cal2] - 1) / sumArr[cal2];
    day1 = day1%sumArr[cal2] ? day1%sumArr[cal2] : sumArr[cal2];

    int mm2 = 0;
    for(int j=1; j<=v[cal2][0]; j++){
      mm2++;
      if(day1 - v[cal2][j] > 0){
        day1 = day1 - v[cal2][j];
      }else{
        break;
      }
    }
    cout << day1 <<" "<< mm2 <<" "<< yy2 <<"\n";
  }
}