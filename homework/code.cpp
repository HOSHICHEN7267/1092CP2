#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define SIZE 500

using namespace std;

string next(string lock, int dir){
    switch(dir){
        case 1:
            lock[0] == '0' ? lock[0] = '9' : --lock[0];
            return lock;
        case 2:
            lock[0] == '9' ? lock[0] = '0' : ++lock[0];
            return lock;
        case 3:
            lock[1] == '0' ? lock[1] = '9' : --lock[1];
            return lock;
        case 4:
            lock[1] == '9' ? lock[1] = '0' : ++lock[1];
            return lock;
        case 5:
            lock[2] == '0' ? lock[2] = '9' : ++lock[2];
            return lock;
        case 6:
            lock[2] == '9' ? lock[2] = '0' : ++lock[2];
            return lock;
        case 7:
            lock[3] == '0' ? lock[3] = '9' : ++lock[3];
            return lock;
        case 8:
            lock[3] == '9' ? lock[3] = '0' : ++lock[3];
            return lock;
    }

    return 0;
}

int main(){

    string target;
    vector<string> stuck;
    queue<string> bfs;
    int len = 0;
    int cnt = -1;

    cin >> target;

    cin >> len;
    for(int i = 0 ; i < len ; ++i){
        string tmp;
        cin >> tmp;
        stuck.push_back(tmp);
    }

    bfs.push("0000");
    
    while(!bfs.empty()){
        ++cnt;
        //cout << "cnt: " << cnt << '\n';
        int size = bfs.size();
        for(int i = 0 ; i < size ; ++i){
            string now = bfs.front();
            bfs.pop();
            if(now == target){
                cout << cnt << '\n';
                return 0;
            }
            else if(find(stuck.begin(), stuck.end(), now) == stuck.end()){
                for(int i = 1 ; i <= 8 ; ++i){
                    bfs.push(next(now, i));
                }
            }
        }
    }
}
