#include<iostream>
using namespace std;
int sqrtInteger(long long int N)
{
    // Write your code here.
	int s=0;
    // int e=1e+16; //or unsigned int e = N;
    unsigned int e = N;
    long long int mid=s+(e-s)/2;

    while(s<=e){
    	if(N==1ll*mid*mid)
            return mid;
        else if(N<1ll*mid*mid){
        	e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return e;
}
double moreprecision(int n,int integersoln,int precision)
{
    double factor =1;
    double ans=integersoln;
    for(int i=0;i<precision;i++)
    {
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor)
        {
            ans=j;
        }
    }
    return ans;
}
int main(){

        int a= sqrtInteger(101);
        cout<<a;
        cout<<moreprecision(101,a,4);
return 0;
}