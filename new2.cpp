class Solution{
    public:
    static bool sortBySecond(const pair<int,int>&a,const pair<int,int> & b){
        return a.second>b.second;
    }
    long long ForYou(int n, vector<int> &arr, int m, vector<vector<int>> &order)
    {
        const long long MOD=1e9+7;
        //Code Here
    
        unordered_map<long long,long long> mpp;
        for(int i=0;i<m;i++)
        {
            int s=order[i][0];
            while(s<=order[i][1])
            {
                ++mpp[s];
                ++s;
            }
        }
        vector<pair<int,int>> v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),sortBySecond);
        sort(arr.begin(),arr.end(),greater<int>());
        long long sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=(v[i].second*arr[i]);
            sum=sum%MOD;
        }
        
        return sum%MOD;
    }