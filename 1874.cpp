#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, check=1, input, idx=0;
    vector<int> v;
    vector<char> v1;
    stack<int> s;
    cin >> N;

    while(N--){
        cin >> input;
        v.push_back(input);
    }

    while(idx<v.size()){
        if(s.empty()){
            s.push(check);
            v1.push_back('+');
            check++;
        }
        else if(v[idx]==s.top()){
            v1.push_back('-');
            s.pop();
            idx++;
        }
        else{
            s.push(check);
            v1.push_back('+');
            check++;
        }
        if(check>v.size()+1){
            cout << "NO" << endl;
            return 0;
        }
    }
    // }

    for(int i=0; i<v1.size(); i++){
        cout << v1[i] << '\n';
    }
    
    return 0;
}