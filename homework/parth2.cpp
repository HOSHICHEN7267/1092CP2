#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){

    char input;
    int cnt = 0;
    vector<char> vec;
    stack<int> tmp;

    while(cin >> input){
        if(input == '('){
            vec.push_back(input);
            tmp.push(cnt);
            ++cnt;
        }
        else if(input == ')'){
            if(!tmp.empty()){
                tmp.pop();
                vec.push_back(input);
                ++cnt;
            }
        }
        else{
            vec.push_back(input);
            ++cnt;
        }
    }

    while(!tmp.empty()){
        vec.erase(vec.begin() + tmp.top());
        --cnt;
        tmp.pop();
    }

    for(int i = 0 ; i < cnt ; ++i){
        cout << vec[i];
    }

    cout << '\n';

    return 0;
}
