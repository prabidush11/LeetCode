class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        //need to find their common prefix
        int ans=0;
        bitset<31> left(l);
        bitset<31> right(r);
        int idx=30;
        while(idx>=0)
        {
            if(left[idx]!=right[idx--])
            break;
        }
        idx++;
        //this is the common prefix
        //next itll be zero
        for(int power=30;power>=idx;power--)
        {
            ans+=left[power]*pow(2,power);
        }
        return ans;
    }
};