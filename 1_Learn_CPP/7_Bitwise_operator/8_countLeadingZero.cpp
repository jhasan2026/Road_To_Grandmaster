#include "iostream"
#define SIZE sizeof(int)*8

using namespace std;
int main()
{
    int n,count=0;
    cin>>n;
    int bit=1<<SIZE-1;
    for (int i = 0; i < SIZE; ++i) {
        if((n<<i)&bit)
        {
            break;
        }
        count++;
    }
    cout<<"Leading zero is "<<count;

}