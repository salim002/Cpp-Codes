#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj_list(n+1);
    vector<int> indegree(n+1, 0);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj_list[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    
    return 0;
}