#include <iostream>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);

  for(int i=1; i<=t; i++){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int sum = a + b + c;

    if(sum%3 == 0){
      printf("Case %d: Peaceful\n", i);
    }else{
      printf("Case %d: Fight\n", i);
    }
  }
  return 0;
}