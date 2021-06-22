#include <iostream>
#include <stack>
#include <queue>
#define SIZE 100001

using namespace std;

int main(){

    int n = 0;
    int input = 0;
    int nowsum = 0;
    int cnt = 0;
    queue<int> num;
    queue<int> sum1;
    stack<int> sum2;
    
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> input;
        num.push(input);
        nowsum += input;
        sum1.push(nowsum);
    }
    
    sum2.push(nowsum);

    for(int i = 0 ; i < n - 1 ; ++i){
        int front = num.front();
        nowsum -= front;
        sum2.push(nowsum);
        num.pop();
    }

    while(!sum1.empty() && !sum2.empty()){
        if(sum1.front() == sum2.top()){
            ++cnt;
            sum1.pop();
            sum2.pop();
        }
        else if(sum1.front() < sum2.top()){
            sum1.pop();
        }
        else{
            sum2.pop();
        }
    }

    cout << cnt << '\n';
    
    return 0;
}
