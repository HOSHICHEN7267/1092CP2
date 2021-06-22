#include <iostream>
#include <algorithm>
#define SIZE 9

using namespace std;

int main(){

    int arr[9] = {0};
    int n = 0, k = 0;
    int cnt = 0;

    for(int i = 0 ; i < 9 ; ++i){
        arr[i] = i + 1;
    }

    cin >> n >> k;

    do{
        ++cnt;
        if(cnt == k){
            for(int i = 0 ; i < n ; ++i){
                cout << arr[i];
            }
            return 0;
        }
    }
    while(next_permutation(arr, arr + n));
}
