#include<stdio.h>
int main()
{
    int nb,nf,i,j,temp;
    printf("Enter the no.of Blocks: ");
    scanf("%d",&nb);
    printf("Enter the no.of Files: ");
    scanf("%d",&nf);
    int b[nb+1],bf[nb+1],f[nf+1],ff[nf+1],frag[nf+1];
    printf("Enter the size of the Blocks: \n");
    for(i=1;i<=nb;i++)
    {
        printf("Block %d: ",i);
        scanf("%d",&b[i]);
        bf[i]=0;
    }
    printf("Enter the size of the Files: \n");
    for(i=1;i<=nf;i++)
    {
        printf("File %d: ",i);
        scanf("%d",&f[i]);
        ff[i]=0;
        frag[i]=0;
    }
    for(i=1;i<=nf;i++)
    {
        for(j=1;j<=nb;j++)
        {
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];
                if(temp>=0)
                {
                    ff[i]=j;
                    break;
                }
            }
        }
        frag[i]=temp;
        bf[ff[i]]=1;
    }
    printf("\nFile NO\tFile Size\tBlock NO\tBlock Size\tFragment\n");
    for(i=1;i<=nf;i++)
    {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,f[i],ff[i],b[ff[i]],frag[i]);
    }
}


/*


Enter the no.of Blocks: 3
Enter the no.of Files: 2
Enter the size of the Blocks: 
Block 1: 5
Block 2: 2
Block 3: 7
Enter the size of the Files: 
File 1: 1
File 2: 4

File NO	File Size	Block NO	Block Size	Fragment
	1		1		1		5		4
	2		4		3		7		3


*/