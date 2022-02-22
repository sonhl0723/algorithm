#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    char ch[100001];
    stack<char> s;
    int ans=0, flag=1, idx=0;   //flag=1일 경우 바로 이전 element가 '('임을 나타낸다.

    cin >> input;
    strcpy(ch,input.c_str());

    while(idx<input.length()){
        if(ch[idx]=='('){
            flag=1;
            s.push(ch[idx]);
        }
        else{
            s.pop();
            if(flag==1 && !s.empty()){
                ans+=s.size();
            }
            else if(flag==0) ans++;
            flag=0;
        }
        idx++;
    }

    cout << ans << '\n';

    return 0;
}