#include <iostream>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);

  for(int i=1; i<=t; i++){
    int p, s, r;
    scanf("%d %d %d", &p, &s, &r);
    
    if(p==s && r != 1){
      printf("Case %d: No\n", i);
    }else{
      printf("Case %d: Yes\n", i);
    }
  }
  return 0;
}