class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>freq(2001,0);
        for(auto i:nums){
            freq[i+1000]++;
        }
        vector<pair<int,int>>s;
        for(int i=0;i<2001;i++){
            if(freq[i]>0) s.push_back({freq[i],i-1000});
        }
        sort(s.begin(),s.end(),greater<pair<int,int>>());
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(s[i].second);
        }
        return res;
    }
};
