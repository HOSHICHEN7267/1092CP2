#include <iostream>
#define SIZE 100000

using namespace std;

int main(){

    int len = 0;
    int target = 0;
    int arr[SIZE] = {};
    int sum[SIZE] = {0};
    int minlen = 0;
    int start = 0;

    cin >> len;

    for(int i = 0 ; i < len ; ++i){
        cin >> arr[i];
    }

    cin >> target;

    sum[0] = arr[0];
    while(sum[start] < target){
        ++start;
        if(start >= len){
            cout << 0 << '\n';
            return 0;
        }
        sum[start] = sum[start-1] + arr[start];
    }

    //cout << "start: " << start << '\n';
    minlen = start + 1;
    while(sum[start] - sum[start - (minlen - 1)] > target){
        --minlen;
    }

    for(int i = start + 1 ; i < len ; ++i){
        sum[i] = sum[i-1] + arr[i];

        int nowlen = minlen + 1;
        while(sum[i] - sum[i - (nowlen - 1)] >= target){
            --nowlen;
        }

        if(nowlen < minlen) minlen = nowlen;
    }

    cout << minlen << '\n';

    return 0;
}
