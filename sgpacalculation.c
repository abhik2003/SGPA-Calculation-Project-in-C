/*                                             SGPA CALCULATION PROJECT IN C
                                       By: Abhik Maji & Preetam Pati (CSE IIIT Kalyani)                                                    */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUBCR1 3                //CSC 101 
#define SUBCR2 3                //ECC 101
#define SUBCR3 4                //MAC 101
#define SUBCR4 4                //PHC 101
#define SUBCR5 3                //HUC 101
#define SUBCR6 3                //HUC 102
#define SUBCR7 2                //CSC 111
#define SUBCR8 2                //ECC 111

#define SUB1 "CSC 101"
#define SUB2 "ECC 101"
#define SUB3 "MAC 101"
#define SUB4 "PHC 101"
#define SUB5 "HUC 101"
#define SUB6 "HUC 102"
#define SUB7 "CSC 111"
#define SUB8 "ECC 111"

FILE *fptr;
FILE *fptr2;

void welcome();                                 
void line();
int password();                               
void new_password();                            
int update_password();                          
void reset_password();
void menu();                                    
void add_marks();                                
void update();                                  
void view_result();                             
void search_by_reg_no();
void search_by_grade();
void generate_result_reg_wise();
void generate_result_sgpa_wise();
void search_by_name();
void overall_result();
int sub_score(int marks);
char generate_grade(int point);
int student_count();
int student_count2();

