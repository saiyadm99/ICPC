#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  for(int i=1; i<=t; i++){
    string s;
    cin >> s;

    int size = s.size();
    int run = 0, w = 0;

    for(int i=0; i<size; i++){
      if(s[i] == 'W'){
        w++;
      }else{
        run += s[i] - '0';
      }
    }
    
    int over = size/6, ball = size%6;
  
    cout << over <<"."<<ball<<( size>6 ? " Overs " : " Over ");
    cout << run <<(run < 2 ? " Run " : " Runs ");
    cout << w << (w < 2 ? " Wicket." : " Wickets.")<<"\n";
  }
}