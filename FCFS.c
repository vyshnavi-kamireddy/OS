#include<stdio.h>
int main()
{
    int n;
    printf("Enter the no.of processes : ");
    scanf("%d",&n);
    int bt[n];
    int wt[n];
    int tat[n];
    float wtavg,tatavg;
    for(int i=0;i<n;i++)
    {
        printf("Enter the burst Time for P%d : ",i);
        scanf("%d",&bt[i]);
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
    printf("PROCESS\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for(int i=0;i<n;i++)
    {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
    }
    printf("Average waiting Time = %f\n",wtavg/n);
    printf("Average Turn Around Time = %f\n",tatavg/n);
}

/*
Enter the no.of processes : 3
Enter the burst Time for P0 : 24
Enter the burst Time for P1 : 3
Enter the burst Time for P2 : 3
PROCESS	BURST TIME	WAITING TIME	TURN AROUND TIME
	P0		24		0		24
	P1		3		24		27
	P2		3		27		30
Average waiting Time = 17.000000
Average Turn Around Time = 27.000000
*/