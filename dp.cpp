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
int lcs(string a, string b, int n ,int m)
{
    int l[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                l[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                l[i][j]=1+l[i-1][j-1];
            }
            else
            {
                l[i][j]=max(l[i-1][j],l[i][j-1]);
            }
        }
    }
    return l[n][m];    
}
int editdist(string s1,string s2)
{
    int n=s1.size();
    int m=s2.size();
    int dp[m+1][n+1]; 
  
    // Fill d[][] in bottom up manner 
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            // If first string is empty, only option is to 
            // insert all characters of second string 
            if (i==0) 
                dp[i][j] = j;  // Min. operations = j 
  
            // If second string is empty, only option is to 
            // remove all characters of second string 
            else if (j==0) 
                dp[i][j] = i; // Min. operations = i 
  
            // If last characters are same, ignore last char 
            // and recur for remaining string 
            else if (s1[i-1] == s2[j-1]) 
                dp[i][j] = dp[i-1][j-1]; 
  
            // If the last character is different, consider all 
            // possibilities and find the minimum 
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert 
                                   min(dp[i-1][j],  // Remove 
                                   dp[i-1][j-1])); // Replace 
        } 
    } 
    return dp[m][n];
    
}

// there is some error
int cost(int n,int a[][n])
{
    int c[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0)
            {
                c[i][j]=a[i][j];
            }
            else
            {
                c[i][j]=a[i][j]+min(c[i-1][j-1],min(c[i-1][j],c[i-1][j-1]));
            }
        }
    }
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(c[n-1][i]>maxi)
        {
            maxi=a[n-1][i];
        }
    }
    return maxi;
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
        string x;
        string y;
        int o=x.size();
        int p=y.size();
        cin>>x>>y;
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout << lis(a,n)<< endl;
        cout << maxsumsubseq(a,n) << endl;
        cout <<lcs (x,y,o,p) <<end;l;
    }
}
