#include <iostream>
#include <algorithm>

using namespace std;

struct Information{
  int age;
  string name;
  int join_num;
};

bool comp(const Information& a, const Information& b){
  if(a.age != b.age){
    return a.age < b.age;
  }
  else{
    return a.join_num < b.join_num;
  }
}

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int Testcase;
  cin >> Testcase;

  struct Information information[Testcase];

  for(int i = 0; i < Testcase; i++){
    int a;
    string s;
    cin >> a >> s;

    information[i].age = a;
    information[i].name = s;
    information[i].join_num = i;
  }

  sort(information, information + Testcase, comp);

  for(int i = 0; i < Testcase; i++){
    cout << information[i].age << " " << information[i].name << '\n';
  }

  return 0;
}
