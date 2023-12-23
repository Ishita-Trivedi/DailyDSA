class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>st;
        int x=0,y=0;st.insert({x,y});
        for(int i=0;i<path.length();i++){
            char dir=path[i];
            if(dir=='N')y++;
            else if(dir=='S')y--;
            else if(dir=='E')x++;
            else
            x--;//W
            if(st.find({x,y})!=st.end())return true;
            st.insert({x,y});
        }
        return false;
    }
};