#include <iostream>
#include <cstring>
#include <stack>
#include <list>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    list< pair<int,int> > l;
    stack<int> s;
    string input;

    cin >> input;

    for(int i=0; i<input.length(); i++){
        if(input[i]=='(') s.push(i);
        else if(input[i]==')'){
            l.push_back(make_pair(s.top(), i));
            s.pop();
        }
    }

    

    return 0;
}