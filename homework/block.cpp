#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define SIZE 30

using namespace std;

int main(){

    int num = 0;
    int a = 0, b = 0;
    int posai = 0, posaj = 0, posbi = 0, posbj = 0;
    string order1;
    string order2;

    while(cin >> num){

        vector<vector<int>> vec(SIZE);

        for(int i = 0 ; i < num ; ++i){
            vec[i].push_back(i);
        }

        while(cin >> order1 && order1 != "quit"){

            cin >> a >> order2 >> b;

            //cout << order1 << " " << a << " " << order2 << " " << b << '\n';

            if(a != b){
                for(int i = 0 ; i < num ; ++i){
                    for(int j = 0 ; j < vec[i].size() ; ++j){
                        if(a == vec[i][j]){
                            posai = i;
                            posaj = vec[i].size() - j - 1;
                        }
                        if(b == vec[i][j]){
                            posbi = i;
                            posbj = vec[i].size() - j - 1;
                        }
                    }
                }

                if(posai == posbi){
                    continue;
                }

                if(order1 == "move" && order2 == "onto"){
                    for(int i = 0 ; i < posaj ; ++i){
                        int last = vec[posai].back();
                        vec[last].push_back(last);
                        vec[posai].pop_back();
                    }

                    for(int i = 0 ; i < posbj ; ++i){
                        int last = vec[posbi].back();
                        vec[last].push_back(last);
                        vec[posbi].pop_back();
                    }

                    vec[posbi].push_back(a);
                    vec[posai].pop_back();
                }
                else if(order1 == "move" && order2 == "over"){
                    for(int i = 0 ; i < posaj ; ++i){
                        int last = vec[posai].back();
                        vec[last].push_back(last);
                        vec[posai].pop_back();
                    }

                    vec[posbi].push_back(a);
                    vec[posai].pop_back();
                }
                else if(order1 == "pile" && order2 == "onto"){
                    stack<int> tmp;

                    for(int i = 0 ; i <= posaj ; ++i){
                        int last = vec[posai].back();
                        tmp.push(last);
                        vec[posai].pop_back();
                    }

                    for(int i = 0 ; i < posbj ; ++i){
                        int last = vec[posbi].back();
                        vec[last].push_back(last);
                        vec[posbi].pop_back();
                    }

                    while(!tmp.empty()){
                        vec[posbi].push_back(tmp.top());
                        tmp.pop();
                    }
                }
                else if(order1 == "pile" && order2 == "over"){
                    stack<int> tmp;

                    for(int i = 0 ; i <= posaj ; ++i){
                        int last = vec[posai].back();
                        tmp.push(last);
                        vec[posai].pop_back();
                    }

                    while(!tmp.empty()){
                        vec[posbi].push_back(tmp.top());
                        tmp.pop();
                    }

                }
            }        
        }

        for(int i = 0 ; i < num ; ++i){
            cout << i << ": ";
            for(int j = 0 ; j < vec[i].size() ; ++j){
                cout << vec[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}
