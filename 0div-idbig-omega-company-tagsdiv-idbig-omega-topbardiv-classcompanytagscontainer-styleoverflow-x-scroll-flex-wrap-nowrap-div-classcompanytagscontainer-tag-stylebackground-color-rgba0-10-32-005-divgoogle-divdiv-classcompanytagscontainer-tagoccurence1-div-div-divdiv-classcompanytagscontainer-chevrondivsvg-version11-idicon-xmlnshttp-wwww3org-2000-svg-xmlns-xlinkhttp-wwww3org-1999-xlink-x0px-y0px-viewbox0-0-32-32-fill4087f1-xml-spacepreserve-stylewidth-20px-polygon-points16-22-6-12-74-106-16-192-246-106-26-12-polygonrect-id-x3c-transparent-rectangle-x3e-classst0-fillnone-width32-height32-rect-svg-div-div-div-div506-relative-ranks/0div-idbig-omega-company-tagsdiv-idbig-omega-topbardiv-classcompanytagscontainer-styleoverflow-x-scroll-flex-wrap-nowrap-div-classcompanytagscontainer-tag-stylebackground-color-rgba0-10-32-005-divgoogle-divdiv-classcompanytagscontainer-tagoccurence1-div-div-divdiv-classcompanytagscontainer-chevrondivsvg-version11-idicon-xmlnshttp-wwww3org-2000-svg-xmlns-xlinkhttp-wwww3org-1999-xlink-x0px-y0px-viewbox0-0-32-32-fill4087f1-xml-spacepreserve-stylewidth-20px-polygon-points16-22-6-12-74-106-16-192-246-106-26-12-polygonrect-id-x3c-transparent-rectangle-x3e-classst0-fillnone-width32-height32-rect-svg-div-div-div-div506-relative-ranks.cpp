class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
     priority_queue<pair<int,int>>pq;
     int cnt=0,n=score.size();
     for(int i=0;i<score.size();i++){
        pq.push({score[i],i});
     }  
     vector<string>ranks(n,"");
     while(!pq.empty()){
        int i=pq.top().second;pq.pop();
        cnt++;
        if(cnt==1)
        ranks[i]="Gold Medal";
        else if(cnt==2)
        ranks[i]="Silver Medal";
        else if(cnt==3)
        ranks[i]="Bronze Medal";
        else
        ranks[i]=to_string(cnt);
     }
     return ranks;
    }
};