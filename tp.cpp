#include <bits/stdc++.h>
using namespace std;
class disjoint{
    vector<int>rank;
    vector<int>parent;
public:
    disjoint(int n){
        rank.resize(n+1,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findP(int node){
        if(node==parent[node])return node;
        return parent[node]=findP(parent[node]);
    }
    void unionRank(int u,int v){
        int ultU=findP(u);
        int ultV=findP(v);
        if(ultU==ultV)return;
        if(rank[ultU]<rank[ultV]){
            parent[ultU]=ultV;
        }
        else if(rank[ultU]>rank[ultV]){
            parent[ultV]=ultU;
        }
        else{
            parent[ultV]=ultU;

            rank[ultU]++;
        }
    }
};
class kruskals{
public:
    int spanning(int V,vector<vector<pair<int,int>>>&adj,vector<pair<int,int>>&mstedges){
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int node=i;
                int adjnode=it.first;
                int wt=it.second;

                edges.push_back({wt,{node,adjnode}});
            }
        }
        disjoint d(V);
        sort(edges.begin(),edges.end());
        int mstwt=0;
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(d.findP(u)!=d.findP(v)){
                d.unionRank(u,v);
                mstwt+=wt;
                mstedges.push_back({u,v});
            }
        }
        return mstwt;
    }
};
int main(){

}