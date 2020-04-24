#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct my
{
    char name[20];
    char number[20];
    struct my *next;
}my;
my *head = NULL;

/*void newdata()
{
    FILE *file;
    char name[20];
    int number,j,k,i,p,n;
    printf("Enter the total number of persons : ");
    scanf("%d",&n);
    file = fopen("tee.txt","a");
    for(p=1;p<=n;p++)
    {
        printf("Enter the name of the person %d : ",p);
        scanf(" %[^\n]s",&name);
        printf("Enter the total number of persons : ",p);
        scanf("%d",&number);
        j=strlen(name);
        k=18-j;
        fprintf(file,"%s",name);
        for(i=0;i<k;i++)
            fprintf(file,"_");
        fprintf(file,"%d",number);
        fprintf(file,"\n");
    }
    fclose(file);
}*/

void newdata()
{
    FILE *file;
    my *newperson,*temp;
    int i,n,j,k;
    file = fopen("tee.txt","a");
    //fprintf(file,"hello");
    if(file==NULL)
        printf("there is no file named this");
    else
    {
        printf("file is open\n");
        printf("Enter the total number of persons : ");
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            newperson = malloc(sizeof(my));
            printf("Enter the name of the person %d : ",i);
            scanf(" %[^\n]s",&newperson -> name);
            printf("Enter the number of person %d : ",i);
            scanf(" %[^\n]s",&newperson -> number);
            newperson -> next = NULL;

            if(head==NULL)
            {
                head = newperson;
            }
            else
            {
                temp = head;
                while(temp->next!=NULL)
                {
                    temp = temp -> next;
                }
                temp -> next = newperson;
            }
        }
        temp = head;
        while(temp!=NULL)
        {
            //printf("%s ---- %d",temp->name,temp->number);
            j=strlen(temp->name);
            k=18-j;
            fprintf(file,"%s",temp->name);
            for(i=0;i<k;i++)
                fprintf(file," ");
            fprintf(file,"%s",temp->number);
            temp = temp -> next;
            fprintf(file,"\n");
        }
        fclose(file);
    }
}
void display()
{
    FILE *file;
    char c[90];

    file = fopen("tee.txt","r");
    if(file==NULL)
        printf("there is no file named this");
    else
    {
        printf("Name              Number\n");
        printf("-----------|----------------\n\n");
        while(!feof(file))
        {
        fgets(c,85,file);
        printf("%s",c);
        c[0]='\0';
        }
        fclose(file);
    }
}
void search()
{
    FILE *file;
    char c[90],ch[20],com[20];
    int j,i,k=0,p=0;

    file = fopen("tee.txt","r");
    if(file == NULL)
    printf("there is no file named this\n");
    else
    {
        printf("Enter the name of the person : ");
        scanf(" %[^\n]s",&ch);
        j=strlen(ch);
        while(!feof(file))
        {
            fgets(c,85,file);
            for(i=0;i<j;i++)
            {
                com[k] = c[i];
                k++;
            }
            com[k]='\0';
            k = 0;
            if(strcmp(ch,com)==0)
            {
                p=1;
                printf("Name              Number\n");
                printf("-----------|----------------\n");
                printf("%s",c);
                break;
            }
        }
        if(p==0)
            printf("This person does not exists in file\n");
        p=0;
    fclose(file);
    }
}
void delate()
{
    FILE *file,*file1;
    int j,i,k=0,p=0;
    char c[90],d[90],ch[20],com[20];
    file = fopen("tee.txt","r");
   file1 = fopen("temp.txt","w");
   fclose(file1);
   file1 = fopen("temp.txt","a");

    if(file ==  NULL)
        printf("file does not exists");
    else
    {
        printf("Enter the name of the person : ");
        scanf(" %[^\n]s",&ch);
        j=strlen(ch);
        while(!feof(file))
        {
            fgets(c,85,file);
            for(i=0;i<j;i++)
            {
                com[k] = c[i];
                k++;
            }
            com[k]='\0';
            k = 0;
            if(strcmp(ch,com)!=0)
            {
               fprintf(file1,"%s",c);
            }
            else
            {
                p=1;
            }
               c[0]='\0';
        }
    }
    fclose(file);
    fclose(file1);
    int r;
   remove("tee.txt");
   r = rename("temp.txt","tee.txt");

   if(r == 0 && p==1)
      printf("Deleted successfully");
    else
      printf("Unable to delete or contact not exist");
    p=0;
}

int main()
{
    int l;
    while(1)
    {
    printf("\nwhat do you want to do : \n");
    printf("\t\t\t1. Add\n");
    printf("\t\t\t2. Display\n");
    printf("\t\t\t3. Search\n");
    printf("\t\t\t4. Delete\n");
    printf("\t\t\t0. End\n");
    printf("Enter your choice : ");
    scanf("%d",&l);
    if(l==1)
    newdata();
    else if(l==2)
    display();
    else if(l==3)
    search();
    else if(l==4)
    delate();
    else if(l==0)
        break;
    }
    return 0;
}
