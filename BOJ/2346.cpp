#include <iostream>
#include <list>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, input, idx=0;
    bool flag=true;
    pair<int,int> tmp;
    list< pair<int, int> > l;
    cin >> N;

    while(N--){
        cin >> input;
        l.push_back(make_pair(idx, input));
        idx++;
    }

    while(!l.empty()){
        if(flag){
            tmp=l.front();
            l.pop_front();
        }
        else{
            tmp=l.back();
            l.pop_back();
        }

        cout << tmp.first+1 << ' ';

        if(l.empty()) break;
        
        if(tmp.second<0){
            input=(-(tmp.second+1));
            while(input--){
                tmp=l.back();
                l.pop_back();
                l.push_front(tmp);
            }
            flag=false;
        }
        else{
            input=tmp.second-1;
            while(input--){
                tmp=l.front();
                l.pop_front();
                l.push_back(tmp);
            }
            flag=true;
        }
    }

    return 0;
}