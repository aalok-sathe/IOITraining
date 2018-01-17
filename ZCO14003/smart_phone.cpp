    #include <iostream>
    #include <vector>
    #include <algorithm>
    #define lld long long int
    using namespace std;
    //aalok_sathe
    int main()
    {
    	lld n/*a[n]*/; cin>>n;
    	vector <lld> v;
    	for (lld i=0; i<n; i++)
    	{
    		lld t; cin>>t;
    		v.push_back(t);
    	}
    	
    //	int N = sizeof(a)/sizeof(int);
    	sort(v.begin(), v.end());
    //	sort(a, a+n);
    	
    	lld max=0;
    	
    	for (lld i=0; i<n; i++)
    	{
    		//cout<<a[i]<<" \n";
    		lld y= v[i]*(n-i);
    		max=(y>max)?y:max;
    	}
    	cout<<max<<endl;
    } 
