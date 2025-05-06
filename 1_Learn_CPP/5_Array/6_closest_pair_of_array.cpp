#include "iostream"
#include "vector"
#include "math.h"
#include "float.h"
using namespace std;

struct Point{
    double x,y;
};

double euclidianDistance(Point p1,Point p2){
    return sqrt(pow(p1.x-p2.x,2) - pow(p1.y-p2.y,2));
}

pair<Point,Point> findShortestPair(vector<Point> &points){
    pair<Point,Point> shortestPair;
    double shortestDistance = DBL_MAX;
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i+1; j < points.size(); ++j) {
            double distance = euclidianDistance(points[i],points[j]);
            if(shortestDistance > distance){
                shortestDistance = distance;
                shortestPair = {points[i],points[j]};
            }
        }
    }
    return shortestPair;
}

int main(){
    vector<Point> points = {{2.1, 3.2}, {1.3, 4.7}, {5.5, 1.1}, {2.0, 1.0}, {3.0, 4.0}};
    pair<Point,Point> shortestPair;
    shortestPair = findShortestPair(points);
    cout<<"("<<shortestPair.first.x<<" , "<<shortestPair.first.y<<")"<<endl;
    cout<<"("<<shortestPair.second.x<<" , "<<shortestPair.second.y<<")"<<endl;
}