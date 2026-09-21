class Solution {
public:
    int hIndex(vector<int>& candidates) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        int h = 0;

        for (int i = 0; i < n; i++) {
            int papers = n - i;

            if (candidates[i] >= papers) {
                h = papers;
                break;
            }
        }

        return h;
    }
};