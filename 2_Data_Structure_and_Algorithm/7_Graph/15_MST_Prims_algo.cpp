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


vector<pair<pair<int,int>,int>> MSTbyPrimsAlgo(unordered_map<int,list<pair<int,int>>> adjList){
    int vertex=adjList.size();
    vector<int> parent(vertex+1,-1);            //track their parent // parent is -1
    vector<int> key(vertex+1,INT_MAX);          //for calculation of weight
    vector<bool> mst(vertex+1, false);          //for tracking all node as true in mst

    key[1] = 0;                             //let start from 0th node ::   weight is 0

    for (int i = 0; i <= vertex; ++i) {             //traverse for every node

        int from,miniKey=INT_MAX;                   //mini:: INT_MAX        //for a edge::   from--->to
        for (int ver = 0; ver <= vertex; ++ver) {       //finding minimum from the key vector(if it will be minimum, mst is false for that vertex)
            if(key[ver] < miniKey && !mst[ver]){
                miniKey = key[ver];                      //mini is minimumKeyValue
                from = ver;                         //from:: is the vertex for minimumKeyValue
            }
        }

        mst[from] = true;                    //mst will become true for that vertex

        for (auto neighbour:adjList[from]) {        //traverse it's neighbour pair
            int to = neighbour.first;                           //to:: from's   neighbour           ::
            int weight = neighbour.second;                          //weight of (from-->to)

            if(!mst[to]  && weight < key[to]){                   //weight of neighbour is less than  minimumKeyValue of neighbour
                parent[to] = from;                       //parent of neighbour is from
                key[to] = weight;               //keyValue of neighbour is weight of (from-->to)
            }
        }
    }

    vector<pair<pair<int,int>,int>> ans;        //convert into from--to--weight format
    for (int i = 2; i <= vertex ; ++i) {
        ans.push_back({{parent[i], i},key[i]});
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

    vector<pair<pair<int,int>,int>> ans = MSTbyPrimsAlgo(g.adjList);

    for (auto x:ans) {
        cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
    }
}