#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Information{
  int country;
  int number;
  int score;
};

bool comp(const Information& a, const Information& b){
  return a.score > b.score;
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int Testcase;
  cin >> Testcase;

  struct Information information[Testcase];

  for(int i = 0; i < Testcase; i++){
    int country_info, number_info, score_info;
    cin >> country_info >> number_info >> score_info;

    information[i].country = country_info;
    information[i].number = number_info;
    information[i].score = score_info;
  }

  sort(information, information + Testcase, comp);
  int check[101];
  int print_check = 0;

  memset(check, 0, sizeof(check));

  for(int i = 0; i < Testcase; i++){
    if(check[information[i].country] != 2){
      cout << information[i].country << " " << information[i].number << '\n';
      check[information[i].country]++;
      print_check++;
      if(print_check == 3){
        break;
      }
    }
    else{
      continue;
    }
  }

  return 0;
}
