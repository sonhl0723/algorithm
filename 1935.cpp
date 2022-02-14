#include <iostream>
#include <stack>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;

double cal(double a, double b, char opt){
    if(opt=='+') return a+b;
    else if(opt=='-') return a-b;
    else if(opt=='*') return a*b;
    else if(opt=='/') return a/b;
    else return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, idx=0;
    double value, a, b;
    string input;
    char ch[101];
    map<char, double> m;
    stack<double> i;

    cin >> N;
    cin >> input;
    strcpy(ch,input.c_str());

    while(N--){
        cin >> value;
        m.insert(make_pair(65+idx, value));
        idx++;
    }
    idx=0;
    while(idx<input.length()){
        if(ch[idx]>=65 && ch[idx]<=90) i.push(m[ch[idx]]);
        else{
            a = i.top();
            i.pop();
            b = i.top();
            i.pop();
            i.push(cal(b, a, ch[idx]));
        }
        idx++;
    }

    cout << fixed;
    cout.precision(2);
    cout << i.top() << '\n';

    return 0;
}