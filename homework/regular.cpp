#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){

    string target;
    string regular;
    queue<char> tq;
    queue<char> rq;

    cin >> target >> regular;

    for(int i = 0 ; i < target.length() ; ++i){
        tq.push(target[i]);
    }

    for(int i = 0 ; i < regular.length() ; ++i){
        if(regular[i+1] == '*'){
            if(regular[i] == '.'){
                cout << "true\n";
                return 0;
            }
            rq.push('A' + (regular[i] - 'a'));
            ++i;
        }
        else{
            rq.push(regular[i]);
        }
    }

    while(!tq.empty() && !rq.empty()){
        if(rq.front() >= 'A' && rq.front() <= 'Z'){
            while('a' + (rq.front() - 'A') == tq.front() && !tq.empty()){
                tq.pop();
            }
            rq.pop();
        }
        else if(rq.front() == '.'){
            tq.pop();
            rq.pop();
        }
        else{
            if(rq.front() == tq.front()){
                tq.pop();
                rq.pop();
            }
            else{
                cout << "false\n";
                //cout << "alphabet doesn't match\n";
                return 0;
            }
        }
    }

    if(tq.empty()){
        while(!rq.empty()){
            if(rq.front() >= 'A' && rq.front() <= 'Z'){
                rq.pop();
            }
            else{
                cout << "false\n";
                //cout << "run out of alphabet\n";
                return 0;
            }
        }
        cout << "true\n";
    }
    else if(rq.empty()){
        cout << "false\n";
        //cout << "run out of regular\n";
    }
}
