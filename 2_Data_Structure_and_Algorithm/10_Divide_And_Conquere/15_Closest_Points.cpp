#include "iostream"
#include "vector"
#include "math.h"
using namespace std;

double euclidianDistance(pair<double,double> point1,pair<double,double> point2){
    return sqrt(pow(point1.first-point2.first,2)+pow(point1.second-point2.second,2));
}

void mergeList(vector<pair<double,double>> &points,int start,int mid,int end,pair<double,double> &point1,pair<double,double> &point2){
    int n1 = mid+1 - start;
    int n2 = end - mid;

    vector<pair<double,double>> sub1(n1);
    vector<pair<double,double>> sub2(n2);

    for (int i = 0; i < n1; ++i) {
        sub1[i] = points[start + i];
    }
    for (int i = 0; i < n2; ++i) {
        sub2[i] = points[mid+1 + i];
    }
    double dist = INT_MAX;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            double distCal = euclidianDistance(sub1[i],sub2[j]);
             if(dist > distCal){
                 point1 = sub1[i];
                 point2 = sub1[j];
                 dist = distCal;
             }
        }
    }
}

void closestDistancePoint(vector<pair<double,double>> &points,int start,int end,pair<double,double> &point1,pair<double,double> &point2){
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    closestDistancePoint(points,start,mid,point1,point2);
    closestDistancePoint(points,mid+1,end,point1,point2);
    mergeList(points,start,mid,end,point1,point2);

}

int main(){
    vector<pair<double,double>> points;
    points.push_back({0.8919, 0.7899});
    points.push_back({0.1877, 0.2737});
    points.push_back({0.1017, 0.9399});
    points.push_back({0.1594, 0.9441});
    points.push_back({0.9562, 0.9472});
    points.push_back({0.3323, 0.3861});

    pair<double,double> point1,point2;
    closestDistancePoint(points,0,5,point1,point2);
    cout<<point1.first<<","<<point1.second<<endl;
    cout<<point2.first<<","<<point2.second<<endl;
    cout<<euclidianDistance(point1,point2)<<endl;
}