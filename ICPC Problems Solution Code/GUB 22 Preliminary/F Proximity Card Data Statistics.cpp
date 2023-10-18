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
  int n;
  cin >> n;

  vector<string> bloodGroup = {"A+", "A-", "AB+", "AB-", "B+", "B-", "O+", "O-"};
  unordered_map<string, vector<string>> emails;
  unordered_map<string, int> birthyears;
  unordered_map<string, int> bloods;

  for(int i=0; i<n; i++){
    string s;
    for(int i=0; i<4; i++){
      string temp;
      cin >> temp;
      s += temp;
      if(i != 3) s += " ";
    }

    string year = s.substr(6, 4);
    string month = s.substr(3, 2);
    string day = s.substr(0, 2);
    string hour = s.substr(11, 8);
    string time = year+month+day+hour;
    string email = s.substr(20, 25);
    string birthYear = s.substr(51, 4);
    string blood = s.substr(56, s.size()-56);

    if(emails.count(email)>0){
      if(time > emails[email][0]){
        emails[email] = {time, birthYear, blood};
      }
    }else{
      emails[email] = {time, birthYear, blood};
    }
  }

  for(auto it : emails){
    string birthyear = it.second[1];
    string blood = it.second[2];
    birthyears[birthyear]++;
    bloods[blood]++;
  }

  for(auto it : bloodGroup){
    cout << it <<" "<< bloods[it] <<"\n";
  }

  vector<pair<string, int>> vec;

  for(auto it : birthyears){
    vec.push_back({it.first, it.second});
  }
  sort(vec.begin(), vec.end());

  for(auto it : vec){
    cout << it.first <<" "<< it.second <<"\n";
  }
}


//01/02/2023#15:58:31 2022100011006@seu.edu.bd 28/07/2001 A+
//day/month/year#hour:minute:second

// string year = s.substr(6, 4);
// string month = s.substr(3, 2);
// string day = s.substr(0, 2);
// string hour = s.substr(11, 8);
// string time = year+month+day+hour;
// string email = s.substr(20, 25);
// string birth = s.substr(45, 10);
// string blood = s.substr(56, s.size()-56);


