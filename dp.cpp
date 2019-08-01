#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

int lis(int a[],int n)
{
    int l[n];
    l[0]=1;
    for(int i=1;i<n;i++)
    {
        l[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j] && l[i]<l[j]+1)
            {
                l[i]=l[j]+1;
            }
        }
    }
    return *max_element(l,l+n);
    
}
int maxsumsubseq(int a[],int n)
{
    int l[n];
    l[0]=a[0];
    for(int i=1;i<n;i++)
    {
        l[i]=a[i];
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j] && l[i]<(l[j]+a[i]))
            {
                int t=l[j]+a[i];
                l[i]=t;
            }
        }
    }
    return *max_element(l,l+n);
    
}
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout << lis(a,n)<< endl;
        cout << maxsumsubseq(a,n) << endl;
    }
}
