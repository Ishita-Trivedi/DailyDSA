class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i=0,z=m,j=0;
        while(j<n){
            if(nums1[i]==0&&i>=z){
                nums1[i]=nums2[j];
                z++;j++;
            }
            // else if(nums1[i]<=nums2[j])i++;//smaller/equal
            else if(nums1[i]>nums2[j]){//greater
                for(int k=z;k>i;k--)
                nums1[k]=nums1[k-1];
                nums1[i]=nums2[j];j++;z++;
            }
            i++;
        }
    }
};