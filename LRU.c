#include<stdio.h>

int main()
{
    int n,f,pf=0,min,next=1;
    printf("Enter the size of the reference String : ");
    scanf("%d",&n);
    int rs[n];
    int flag[n];
    printf("Enter the reference String : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
        flag[i]=0;
    }
    printf("Enter the no.of Frames : ");
    scanf("%d",&f);
    int m[f];
    int count[f];
    for(int i=0;i<f;i++)
    {
        m[i]=-1;
        count[i]=0;
    }
    printf("The page Replacement process is : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<f;j++)
        {
            if(m[j]==rs[i])
            {
                flag[i]=1;
                count[j]=next;
                next++;
            }
        }
        if(flag[i]==0)
        {
            if(i<f)
            {
                m[i]=rs[i];
                count[i]=next;
                next++;
            }
            else
            {
                min=0;
                for(int j=0;j<f;j++)
                {
                    if(count[min]>count[j])
                    {
                        min=j;
                    }
                }
                m[min]=rs[i];
                count[min]=next;
                next++;
            }
            pf++;
        }
        for(int j=0;j<f;j++)
        {
            printf("\t%d",m[j]);
        }
        if(flag[i]==0)
        {
            printf("\tPF NO : %d",pf);
        }
        printf("\n");
    }
    printf("The no.of page faults using LRU = %d",pf);
}

/*
Enter the size of the reference String : 20
Enter the reference String : 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
Enter the no.of Frames : 3
The page Replacement process is : 
	7	-1	-1	PF NO : 1
	7	0	-1	PF NO : 2
	7	0	1	PF NO : 3
	2	0	1	PF NO : 4
	2	0	1
	2	0	3	PF NO : 5
	2	0	3
	4	0	3	PF NO : 6
	4	0	2	PF NO : 7
	4	3	2	PF NO : 8
	0	3	2	PF NO : 9
	0	3	2
	0	3	2
	1	3	2	PF NO : 10
	1	3	2
	1	0	2	PF NO : 11
	1	0	2
	1	0	7	PF NO : 12
	1	0	7
	1	0	7
The no.of page faults using LRU = 12
*/