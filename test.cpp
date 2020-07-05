#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Stack{
  int data[10000];
  int size;

  Stack(){
    size = 0;
  }

  void push(int new_element){
    data[size] = new_element;
    size += 1;
  }

  int pop(){
    if(empty()){
      return -1;
    }
    else{
      size -= 1;
      return data[size];
    }
  }

  bool empty(){
    if(size==0){
      return true;
    }
    else{
      return false;
    }

  }

  int top(){
    if(empty()){
      return -1;
    }
    else{
      return data[size-1];
    }
  }
};

int main(){
  int n;
  cin >> n;

  Stack stc;

  while(n--){
    string  inst;
    cin >> inst;

    if(inst == "push"){
      int a;
      cin >> a;
      stc.push(a);
    }
    else if(inst == "pop"){
      cout << (stc.empty() ? -1 : stc.top()) << '\n';
      if(!stc.empty()){
        stc.pop();
      }
    }
    else if(inst == "size"){
      cout << stc.size << '\n';
    }
    else if(inst == "top"){
      cout << (stc.empty() ? -1 : stc.top()) << '\n';
    }
    else if(inst == "empty"){
      cout << stc.empty() << '\n';
    }
  }

  return 0;
}
