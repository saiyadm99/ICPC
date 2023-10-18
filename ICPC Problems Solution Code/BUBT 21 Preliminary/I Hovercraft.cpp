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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // 𝐿 + 𝑊 − ( 2𝐿𝑥 − 2𝑥).
  while(true){
    double L, W;
    cin >> L >> W;
    if(L == 0 && W == 0) break;
    double totalDist = L + W;

    for(double x=0; x<L/2; x = x+0.005){
      double l = L/2 + x;
      double a = L - l;
      double b = sqrt(l*l - a*a);
      double y = W-b;
      double dist = 2 * l + y;
      totalDist = min(totalDist, dist);
    }

    cout << fixed << setprecision(4) << totalDist << "\n";
  }

}