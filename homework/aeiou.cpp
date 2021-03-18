#include <iostream>

#define SIZE 510

using namespace std;

int main(){

    int target = 0;
    long long int dp[SIZE][5] = {0};

    cin >> target;

    for(int i = 0 ; i < 5 ; ++i){
        dp[1][i] = 1;
    }

    dp[2][0] = 5;
    
    for(int i = 2 ; i <= target ; ++i){
        long long int sum = 0;
        for(int j = 0 ; j < 5 ; ++j){
            if(j){
                dp[i][j] += dp[i][j-1] - dp[i-1][j-1];
            }
            sum += dp[i][j];
        }
        dp[i+1][0] = sum;
    }

    cout << dp[target + 1][0] << '\n';

    return 0;
}
