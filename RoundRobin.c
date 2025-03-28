#include<stdio.h>
int main()
{
    int n,t,temp=0;
    printf("Enter the no.of processes : ");
    scanf("%d",&n);
    int bt[n];
    int ct[n];
    int tat[n];
    int wt[n];
    float wtavg=0,tatavg=0;
    for(int i=0;i<n;i++)
    {
        printf("Enter Burst Time for P%d : ",i);
        scanf("%d",&bt[i]);
        ct[i]=bt[i];
    }
    printf("Enter the time slice  : ");
    scanf("%d",&t);
    int max=bt[0];
    for(int i=1;i<n;i++)
    {
        if(max<bt[i])
        {
            max=bt[i];
        }
    }
    for(int j=0;j<(max/t)+1;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(bt[i]!=0)
            {
                if(bt[i]<=t)
                {
                    tat[i]=temp+bt[i];
                    temp=temp+bt[i];
                    bt[i]=0;
                }
                else
                {
                    bt[i]=bt[i]-t;
                    temp=temp+t;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        wt[i]=tat[i]-ct[i];
        wtavg+=wt[i];
        tatavg+=tat[i];
    }
    printf("PROCESS\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for(int i=0;i<n;i++)
    {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n",i,ct[i],wt[i],tat[i]);
    }
    printf("Average waiting Time = %f\n",wtavg/n);
    printf("Average Turn Around Time = %f\n",tatavg/n);
}

/*
Enter the no.of processes : 3
Enter Burst Time for P0 : 24
Enter Burst Time for P1 : 3
Enter Burst Time for P2 : 3
Enter the time slice  : 3
PROCESS	BURST TIME	WAITING TIME	TURN AROUND TIME
	P0		24		6		30
	P1		3		3		6
	P2		3		6		9
Average waiting Time = 5.000000
Average Turn Around Time = 15.000000
*/