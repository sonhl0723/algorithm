#include <iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, input, idx, tmp, print_num;
    cin >> N;

    while(N--){
        cin >> input;
        int arr[input];
        for(idx=0; idx<input; idx++){
            arr[idx]=idx+1;
        }
        print_num=input;
        while(print_num--){
            for(idx=2; idx<input; idx++){
                if(arr[idx-2]+arr[idx-1]==arr[idx]){
                    tmp=arr[idx-1];
                    arr[idx-1]=arr[idx];
                    arr[idx]=tmp;
                }
            }
            for(idx=0; idx<input; idx++){
                cout << arr[idx] << ' ';
            }

            cout << '\n';
            tmp=arr[print_num];
            arr[print_num]=arr[0];
            arr[0]=tmp;
        }
    }
    
    return 0;
}