#include<bits/stdc++.h>
using namespace std; 

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


class Solution 
{
    public:
    static bool mycmp(Job &j1,Job &j2){
        return j1.profit>j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int jdone=0,tprofit=0;
        int maxdeadline=arr[0].dead;
        for(int i=1;i<n;i++)
        maxdeadline=max(maxdeadline,arr[i].dead);
        int tarr[maxdeadline+1]={0};
        vector<int> v;
        sort(arr,arr+n,mycmp);
        for(int i=0;i<n;i++){
            int j=arr[i].dead;
            while(j>=1 && tarr[j]!=0)
            j--;
            if(j!=0){
                tprofit+=arr[i].profit;
                jdone++;
                tarr[j]=arr[i].profit;
            }
        }
        v.push_back(jdone);
        v.push_back(tprofit);
        return v;
    } 
};

int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        Job arr[n];
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}
