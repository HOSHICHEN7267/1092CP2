#include <iostream>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(){

    int n = 0;
    map<int, int> table;

    cin >> n;
    getchar();
    for(int i = 0 ; i < n ; ++i){
        //puts("aaa");
        int now = 0;
        set<int> tmp;
        string arr;
        stringstream buffer;
        
        getline(cin, arr);
        cin.clear();
        buffer << arr;

        while(getline(buffer, arr, ' ')){
            //cout << arr << '\n';
            now = stoi(arr);
            tmp.insert(now);

        }

        buffer.clear();
        for (set<int>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
            //cout << *it << ' ';
            ++table[*it];
        }
    }

    //cout << '\n';

    bool check = false;
    for(map<int, int>::iterator it = table.begin() ; it != table.end() ; ++it){
        if(it -> second == n){
            if(!check){
                cout << it -> first;
                check = true;
            }
            else{
                cout << ' ' << it -> first;
            }
        }
    }

    return 0;
}
