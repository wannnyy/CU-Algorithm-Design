class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>> d;
        vector<vector<int>> ans;
        for(auto g : points)
        {
            d.push_back(pair(distance(g[0],g[1]),g));
        }
        sort(d.begin(),d.end(),[](auto &left,auto &right){
            return left.first < right.first;
        });

        for(int i=0;i<k;i++){
            ans.push_back(d[i].second);
        }
        return ans;
    }


    int distance(int x, int y){
        return x*x + y*y;
    }

};