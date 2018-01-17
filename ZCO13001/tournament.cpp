    #include <iostream>
    #include <vector>
    #include <algorithm>
    //aalok_sathe
    using namespace std;
     
    int main()
    {
    	ios_base::sync_with_stdio(0);
    	cin.tie(NULL);
    	long long int n;//,a[n+2]; 
    	cin>>n; long long int rev=0;
    	vector <long long int> sum,a;
    	
    	for (int i=0; i<n; i++)
    	{
    		long long int k; cin>>k; a.push_back(k);
    	}
    	sort(a.begin(), a.end());
    	
    	sum.push_back(a[0]);
    	for (long long int i=1; i<n-1; i++)
    	sum.push_back(sum[i-1] + a[i]);
    	
    	for (long long int i=n-1; i>0; i--)
    	{
    		rev += a[i]*i - sum [i-1];
    	}
    	
    /*	for (int i=0; i<n; i++)
    		for (int j=i+1; j<n; j++)
    			if (i!=j) rev += (a[i]>a[j])?a[i]-a[j]:a[j]-a[i];
    */			
    	cout<<rev;
    	
    	return 0;
    } 
