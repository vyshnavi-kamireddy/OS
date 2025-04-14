#include<stdio.h>

int main()
{
    int n,i,j,k,f,pf=0,count=0;
    printf("Enter the size of the reference String : ");
    scanf("%d",&n);
    int rs[n];
    printf("Enter the reference String : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
    }
    printf("Enter no.of Frames : ");
    scanf("%d",&f);
    int m[f];
    for(i=0;i<f;i++)
    {
        m[i]=-1;
    }
    printf("The Page replacement process is : \n");
    for(i=0;i<n;i++)
    {
        for(k=0;k<f;k++)
        {
            if(m[k]==rs[i])
            {
                break;
            }
        }
        if(k==f)
        {
            m[count++]=rs[i];
            pf++;
        }
        for(j=0;j<f;j++)
        {
            printf("\t%d",m[j]);
        }
        if(k==f)
        {
            printf("\tPF NO : %d",pf);
        }
        printf("\n");
        if(count==f)
        {
            count=0;
        }
    }
    printf("The no.of Page Faults using FIFO = %d",pf);
}

/*
Enter the length of the reference String: 20
Enter the reference String : 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
Enter no.of Frames : 3
The Page replacement process is : 
	7	-1	-1	PF NO : 1
	7	0	-1	PF NO : 2
	7	0	1	PF NO : 3
	2	0	1	PF NO : 4
	2	0	1
	2	3	1	PF NO : 5
	2	3	0	PF NO : 6
	4	3	0	PF NO : 7
	4	2	0	PF NO : 8
	4	2	3	PF NO : 9
	0	2	3	PF NO : 10
	0	2	3
	0	2	3
	0	1	3	PF NO : 11
	0	1	2	PF NO : 12
	0	1	2
	0	1	2
	7	1	2	PF NO : 13
	7	0	2	PF NO : 14
	7	0	1	PF NO : 15
The no.of Page Faults using FIFO = 15
*/
