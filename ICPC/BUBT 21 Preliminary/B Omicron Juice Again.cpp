#include <iostream>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);

  for(int i=1; i<=t; i++){
    int a, b, c, k;
    scanf("%d %d %d %d", &a, &b, &c, &k);
    int sum = a/k + b/k + c/k;

    if(sum%3 == 0 && a%k==b%k && b%k==c%k && a%k==c%k){
      printf("Case %d: Peaceful\n", i);
    }else{
      printf("Case %d: Fight\n", i);
    }
  }
  return 0;
}