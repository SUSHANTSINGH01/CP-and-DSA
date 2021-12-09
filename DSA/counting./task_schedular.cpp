class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        
        unordered_map<char, int>mp;
        priority_queue<int> pq;
        int m=tasks.size();
        
        for(int i=0;i<m;i++)
        mp[tasks[i]]++;
        
        for(auto it: mp)
        pq.push(it.second);
        
        int ans=0;
        while(!pq.empty())
        {
            int top=pq.top(); 
            pq.pop();
            top--;
            vector<int>v;
            
            if(top>0)
            v.push_back(top);
            int i=0;
            ans++;
            while(i<n && !pq.empty())
            {
                if(pq.top()-1>0)
                v.push_back(pq.top()-1);
                pq.pop();
                ans++;
                i++;
            }
           
            if(i<n && v.size()>0) 
            ans+=(n-i);
            for(int i=0; i<v.size(); i++)
            pq.push(v[i]);
        }
        return ans;
    }
};
