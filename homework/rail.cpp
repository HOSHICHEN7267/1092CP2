#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){

    int num = 0;
    int target = 0;
    queue<int> train;
    stack<int> station;

    while(cin >> num){
        int check = 0;

        while(!train.empty()){
            train.pop();
        }

        while(!station.empty()){
            station.pop();
        }

        for(int i = 1 ; i <= num ; ++i){
            train.push(i);
        }

        for(int i = 0 ; i < num ; ++i){
            cin >> target;
            if(!station.empty() && station.top() == target){
                station.pop();
            }
            else{
                while(!train.empty() && train.front() != target){
                    station.push(train.front());
                    train.pop();
                }

                if(train.empty()){
                    cout << "NIE\n";
                    check = 1;
                    ++i;
                    while(i < num){
                        cin >> target;
                        ++i;
                    }
                    break;
                }
                else{
                    train.pop();
                }
            }
        }

        if(!check){
            cout << "TAK\n";
        }
    }
}
