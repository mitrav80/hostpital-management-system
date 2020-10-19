#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct ad
{
    char name[30];
    char disease[30];
    int cabin,phone,age;
} x[100];
int n,i,j=0,a=0,sum=0,g,flag,num;
void readFile();
void writeToFile();
void add();
void view();
void search();
void edit();
void del();
void show();
int main()

{
    readFile();
    int c,i,q;
    printf("Hospital Management System\n");
    int m,n;

//making out the pattern
    
    for  (m=1; m<=4; m++)
    {
        for(n=1; n<=5; n++)
            printf(" ");
        for(n=1; n<=m-1; n++)
        {
            printf(" ");
        }
        for(n=1; n<=4-m+1; n++)
        {
            if(n==4-m+1 || m==1 || m==4)
                printf("*");
            else
                printf(" ");
        }
        for(n=1; n<=4-m+1; n++)
        {
            if(n==1 ||m==1 || m==4)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    while(c!=6)
    {

        printf("----Enter your choice----\n\n1. Add Information\n2. View Information\n3. Search\n4. Edit Information\n5. Delete Information\n6. Exit\n\nOption:");
        scanf("%d",&c);//choice for option
        fflush(stdin);//making it clear
        if(c==1)//add
        {
            system("clear");
            add();
        }
        else if(c==2)//view
        {
            system("clear");
            view();
        }
        else if(c==3)//search
        {
            system("clear");
            search();
        }
        else if(c==4)//edit
        {
            system("clear");
            edit();
        }
        else if(c==5)//delete
        {
            system("clear");
            del();
        }
        else if(c==6)
        {
            writeToFile();
            return 0;
        }
        else
        {
            system("clear");
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}

void add()   //adding data in database
{
    printf("\n\n");
    printf("Data inputed on the database : %d\n\n",num);//how many inputs
    printf("How many entry do you want to add? : \n");
    scanf("%d",&n);
    sum=n+num;

    for(i=num,j=0; i<sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter patient's Name : ");
        fgets(x[i].name, sizeof(x[i].name), stdin);
        printf("Enter the age : ");
        scanf("%d",&x[i].age);
        fflush(stdin);
        printf("Enter cabin no : ");
        scanf("%d",&x[i].cabin);
        fflush(stdin);
        printf("Enter disease : ");
        fgets(x[i].disease, sizeof(x[i].name), stdin);
        fflush(stdin);
        printf("Enter phone number : ");
        scanf("%d",&x[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}
// view detail
void view() 
{
    for (i=0; i<num; i++)
    {
        printf("\n");
        printf("Serial Number=%d\n",i);
        printf("Name = ");
        puts(x[i].name);
        printf("Disease = ");
        puts(x[i].disease);
        printf("Cabin no = %d\nPhone number = 0%d\nAge=%d",x[i].cabin,x[i].phone,x[i].age);
        printf("\n\n");
    }
}
// edit of data
void edit()
{
    int q,p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Disease\n3.Age\n4.Cabin\n5.Phone no.\n");
    printf("Option=");
    scanf("%d",&q);//option
    if(q<=5)
    {
        printf("Enter the serial no of that patient= (0 - %d)=",num-1);
        scanf("%d",&p);//serial number
        if(p<num)
        {
            if(q==1)
            {
                fflush(stdin);
                printf("Enter the new name : ");
                fgets(x[p].name, sizeof(x[p].name), stdin);

            }
            else if(q==2)
            {
                fflush(stdin);
                printf("Enter the new Disease : ");
                fgets(x[p].disease, sizeof(x[p].disease), stdin);
            }
            else if(q==3)
            {
                fflush(stdin);
                printf("Enter the new Age : ");
                scanf("%d",&x[p].age);
            }

            else if(q==4)
            {
                fflush(stdin);
                printf("Enter the new Cabin no : ");
                scanf("%d",&x[p].cabin);
            }

            else if(q==5)
            {
                fflush(stdin);
                printf("Enter the new Phone no : ");
                scanf("%d",&x[p].phone);
            }
        }
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}

void search()
{
    int s,h,f;
    char u[100];
    printf("By what do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.Cabin no.\n5.Phone no.\n6.Age\n\nOption : ");
    scanf("%d",&h);
    if(h==1)
    {
        printf("Enter Serial number of the patient=");
        scanf("%d",&s);
        if(s<num)
        {
            printf("\n");
            printf("Serial Number=%d\n",s);
            printf("Name = ");
            puts(x[s].name);
            printf("Disease = ");
            puts(x[s].disease);
            printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[s].cabin,x[s].phone,x[s].age);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if(h==2)//problem is here.........
    {
        int f=1;
        fflush(stdin);
        printf("Enter your name : ");
        fgets(u, sizeof(u), stdin);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\nNot Found\n");



    }
    else if(h==3)
    {
        int f=1;
        fflush(stdin);
        printf("Enter Disease : ");
        fgets(u, sizeof(u), stdin);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].disease)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
            }


        }

        if(f==1)
            printf("\nNot Found\n");


    }
    else if(h==4)
    {
        int f=1;
        printf("Enter Cabin number : ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].cabin)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
            }

        }

        if(f==1)
            printf("Not Found\n\n");

    }
    else if(h==5)
    {
        int f=1;
        printf("Enter Phone number : ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].phone)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found");
    }
    else if(h==6)
    {
        int f=1;
        printf("Enter Age : ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].age)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(x[g].name);
                printf("Disease = ");
                puts(x[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",x[g].cabin,x[g].phone,x[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Paitent Not Found\n\n");

    }
    else
        printf("\n\nInvalid input\n\n");




}

void del()
{
    int f,h;
    printf("Enter the paitent number of the patient that you want to delete:");
    scanf("%d",&f);
    if(f>0)
    {
        printf("Menu\n");
        printf("------------------------\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Disease\n4.Remove age\n5.Remove Cabin\n6.Remove phone number\nPlease select your option : ");
        scanf("%d",&h);
        if(h==1)
        {
            while(f<num)
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].disease,x[f+1].disease);
                x[f].age=x[f+1].age;
                x[f].cabin=x[f+1].cabin;
                x[f].phone=x[f+1].phone;
                f++;
            }
            num--;
        }
        else if(h==2)
        {
            strcpy(x[f].name,"Cleared");

        }
        else if(h==3)
        {
            strcpy(x[f].disease,"Cleared");
        }
        else if(h==4)
        {
            x[f].age=0;
        }
        else if(h==5)
        {
            x[f].cabin=0;
        }
        else if(h==6)
        {
            x[f].phone=0;
        }

    }
    else
        printf("\n\nInvalid patient number\n");

}

void readFile()
{
    FILE *fp = fopen("paitent.dat","r");
    if(fp == NULL)
    {
        //create a empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("paitent.dat","wr");
        fclose(fp);
        printf("File does not exist, Creating new file, exiting...\n\n\n");
    }

    num = fread(x, sizeof(struct ad),100, fp);
    fclose(fp);
}

void writeToFile() 
    FILE *fp = fopen("patient.dat","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct ad),num, fp);

    fclose(fp);
}
