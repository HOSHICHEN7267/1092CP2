#include <bits/stdc++.h>
#define SIZE 20000

using namespace std;

int main(){

    int len = 0;
    int arr[SIZE] = {0};
    int Max = -1234578;

    cin >> len;

    for(int i = 0 ; i < len ; ++i){
        cin >> arr[i];
    }

    for(int i = 0 ; i < len ; ++i){
        int num = 1;
        for(int j = i ; j < len ; ++j){
            num *= arr[j];
            if(num > Max) Max = num;
        }
    }

    cout << Max << '\n';
}
