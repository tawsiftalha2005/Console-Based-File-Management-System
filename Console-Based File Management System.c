#include<stdio.h>
#include<string.h>
#define MAX 10
#include<stdlib.h>

char fileName[MAX][20];
int fileSize[MAX];
int totalfiles=0;

void addFile()
{
    if(totalfiles>=MAX)
    {
        printf("File limit reached\n");
        return;
    }
    printf("Enter file name: ");
    scanf("%s",fileName[totalfiles]);

    printf("Enter file size: ");
    scanf("%d",&fileSize[totalfiles]);

    totalfiles++;


}

void displayFiles()
{
    int i;
    if(totalfiles==0)
    {
        printf("No files found\n");
        return;
    }
    for(i=0; i<totalfiles; i++)
    {
        printf("%d. %s-%dKB\n",i+1,fileName[i],fileSize[i]);
    }
}

void searchFile()
{
    char search[20];
    int i,found=0;

    printf("Enter file name to search: ");
    scanf("%s",search);

    for(i=0; i<totalfiles;i++)
    {
        if(strcmp(fileName[i],search)==0)
        {
            printf("File found: %s(%dKB)\n",fileName[i],fileSize[i]);
            found=1;
            break;
        }
    }
    if(!found)
        printf("File not found\n");

    }

    void sortFiles()
    {
        int i,j,tempSize;
        char tempName[20];

    for(i=0; i<totalfiles-1; i++)
    {
       for(j=i+1; j<totalfiles; j++)
       {
           if(fileSize[i]>fileSize[j])
           {
               tempSize=fileSize[i];
               tempSize=fileSize[i];
               fileSize[i]=fileSize[j];
               fileSize[j]=tempSize;

               strcpy(tempName,fileName[i]);
               strcpy(fileName[i],fileName[j]);
               strcpy(fileName[j],tempName);
           }
       }
    }
   printf("Files sorted by size\n");
    }

    char stack[MAX][20];
    int top=-1;

    void openFile()
    {
        if(totalfiles==0)
        {
            printf("No files available\n");
            return;
        }
        if(top==MAX-1)
        {
            printf("Stack full\n");
            return;
        }
        strcpy(stack[++top],fileName[totalfiles-1]);
        printf("Opened file: %s\n",stack[top]);

    }

    void showRecentFiles()
    {
        int i;
        if(top==-1)
        {
            printf("No recent files\n");
            return;
        }
        for(i=top;i>=0;i--)
        {
            printf("%s\n",stack[i]);
        }
    }


    char queue[MAX][20];
    int front=0,rear=-1;

    void addToQueue()
    {
        if(rear==MAX-1)
        {
          printf("Queue full\n");
          return;
        }
        printf("Enter file name for upload: ");
        scanf("%s",queue[++rear]);

    }
void processQueue()
{
    if(front>rear)
    {
        printf("Queue empty\n");
        return;
    }
    printf("Processed file: %s\n",queue[front]);
    front++;
}

struct node {
    char name[20];
    struct node* next;
};

struct node* head = NULL;

void addFileList() {
    struct node newNode;
    struct node* temp;

    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    printf("Enter file name: ");
    scanf("%s", ptr->name);

    ptr->next = NULL;

    if (head == NULL) {
        head = ptr;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}
void showFileList() {
    struct node* temp = head;

    if (temp == NULL) {
        printf("List empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}
int graph[MAX][MAX];
int visited[MAX];
int n;

void bfs(int start)
{
    int q[MAX],f=0,r=0,i;
    q[r++]=start;
    visited[start]=1;

    while(f<r)
    {
        start=q[f++];
        printf("%d",start);

        for(i=0; i<n; i++)
        {
            if(graph[start][i]==1 &&visited[i]==0)
            {
                q[r++]=i;
                visited[i]=1;
            }
        }
    }
}

void dfs(int v)
{
    int i;
    visited[v]=1;
    printf("%d ",v);

    for(i=0; i<n; i++)
    {
        if(graph[v][i]==1 && visited[i]==0)
            dfs(i);
    }
}



void hanoi(int n, char from, char to, char aux)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",from,to);
        return;
    }
    hanoi(n-1,from,aux,to);
    printf("Move disk %d from %c %c\n",n,from,to);
    hanoi(n-1,aux,to,from);

}
int main()
{
    int choice,i,j;

    while(1)
    {
        printf("\n-----FILE MANAGEMENT SYSTEM-----\n");
        printf("1.Add File\n");
        printf("2.Display Files\n");
        printf("3.Search File\n");
        printf("4.Sort Files\n");
        printf("5.Open File (Stack)\n");
        printf("6.Recent Files\n");
        printf("7.Upload Queue\n");
        printf("8.Process Upload\n");
        printf("9.Linked List\n");
        printf("10.Graph BFS & DFS\n");
        printf("11.Tower of Hanoi\n");
        printf("0.Exit\n");
        printf("Enter choice: ");

        scanf("%d",&choice);

        if(choice==0)
            break;

        switch(choice)
        {
            case 1:addFile();break;
            case 2:displayFiles();break;
            case 3:searchFile();break;
            case 4:sortFiles();break;
            case 5:openFile();break;
            case 6:showRecentFiles();break;
            case 7:addToQueue();break;
            case 8:processQueue();break;
            case 9:addFileList();
                   showFileList();
                    break;
            case 10:
                printf("Enter number of nodes: ");
                scanf("%d",&n);

                printf("Enter adjaceny matrix:\n");
                for(i=0; i<n; i++)
                    for(j=0; j<n; j++)
                    scanf("%d",&graph[i][j]);

                for(i=0; i<n; i++)
                    visited[i]=0;

                printf("BFS:");
                bfs(0);

                for(i=0; i<n; i++)
                    visited[i]=0;

                printf("\nDFS:");
                dfs(0);
                printf("\n");
                break;
            case 11:
                hanoi(3,'A','C','B');
                break;

    }
}
return 0;
}
