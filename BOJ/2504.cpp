#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int check_ch(int a, int b){
    if(a==-1 && b==-2) return 2;
    else if(a==-3 && b==-4) return 3;
    else return 0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N;
    int input, tmp, tmp1, ans=0;
    bool flag=false;
    stack<int> s;
    cin >> N;
    if(N.length()==1){
        cout << 0 << '\n';
        return 0;
    }
    for(int i=0; i<N.length(); i++){
        if(N[i]==40) input=-1;
        else if(N[i]==41) input = -2;
        else if(N[i]==91) input = -3;
        else input = -4;

        if(input==-1 || input==-3) s.push(input);
        else if(s.empty()){
            if(input==-2 || input==-4){
                flag=true;
                break;
            }
        }
        else if(s.top()<0){
            tmp1=check_ch(s.top(), input);
            if(tmp1==0){
                flag=true;
                break;
            }
            s.pop();
            s.push(tmp1);
            input=-5;
        }
        else{
            tmp=s.top();
            s.pop();
            if(s.empty()){
                flag=true;
                break;
            }
            tmp1=check_ch(s.top(), input);
            if(tmp1==0){
                flag=true;
                break;
            }
            s.pop();
            s.push(tmp1);
            tmp*=s.top();
            s.pop();
            s.push(tmp);
            input=-5;
        }

        if(input==-5 && s.size()>1){
            tmp=s.top();
            s.pop();
            if(s.top()>0){
                tmp+=s.top();
                s.pop();
            }
            s.push(tmp);
        }
    }

    if(!flag){
        while(!s.empty()){
            if(s.top()<0){
                cout << 0 << '\n';
                return 0;
            }
            ans+=s.top();
            s.pop();
        }
        cout << ans << '\n';
    }
    else cout << 0 << '\n';

    return 0;
}