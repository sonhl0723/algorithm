#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, input, idx=0;
    cin >> N;
    vector<int> v;
    set<int> s;
    set<int>::iterator iter;
    map<int, int> m;


    while(N--){
        cin >> input;
        v.push_back(input);
        s.insert(input);
    }

    for(iter = s.begin(); iter != s.end(); iter++){
        m.insert(make_pair(*iter, idx));
        idx++;
    }

    for(int i=0; i<v.size(); i++){
        cout << m[v[i]] << " ";
    }

    return 0;
}