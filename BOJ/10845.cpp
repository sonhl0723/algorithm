#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Queue{
  vector<int> v;
  int size;

  Queue(){
    size = 0;
  }

  void push(int n){
    v.push_back(n);
    size ++;
  }

  int pop(){
    if(v.size() == 0){
      return -1;
    }
    else{
      int front_elem = v[0];
      v.erase(v.begin());
      size --;
      return front_elem;
    }
  }

  int empty(){
    if(v.size() == 0){
      return 1;
    }
    else{
      return 0;
    }
  }

  int front(){
    if(v.size() == 0){
      return -1;
    }
    else{
      return v[0];
    }
  }

  int back(){
    if(v.size() == 0){
      return -1;
    }
    else{
      return v[v.size() - 1];
    }
  }
};

int main(void){
  int N;

  Queue q;

  cin >> N;

  while(N--){
    string cmd;

    cin >> cmd;

    if(cmd == "push"){
      int n;
      cin >> n;
      q.push(n);
    }
    else if(cmd == "pop"){
      cout << q.pop() << '\n';
    }
    else if(cmd == "size"){
      cout << q.size << '\n';
    }
    else if(cmd == "empty"){
      cout << q.empty() << '\n';
    }
    else if(cmd == "front"){
      cout << q.front() << '\n';
    }
    else{
      cout << q.back() << '\n';
    }
  }

  return 0;
}
