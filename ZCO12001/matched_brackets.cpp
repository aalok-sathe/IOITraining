    #include <iostream>
    //aalok_s
    using namespace std;
     
    int main()
    {
    	//variables:
    	int depth=0,depthpos=0, maxlen=0, lenpos=0, lenctr=0, depctr=0, count=0;
    	int curlen=0, curlenpos=0, curdep=0, curdeppos=0;
    	int n,tmp;
    	cin>>n;
    	
    	for (int i=0; i<n; i++)
    	{
    		cin>>tmp;
    		
    		if (tmp==1)
    		{
    			count++;					//number of unmatched brackets//
    			
    			curdep++;
    			curdeppos=i;
    			
    			curlen++;
    			curlenpos=i+1-curlen;
    			
    			if (curdep>depth) {
    				depth=curdep; depthpos=curdeppos+1;
    			}
    			
    		}
    		else
    		{
    			count--;
    			
    			curdep--;
    			curdeppos=i;
    			
    			curlen++;
    			curlenpos=i+1-curlen;
    			
    			if (count==0) 
    			{	
    				lenpos=(curlen>maxlen)?curlenpos+1:lenpos;
    				maxlen=(curlen>maxlen)?curlen:maxlen;
    				
    				curlen=0;
    			}
    		}
    	}
    	
    	cout<<depth<<' '<<depthpos<<' '<<maxlen<<' '<<lenpos<<'\n';
    	return 0;
    } 
