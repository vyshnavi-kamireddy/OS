#include<stdio.h>

int main()
{
    int n,f,flag,pf=0,farthest,index,found;
    printf("Enter the size of the reference String : ");
    scanf("%d",&n);
    int rs[n];
    printf("Enter the reference String : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
    }
    printf("Enter no.of Frames : ");
    scanf("%d",&f);
    int m[f];
    for(int i=0;i<f;i++)
    {
        m[i]=-1;
    }
    printf("The page Replacement process = \n");
    for(int i=0;i<n;i++)
    {
        flag=0;
        for(int j=0;j<f;j++)
        {
            if(m[j]==rs[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int j=0;j<f;j++)
            {
                if(m[j]==-1)
                {
                    m[j]=rs[i];
                    flag=1;
                    pf++;
                    break;
                }
            }
        }
        if(flag==0)
        {
            farthest=-1;
            index=-1;
            for(int j=0;j<f;j++)
            {
                found=0;
                for(int k=i+1;k<n;k++)
                {
                    if(m[j]==rs[k])
                    {
                        found=1;
                        if(k>farthest)
                        {
                            farthest=k;
                            index=j;
                        }
                        break;
                    }
                }
                if(found==0)
                {
                    index=j;
                    break;
                }
            }
            m[index]=rs[i];
            pf++;
        }
        for(int j=0;j<f;j++)
        {
            printf("\t%d",m[j]);
        }
        printf("\n");
    }
    printf("The no.of page faults using OPTIMAL = %d",pf);
}

/*
Enter the size of the reference String : 5
Enter the reference String : 1 2 3 4 1
Enter no.of Frames : 3
The page Replacement process = 
	1	-1	-1
	1	2	-1
	1	2	3
	1	4	3
	1	4	3
The no.of page faults using OPTIMAL = 4
*/