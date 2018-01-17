    //triathlon-c/cpp
    //aalok_sathe
    #include <stdio.h>
    #include <algorithm>
    #include <utility>
    #include <vector>
    using namespace std;
     
    bool paircmp(pair<int,int> firstelem, pair<int,int> secondelem){
    	return firstelem.first > secondelem.first;
    }
    int main()
    {
    	int n,x,y,z,i;
    	pair<int,int> pa;
    	vector <pair<int,int> > vec;
    	scanf("%d", &n);
    	
    	for (i=0; i<n; i++){
    		scanf("%d %d %d", &x,&y,&z);
    		pa.second=x;pa.first=y+z;
    		
    		vec.push_back(pa);	
    	}
    	sort(vec.begin(), vec.end(), paircmp);
    	
    	int maxtime=0, cnt=0;
    	for (i=0; i<n; i++){
    		maxtime = max(maxtime, cnt+vec[i].first+vec[i].second);
    		cnt+=vec[i].second;
    	}
    	
    	printf("%d", maxtime);
    	
    	return 0;
    }
