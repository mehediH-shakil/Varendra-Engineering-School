#include<stdio.h>

struct student
{
    int roll;
    char name[30];
    char Class[30];
}s;

void admission()
{
    system("cls");
    FILE *fp;
    fp = fopen("ves.txt", "a");
    printf("Enter the Roll     : ");
    scanf("%d", &s.roll);
    printf("Enter the Name     : ");
    scanf("%s", &s.name);
    printf("Enter the Class    : ");
    scanf("%s", &s.Class);
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}


void display()
{
    system("cls");
    FILE *fp1;
    printf("==========================Result Display==========================\n");
    fp1 = fopen("ves.txt","r");
    printf("\nRoll\t\t\t\tName\t\t\t\tClass\n\n");
    while (fread(&s,sizeof(s),1,fp1))
    printf("%d\t\t\t%s\t\t\t\t%s\n",s.roll,s.name,s.Class);
    printf("\n==================================================================");
    fclose(fp1);
}


void search()
{
    system("cls");
    FILE *fp2;
    int r,vu,a;
    printf("\nEnter the Roll  : ");
    scanf("%d", &r);
    a=aroll(r);
    if(a==0)
        printf("Roll No %d is not available in the file\n",r);
    else
    {
        fp2 = fopen("ves.txt", "r");
        while (fread(&s,sizeof(s),1,fp2))
        {
            vu= s.roll;
            if (vu==r)
            {
                printf("==========================Result Display==========================\n\n");
                printf("\nRoll    =  %d",s.roll);
                printf("\nName    =  %s",s.name);
                printf("\nClass   =  %s\n",s.Class);
                printf("\n==================================================================");
            }
        }
        fclose(fp2);
    }
}


void Delete()
{
    system("cls");
    FILE *fp1;
    FILE *fp2;
    int r,vu;
    printf("Enter the Roll : ");
    scanf("%d",&r);
    if(aroll(r)==0)
        printf("Roll no %d is not available in the file\n",r);
    else
    {
        system("cls");
        fp1=fopen("ves.txt","r");
        fp2=fopen("vu.txt","w");
        while (fread(&s,sizeof(s),1,fp1))
        {
            vu=s.roll;
            if(vu!=r)
                fwrite(&s,sizeof(s),1,fp2);
        }
        fclose(fp1);
        fclose(fp2);
        fp1 = fopen("ves.txt","w");
        fp2 = fopen("vu.txt","r");
        while (fread(&s,sizeof(s),1, fp2))
            fwrite(&s,sizeof(s),1, fp1);
        printf("\nRecord Deleted\n");
        fclose(fp1);
        fclose(fp2);
    }

}

void modify()
{
    system("cls");
    int a;
    FILE *fp3;
    FILE *fp4;
    int vu,r,ch;
    printf("Enter roll number to update: ");
    scanf("%d",&r);
    a=aroll(r);
    if(a==0)
    {
        printf("Roll number %d is not Available in the file",r);
    }
    else
    {
        fp4 = fopen("ves.txt", "r");
        fp3 = fopen("vu.txt", "w");
        while(fread(&s,sizeof(s),1,fp4))
        {
            vu=s.roll;
            if(vu!=r)
                fwrite(&s,sizeof(s),1,fp3);
            else
            {
                printf("\n\t1. Update Name of Roll Number %d",r);
                printf("\n\t2. Update Class of Roll Number %d",r);
                printf("\n\t3. Update both Name and Class of Roll Number %d",r);
                printf("\nEnter your choice:");
                scanf("%d",&ch);
                switch (ch)
                {
                case 1:
                    printf("Enter Name:");
                    scanf("%s",&s.name);
                    break;
                case 2:
                    printf("Enter Class : ");
                    scanf("%s",&s.Class);
                    break;
                case 3:
                    printf("Enter Name: ");
                    scanf("%s", &s.name);
                    printf("Enter Class: ");
                    scanf("%s", &s.Class);
                    break;
                default:
                    printf("Invalid Selection");
                    break;
                }
                fwrite(&s,sizeof(s),1,fp3);
            }
        }
        fclose(fp4);
        fclose(fp3);
        fp3 = fopen("ves.txt","w");
        fp4 = fopen("vu.txt","r");
        while (fread(&s,sizeof(s),1,fp3))
        {
            fwrite(&s,sizeof(s),1,fp4);
        }
        fclose(fp4);
        fclose(fp3);
        printf("Recode updated\n");
    }
}

int aroll(int r)
{
    system("cls");
    FILE *fp;
    int c = 0;
    fp = fopen("ves.txt", "r");
    while (!feof(fp))
    {
        fread(&s,sizeof(s),1,fp);

        if (r==s.roll)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int empty()
{
    system("cls");
    int c = 0;
    FILE *fp;
    fp = fopen("ves.txt", "r");
    while (fread(&s,sizeof(s),1,fp))
        c = 1;
    fclose(fp);
    return c;
}


int main()
{
    int c, temp;
    do
    {
        printf("\n\n\n");
        printf("\t\t\t|-----------------------------|\t\t\t\n");
        printf("\t\t\t|           WLCOME            |\t\t\t\n");
        printf("\t\t\t| VARENDRA ENGINNERING SCHOOL |\t\t\t\n");
        printf("\t\t\t|     RAJSHAHI,BANGLADESH     |\t\t\t\n");
        printf("\t\t\t|-----------------------------|\t\t\t\n");
        printf("\t\t\t| Developer By @ Mehedi Hasan |\t\t\t\n");
        printf("\t\t\t|-----------------------------|\t\t\t\n");
        printf("1. Admission\n");
        printf("2. Student Information\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Modify\n");
        printf("0. Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &c);
        printf("\n");
        switch (c)
        {
        case 1:
            admission();
            break;
        case 2:
            temp=empty();
            if (temp==0)
                printf("\nThe file is EMPTY\n");
            else
                display();
            break;
        case 3:
            search();
            break;
        case 4:
            Delete();
            break;
        case 5:
            modify();
            break;
        case 0:
            printf("\t\t\t\t-------------\t\t\t\n");
            printf("\t\t\t\t| THANK YOU |\t\t\t\n");
            printf("\t\t\t\t| FOR VISIT |\t\t\t\n");
            printf("\t\t\t\t-------------\t\t\t\n");
            break;
        default:
            printf("\nYour choice is wrong\n");
            printf("Please try again...\n");
            break;
        }
    }
    while (c!=0);
}
