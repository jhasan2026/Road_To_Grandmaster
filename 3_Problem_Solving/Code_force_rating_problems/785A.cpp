#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;



int main(){
    unordered_map<string,int> face;
    face["Tetrahedron"] = 4;
    face["Cube"] = 6;
    face["Octahedron"] = 8;
    face["Dodecahedron"] = 12;
    face["Icosahedron"] = 20;
    int n;
    cin>>n;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        string str;
        cin>>str;
        count+=face[str];
    }
    cout<<count<<endl;
}