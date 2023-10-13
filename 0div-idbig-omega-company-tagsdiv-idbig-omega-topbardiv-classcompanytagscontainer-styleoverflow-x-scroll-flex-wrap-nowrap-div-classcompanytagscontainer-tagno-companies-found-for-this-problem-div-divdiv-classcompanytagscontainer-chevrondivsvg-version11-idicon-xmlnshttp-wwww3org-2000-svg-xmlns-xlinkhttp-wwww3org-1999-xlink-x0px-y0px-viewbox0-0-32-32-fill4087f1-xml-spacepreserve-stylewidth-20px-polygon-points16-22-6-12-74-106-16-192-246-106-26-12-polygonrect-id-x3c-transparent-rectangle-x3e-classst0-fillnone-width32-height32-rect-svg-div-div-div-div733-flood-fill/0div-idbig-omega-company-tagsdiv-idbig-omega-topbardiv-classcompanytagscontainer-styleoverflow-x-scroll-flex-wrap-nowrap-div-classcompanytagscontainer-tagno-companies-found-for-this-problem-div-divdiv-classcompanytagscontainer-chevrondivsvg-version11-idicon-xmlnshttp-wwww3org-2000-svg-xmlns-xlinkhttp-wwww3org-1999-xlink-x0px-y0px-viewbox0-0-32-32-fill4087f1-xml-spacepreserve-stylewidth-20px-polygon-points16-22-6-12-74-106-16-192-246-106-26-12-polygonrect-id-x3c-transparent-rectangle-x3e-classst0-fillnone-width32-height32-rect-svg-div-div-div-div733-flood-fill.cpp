class Solution {
public:
    void pushing(int i,int j,queue<pair<int,int>>&q,int r,int c)
    {
        int xar[]={1,-1,0,0};
        int yar[]={0,0,1,-1};
        for(int ind=0;ind<4;ind++){
            int x,y;
            x=i+xar[ind];y=j+yar[ind];
            if(x>=0&&x<r&&y>=0&&y<c)q.push({x,y});
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        int r=image.size(),c=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});int starting=image[sr][sc];
        while(!q.empty()){
            auto x=q.front();q.pop();
            int i=x.first,j=x.second;
            if(image[i][j]==starting){
            image[i][j]=color;
            pushing(i,j,q,r,c);
            }
        }
        return image;
    }
};