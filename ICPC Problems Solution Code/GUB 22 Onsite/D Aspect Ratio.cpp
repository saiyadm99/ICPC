#include <cstdio>
#include <cmath>

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 1; i <= t; i++) {
    double k;
    scanf("%lf", &k);

    // Calculate the result directly without computing xx and yy
    double ans = sqrt((1 - k * k) / (k * k - 4));

    printf("%.4lf\n", ans);
  }
  return 0;
}
