#include "iostream"
#include "vector"
#include "list"
#include "unordered_map"
#include "algorithm"


using namespace std;

class WeiGraph{
public:
    unordered_map<int,list<pair<int,int>>> adjList;
    vector<vector<int>> edges;

    void addEdge(int from,int to,int weight,bool direction){
        adjList[from].push_back({to,weight});
        adjList[to];

        if(!direction){
            adjList[to].push_back({from,weight});
        }

        vector<int> edge;
        edge.push_back(from);
        edge.push_back(to);
        edge.push_back(weight);
        edges.push_back(edge);
    }
    void printAdjList(){
        for (auto node:adjList) {
            cout<<node.first<<"--> ";
            for (auto neighbour:node.second) {
                cout<<"["<<neighbour.first<<","<<neighbour.second<<"] ";
            }
            cout<<endl;
        }
    }
};

void makeSet(vector<int> &parent,vector<int> &rank,int vertex){
    for (int ver = 0; ver <= vertex ; ++ver) {
        parent[ver] = ver;                      //initially parent of each value is himself
        rank[ver] = 0;                          //rank is zero
    }
}
int findParent(vector<int> &parent,int node){
    if(parent[node] == node){                           //base :  recursive traverse ends until root(captain) is found :: value's parent is himself
        return node;                         //return his own value
    }
    return parent[node] =  findParent(parent,parent[node]);         //get him parent value   and direct connect to root
}
void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
    u = findParent(parent,u);           //find one value's parent as u
    v = findParent(parent,v);           //find another value's parent as v

    if(rank[u]>rank[v]){            //change parent of minimum ranked value  (by more ranked value)
        parent[v] = u;
    }
    else if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else{                    //if both are same  :: change parent any of them by another(here it is maximum) :: and increase another one's rank
        parent[u] = v;          //also, parent[v]=u;  rank[u]++;
        (rank[v])++;
    }
}

bool cmp(vector<int> &p1,vector<int> &p2){                  //comparator for sorting in descending order by weight
    return p1[2] < p2[2];
}

vector<pair<pair<int,int>,int>> MSTbyKruskalAlgo(vector<vector<int>> edges,int vertex){
    vector<int> parent(vertex+1);                    //vector for tracking very vertex's parent
    vector<int> rank(vertex+1);                      //vector for tracking rank of every vertex

    makeSet(parent,rank,vertex);                //make these vector initialize

    sort(edges.begin(), edges.end(), cmp);                  //sort edges's list in descending order by weight
    vector<pair<pair<int,int>,int>> ans;

    for (int i = 0; i < edges.size(); ++i) {                                //traverse every edge's one by one
        int fromParent = findParent(parent,edges[i][0]);            //find from's parent
        int toParent = findParent(parent,edges[i][1]);          //find to's parent
        int weight = edges[i][2];                                       //weight of every edge

        if(fromParent != toParent){                                     //if parent of from and parent of to doesn't match
            unionSet(fromParent,toParent,parent,rank);      //Do union of u and v
            ans.push_back({{fromParent,toParent},weight});
        }

    }

    return ans;
}



int main(){
    WeiGraph g;
    g.addEdge(5,4,9, false);
    g.addEdge(5,1,4, false);
    g.addEdge(4,1,1, false);
    g.addEdge(4,3,5, false);
    g.addEdge(4,2,3, false);
    g.addEdge(1,2,2, false);
    g.addEdge(3,2,3, false);
    g.addEdge(3,6,8, false);
    g.addEdge(2,6,7, false);

    vector<pair<pair<int,int>,int>> ans = MSTbyKruskalAlgo(g.edges,6);

    for (auto x:ans) {
        cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
    }

}