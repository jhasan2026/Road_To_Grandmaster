#include "iostream"
#include "vector"
#include "list"
#include "unordered_map"
#include "queue"

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


bool dirCheckCycleTopoSortKhanAlgo(unordered_map<int,list<int>> &adjList){
    unordered_map<int,int> indegree ;               //indegree map
    for (auto node:adjList) {       //find all indegree
        indegree[node.first];
        for (auto neighbour:node.second) {
            indegree[neighbour]++;
        }
    }
    queue<int> q;
    for (auto node:indegree) {      //take all vertex
        if(node.second==0){                     //if any vertex indegree is 0 :: push it into queue
            q.push(node.first);
        }
    }

    int count = 0;

    while (!q.empty()){
        int frontNode = q.front();          //take element from queue
        q.pop();

        count++;

        for (auto neighbour:adjList[frontNode]) {       //traverse its neighbour
            indegree[neighbour]--;                      //decrease their indegree
            if(indegree[neighbour] == 0){           //if any neighbour's indegree is 0 :: push it into queue
                q.push(neighbour);
            }
        }
    }
    if(count == adjList.size()){
        return false;
    }
    return true;
}


int main(){
    Graph g;
    g.addEdge(0,3, true);
    g.addEdge(3,4, true);
    g.addEdge(4,0, true);
    g.addEdge(0,2, true);
    g.addEdge(2,1, true);
    g.addEdge(1,0, true);

    cout<<dirCheckCycleTopoSortKhanAlgo(g.adjList);

}