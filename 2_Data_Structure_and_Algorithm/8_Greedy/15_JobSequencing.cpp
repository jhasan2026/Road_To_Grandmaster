#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
struct Job{
public:
    int id;
    int dead;
    int profit;
    Job(int id,int dead,int profit){
        this->id=id;
        this->dead=dead;
        this->profit=profit;
    }
};
static bool cmppp(Job a,Job b){
    return a.profit > b.profit;
}
vector<int> jobSchedule(vector<Job> arr){
    int n=arr.size();
    sort(arr.begin(), arr.end(),cmppp);

    int maxDeadline=INT_MIN;
    for (int i = 0; i < n; ++i) {
        maxDeadline=max(maxDeadline,arr[i].dead);
    }

    vector<int> schedule(maxDeadline+1,-1);

    int count=0;
    int maxProfit=0;
    for (int i = 0; i < n; ++i) {
        int currProfit=arr[i].profit;
        int currJobId=arr[i].id;
        int currDead=arr[i].dead;

        for (int j = currDead; j >0 ; --j) {
            if(schedule[j] == -1){
                count++;
                maxProfit+= currProfit;
                schedule[j]=currJobId;
                break;
            }
        }
    }
    vector<int> ans;
    ans.push_back(count);
    ans.push_back(maxProfit);
    return ans;

}

int main(){
    vector<Job> arr={
            Job(1,4,20),
            Job(2,1,10),
            Job(3,1,40),
            Job(4,1,30)

    };
    vector<int> ans= jobSchedule(arr);
    for (auto x:ans) {
        cout<<x<<" ";
    }
    cout<<endl;
}