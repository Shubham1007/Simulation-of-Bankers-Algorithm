#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int res[10],max[10],need[10],available,temp,free,tempava,sum=0;
	cout<<"Enter number of process\n";
	cin>>n;

	for(int i=0;i<n;i++)
		{
			cout<<"Enter resource and max for process"<<i<<endl;
			cin>>res[i]>>max[i];	
		}
	

	for(int i=0;i<n;i++)
		need[i] = max[i] - res[i];
	

	bool visited[10];
	for(int i=0;i<n;i++)
	visited[i] = false;
	

	cout<<"Enter Available\n";
	cin>>available;
	tempava = available;
	 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{

				if(need[j]<available && visited[j] == false)
				{

					temp = available - need[j];
					free = res[j] + need[j];	
					available = free + temp;
					visited[j] = true;
					
				}
			}				
	}
	

	for(int i=0;i<n;i++)
	sum+=res[i];
		
	if(sum+tempava == available)
	cout<<"Safe state";
	else
	cout<<"Unsafe state";
	return 0;
}
