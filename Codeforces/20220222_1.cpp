#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    char input;
    bool flag;
    list<char> l;
    list<char>::iterator it;
    cin >> N;

    while(N--){
        flag=false;

        for(int i=0; i<6; i++){
            cin >> input;
            if(input>97) l.push_back(input);
            else{
                it=find(l.begin(), l.end(), input+32);
                if(it==l.end()) flag=true;
            }
        }

        if(flag) cout << "NO" << '\n';
        else cout << "YES" << '\n';

        while(!l.empty()) l.pop_back();
    }

    return 0;
}