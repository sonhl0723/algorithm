#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Deque{
  vector<int> v;
  int size;

  Deque(){
    size = 0;
  }

  void push_front(int n){
    v.insert(v.begin(), n);
    size ++;
  }

  void push_back(int n){
    v.push_back(n);
    size++;
  }

  int pop_front(){
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

  int pop_back(){
    if(v.size() == 0){
      return -1;
    }
    else{
      int end_elem = v[v.size()-1];
      v.erase(v.begin()+(v.size()-1));
      size --;
      return end_elem;
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

  Deque q;

  cin >> N;

  while(N--){
    string cmd;

    cin >> cmd;

    if(cmd == "push_front"){
      int n;
      cin >> n;
      q.push_front(n);
    }
    else if(cmd == "push_back"){
      int n;
      cin >> n;
      q.push_back(n);
    }
    else if(cmd == "pop_front"){
      cout << q.pop_front() << '\n';
    }
    else if(cmd == "pop_back"){
      cout << q.pop_back() << '\n';
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
