#include <iostream>

using namespace std;

long long ksc(long long a, long long b, long long mod){

    long long ans = 0;

    while(b){
        if(b & 1){
            ans = (ans + a) % mod;
        }
        a = (a + a) % mod;
        b >>= 1;
    }

    return ans;
}

int main(){

    int line = 0;

    cin >> line;

    for(int i = 0 ; i < line ; ++i){

        long long a = 0;
        long long b = 0;
        long long mod = 0;

        cin >> a >> b >> mod;

        //cout << "a: " << a << " b: " << b << " mod: " << mod << '\n';

        long long ans = 1;
        long long base = a;

        while(b){
            if(b & 1){
                ans = ksc(ans, base, mod) % mod;
            }
            base = ksc(base, base, mod) % mod;
            b >>= 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
