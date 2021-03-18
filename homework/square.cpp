#include <iostream>

#define SIZE 100010

using namespace std;

int main(){

    int target = 0;
    int i = 2;
    int dp[SIZE] = {};
    
    cin >> target;

    for(int j = 0 ; j < SIZE ; ++j){
        dp[j] = j;
    }
    
    while(i*i <= target){
        for(int j = i*i ; j <= target ; ++j){
            dp[j] = min(dp[j], dp[j - i*i] + 1);
        }
        ++i;
    }

    cout << dp[target] << '\n';

    return 0;
}
