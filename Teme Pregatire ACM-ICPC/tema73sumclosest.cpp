#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minim=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());

        for (int i=0;i<nums.size()-2;++i) {
            int st=i+1;
            int dr=nums.size()-1;
            while (st<dr) {
                int suma=nums[i]+nums[st]+nums[dr];
                if (abs(target-suma)<abs(target-minim)) minim=suma;

                if (suma==target) return suma;
                else
                if (suma>target) --dr;
                else
                ++st;
            }
        }
    return minim;
    }
};

int main()
{

    return 0;
}
