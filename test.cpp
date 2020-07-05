#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  cin.ignore();

  while(n--){
    string example;
    getline(cin, example);
    example += "\n";

    stack<char> stc;

    for(char c : example){
      if(c == ' ' || c == '\n'){
        while(!stc.empty()){
          cout << stc.top();
          stc.pop();
        }
        cout << c;
      }
      else{
        stc.push(c);
      }
    }
  }

  return 0;
}

// struct Stack{
//   int data[10000];
//   int size;
//
//   Stack(){
//     size = 0;
//   }
//
//   void push(int new_element){
//     data[size] = new_element;
//     size += 1;
//   }
//
//   int pop(){
//     if(empty()){
//       return -1;
//     }
//     else{
//       size -= 1;
//       return data[size];
//     }
//   }
//
//   bool empty(){
//     if(size==0){
//       return true;
//     }
//     else{
//       return false;
//     }
//
//   }
//
//   int top(){
//     if(empty()){
//       return -1;
//     }
//     else{
//       return data[size-1];
//     }
//   }
// };
//
// int main(){
//   int n;
//   cin >> n;
//
//   Stack stc;
//
//   while(n--){
//     string  inst;
//     cin >> inst;
//
//     if(inst == "push"){
//       int a;
//       cin >> a;
//       stc.push(a);
//     }
//     else if(inst == "pop"){
//       cout << (stc.empty() ? -1 : stc.top()) << '\n';
//       if(!stc.empty()){
//         stc.pop();
//       }
//     }
//     else if(inst == "size"){
//       cout << stc.size << '\n';
//     }
//     else if(inst == "top"){
//       cout << (stc.empty() ? -1 : stc.top()) << '\n';
//     }
//     else if(inst == "empty"){
//       cout << stc.empty() << '\n';
//     }
//   }
//
//   return 0;
// }
