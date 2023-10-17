#include <iostream>
using namespace std;

// Function to calculate the factorial of a number
long long factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
      result *= i;
    }
    return result;
  }
}

int main() {
  int t;
  scanf("%d", &t);

  for(int i=1; i<=t; i++){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
      int x;
      scanf("%d", &x);
    }

    printf("Case %d: %lld\n", i, factorial(n));
  }
  return 0;
}