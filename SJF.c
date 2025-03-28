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
    float wtavg,tatavg;
    for(int i=0;i<n;i++)
    {
        printf("Enter burst time for P%d : ",i);
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(bt[j]<bt[i])
            {
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
    printf("PROCESS\tBURST TIME\tWAITING TIME\tTURN AROUND TIME\n");
    for(int i=0;i<n;i++)
    {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf("Average waiting Time = %f\n",wtavg/n);
    printf("Average Turn Around Time = %f\n",tatavg/n);
}

/*
Enter the no.of processes : 4
Enter burst time for P0 : 6
Enter burst time for P1 : 8
Enter burst time for P2 : 7
Enter burst time for P3 : 3
PROCESS	BURST TIME	WAITING TIME	TURN AROUND TIME
	P3		3		0		3
	P0		6		3		9
	P2		7		9		16
	P1		8		16		24
Average waiting Time = 7.000000
Average Turn Around Time = 13.000000
*/