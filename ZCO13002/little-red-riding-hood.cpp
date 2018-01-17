    #include <iostream>
    #include <limits.h>
    #include <stdio.h>
    //aalok_sathe, 14 nov 2015, 21:56
     
    using namespace std;
     
    int grid[3][500][500]={0};  // [0][x][y] marks abs values. [1][x][y] marks availabiity(safe=1, unsafe=0), [3][][] marks reachability
    int charm[10000][3]={0}; // [index of charm][x,y,k]
     
    int main()
    {
    	int n,m; cin>>n>>m;
    	
    	for (int i=0; i<n; i++)      // input grid into [0][][] for abs vals.
    		for (int j=0; j<n; j++)
    			cin>>grid[0][i][j];
    			
    //		cout<<grid[0][n-1][n-1];
    			
    	for (int i=0; i<m; i++)        // input charms
    		for (int j=0; j<3; j++) {
    			cin>>charm[i][j];
    		//	if (j<2) charm[i][j]--;
    		}
    			
    			
    	for (int i=0; i<m; i++)          // marking all safe cells as 1
    	{
    		int xc = charm[i][0]-1, yc = charm[i][1]-1, k = charm[i][2];
    //		printf("%d %d %d\n", xc,yc,k);
    		
    		for (int x=0; x<=k; x++)
    		{
    	//		int ab = (x>-x)?x:-x;
    	//		printf(" ab=%d ", ab);
    			for (int y=k-x; y>=0; y--) {
    				//int y=k-x;
    	//			printf(" x=%d y=%d xc=%d yc=%d\n", x,y,xc,yc);
    				
    				if (xc+x < n and yc+y < n) {
    					grid[1][xc+x][yc+y]=1;
    			//		printf("1 %d\n", grid[1][xc+x][yc+y]);
    				}
    				
    				if (xc+x < n and yc-y >= 0) {
    					grid[1][xc+x][yc-y]=1;
    		//			printf("2 %d\n", grid[1][xc+x][yc-y]);
    				}
    				
    				if (xc-x >= 0 and yc-y >= 0) {
    					grid[1][xc-x][yc-y]=1;
    		//			printf("3 %d\n", grid[1][xc-x][yc-y]);
    				}
    				
    				if (xc-x >= 0 and yc+y < n) {
    					grid[1][xc-x][yc+y]=1;
    //					printf("4 %d\n", grid[1][xc-x][yc+y]);
    				}
    				
    				
    				
    			}
    		}
    			
    	}
    	                   
    	grid[2][0][0]=1; grid[1][0][0]=1;
    					                                            // dp exercise
    	if (grid[1][n-1][n-1])								// if end position can be reached (1) based on charm
    	for (int i=0; i<n; i++)
    		for (int j=0; j<n; j++)
    		{
    			if (i==0 and j==0); //printf(" i,j are 0. %d\n" ,grid[0][i][j]);
    			else
    			if (grid[1][i][j])                   // influence of charm
    			{
    				if (i-1>=0) grid[2][i][j]=max(grid[2][i-1][j],grid[2][i][j]);
    				if (j-1>=0) grid[2][i][j]=max(grid[2][i][j-1],grid[2][i][j]);
    				
    		//		printf(" val %d i %d j %d\n", grid[2][i][j],i,j);
    				if (grid[2][i][j])				// if cell is reachable overall (2) then update its dp abs. value to minimum
    				{
    					int minn;
    					
    					int u=0;
    					
    					if (i-1>=0 and grid[2][i-1][j]){
    						minn=(grid[0][i-1][j]);
    						u=1;
    					} 
    					
    					if (j-1>=0 and grid[2][i][j-1] and u) minn=(grid[0][i][j-1]<minn)?minn:grid[0][i][j-1];
    					else if (j-1>=0 and grid[2][i][j-1]) minn=(grid[0][i][j-1]);
    					
    	//				printf(" grid[0][i][j] %d\n",grid[0][i][j]);
    					
    					grid[0][i][j]+=minn;
    					
    	//				printf("%d abs %d i %d j\n", grid[0][i][j],i,j);
    				}
    				
    			}
    						 
    		}
    	else grid[2][n-1][n-1]=0;
     
    	if (grid[2][n-1][n-1]) cout<<"YES\n"<<grid[0][n-1][n-1];
    	else cout<<"NO\n";
    	
    	return 0;
    }
     
    /* diagnostic print statement
    cout<< " 1 \n"; */ 
