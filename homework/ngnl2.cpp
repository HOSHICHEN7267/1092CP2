#include <iostream>
#include <queue>
#include <algorithm>
#define SIZE 100010

using namespace std;

int main(){

    int num = 0;
    int now = 0;
    int arr[SIZE] = {0};
    long long int sum = 0;
    int sumnum = 0;
    queue<int> tmp;
    cin >> num;

    for(int i = 0 ; i < num ; ++i){
        cin >> now;
        if(now > 0 && !arr[now]){
            tmp.push(now);
        }
        ++arr[now];
    }

    while(!tmp.empty()){
        int nn = tmp.front() * arr[tmp.front()];
        if(nn > sum){
            sum = nn;
            sumnum = tmp.front();
        }
        tmp.pop();
    }

    cout << sumnum << '\n';
    cout << sum * 10000 << '\n';

    return 0;
}
