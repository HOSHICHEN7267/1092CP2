#include <iostream>
#define SIZE 1010

using namespace std;

int main(){

    int lena = 0, lenb = 0;
    int a[SIZE] = {}, b[SIZE] = {};
    int dp[SIZE][SIZE] = {0};
    int output = 0;
    
    cin >> lena;
    for(int i = 0 ; i < lena ; ++i){
        cin >> a[i];
    }

    cin >> lenb;
    for(int i = 0 ; i < lenb ; ++i){
        cin >> b[i];
    }

    for(int i = 0 ; i < lena ; ++i){
        for(int j = 0 ; j < lenb ; ++j){
            if(a[i] == b[j]){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i-1][j-1] + 1;
                }

                if(dp[i][j] > output) output = dp[i][j];
            }

            //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n';
        }
    }

    cout << output << '\n'; 

    return 0;
}
