#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);

  for(int j=1; j<=t; j++){
    int n;
    scanf("%d", &n);

    vector<int> v(n);

    for(int i=0; i<n; i++){
      scanf("%d", &v[i]);
    }

    long long sum = 0;
    int sumMin = -10001000;
    for(int i=0; i<n; i++){
      if(v[i]>0){
        sum += v[i];
      }else{
        sumMin = max(sumMin, v[i]);
      } 
    }

    if(sum == 0){
      printf("Case %d: %d %d\n", j, sumMin, 0);
      continue;
    }

    int start = 0, end = 0;

    for(int i=0; i<n; i++){
      if(v[i]>0){
        start = i;
        break;
      }
    }

    for(int i=n-1; i>=0; i--){
      if(v[i]>0){
        end = i;
        break;
      }
    }

    int ct = 0;
    while(start<end){
      if(v[start]<0){
        ct++;
        while(start<end && v[start] <= 0){
          start++;
        }
      }
      start++;
    }
    printf("Case %d: %lld %d\n", j, sum, ct);
  }
}