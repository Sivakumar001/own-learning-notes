#include<bits/stdc++.h>

using namespace std;

bool jobs_comparator(vector<int> j1, vector<int>j2){
    if(j1[2]>j2[2])return true;
    else if(j1[2]<j2[2])return false;
    else if(j1[1]>j2[1])return true;
}

vector<int> job_sequencing(vector<vector<int>> jobs){
    sort(jobs.begin(), jobs.end(), jobs_comparator);

    int maxi=0;

    for(auto itr: jobs){
        if(maxi <= itr[1]){
            maxi = itr[1];
        }
    }

    int countjob=0,job_profit=0;
    vector<int> arrangement(maxi, -1);

    for(int i=0;i<maxi;i++){
        int j=jobs[i][1] - 1;

        while(j!=-1){
            if(arrangement[j]==-1){
                arrangement[j] = jobs[i][1];
                countjob++;
                job_profit += jobs[i][2];
                break;
            }
            j--;
        }

    }
    return {countjob, job_profit};
}


int main(){
    vector<vector<int>> jobs = {{1,4,20},{2,1,20},{3,1,20},{4,1,30}};
    vector<int> ans = job_sequencing(jobs);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}