#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    string str, result;
    stack<char> s;

    cin.ignore();
    while(T--){
        getline(cin, str);
        result = "";

        for(int i = 0; i < str.length(); i++){
            if(str[i] == ' '){
                while(!s.empty()){
                    result = result + s.top();
                    s.pop();
                }
                result = result + ' ';
            }
            else{
                s.push(str[i]);
            }
        }

        while(!s.empty()){
            result = result + s.top();
            s.pop();
        }

        cout << result << '\n';
    }

    return 0;
}