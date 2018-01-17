    #include <iostream>
    #include <vector>
    #include <algorithm>
    #define num long long int
    using namespace std;
     
    int ar[10000007];
    int n,k;
     
    bool comp(int a, int b)
    {return a<b;
    }
     
    int main()
    {
    	cin>>n>>k;
    	int crt, maks=1;
    	for (int y=0; y<n; y++)
    	cin>>ar[y];
     
    	sort(ar, ar+n, comp);
    	crt=ar[0];
    	for (int h=1; h<n; h++)
    	{
    		if (ar[h]-crt>=k)
    		{
    			maks++;
    			crt=ar[h];
    		}
    	}
    	
    	
    	cout<<maks<<endl;
    	return 0;
    } 
