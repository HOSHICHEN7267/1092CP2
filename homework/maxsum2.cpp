#include <iostream>
#include <algorithm>
#define SIZE 101

using namespace std;

int main(){

    int len = 0;
    int arr[SIZE] = {0};
    int dp[SIZE][SIZE] = {};

    cin >> len;
    for(int i = 0 ; i < len ; ++i){
        cin >> arr[i];
    }
    
    for(int i = 0 ; i < len ; ++i){
        dp[i][i] = arr[i];
    }

    for(int i = len - 1 ; i >= 0 ; --i){
        for(int j = i + 1 ; j < len ; ++j){
            dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
        }
    }

    dp[0][len-1] >= 0 ? cout << "True\n" : cout << "False\n";

    return 0;
}
