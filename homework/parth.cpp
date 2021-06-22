#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){

    int cnt = 0;
    stack<char> stk;
    queue<char> output;
    char now;

    while(cin >> now){
        if(now == '('){
            stk.push('(');
            ++cnt;
        }
        else if(now == ')'){
            if(cnt){
                stack<char> tmp;
                tmp.push(')');
                while(stk.top() != '('){
                   tmp.push(stk.top());
                   stk.pop();
                }
                tmp.push(stk.top());
                stk.pop();
                --cnt;

                while(!tmp.empty()){
                    output.push(tmp.top());
                    tmp.pop();
                }
            }
        }
        else{
            if(!cnt){
                output.push(now);
            }
            else{
                stk.push(now);
            }
        }
    }

    while(!output.empty()){
        cout << output.front();
        output.pop();
    }

    while(!stk.empty()){
        if(stk.top() != '('){
            cout << stk.top();
        }
        stk.pop();
    }

    cout << '\n';

    return 0;
}
