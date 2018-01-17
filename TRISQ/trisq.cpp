    #include <iostream>
    //#include <limits>
    using namespace std;
    const int mx = 10005;
    int main()
    {
    	int arr[mx]; int add, count=2;
    	arr[0]=0;
    	for (int i=1; i<mx; i++)
    	{
    		if (i==1||i==2||i==3) add=0;
    		else if (i==4) add++;
    		else if (i%2==0) {
    			add+=count;
    			count+=1;
    		}
    		
    		arr[i]=add;
    	}
    	
    	int tst; cin>>tst;
    	while (tst--)
    	{
    		int y; cin>>y;
    		cout<<arr[y]<<endl;
    	}
    	
    	return 0;
    } 
    
