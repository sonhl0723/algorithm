#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <deque>

using namespace std;

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;

  while(T--){
    string Run_type;
    int exam_size;
    deque<int> dq;

    cin >> Run_type >> exam_size;

    string str_exam;

    cin >> str_exam;

    string shelter;

    for(int i = 0; i < str_exam.length(); i++){
      if(str_exam[i] >= '0' && str_exam[i] <= '9'){
        shelter += str_exam[i];
      }
      else{
        if(!shelter.empty()){
          dq.push_back(stoi(shelter));
          shelter.clear();
        }
      }
    }

    int Run_len = Run_type.length();
    int R_check = 0;
    int Error_check = 0;

    for(int k = 0; k < Run_len; k++){
      if(Run_type[k] == 'R' && R_check == 0){
        R_check++;
      }
      else if(Run_type[k] == 'R' && R_check == 1){
        R_check--;
      }
      else if(Run_type[k] == 'D' && R_check == 0 && dq.size() != 0){
        dq.pop_front();
      }
      else if(Run_type[k] == 'D' && R_check == 1 && dq.size() != 0){
        dq.pop_back();
      }
      else{
        Error_check++;
      }
    }

    if(Error_check >= 1){
      cout << "error" << '\n';
    }
    else if(R_check == 0){
      cout << '[';
      while(!dq.empty()){
        cout << dq.front();
        dq.pop_front();
        if(!dq.empty()){
          cout << ',';
        }
      }
      cout << "]\n";
    }
    else if(R_check == 1){
      cout << '[';
      while(!dq.empty()){
        cout << dq.back();
        dq.pop_back();
        if(!dq.empty()){
          cout << ',';
        }
      }
      cout <<  "]\n";
      }
    }

  return 0;
}
