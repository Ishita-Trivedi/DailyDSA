class Solution {
private:
    pair<int,int>calculate(int indx,int st,int n,vector<int>& rating){
        int smaller=0,larger=0;
        for(int i=st;i<n;i++){
            if(rating[indx]<rating[i])
            larger++;
            else if(rating[indx]>rating[i])
            smaller++;
        }
        return {smaller,larger};
    }
    int counts(int i,int n,vector<int>& rating){
        auto lhs=calculate(i,0,i,rating);
        auto rhs=calculate(i,i+1,n,rating);
        int cnt=0;
        cnt+=lhs.first*rhs.second;//asecding count
        cnt+=lhs.second*rhs.first;//descending count
        return cnt;
    }
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size(),cnt=0;
        for(int i=1;i<n;i++){
            cnt+=counts(i,n,rating);
        }
        return cnt;
    }
};