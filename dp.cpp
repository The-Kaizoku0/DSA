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
 
// coin change 
int count( int S[], int m, int n ) 
{ 
    int i, j, x, y; 
  
    // We need n+1 rows as the table  
    // is constructed in bottom up 
    // manner using the base case 0 
    // value case (n = 0) 
    int table[n + 1][m]; 
      
    // Fill the enteries for 0 
    // value case (n = 0) 
    for (i = 0; i < m; i++) 
        table[0][i] = 1; 
  
    // Fill rest of the table entries  
    // in bottom up manner  
    for (i = 1; i < n + 1; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            // Count of solutions including S[j] 
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 
  
            // Count of solutions excluding S[j] 
            y = (j >= 1) ? table[i][j - 1] : 0; 
  
            // total count 
            table[i][j] = x + y; 
        } 
    } 
    return table[n][m - 1]; 
}  

// subset sum problem
string subsetsum(int set[], int n, int sum)
{
    bool subset[n+1][sum+1]; 
   
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
      subset[i][0] = true; 
   
    // If sum is not 0 and set is empty, then answer is false 
    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false; 
   
     // Fill the subset table in botton up manner 
     for (int i = 1; i <= n; i++) 
     { 
       for (int j = 1; j <= sum; j++) 
       { 
         if(j<set[i-1]) 
         subset[i][j] = subset[i-1][j]; 
         if (j >= set[i-1]) 
           subset[i][j] = subset[i-1][j] ||  
                                 subset[i - 1][j-set[i-1]]; 
       } 
     } 
    if(subset[n][sum])
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

//perfect sum, give no. of subset with given sum
int perfectsum(int a[],int n, int sum)
{
    int dp[n+1][sum+1];
    for(int j=1;j<=sum;j++)
    {
        dp[0][j]=0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
                dp[i][j]=dp[i-1][j];
                if(j>=a[i-1])
                {
                    dp[i][j]+=dp[i-1][j-a[i-1]];
                }
        }
    }
    return dp[n][sum];
}

// min jump to reach the end
int minjump(int a[],int n)
{
    int jump[n];
    jump[0]=0;
    if(a[0]==0)
    {
        return -1;
    }
    for(int i=1;i<n;i++)
    {
        jump[i]=INT_MAX;
        
        for(int j=0;j<i;j++)
        {

            if(i-j<=a[j])
            {
                jump[i]=min(jump[i], 1+jump[j]);
            }
        }
    
    }
    if(jump[n-1]==INT_MAX)
    {
        return -1;
    }
    return jump[n-1];
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
