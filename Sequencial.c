#include<stdio.h>
#include<string.h>
struct fileTable
{
    char name[20];
    int sb,nob;
}ft[30];
int main()
{
    int n,i,j;
    char s[20];
    printf("Enter No.of Files: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter File-%d Name: ",i+1);
        scanf("%s",&ft[i].name);
        printf("Enter the Starting Block of File-%d: ",i+1);
        scanf("%d",&ft[i].sb);
        printf("Enter No.of Blocks in File-%d: ",i+1);
        scanf("%d",&ft[i].nob);
    }
    printf("Enter the File Name to be Searched-- ");
    scanf("%s",&s);
    for(i=0;i<n;i++)
    {
        if(strcmp(s,ft[i].name)==0)
        {
            break;
        }
    }
    if(i==n)
    {
        printf("File Not Found");
    }
    else
    {
        printf("File-Name\tStarting-Block\tNo.of Blocks\tBlocks Occupied\n");
        printf("\t%s\t\t%d\t\t%d\t\t",ft[i].name,ft[i].sb,ft[i].nob);
        for(j=0;j<ft[i].nob;j++)
        {
            printf("%d,",ft[i].sb+j);
        }
    }
}


/*


Enter No.of Files: 3
Enter File-1 Name: A
Enter the Starting Block of File-1: 85
Enter No.of Blocks in File-1: 6
Enter File-2 Name: B
Enter the Starting Block of File-2: 102
Enter No.of Blocks in File-2: 4
Enter File-3 Name: C
Enter the Starting Block of File-3: 60
Enter No.of Blocks in File-3: 4
Enter the File Name to be Searched-- B
File-Name	Starting-Block	No.of Blocks	Blocks Occupied
	B		102		4		102,103,104,105,


*/