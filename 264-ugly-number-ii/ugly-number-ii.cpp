class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        vector<queue<int>>arr(3);
        unordered_set<int> present;
        //arr[0]->2 arr[1]->3 arr[2]->5
        arr[0].push(2);
        present.insert(2);
        arr[1].push(3);
        present.insert(3);
        arr[2].push(5);
        present.insert(5);
        int num;
        for(int i=2;i<=n;i++)
        {
            if (!arr[0].empty() && (arr[1].empty() || arr[0].front() <= arr[1].front()) &&
    (arr[2].empty() || arr[0].front() <= arr[2].front()))
{
    num = arr[0].front();
    arr[0].pop();
}
else if (!arr[1].empty() && (arr[0].empty() || arr[1].front() <= arr[0].front()) &&
         (arr[2].empty() || arr[1].front() <= arr[2].front()))
{
    num = arr[1].front();
    arr[1].pop();
}
else if (!arr[2].empty())
{
    num = arr[2].front();
    arr[2].pop();
}
else
{
    return -1;
}
            //insert
            if(num*1ll*2<=INT_MAX && present.find(num*2)==present.end())
            {arr[0].push(num*2);present.insert(num*2);}
            if(num*1ll*3<=INT_MAX && present.find(num*3)==present.end())
            {arr[1].push(num*3);present.insert(num*3);}
            if(num*1ll*5<=INT_MAX && present.find(num*5)==present.end())
            {arr[2].push(num*5);present.insert(num*5);}
        }
        return num;
    }
};