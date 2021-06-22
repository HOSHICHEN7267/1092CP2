#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main(){

    int start = 0, target = 0;
    int busnum = 0;
    int stopnum = 0;
    unordered_map< int, vector<int> > stops;
    vector< vector<int> > route;
    queue<int> bfs;
    int ans = 0;

    cin >> start >> target >> busnum;

    if(start == target){
        cout << 0 << '\n';
        return 0;
    }

    for(int i = 0 ; i < busnum ; ++i){
        cin >> stopnum;
        vector<int> tmp;
        for(int j = 0 ; j < stopnum ; ++j){
            //cout << "j: " << j << '\n';
            int a;
            cin >> a;
            tmp.push_back(a);
        }
        route.push_back(tmp);
    }

    for(int i = 0 ; i < route.size() ; ++i){
        //cout << "i: " << i << '\n';
        for(int j : route[i]){
            stops[j].push_back(i);
        } 
    }

    vector<int> visited(route.size(), 0);
    bfs.push(start);

    while(!bfs.empty()){
        int num = bfs.size();
        ++ans;
        while(num--){
            //cout << "num: " << num << '\n';
            int now = bfs.front();
            bfs.pop();
            for(int i : stops[now]){
                //cout << "i: " << i << '\n';
                if(visited[i]){
                    continue;
                }
                visited[i] = 1;
                for(int j : route[i]){
                    //cout << "j: " << j << '\n';
                    if(j == target){
                        cout << ans << '\n';
                        return 0;
                    }
                    bfs.push(j);
                }
                //cout << '\n';
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