int main()
{
    char ch;
    int password_match;
    welcome();
    password_match=password();
    if(password_match==1)
       menu();
    else 
        {

            printf("\n\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**--**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
            printf("\n\t\t            =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            printf("\n\t\t            =                                                                                                                                                   ="); 
            printf("\n\t\t            =                                                SORRY..... YOUR ATTEMPTS HAVE CROSSED LIMIT                                                        =");
            printf("\n\t\t            =                                                      PLEASE TRY AGAIN AFTER EXITING                                                               ="); 
            printf("\n\t\t            =                                                                                                                                                   ="); 
            printf("\n\t\t            =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            printf("\n\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**--**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
            ch=getchar();
        }     
    return 0;    
}

void welcome()
{
    printf("\n\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**--**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    printf("\n\t\t            =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t            =                                                                                                                                                   ="); 
    printf("\n\t\t            =                                                              WRITE YOUR INSTITUTION NAME HERE                                                     =");
    printf("\n\t\t            =                                                                         WELCOME                                                                   =");
    printf("\n\t\t            =                                                                           TO                                                                      =");
    printf("\n\t\t            =                                                             SEMESTER GRADE POINT AVERAGE (SGPA)                                                   =");
    printf("\n\t\t            =                                                                     GENERATION SYSTEM                                                             =");
    printf("\n\t\t            =                                                               BY: ABHIK MAJI & PREETAM PATI                                                       =");
    printf("\n\t\t            =                                                                                                                                                   ="); 
    printf("\n\t\t            =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**--**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    return;
}

int password()
{
    char password[15],password_ip[15],choice;
    int check=0,count=0,check_update=0;
    FILE *fptr;
    if ((fptr = fopen("password.bin","rb")) == NULL)
    {
        new_password();
        check=1;
    }
    else
    {
        do
            {
                printf("\n\t\t\t ENTER PASSWORD: ");
                scanf(" %s",password_ip);
                if (count==0)
                    fread(&password, sizeof(password), 1, fptr);
                if(strcmp(password_ip,password)==0)
                {
                    check=1;
                }
                else
                    printf("\n\t\t\t INCORRECT PASSWORD...\n");
                count++;
            } while (count<5 && check!=1 );
    fclose(fptr);
    }
    if (check==1)
        while (check_update!=1)
        {
            printf("\n\t\t\t DO YOU WANT TO CHANGE PASSWORD[Y/N]: ");
            scanf(" %c",&choice);
            if(choice=='Y' || choice=='y' )
                check_update=update_password();
            else 
                break;    
        }
    if(count==5)
        reset_password();    
    return check;
}

void new_password()
{
    char new_password[15];
    FILE *fptr;
    
    if ((fptr = fopen("password.bin","wb")) == NULL)
    {
    printf("ERROR! OPENING FILE");
    exit(1);
    }
    printf("\n\t\t\t ENTER NEW PASSWORD: ");
    scanf(" %s",new_password);
    fwrite(&new_password, sizeof(new_password), 1, fptr);
    fclose(fptr);
    return;
}

int update_password()
{
    char updated_password[10],password_ip[10],password[10];
    int check=0;
    FILE *fptr;
    fptr = fopen("password.bin","rb");
    printf("\n\t\t\t ENTER CURRENT PASSWORD: ");
    scanf(" %s",password_ip);
    fread(&password, sizeof(password), 1, fptr);
    if(strcmp(password_ip,password)==0)
    {
        check=1;
    }
    fclose (fptr);
    if(check==1)
    {
        fptr=fopen("password.bin","wb");
        printf("\n\t\t\t ENTER NEW PASSWORD: ");
        scanf(" %s",password);
        fwrite(&password, sizeof(password), 1, fptr);
        fclose(fptr);
    }
    else
    {
        printf("\n\t\t\t WRONG PASSWORD\n");
    }
    return check; 
}

void reset_password()
{
    char ch;
    printf("\n\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**--**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");;
    printf("\n\t\t            =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t            =                                                                                                                                                   ="); 
    printf("\n\t\t            =                                                      ARE YOU SURE TO RESET PASSWORD                                                               =");                  
    printf("\n\t\t            =                                         IF YOU RESET PASSWORD ALL THE RECORDS WILL BE DELETED                                                     =");                  
    printf("\n\t\t            =                                                                                                                                                   ="); 
    printf("\n\t\t            =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**--**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");;
    printf("\n\t\t\t YOUR CHICE [Y/N]: ");
    scanf(" %c",&ch);
    if(ch=='y' || ch=='Y')
    {
        remove("project.csv");
        remove("project2.csv");
        remove("password.bin");
    }
    return;
}

void menu()
{
    int choice,ch;
    do
    {
    printf("\n\n\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**--**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");;
    printf("\n\t\t           =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t                                              =                               --------                                      =                      ");
    printf("\n\t\t                                              =                               | MENU |                                      =                      ");
    printf("\n\t\t                                              =                               --------                                      =                      ");
    printf("\n\t\t                                              =                                                                             =                      ");
    printf("\n\t\t                                              =           ADD MARKS OF STUDENT                       ENTER 1                =                      ");
    printf("\n\t\t                                              =           GENERATE RESULT REGISTRATION NUMBER WISE   ENTER 2                =                      ");
    printf("\n\t\t                                              =           GENERATE RESULT SGPA WISE                  ENTER 3                =                      ");
    printf("\n\t\t                                              =           VIEW RESULT OF ALL STUDENTS                ENTER 4                =                      ");
    printf("\n\t\t                                              =           SEARCH STUDENT BY REGISTRATION NO.         ENTER 5                =                      ");
    printf("\n\t\t                                              =           SEARCH STUDENT BY GRADE                    ENTER 6                =                      ");
    printf("\n\t\t                                              =           SEARCH STUDENT BY NAME                     ENTER 7                =                      ");
    printf("\n\t\t                                              =           UPDATE THE RECORD                          ENTER 8                =                      ");
    printf("\n\t\t                                              =           OVERALL RESULT                             ENTER 9               =                      ");
    printf("\n\t\t                                              =           EXIT                                       ENTER 0                =                      ");
    printf("\n\t\t                                              =                                                                             =                      ");
    printf("\n\t\t           =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**--**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");;
    printf("\n\n\t                                             YOUR CHOICE : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            add_marks();
            break;
        case 2:
            generate_result_reg_wise();
            printf("\n\t\t\t RESULT HAS BEEN GENERATED REGISTRATION NUMBER WISE...\n");
            break;
        case 3:
		  	generate_result_sgpa_wise();
              printf("\n\t\t\t RESULT HAS BEEN GENERATED SGPA WISE...\n");
            break;   
        case 4:
            view_result();
            break;
        case 5:
            search_by_reg_no();  
            break;
        case 6:
            search_by_grade();
            break;
        case 7:
            search_by_name();
            break;
        case 8:
            update();
            printf("\n\t\t\t MARKS UPDATED...\n");
            break;
        case 9:         
            overall_result();
            break;               
        case 0:
            printf("\n\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**--**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");;
            printf("\n\t\t            =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            printf("\n\t\t            =                                                                                                                                                   ="); 
            printf("\n\t\t            =                                                                     THANK YOU                                                                     =");                  
            printf("\n\t\t            =                                                                                                                                                   ="); 
            printf("\n\t\t            =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            printf("\n\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**--**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");;
            break;    
        default :
            printf("\n\t\t\t PLEASE ENTER A VALID INPUT\n");
            break;       
    }
    } while (choice!=0);  
    ch=getchar();
    printf("\n");
    return;
}

void add_marks()
{
    int std_reg,marks,i=0,sub_point[8];
    int sub_credit[]={SUBCR1,SUBCR2,SUBCR3,SUBCR4,SUBCR5,SUBCR6,SUBCR7,SUBCR8};
    int total_credit=SUBCR1+SUBCR2+SUBCR3+SUBCR4+SUBCR5+SUBCR6+SUBCR7+SUBCR8;
    float sgpa,std_credit_float,total_credit_float;
    int std_credit=0;
    char grade[9];
    char choice='Y',std_name[25];
    char *sub[]={SUB1,SUB2,SUB3,SUB4,SUB5,SUB6,SUB7,SUB8};
    fptr=fopen("project.csv","a+");
    if(fptr==NULL)
    {
        printf("\n\t\t\t ERROR IN FILE OPENING...\n");
        exit(1);
    }
    while(choice=='Y'||choice=='y')
    {
        printf("\n\t\t\t ENTER STUDENTS NAME: ");
        scanf(" %[^\n]s",std_name);
        fprintf(fptr,"%s,",std_name);
        printf("\n\t\t\t ENTER STUDENTS REGISTRATION NO: ");
        scanf(" %d",&std_reg);
        fprintf(fptr,"%d",std_reg);
        i=0;
        while (i<8)
        {
            printf("\n\t\t\t ENTER MARKS IN %s: ",sub[i]);
            scanf(" %d",&marks);
            fprintf(fptr,",%d",marks);
            i++;
        }
        fprintf(fptr,"\n");
        printf("\n\t\t\t DO YOU WANT TO ADD MORE STUDENTS' MARKS[Y/N]: ");
        scanf(" %c",&choice);
    }
    fclose(fptr);
    return;
}

void update()
{
        struct data{
        char std_name[25],grade[8],final_grade;
        int std_reg,marks[8],sub_point[8],sgpa_int;
        float sgpa;
    }s[1000];
    struct s{
        char std[100];
    }student[1000];
    struct data temp;
    int i=0,j,STUDENTNUM,compare,k,c[1000],l,std_reg,marks,count=0,ip_reg;
    int std_credit, sub_credit[]={SUBCR1,SUBCR2,SUBCR3,SUBCR4,SUBCR5,SUBCR6,SUBCR7,SUBCR8};
    float total_credit=SUBCR1+SUBCR2+SUBCR3+SUBCR4+SUBCR5+SUBCR6+SUBCR7+SUBCR8,std_credit_float;
    char grade[9],ip_name[25],std_name[25],std_name2[25];
    char choice='Y',comma;
    char *sub[]={SUB1,SUB2,SUB3,SUB4,SUB5,SUB6,SUB7,SUB8};
    STUDENTNUM=student_count();
    fptr=fopen("project.csv","r");
    if(fptr==NULL)
    {
        printf("\n\t\t\t ERROR IN FILE OPENING...\n");
        exit(1);                                                     //Exit1
    }
    printf("\n\t\t\t ENTER THE NAME OF STUDENT: ");
    scanf(" %[^\n]s",ip_name);
    while(i<STUDENTNUM) 
    {
        fscanf(fptr," %[^\n]s",student[i].std);
        compare=strncmp(ip_name,student[i].std,strlen(ip_name));
        if(compare==0)
        {
            printf("\n\t\t\t %s\n",student[i].std);
                count++;
        }
        i++;
    }
    fclose(fptr);
    if(count==0)
        printf("\n\t\t\t NO STUDENT FOUND FOR THIS NAME.\n");    
    else
    {
        fptr=fopen("project.csv","w");
        for(i=0;i<STUDENTNUM;i++)
        {
            compare=strncmp(ip_name,student[i].std,strlen(ip_name));
            if(compare==0)
                {
                    printf("\n\t\t\t ENTER THE NAME OF STUDENT: ");
                    scanf(" %[^\n]s",std_name);
                    fprintf(fptr,"%s,",std_name);
                    printf("\n\t\t\t ENTER STUDENTS REGISTRATION NO: ");
                    scanf(" %d",&std_reg);
                    fprintf(fptr,"%d",std_reg);
                    j=0;
                    while (j<8)
                    {
                        printf("\n\t\t\t ENTER MARKS IN %s: ",sub[j]);
                        scanf(" %d",&marks);
                        fprintf(fptr,",%d",marks);
                        j++;
                    }
                    fprintf(fptr,"\n");
                }
             else
                {
                    fprintf(fptr,"%s",student[i].std);
                    fprintf(fptr,"\n");
                }   
                  
        }    
        fclose(fptr);
    }    
    for(i=0;i<STUDENTNUM;i++)
    {
        for(j=0;j<25;j++)
        {
            s[i].std_name[j]='\0';
        }
    }
    generate_result_reg_wise();
    return; 
}

void generate_result_reg_wise()
{
    struct data{
        char std_name[25],grade[8],final_grade;
        int std_reg,marks[8],sub_point[8],sgpa_int;
        float sgpa;
    }s[1000];
    struct data temp;
    int i=0,j,STUDENTNUM,k;
    int std_credit, sub_credit[]={SUBCR1,SUBCR2,SUBCR3,SUBCR4,SUBCR5,SUBCR6,SUBCR7,SUBCR8};
    float total_credit=SUBCR1+SUBCR2+SUBCR3+SUBCR4+SUBCR5+SUBCR6+SUBCR7+SUBCR8,std_credit_float;
    char grade[9];
    char choice='Y',comma;
    char *sub[]={
        "CSC 101","ECC 101","MAC 101","PHC 101","HUC 101","HUC 102","CSC 111","ECC 111"
    };
    STUDENTNUM=student_count();
    fptr=fopen("project.csv","r");
    fptr2=fopen("project2.csv","w");
    if(fptr==NULL)
    {
        printf("\n\t\t\t ERROR IN FILE OPENING...\n");
        exit(1);                                                     //Exit1
    }
     if(fptr2==NULL)
    {
        printf("\n\t\t\t ERROR IN FILE OPENING...\n");
        exit(2);                                                      //Exit2
    }
    while(i<STUDENTNUM)
    {
        for(k=0;;k++)
        {
            s[i].std_name[k]=fgetc(fptr);
            if(s[i].std_name[k]==',')
                break;
        }   

        fscanf(fptr," %d",&s[i].std_reg);

        j=0;
        std_credit=0;
        while (j<8)
        {
            fscanf(fptr," %c",&comma);
            fscanf(fptr," %d",&s[i].marks[j]);
            s[i].sub_point[j]=sub_score(s[i].marks[j]);
            s[i].grade[j]=generate_grade(s[i].sub_point[j]);
            std_credit+=(s[i].sub_point[j])*(sub_credit[j]);  // T.C=24   ST.C.=3*8+4*7+...<=240(max)...230
            j++;                                              // SGPA=230/24=9.583
        }
        comma=fgetc(fptr);
        std_credit_float=(float)std_credit;   //230
        s[i].sgpa=(float)(std_credit_float/total_credit); //9.583
        s[i].sgpa_int=(int)s[i].sgpa;                      //9
        s[i].final_grade=generate_grade((s[i].sgpa_int+1)); //10>>O
        i++;  
    }
    for(i=0;i<STUDENTNUM-1;i++)
    {
        for(j=i+1;j<STUDENTNUM;j++)
        {                                         //Main Logic
            if(s[i].std_reg>s[j].std_reg)         // A.M. 700  
            {                                     //P.P. 600
                strcpy(temp.std_name,s[i].std_name);
                strcpy(s[i].std_name,s[j].std_name);
                strcpy(s[j].std_name,temp.std_name);
                temp.std_reg=s[i].std_reg;
                s[i].std_reg=s[j].std_reg;
                s[j].std_reg=temp.std_reg;
                k=0;
                while(k<8)
                {
                    temp.marks[k]=s[i].marks[k];
                    s[i].marks[k]=s[j].marks[k];
                    s[j].marks[k]=temp.marks[k];
                    temp.grade[k]=s[i].grade[k];
                    s[i].grade[k]=s[j].grade[k];
                    s[j].grade[k]=temp.grade[k];
                    k++;
                }
                temp.sgpa=s[i].sgpa;
                s[i].sgpa=s[j].sgpa;
                s[j].sgpa=temp.sgpa;
                temp.final_grade=s[i].final_grade;
                s[i].final_grade=s[j].final_grade;
                s[j].final_grade=temp.final_grade;
            }
        }
    }
    i=0;
    while(i<STUDENTNUM)
    {
        fprintf(fptr2,"%s",s[i].std_name);
        fprintf(fptr2,"%d",s[i].std_reg);
        j=0;
        while (j<8)
        {
            fprintf(fptr2,",%d",s[i].marks[j]);
            fprintf(fptr2,",%c",s[i].grade[j]);
            j++;
        }
        fprintf(fptr2,",%2.3f,%c\n",s[i].sgpa,s[i].final_grade);
        i++;        
    }
    for(i=0;i<STUDENTNUM;i++)
    for(j=0;j<25;j++)
    {
        s[i].std_name[j]='\0';
    }
    fclose(fptr);
    fclose(fptr2);
    return;    
}

void generate_result_sgpa_wise()
{
    struct data{
        char std_name[25],grade[8],final_grade;
        int std_reg,marks[8],sub_point[8],sgpa_int;
        float sgpa;

    }s[1000];
    struct data temp;
    int i=0,j,STUDENTNUM,k;
    int std_credit, sub_credit[]={SUBCR1,SUBCR2,SUBCR3,SUBCR4,SUBCR5,SUBCR6,SUBCR7,SUBCR8};
    float total_credit=SUBCR1+SUBCR2+SUBCR3+SUBCR4+SUBCR5+SUBCR6+SUBCR7+SUBCR8,std_credit_float;
    char grade[9];
    char choice='Y',comma;
    char *sub[]={
        "CSC 101","ECC 101","MAC 101","PHC 101","HUC 101","HUC 102","CSC 111","ECC 111"
    };
    STUDENTNUM=student_count();
    fptr=fopen("project.csv","r");
    fptr2=fopen("project2.csv","w");
    if(fptr==NULL)
    {
        printf("\n\t\t\t Error in File Opening...\n");
        exit(1);                                                     //Exit1
    }
     if(fptr2==NULL)
    {
        printf("\n\t\t\t Error in File Opening...\n");
        exit(2);                                                      //Exit2
    }
    while(i<STUDENTNUM)
    {
        for(k=0;;k++)
        {
            s[i].std_name[k]=fgetc(fptr);
            if(s[i].std_name[k]==',')
            break;
        }   
        fscanf(fptr," %d",&s[i].std_reg);
        j=0;
        std_credit=0;
        while (j<8)
        {
            fscanf(fptr," %c",&comma);
            fscanf(fptr," %d",&s[i].marks[j]);
            s[i].sub_point[j]=sub_score(s[i].marks[j]);
            s[i].grade[j]=generate_grade(s[i].sub_point[j]);
            std_credit+=(s[i].sub_point[j])*(sub_credit[j]);
            j++;
        }
        std_credit_float=(float)std_credit;
        s[i].sgpa=(float)(std_credit_float/total_credit);
        s[i].sgpa_int=(int)s[i].sgpa;
        s[i].final_grade=generate_grade((s[i].sgpa_int+1));
        comma=fgetc(fptr); 
        i++;  
    }
    for(i=0;i<STUDENTNUM-1;i++)
    {
        for(j=i+1;j<STUDENTNUM;j++)
        {
            if(s[i].sgpa<s[j].sgpa)      //Main Logic
            {
                strcpy(temp.std_name,s[i].std_name);
                strcpy(s[i].std_name,s[j].std_name);
                strcpy(s[j].std_name,temp.std_name);
                temp.std_reg=s[i].std_reg;
                s[i].std_reg=s[j].std_reg;
                s[j].std_reg=temp.std_reg;
                k=0;
                while(k<8)
                {
                    temp.marks[k]=s[i].marks[k];
                    s[i].marks[k]=s[j].marks[k];
                    s[j].marks[k]=temp.marks[k];
                    temp.grade[k]=s[i].grade[k];
                    s[i].grade[k]=s[j].grade[k];
                    s[j].grade[k]=temp.grade[k];
                    k++;
                }
                temp.sgpa=s[i].sgpa;
                s[i].sgpa=s[j].sgpa;
                s[j].sgpa=temp.sgpa;
                temp.final_grade=s[i].final_grade;
                s[i].final_grade=s[j].final_grade;
                s[j].final_grade=temp.final_grade;
            }
        }
    }
    i=0;
    while(i<STUDENTNUM)
    {
        fprintf(fptr2,"%s",s[i].std_name);
        fprintf(fptr2,"%d",s[i].std_reg);
        j=0;
        while (j<8)
        {
            fprintf(fptr2,",%d",s[i].marks[j]);
            fprintf(fptr2,",%c",s[i].grade[j]);
            j++;
        }
        fprintf(fptr2,",%2.3f,%c\n",s[i].sgpa,s[i].final_grade);
        i++;        
    }
    for(i=0;i<STUDENTNUM;i++)
    for(j=0;j<25;j++)
    {
        s[i].std_name[j]='\0';
    }
    fclose(fptr);
    fclose(fptr2);
    return;    
}

void line()

{
    printf("\n\t\t---------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    return;
}

void view_result()
{
    struct data{
        char std_name[25],grade[8],final_grade;
        int std_reg,marks[8],sub_point[8],sgpa_int;
        float sgpa;
    }s[1000];
    int i=0,j,STUDENTNUM,k;
    int std_credit, sub_credit[]={SUBCR1,SUBCR2,SUBCR3,SUBCR4,SUBCR5,SUBCR6,SUBCR7,SUBCR8};
    float total_credit=SUBCR1+SUBCR2+SUBCR3+SUBCR4+SUBCR5+SUBCR6+SUBCR7+SUBCR8,std_credit_float;
    char grade[9],name;
    char choice='Y',comma;
    char *sub[]={
        "CSC 101","ECC 101","MAC 101","PHC 101","HUC 101","HUC 102","CSC 111","ECC 111"
    };
    STUDENTNUM=student_count2();
    fptr2=fopen("project2.csv","r");
    if(fptr2==NULL)
    {
        printf("\n\t\t\t ERROR IN FILE OPENINg...\n");
        exit(3);                                            //Exit3
    }
    for(i=0;i<STUDENTNUM;i++)
      for(j=0;j<25;j++)
        {
            s[i].std_name[j]='\0';
        }
        i=0;
    while(i<STUDENTNUM)
    {
        for(k=0;;k++)
        {
            name=fgetc(fptr2);
            if(name==',')
                break;
            else    
            s[i].std_name[k]=name;
        }
        fscanf(fptr2," %d",&s[i].std_reg);
        j=0;
        std_credit=0;
        while (j<8)
        {
            fscanf(fptr2," %c",&comma); 
            fscanf(fptr2," %d",&s[i].marks[j]);
            fscanf(fptr2," %c",&comma); 
            fscanf(fptr2," %c",&s[i].grade[j]);
            j++;
        }
        fscanf(fptr2," %c",&comma);
        fscanf(fptr2," %f",&s[i].sgpa);
        fscanf(fptr2," %c",&comma); 
        fscanf(fptr2," %c",&s[i].final_grade);
        comma=fgetc(fptr2);   //  It removes '\n' at the end of Final Grade 
        i++;  
    }
    line();
    line();
    printf("\n\t\t          NAME        REG. NO. \tCSC 101\t\tECC 101\t\tMAC 101\t\tPHC 101\t\tHUC 101\t\tHUC 102\t\tCSC 111\t\tECC 111\t\tSGPA");
    line();
    line();
    printf("\n");
    i=0;
    while(i<STUDENTNUM)
    {
        printf("\n\t\t %s\t",s[i].std_name);
        // for(k=0;k<(20-strlen(s[i].std_name));k++)
        //     printf(" ");
        printf("\t%d\t",s[i].std_reg);
        j=0;
        while (j<8)
        {
            printf("%d\t",s[i].marks[j]);
            printf("%c\t",s[i].grade[j]);
            j++;
        }
        printf("%2.3f\t%c\n",s[i].sgpa,s[i].final_grade);
        i++;        
    }
    line();
    line();
    for(i=0;i<STUDENTNUM;i++)
    for(j=0;j<25;j++)
    {
        s[i].std_name[j]='\0';
    }
    fclose(fptr2);
    return;  
}  

void search_by_reg_no()
{

    struct data{
        char std_name[25],grade[8],final_grade;
        int std_reg,marks[8],sub_point[8],sgpa_int;
        float sgpa;
    }s[1000];
    int i=0,j,STUDENTNUM,ip_reg_no,k;
    int std_credit, sub_credit[]={SUBCR1,SUBCR2,SUBCR3,SUBCR4,SUBCR5,SUBCR6,SUBCR7,SUBCR8};
    float total_credit=SUBCR1+SUBCR2+SUBCR3+SUBCR4+SUBCR5+SUBCR6+SUBCR7+SUBCR8,std_credit_float;
    char grade[9],comma,name;
    char choice='Y';
    char *sub[]={
        "CSC 101","ECC 101","MAC 101","PHC 101","HUC 101","HUC 102","CSC 111","ECC 111"
    };
    printf("\n\t\t\t ENTER THE REGISTRATION NUMBER OF STUDENT: ");
    scanf("%d",&ip_reg_no);
    STUDENTNUM=student_count2();
    fptr2=fopen("project2.csv","r");
    if(fptr2==NULL)
    {
        printf("\n\t\t\t ERROR IN FILE OPENING...\n");
        exit(4);                                                    //Exit4
    }
    while(i<STUDENTNUM)
    {
        if(i!=0)
            comma=fgetc(fptr2);
        for(k=0;;k++)
        {
            name=fgetc(fptr2);
            if(name==',')
                break;
            else    
            s[i].std_name[k]=name;
        }
        fscanf(fptr2," %d",&s[i].std_reg);
        j=0;
        std_credit=0;
        while (j<8)
        {
            fscanf(fptr2," %c",&comma); 
            fscanf(fptr2," %d",&s[i].marks[j]);
            fscanf(fptr2," %c",&comma); 
            fscanf(fptr2," %c",&s[i].grade[j]);
            j++;
        }
        fscanf(fptr2," %c",&comma); 
        fscanf(fptr2," %f",&s[i].sgpa);
        fscanf(fptr2," %c",&comma); 
        fscanf(fptr2," %c",&s[i].final_grade);
        if (s[i].std_reg==ip_reg_no)   //Main Logic
            break;
        i++;  
    }
    if(i==STUDENTNUM)
        printf("\n\t\t\t STUDENT NOT FOUND FOR THIS REGISTRATION NUMBER\n");
    else
    {
        line();
        printf("\n\t\t          NAME        REG. NO. \tCSC 101\t\tECC 101\t\tMAC 101\t\tPHC 101\t\tHUC 101\t\tHUC 102\t\tCSC 111\t\tECC 111\t\tSGPA");
        line();
        printf("\n");
        printf("\n\t\t %s\t",s[i].std_name);
        printf("\t%d\t",s[i].std_reg);
        j=0;
        while (j<8)
        {
            printf("%d\t",s[i].marks[j]);
            printf("%c\t",s[i].grade[j]);
            j++;
        }
        printf("%2.3f\t%c\n",s[i].sgpa,s[i].final_grade);
    }
        line();
    for(i=0;i<STUDENTNUM;i++)
    for(j=0;j<25;j++)
    {
        s[i].std_name[j]='\0';
    }
    return;
}

void search_by_grade()
{
    struct data{
        char std_name[25],grade[8],final_grade;
        int std_reg,marks[8],sub_point[8],sgpa_int;
        float sgpa;
    }s[1000];
    int i=0,j,STUDENTNUM,count=0,k;
    int std_credit, sub_credit[]={SUBCR1,SUBCR2,SUBCR3,SUBCR4,SUBCR5,SUBCR6,SUBCR7,SUBCR8};
    float total_credit=SUBCR1+SUBCR2+SUBCR3+SUBCR4+SUBCR5+SUBCR6+SUBCR7+SUBCR8,std_credit_float;
    char grade[9],ip_grade,comma,name;
    char choice='Y';
    char *sub[]={
        "CSC 101","ECC 101","MAC 101","PHC 101","HUC 101","HUC 102","CSC 111","ECC 111"
    };
    printf("\n\t\t\tENTER THE GRADE YOU WANT TO SEARCH [O,E,A,B,C,F]\n\n\t\t\tYOUR CHOICE: ");
    scanf(" %c",&ip_grade);
    if(ip_grade=='O'||ip_grade=='o')
        ip_grade='O';     
    else if(ip_grade=='E'||ip_grade=='e')
        ip_grade='E';
    else if(ip_grade=='A'||ip_grade=='a')
        ip_grade='A';
    else if(ip_grade=='B'||ip_grade=='b')
        ip_grade='B'; 
    else if(ip_grade=='C'||ip_grade=='c')
        ip_grade='C';    
    else if(ip_grade=='F'||ip_grade=='f')
        ip_grade='F';             
    STUDENTNUM=student_count2();
    fptr2=fopen("project2.csv","r");
    if(fptr2==NULL)      
    {
        printf("\n\t\t\t ERROR IN FILE OPENING...\n");
        exit(5);                                                 //Exit5
    }
    while(i<STUDENTNUM)
    {
        if(i!=0)
            comma=fgetc(fptr2);
        for(k=0;;k++)
        {
            name=fgetc(fptr2);
            if(name==',')
                break;
            else    
            s[i].std_name[k]=name;
        }
        fscanf(fptr2," %d",&s[i].std_reg);
        j=0;
        while (j<8)
        {
            fscanf(fptr2," %c",&comma);
            fscanf(fptr2," %d",&s[i].marks[j]);
            fscanf(fptr2," %c",&comma);
            fscanf(fptr2," %c",&s[i].grade[j]);
            j++;
        }
        fscanf(fptr2," %c",&comma);
        fscanf(fptr2," %f",&s[i].sgpa);
        fscanf(fptr2," %c",&comma);
        fscanf(fptr2," %c",&s[i].final_grade);
        i++;  
    }
     fclose(fptr2);
    i=0;
    
    while(i<STUDENTNUM)
    {
        if (s[i].final_grade==ip_grade)   //Main Logic
        {
            count++;
            if(count==1)
            {
                line();
                line();
                printf("\n\t\t          NAME        REG. NO. \tCSC 101\t\tECC 101\t\tMAC 101\t\tPHC 101\t\tHUC 101\t\tHUC 102\t\tCSC 111\t\tECC 111\t\tSGPA");
                line();
                line();
                printf("\n");
            }
            printf("\n\t\t %s\t",s[i].std_name);
            printf("\t%d\t",s[i].std_reg);
            j=0;
            while (j<8)
            {
                printf("%d\t",s[i].marks[j]);
                printf("%c\t",s[i].grade[j]);
                j++;
            }
            printf("%2.3f\t%c\n",s[i].sgpa,s[i].final_grade);
        }
        i++;
    }
    if(count!=0)
    {
        line();
        line();
        printf("\n\t\t\t NUMBER OF STUDENTS IN THIS GRADE: %d\n",count);
    }
    else
        printf("\n\t\t\t NO STUDENT IN THIS GRADE\n");            
for(i=0;i<STUDENTNUM;i++)
    for(j=0;j<25;j++)
    {
        s[i].std_name[j]='\0';
    }
    return;
}

void search_by_name()
{
    struct data{
        char std_name[25],grade[8],final_grade;
        int std_reg,marks[8],sub_point[8],sgpa_int;
        float sgpa;
    }s[1000];
    int i=0,j,STUDENTNUM,ip_reg_no,k,compare,c[100],l=0,count=0;
    int std_credit, sub_credit[]={SUBCR1,SUBCR2,SUBCR3,SUBCR4,SUBCR5,SUBCR6,SUBCR7,SUBCR8};
    float total_credit=SUBCR1+SUBCR2+SUBCR3+SUBCR4+SUBCR5+SUBCR6+SUBCR7+SUBCR8,std_credit_float;
    char grade[9],comma,name,ip_name[25],temp[25];
    char choice='Y';
    char *sub[]={
        "CSC 101","ECC 101","MAC 101","PHC 101","HUC 101","HUC 102","CSC 111","ECC 111"
    };
    printf("\n\t\t\t ENTER THE NAME OF STUDENT: ");
    scanf(" %[^\n]s",ip_name);
    STUDENTNUM=student_count2();
    fptr2=fopen("project2.csv","r");
    if(fptr2==NULL)
    {
        printf("\n\t\t\t ERROR IN FILE OPENING...\n");
        exit(4);                                                    //Exit4
    }
    while(i<STUDENTNUM)
    {
        if(i!=0)
            comma=fgetc(fptr2);
        for(k=0;;k++)
        {
            name=fgetc(fptr2);
            if(name==',')
                break;
            else    
            s[i].std_name[k]=name;
        }
        fscanf(fptr2," %d",&s[i].std_reg);
        j=0;
        while (j<8)
        {
            fscanf(fptr2," %c",&comma);
            fscanf(fptr2," %d",&s[i].marks[j]);
            fscanf(fptr2," %c",&comma);
            fscanf(fptr2," %c",&s[i].grade[j]);
            j++;
        }
        fscanf(fptr2," %c",&comma);
        fscanf(fptr2," %f",&s[i].sgpa);
        fscanf(fptr2," %c",&comma);
        fscanf(fptr2," %c",&s[i].final_grade);
        i++;  
    }
     fclose(fptr2);
    i=0;
    
    while(i<STUDENTNUM)
    {
        strcpy(temp,s[i].std_name);
        compare=strncmp(ip_name,temp,strlen(ip_name));
        if(compare==0) 
        {
            count++;
            if(count==1)
            {
                line();
                line();
                printf("\n\t\t          NAME        REG. NO. \tCSC 101\t\tECC 101\t\tMAC 101\t\tPHC 101\t\tHUC 101\t\tHUC 102\t\tCSC 111\t\tECC 111\t\tSGPA");
                line();
                line();
                printf("\n");
            }
            printf("\n\t\t %s\t",s[i].std_name);
            printf("\t%d\t",s[i].std_reg);
            j=0;
            while (j<8)
            {
                printf("%d\t",s[i].marks[j]);
                printf("%c\t",s[i].grade[j]);
                j++;
            }
            printf("%2.3f\t%c\n",s[i].sgpa,s[i].final_grade);
        }
        i++;
    }
    if(count!=0)
    {
        line();
        line();
    }
    else
        printf("\n\t\t\t NO STUDENT FOUND FOR THIS NAME\n");            
    for(i=0;i<STUDENTNUM;i++)
      for(j=0;j<25;j++)
        {
            s[i].std_name[j]='\0';
        }      
    return;
}

void overall_result()
{

    struct data{
        char std_name[25],grade[8],final_grade;
        int std_reg,marks[8],sub_point[8],sgpa_int;
        float sgpa;
    }s[1000];
    int i=0,j,STUDENTNUM,count=0,k;
    int grade_c[9][6];
    for(i=0;i<9;i++)
        for(j=0;j<6;j++)
            grade_c[i][j]=0;
    int std_credit, sub_credit[]={SUBCR1,SUBCR2,SUBCR3,SUBCR4,SUBCR5,SUBCR6,SUBCR7,SUBCR8};
    float total_credit=SUBCR1+SUBCR2+SUBCR3+SUBCR4+SUBCR5+SUBCR6+SUBCR7+SUBCR8,std_credit_float;
    char grade[6]={'O','E','A','B','C','F'},ip_grade,comma,name;
    char choice='Y';
    char *sub[]={
        "CSC 101","ECC 101","MAC 101","PHC 101","HUC 101","HUC 102","CSC 111","ECC 111"
    };           
    STUDENTNUM=student_count2();
    fptr2=fopen("project2.csv","r");
    if(fptr2==NULL)      
    {
        printf("\n\t\t\t ERROR IN FILE OPENING...\n");
        exit(5);                                                 //Exit5
    }
    i=0;j=0;
    while(i<STUDENTNUM)
    {
        for(k=0;;k++)
        {
            fscanf(fptr2," %c",&name);
            if(name==',')
                break;
            else    
            s[i].std_name[k]=name;
        }
        fscanf(fptr2," %d",&s[i].std_reg);
        j=0;
        while (j<8)
        {
            fscanf(fptr2," %c",&comma);
            fscanf(fptr2," %d",&s[i].marks[j]);
            fscanf(fptr2," %c",&comma);
            fscanf(fptr2," %c",&s[i].grade[j]);
            if(s[i].grade[j]=='O')
                grade_c[j][0]++;
            else if(s[i].grade[j]=='E')
                grade_c[j][1]++;
            else if(s[i].grade[j]=='A')
                grade_c[j][2]++;
            else if(s[i].grade[j]=='B')
                grade_c[j][3]++;
            else if(s[i].grade[j]=='C')
                grade_c[j][4]++;
            else 
                grade_c[j][5]++; 
            j++;
        }
        fscanf(fptr2," %c",&comma);
        fscanf(fptr2," %f",&s[i].sgpa);
        fscanf(fptr2," %c",&comma);
        fscanf(fptr2," %c",&s[i].final_grade);
        if(s[i].final_grade=='O')
            grade_c[8][0]++;
        else if(s[i].final_grade=='E')
            grade_c[8][1]++;
        else if(s[i].final_grade=='A')
            grade_c[8][2]++;
        else if(s[i].final_grade=='B')
            grade_c[8][3]++;
        else if(s[i].final_grade=='C')
            grade_c[8][4]++;
        else 
            grade_c[8][5]++;                
        i++;  
    }
     fclose(fptr2);
    i=0;
    line();
    line();
    printf("\n");
    for(i=0;i<9;i++)
    {
        if(i<8)
            printf("\n\t\t\t%s     :   ",sub[i]);
        else
            printf("\n\t\t\tFINAL GRADE :   ");
        for(j=0;j<6;j++)
        {
            printf("%c - %2d       ",grade[j],grade_c[i][j]) ;
        }
    }
    printf("\n");
    line();
    line(); 
for(i=0;i<STUDENTNUM;i++)
    for(j=0;j<25;j++)
    {
        s[i].std_name[j]='\0';
    }
    return;
}

int sub_score(int marks)
{
    int point;
    if(marks>=90)
        point=10;
    else if(marks>=80)
        point=9; 
    else if(marks>=70)
        point=8;
    else if(marks>=60)
        point=7;
    else if(marks>=50)
        point=6;
    else
        point=0;
    return point;        
}

char generate_grade(int point)
{
    char grade;
    if(point==10||point==11)        //9.5 O?E>>>O  9+1=10>>>O  10+1=11>>>O
        grade='O';
    else if(point==9)
        grade='E';
    else if(point==8)
        grade='A';
    else if(point==7)
        grade='B';
    else if(point==6)
        grade='C';
    else
        grade='F';
    return grade;
}

int student_count()
{
    char ch;
    int count=0;
    fptr=fopen("project.csv","r");
    if(fptr==NULL)
    {
        printf("Error in File Opening2...\n");
        exit(6);                                    //Exit6
    }
    while(1)
    {
        ch=fgetc(fptr);
        if(ch==EOF)
            {
                break;
            }
        if(ch=='\n')
            {
                count++;
            }    
    }
    fclose(fptr);
    return count;
}

int student_count2()
{
    char ch;
    int count=0;
    fptr2=fopen("project2.csv","r");
    if(fptr2==NULL)
    {
        printf("Error in File Opening2...\n");
        exit(7);                            //Exit7
    }
    while(1)
    {
        ch=fgetc(fptr2);
        if(ch==EOF)
            {
                break;
            }
        if(ch=='\n')
            {
                count++;
            }    
    }
    fclose(fptr2);
    return count;
}
