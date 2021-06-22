#include <iostream>

using namespace std;

int main(){
    
    int l = 0, r = 0;
    int arr[32] = {0};
    int ans = 0;

    cin >> l >> r;

    for(int i = 31 ; i >= 0 ; --i){
        if((l & (1 << i)) == (r & (1 << i))){
            arr[i] = (l & (1 << i)) ? 1 : 0;
        }
        else{
            break;
        }
    }

    for(int i = 0 ; i < 32 ; ++i){
        if(arr[i]){
            ans += (1 << i);
        }
    }
    
    cout << ans << '\n';

    return 0;
}


