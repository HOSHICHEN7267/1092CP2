#include <iostream>
#include <algorithm>

#define SIZE 100010

using namespace std;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[SIZE] = {0};
    int cnt = 0;
    int l = 0;
    int sum = 0;
    int max = 0;

    while(cin >> arr[cnt]){
        ++cnt;
    }
    
    sum += arr[0];

    for(int i = 1 ; i < cnt ; ++i){
        if(count(arr + l, arr + i - 1, arr[i])){
            while(arr[l] != arr[i]){
                sum -= arr[l];
                ++l;
            }
            sum -= arr[l];
            ++l;
        }
        sum += arr[i];
        if(sum > max) max = sum;
    }

    cout << max << '\n';

    return 0;
}
