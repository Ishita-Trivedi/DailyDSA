class Solution {
typedef pair<int,int>p;
public:
    set<p>st;
    void update(int &x,int &y,int k,char dir){
        int sign=1;
        if(dir=='S'||dir=='W')sign*=(-1);
        if(dir=='N'||dir=='S'){
            for(int i=1;i<=k;i++){
                int nw=y+sign;
                if(st.find({x,nw})!=st.end())break;
                y=nw;
            }
        }
        else{
            for(int i=1;i<=k;i++){
                int nw=x+sign;
                if(st.find({nw,y})!=st.end())break;
                x=nw;
            }
        }
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0,y=0,d=0,dist=0;
        char directions[4]={'N','E','S','W'};
        for(auto vec:obstacles){
            int tx=vec[0],ty=vec[1];
            st.insert({tx,ty});
        }
        for(int k:commands){
            if(k>=1&&k<=9)update(x,y,k,directions[d]);
            else {
                if(k==-2)
                {
                    if(d==0)d=3;
                    else
                    d--;
                }
                else if(k==-1){
                    d=(d+1)%4;
                }
            }
           dist=max(dist,x*x+y*y);
        }
        return dist;
    }
};