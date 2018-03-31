#include<bits/stdc++.h>
using namespace std;

int maximum[400][400];
int alloc[400][400];
int need[400][400];
int avail[400];
int n,r;
void update();
void input();
void show();
void cal();
void input1();
int xt=0;
int safetyseq(int avail[400],int need[400][400],int alloc[400][400],int n,int r);


int main()
{
       int i,j;
    	printf("Enter the no of Processes\t");
           scanf("%d",&n);
           printf("Enter the no of resource instances\t");
           scanf("%d",&r);
       	   input();
           printf("Enter the available Resources\n");
   
           for(j=0;j<r;j++)
           {
           	 scanf("%d",&avail[j]);
           }
       show();
       cal();
       if(xt==1)
       {
       		safetyseq(avail,need,alloc,n,r);
	   }
       
       
       return 0;
}


// take input 
void input()
{
	
	       printf("Enter the Max Matrix\n");
           for(int i=0;i<n;i++)
           {
              for(int j=0;j<r;j++)
              {
                   scanf("%d",&maximum[i][j]);
              }
           }
           printf("Enter the Allocation Matrix\n");
           for(int i=0;i<n;i++)
           {
              for(int j=0;j<r;j++)
              {
                 scanf("%d",&alloc[i][j]);
              }
           }

}



// print the matrix
void cal()
{
               int finish[400],temp,need[400][400],flag=1,k,c1=0;
               int dead[400];
               int safe[400];
               int i,j;
               for(i=0;i<n;i++)
               {
                              finish[i]=0;
               }
    //find need matrix
               for(i=0;i<n;i++)
               {
                      for(j=0;j<r;j++)
                      {
                          need[i][j]=maximum[i][j]-alloc[i][j];
                      }
               }
               
               while(flag)
               {
				flag=0;
				for(i=0;i<n;i++)	
				{
	             int c=0;
	             for(j=0;j<r;j++)
	             {
		            if((finish[i]==0)&&(need[i][j]<=avail[j]))
		            {
	                   c++;
	                   if(c==r)
	                   {
	                  for(k=0;k<r;k++)
	                  {
	                                 avail[k]+=alloc[i][j];
	                                 finish[i]=1;
	                                 flag=1;
	                  }
	                   if(finish[i]==1)
	                  {
	                      i=n;
				      }
	     	 		}
	    	  }
	  	}
	}
 }
                j=0;
                flag=0;
                for(i=0;i<n;i++)
                {
                  if(finish[i]==0)
                  {
                         dead[j]=i;
                         j++;
                         flag=1;
                  }
			   }
               if(flag==1)
               {
                  printf("\n\nSystem is in Deadlock and the Deadlock process are\n");
                  for(i=0;i<n;i++)
                  {
                        printf("P%d\t",dead[i]);
                  }
                  cout<<endl;
                  printf("1) Kill Process Press Process Number \n");
                  printf("2) Exit Press  -1\n");
                  int kt=n;
                  while(kt--)
                  {
                  	
                  	int nm;
                  	cin>>nm;
                  	if(nm!=-1)
                  	{
                  		
                  			for(int j=0;j<n;j++)
                  			{
                  				alloc[nm][j]=0;
                  				maximum[nm][j]=0;
						    }
						    printf("Process %d killed Successfully ",nm);
					  
					  cout<<endl;
                  }
                  
                  else
                  {
                  	break;
				  }
				  
				  cout<<endl<<endl;
				  cout<<"\t\t\t\tAfter Deleting Process \n";
				  cout<<"Allocation Matrix\n";
				  for(int i=0;i<n;i++)
				  {
				  	for(int j=0;j<n;j++)
				  	{
				  		cout<<alloc[i][j]<<" ";
					  }
					  cout<<endl;
				  }
				  cout<<endl;
				  cout<<"Maximum Matrix\n";
				   for(int i=0;i<n;i++)
				  {
				  	for(int j=0;j<n;j++)
				  	{
				  		cout<<alloc[i][j]<<" ";
					  }
					  cout<<endl;
				  }
	
				  
				  
				  }
				  
			   }
               else
               {
               		xt=1;
               		cout<<endl;
                   printf("\nNo Deadlock Occur\n");
                   
               }  
}

// print allocation and max matrix
void show()
{
       int i,j;
       cout<<endl<<endl;
       printf("Process\t Allocation\t Max\t Available ");
       for(i=0;i<n;i++)
       {
                      printf("\nP%d\t   ",i+1);
                      for(j=0;j<r;j++)
                      {
                          printf("%d\t",alloc[i][j]);
                      }
                      printf("\t");
                      for(j=0;j<r;j++)
                      {
                          printf("%d\t",maximum[i][j]); 
                      }
                      printf("\t");
                      if(i==0)
                      {
                         for(j=0;j<r;j++)
                         printf("%d\t",avail[j]);
                  	  }
                  	                    
       }
}

// print safe sequence
int safetyseq(int avail[400],int need[400][400],int allot[400][400],int P,int R)
{
    bool finish[P] = {0};
    int safeSeq[P];
    int work[R];
    for (int i = 0; i < R ; i++)
        work[i] = avail[i];
    int count = 0;
    while (count < P)
    {
        bool found = false;
        
        for (int p = 0; p < P; p++)
        {
            if (finish[p] == 0)
            {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j] || work[j]-need[p][j]<0)
                        break;
                if (j == R)
                {
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        
        if(found==true)
		{
			cout<<endl<<endl;
        cout<<"Safe sequence is:  ";
	    	for (int i = 0; i < P ; i++)
		        cout << safeSeq[i] << " ";
	        break;
		}
		else
		{
			cout<<endl<<endl;
			cout<<"System is not in Safe state.\n"<<endl;
			break;
		}
}
}
    
