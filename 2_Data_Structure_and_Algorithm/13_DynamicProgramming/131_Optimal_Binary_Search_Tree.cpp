#include "iostream"
#include "vector"
#include "float.h"

using namespace std;

double optimalBinarySearchTree(vector<double> &success, vector<double> &unSuccess, int n)
{
    vector<vector<double>> cost(n+2,vector<double>(n+1,0));

    vector<vector<double>> freq(n+2,vector<double>(n+1,0));


    for (int i = 1; i <= n + 1; i++)
    {
        cost[i][i - 1] = unSuccess[i - 1];
        freq[i][i - 1] = unSuccess[i - 1];
    }
    for (int l = 1; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = l + i - 1;
            freq[i][j] = freq[i][j - 1] + success[j] + unSuccess[j];
            cost[i][j] = DBL_MAX;
            for (int k = i; k <= j; k++)
            {
                double temp = cost[i][k - 1] + cost[k + 1][j] + freq[i][j];
                if (temp < cost[i][j])
                    cost[i][j] = temp;
            }
        }
    }
    return cost[1][n];
}

int main(){
    vector<double> p={0,0.15,0.1,0.05,0.1,0.2};
    vector<double> q={0.05,0.1,0.05,0.05,0.05,0.1};
    int n=p.size()-1;
    cout<<optimalBinarySearchTree(p,q,n);
}