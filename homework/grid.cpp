#include <iostream>
#include <queue>
#include <utility>
#define SIZE 200

using namespace std;

int graph[SIZE][SIZE] = {0};
int col = 0, row = 0;
int Max = 0;
queue< pair<int, int> > ans;

void dfs(int i, int j, int len, queue< pair<int, int> > cor){

    ++len;
    cor.push(make_pair(i, j));
    
    bool check = false;
    if(i - 1 >= 0 && graph[i-1][j] > graph[i][j]){
        dfs(i - 1, j, len, cor);
        check = true;
    }
    if(i + 1 < row && graph[i+1][j] > graph[i][j]){ 
        dfs(i + 1, j, len, cor);
        check = true;
    }
    if(j - 1 >= 0 && graph[i][j-1] > graph[i][j]){ 
        dfs(i, j - 1, len, cor);
        check = true;
    }
    if(j + 1 < col && graph[i][j+1] > graph[i][j]){
        dfs(i, j + 1, len, cor);
        check = true;
    }

    if(!check && len > Max){
        Max = len;
        while(!ans.empty()) ans.pop();
        while(!cor.empty()){
            ans.push(cor.front());
            cor.pop();
        }
    }
}

int main(){
    
    cin >> row >> col;
    queue< pair<int, int> > cor;
    
    for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; ++j){
            cin >> graph[i][j];
        }
    }

    for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < col ; ++j){
            dfs(i, j, 0, cor);
        }
    }

    cout << Max << '\n';
    while(!ans.empty()){
        cout << ans.front().first << " " << ans.front().second << '\n';
        ans.pop();
    }

    return 0;
}
