#include <iostream>

using namespace std;

int main(){

    int l = 0, r = 0;
    int ans = 0;
    int num = 0;
    int cntl = 1, cntr = 1;

    cin >> l >> r;

    int tmp = l;
    while(tmp > 0){
        ++cntl;
        tmp >>= 1;
    }

    tmp = r;
    while(tmp > 0){
        --cntl;
        if(cntl == 0){
            cout << 0 << '\n';
            return 0;
        }
        tmp >>= 1;
    }

    /*if(cntr > cntl){
        //cout << "cntr: " << cntr << " cntl: " << cntl << '\n';
        cout << 0 << '\n';
        return 0;
    }*/

    ans = l;

    for(int i = l + 1 ; i <= r ; ++i){
        ans &= i;
    }

    cout << ans << '\n';

    return 0;
}
