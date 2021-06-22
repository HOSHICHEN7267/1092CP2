#include <iostream>
#define SIZE 8000

using namespace std;

int main(){
    int coin[5] = {1, 5, 10, 25, 50};
    int dp[SIZE] = {0};
    int target = 0;

    while(cin >> target){
        for(int i = 0 ; i <= target ; ++i){
            dp[i] = 1;
        }
    
        for(int i = 1 ; i < 5 ; ++i){
            for(int j = coin[i] ; j <= target ; ++j){
                dp[j] += dp[j - coin[i]];
            }
        }

        cout << dp[target] << '\n';
    }

    return 0;
}
