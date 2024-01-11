class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearestX=max(x1,min(x2,xCenter));
        int nearestY=max(y1,min(y2,yCenter));

        int distX=xCenter-nearestX;
        int distY=yCenter-nearestY;
        int d=(distX)*distX+(distY)*distY;

        return radius*radius>=d;
    }
};