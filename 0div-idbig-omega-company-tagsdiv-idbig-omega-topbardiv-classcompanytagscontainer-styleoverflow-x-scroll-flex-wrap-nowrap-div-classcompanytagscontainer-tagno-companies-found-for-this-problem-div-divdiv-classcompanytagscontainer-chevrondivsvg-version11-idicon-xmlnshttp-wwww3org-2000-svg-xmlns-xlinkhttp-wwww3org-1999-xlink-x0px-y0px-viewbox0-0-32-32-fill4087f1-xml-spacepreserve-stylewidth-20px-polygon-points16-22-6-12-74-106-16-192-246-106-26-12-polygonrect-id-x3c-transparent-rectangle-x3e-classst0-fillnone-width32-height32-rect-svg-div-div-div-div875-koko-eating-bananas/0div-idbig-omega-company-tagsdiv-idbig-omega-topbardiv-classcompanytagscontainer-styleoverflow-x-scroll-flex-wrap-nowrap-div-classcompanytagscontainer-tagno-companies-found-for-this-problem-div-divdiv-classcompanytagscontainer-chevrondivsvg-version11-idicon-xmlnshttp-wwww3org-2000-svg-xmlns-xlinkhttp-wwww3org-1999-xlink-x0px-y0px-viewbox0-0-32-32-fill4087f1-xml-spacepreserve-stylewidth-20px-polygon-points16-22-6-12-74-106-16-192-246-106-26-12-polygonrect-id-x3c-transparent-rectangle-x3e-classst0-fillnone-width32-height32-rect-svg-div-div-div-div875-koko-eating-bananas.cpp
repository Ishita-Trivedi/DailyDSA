class Solution {
private:
    bool possible(int k,vector<int>& piles, int h){
        int hr=0;
        for(int x:piles){
            hr +=ceil((double)x/(double)k);
        }
        return hr<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int hour) {
        int h=*max_element(piles.begin(),piles.end()),l=1,mid;
        while(l<=h){
            mid=h-(h-l)/2;
            if(possible(mid,piles,hour))
            h=mid-1;
            else
            l=mid+1;
        }
        return static_cast<int>(l);
    }
};