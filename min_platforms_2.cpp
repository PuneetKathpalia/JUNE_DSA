class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<vector<int>> events;
    	for(int i = 0; i < n; i++) {
    	    events.push_back({arr[i],0});
    	    events.push_back({dep[i],1});
    	}
    	sort(events.begin(), events.end());
    	int maxTrains = 0;
        int trainCount = 0 ;
        for(int i = 0; i < events.size(); i++) {
            if(events[i][1] == 0) trainCount++;
            else trainCount--;
            maxTrains = max(maxTrains, trainCount);
        }
        return maxTrains;
    }
    
};