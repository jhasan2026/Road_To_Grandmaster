#include "iostream"

using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        float att,assi,ct,mid,fin,sum=0;
        cin>>att>>assi>>ct>>mid>>fin;
        mid=(3.0/5)*mid;
        fin=(4.0/10)*fin;
        sum=att+assi+ct+mid+fin;
        if(sum>=90)
        {
            cout<<"A";
        }
        else if(sum>=86 && sum<90)
        {
            cout<<"A-";
        }
        else if(sum>=82 && sum<86)
        {
            cout<<"B+";
        }
        else if(sum>=78 && sum<82)
        {
            cout<<"B";
        }
        else if(sum>=74 && sum<78)
        {
            cout<<"B-";
        }
        else if(sum>=70 && sum<74)
        {
            cout<<"C+";
        }
        else if(sum>=66 && sum<70)
        {
            cout<<"C";
        }
        else if(sum>=62 && sum<66)
        {
            cout<<"C-";
        }
        else if(sum>=58 && sum<62)
        {
            cout<<"D+";
        }
        else if(sum>=55 && sum<58)
        {
            cout<<"D";
        }
        else {
            cout<<"F";
        }
    }

}