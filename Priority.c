#include<stdio.h>
int main()
{
    int n,temp;
    printf("Enter the no.of processes : ");
    scanf("%d",&n);
    int bt[n];
    int p[n];
    int wt[n];
    int tat[n];
    int pri[n];
    float wtavg,tatavg;
    for(int i=0;i<n;i++)
    {
        printf("Enter Burst time and Priority for P%d : ",i);
        scanf("%d %d",&bt[i],&pri[i]);
        p[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(pri[j]<pri[i])
            {
                temp=pri[i];
                pri[i]=pri[j];
                pri[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    wt[0]=wtavg=0;
    tat[0]=tatavg=bt[0];
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        wtavg+=wt[i];
        tatavg+=tat[i];
    }
    printf("PROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for(int i=0;i<n;i++)
    {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],pri[i],bt[i],wt[i],tat[i]);
    }
    printf("Average waiting Time = %f\n",wtavg/n);
    printf("Average Turn Around Time = %f\n",tatavg/n);
}

/*
Enter the no.of processes : 5
Enter Burst time and Priority for P0 : 10 3
Enter Burst time and Priority for P1 : 1 1
Enter Burst time and Priority for P2 : 2 4
Enter Burst time and Priority for P3 : 1 5
Enter Burst time and Priority for P4 : 5 2
PROCESS	PRIORITY	BURST TIME	WAITING TIME	TURN AROUND TIME
	P1		1		1		0		1
	P4		2		5		1		6
	P0		3		10		6		16
	P2		4		2		16		18
	P3		5		1		18		19
Average waiting Time = 8.200000
Average Turn Around Time = 12.000000
*/