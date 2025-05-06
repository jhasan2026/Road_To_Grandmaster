#include "iostream"
#include "vector"
#include "list"
#include "unordered_map"
#include "stack"

using namespace std;

class Graph{
public:
    unordered_map<int,list<int>> adjList;
    vector<vector<int>> edges;

    void addEdge(int from,int to,bool direction){
        adjList[from].push_back(to);
        adjList[to];

        if(!direction){
            adjList[to].push_back(from);
        }

        vector<int> edge;
        edge.push_back(from);
        edge.push_back(to);
        edges.push_back(edge);
    }
    void printAdjList(){
        for (auto node:adjList) {
            cout<<node.first<<"--> ";
            for (auto neighbour:node.second) {
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
    }
};

void dfs(unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &visited, vector<int> &disc, vector<int> &low,vector<vector<int>> &bridges, int &timer, int parent,int source){
    visited[source] = true;                 //make node's visited as true
    disc[source] = low[source] = timer++;   //firstly :: discovery time and lowest discovery time both are (time++) {incremented value of time}

    for(auto neighbour: adjList[source]){       //traverse it's neighbour
        if(neighbour == parent){                    //in backtracking time :: if neighbour is parent :: skip step
            continue;
        }

        if(!visited[neighbour]){                     //if neighbour is not visited
            dfs(adjList,visited,disc,low,bridges,timer,source,neighbour);   //call dfs for neighbour
            low[source] = min(low[source], low[neighbour]);     //came back from recursive call :: lowestDiscoveryTime will update by minimum of(lowestDiscoveryTime of neighbour , lowestDiscoveryTime)
            //because:: it is possible to this node's neighbour(child) have back-edge(another way to reach) :: so get lowest discovery time from its neighbour

            if(low[neighbour] > disc[source]){      //if lowestDiscoveryTime of neighbour is greater than discovery time  :: there is a bridge  ::
                vector<int> singleBridge;
                singleBridge.push_back(source);     //between node and neighbour  :: make a vector of edge
                singleBridge.push_back(neighbour);
                bridges.push_back(singleBridge);        //push it into the result
            }
        }
        else{                           //if neighbour is visited :: there is possibility of having back-edge(another way to reach that node)
            low[source] = min(low[source], disc[neighbour]);        //if back-edge have:: lowestDiscoveryTime will become minimum of (discovery time of neighbour, lowestDiscoveryTime)
        }

    }
}


vector<vector<int>> findBridge(unordered_map<int,list<int>> adjList){
    int vertex = adjList.size();

    //initially discovery time is -1
    vector<int> disc(vertex,-1);        //for counting vertex's discovery time

    //lowest discovery time is -1
    vector<int> low(vertex,-1);         //for counting vertex's lowest discovery time

    unordered_map<int,bool> visited;        //track vertex is visited

    vector<vector<int>> bridges;        //vector is bridge (edges)

    int timer = 0 ;         //starting timer from 0

    for(auto node: adjList){
        if(!visited[node.first]){                    //if not visited  :: do dfs
            dfs(adjList,visited,disc,low,bridges,timer,-1,node.first);
            //starting node's parent -1
        }
    }
    return bridges;
}



int main(){
    Graph g;
    g.addEdge(6,7, false);
    g.addEdge(5,6, false);
    g.addEdge(8,5, false);
    g.addEdge(8,7, false);
    g.addEdge(2,5, false);
    g.addEdge(2,0, false);
    g.addEdge(0,1, false);
    g.addEdge(1,2, false);
    g.addEdge(2,3, false);
    g.addEdge(3,4, false);

    vector<vector<int>> bridges = findBridge(g.adjList);
    for(auto x:bridges){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;

    }

}