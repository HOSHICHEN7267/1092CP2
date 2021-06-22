#include <iostream>
#define SIZE 1000010

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int len = 0;
    int num = 0;
    int Max = 0;
    int a = 0, b = 0;
    int arr[SIZE] = {0};
    int dp[SIZE] = {0};

    cin >> len;
    for(int i = 1 ; i <= len ; ++i){
        cin >> arr[i];
    }

    cin >> num;
    for(int i = 0 ; i < num ; ++i){
        cin >> a >> b;
        if(b > Max){
            for(int j = Max + 1 ; j <= b ; ++j){
                dp[j] = dp[j-1] + arr[j];
            }
            Max = b;
        }
        cout << dp[b] - dp[a-1] << '\n';
    }

    return 0;
}
