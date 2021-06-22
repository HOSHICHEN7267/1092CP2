#include <iostream>
#define SIZE 500

using namespace std;

bool graph[SIZE][SIZE] = {0};
int len = 0;
int cnt = 0;

void dfs(bool visited[][SIZE], int i, int j){

    ++cnt;
    visited[i][j] = 1;

    //cout << "dfs i: " << i << " j: " << j << " value: " << graph[i][j] << '\n';
    //cout << "cnt: " << cnt << '\n';

    if(i - 1 >= 0 && graph[i-1][j] && !visited[i-1][j]){
        dfs(visited, i-1, j);
    }
    if(i + 1 < len && graph[i+1][j] && !visited[i+1][j]){
        dfs(visited, i+1, j);
    }
    if(j - 1 >= 0 && graph[i][j-1] && !visited[i][j-1]){
        dfs(visited, i, j-1);
    }
    if(j + 1 < len && graph[i][j+1] && !visited[i][j+1]){
        dfs(visited, i, j+1);
    }
}

int main(){

    int Max = 0;
    int check = 0;

    cin >> len;

    for(int i = 0 ; i < len ; ++i){
        for(int j = 0 ; j < len ; ++j){
            int tmp;
            cin >> tmp;
            if(tmp){
                check = 1;
                graph[i][j] = 1;
            }
        }
    }

    if(check == 0){
        cout << 1 << '\n';
        return 0;
    }

    //cout << "len: " << len << '\n';

    for(int i = 0 ; i < len ; ++i){
        for(int j = 0 ; j < len ; ++j){
            //cout << "i: " << i << " j: " << j << '\n';
            if(!graph[i][j] && ((i - 1 >= 0 && graph[i-1][j]) || (i + 1 < len && graph[i+1][j]) || (j - 1 >= 0 && graph[i][j-1]) || (j + 1 < len && graph[i][j+1]))){

                bool visited[SIZE][SIZE] = {0};
                //cout << "hi\n";
                //cout << "cnt: " << *cnt << '\n';
                graph[i][j] = 1;
                dfs(visited, i, j);
                graph[i][j] = 0;
                if(cnt > Max) Max = cnt;
                cnt = 0;
            }
        }
    }

    cout << Max << '\n';

    return 0;
}
