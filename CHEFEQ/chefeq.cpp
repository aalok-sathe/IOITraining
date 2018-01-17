    #include <iostream>
    #include <vector>
    #include <algorithm>
    #define big long long int
     
    using namespace std;
    /*hash include alkhwarizm*/
    // aalok_sathe
    int main()
    {
    	big t;
    	
    	cin>>t;
    	while (t--)
    	{
    		big n; cin>>n;
    		vector <big> vec;
    		
    		for (int i=0; i<n; i++)
    		{
    			int hhh; cin>>hhh; vec.push_back(hhh);
    		}
    		
    		sort(vec.begin(), vec.end());
    		
    		int count=0, max=0, curr=vec[0];
    		
    		for (int i=0; i<n; i++)
    		{
    			if (vec[i]==curr) 
    			{	
    				count++;
    				if (count>max) max=count;
    //				cout<<vec[i]<<endl<<count<<endl<<max<<endl;
    			}
    			else 
    			{
    				curr=vec[i]; count=1;
    			}
    			
    		}
    		
    		cout<<(n-max)<<endl;
    	}
    	
    	return 0;
    } 
