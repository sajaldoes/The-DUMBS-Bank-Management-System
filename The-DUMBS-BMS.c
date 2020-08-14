#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<windows.h>
void create_created_acccount();
void create_acc();
void update();
void menu();
void remove_account();
void transaction();
void close();
void display_account_created(int oparetion);
void f_menu();
void Start();
void cash(int oparetion);
void loan();
int cal(int m,double am,double ir);
void recover();
void atm();
void admin_panel();
int num_of_account=0;
struct account
{
    char  id[1000];
    long long int atm_id;
    int pin;
    char name[100];
    int age ;
    char phone[100];
    char password[100];
    double cash;
    int  account_validation;
    struct account *next;
    struct account *previous;
}*start=NULL,*end=NULL,*current;
struct employe
{
    char name[100];
    int age ;
    char phone[100];
    char post[100];
    struct account *next;
    struct account *previous;
}*start1=NULL,*end1=NULL,*current1;



///FILE WORK START
void create_created_acccount()
{
    int i;
    FILE *ptr;
    ptr=fopen("accounts_information.txt","a+");
    for(i=0; i<num_of_account; i++)
    {
        int date,month,year;
        struct account *new_account;
        new_account=(struct account*)malloc(sizeof(struct account));
        if(i>0)
            fgetc(ptr);
        fscanf(ptr,"%[^\n]s",&new_account->name);
        fscanf(ptr,"%s",new_account->id);
        fscanf(ptr,"%s",&new_account->password);
        fscanf(ptr,"%s",&new_account->phone);
        fscanf(ptr,"%d",&new_account->age);
        fscanf(ptr,"%lld",&new_account->atm_id);
        fscanf(ptr,"%d",&new_account->pin);
        fscanf(ptr,"%lf",&new_account->cash);
        fscanf(ptr,"%d",&new_account->account_validation);
        new_account->next=NULL;
        new_account->previous=NULL;
        if(start==NULL)
        {
            start=new_account;
            current=new_account;
        }
        else
        {
            current->next=new_account;
            new_account->previous=current;
            current=new_account;
            end=current;
        }
    }
    fclose(ptr);
}
void close()
{
    int i;
    FILE *ptr;
    ptr=fopen("accounts_information.txt","w");
    struct account *temp=start;
    while(temp!=NULL)
    {
        fprintf(ptr,"%s\n",temp->name);
        fprintf(ptr,"%s\n",temp->id);
        fprintf(ptr,"%s\n",temp->password);
        fprintf(ptr,"%s\n",temp->phone);
        fprintf(ptr,"%d\n",temp->age);
        fprintf(ptr,"%lld\n",temp->atm_id);
        fprintf(ptr,"%d\n",temp->pin);
        fprintf(ptr,"%lf\n",temp->cash);
        fprintf(ptr,"%d\n",temp->account_validation);
        temp=temp->next;
    }
    fclose(ptr);
    ptr=fopen("number_of_account.txt","w");
    fprintf(ptr,"%d",num_of_account);
    fclose(ptr);
}
///FILE WORK END




///BANK SECTION START
void recover()
{
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO YOUR BANKING APP \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n\n\t\t****If you want to Recover your Password or Activate your Account: \n\t\tPlease Visit our BANK and contact with the ADMIN Then they can give you the SOLUTION\n\n\n");
    int c;
    printf("Enter [1] ADMIN PANEL or [2] Menu: ");
    scanf("%d",&c);
    if(c==1)
        admin_panel();
    else
        menu();

}
void loan()
{
    system("cls");
    struct account *temp=start;
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO YOUR BANKING APP \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\tDo you have any account?\n\t\t[1] YES\n\t\t[2] NO\n");
    int a;
    printf("\n\tEnter your choice: ");
    scanf("%d",&a);
    if(a==1)
    {
        printf("\n\n\n\t\t\t\t ****Fill up these correctly for seeing ACCOUNT Details**** \n");
        char id[100];
        printf("\n\tEnter Your Account ID: ");
        scanf("%s",id);
        getchar();
        while(temp!=NULL)
        {
            if(strcmp(id,temp->id)==0)
                break;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("\n\n\t\t\t\tAccount is not found!!!\n\n\t\t\t\tPlease create your account first ^_^ \n\n");
            printf("Press Enter for Home: ");
            getchar();
            menu();
            return;
        }
        int limite=0;
        while(1)
        {
            printf("\tEnter Your password: ");
            char pass[1000];
            scanf("%s",pass);
            if(strcmp(temp->password,pass)!=0)
            {
                limite++;
                printf("\t*****************Wrong Password!!!\n");
                if(limite==3)
                {
                    getchar();
                    printf("\n\n\t\t****You have to remind your original password.\n\n\n");
                    printf("Press Enter for Home: ");
                    getchar();
                    menu();
                    break;
                }
            }
            else
                break;
        }
    }
    else if(a==2)
    {
        printf("\n\n\t\tEnter C to create account or E to exit: ");
        char c;
        scanf("%c",&c);
        if(c=='C')
            create_acc();
        else
            menu();
    }
    system("cls");
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO YOUR BANKING APP \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t\t\t  THE DUMBS BANKING LOAN FEATURES\n");
    printf("\n\t\t\t\tNO  -   PURPOSE    -   RANGE(Up to)    -   INTEREST RATE\n\n");
    printf("\t\t\t\t[1] -  Education   -  BDT 200,000/=    -   (9-12) %%\n");
    printf("\t\t\t\t[2] -  Business    -  BDT 50,00,000/=  -   (14-17) %%\n");
    printf("\t\t\t\t[3] -  Agriculture -  BDT 300,000/=    -   (7-10) %%\n");
    printf("\t\t\t\t[4] -  IT Industry -  BDT 20,00,000/=  -   (13-16) %%\n");
    printf("\t\t\t\t[5] -  Treatment   -  BDT 10,00,000/=  -   (6-9) %%\n");
    printf("\t\t\t\t[6] -  Others      -  BDT 500,000/=    -   (10-13) %%\n");
    printf("\n\t\t\tInstallment should be completed between 36 Months(3 Years)\n");
    printf("\n\t\tAre you interested to take loan?\n\t\t[1] YES\n\t\t[2] NO\n");
    int l;
    printf("\tEnter your choice: ");
    scanf("%d",&l);
    if(l==1)
    {
        printf("\tEnter Purpose: ");
        int p;
        scanf("%d",&p);

        double am,ir,res;
        int m;
        if(p==1)
            ir=9.00,printf("\n\t\t\t\tYou have selected for Educational Purpose");
        else if(p==2)
            ir=14.00,printf("\n\t\t\t\tYou have selected for Business Purpose");
        else if(p==3)
            ir=7.00,printf("\n\t\t\t\tYou have selected for Agricultural Purpose ");
        else if(p==4)
            ir=13.00,printf("\n\t\t\t\tYou have selected for IT Industry Purpose ");
        else if(p==5)
            ir=6.00,printf("\n\t\t\t\tYou have selected for Treatment Purpose ");
        else if(p==6)
            ir=10.00,printf("\n\t\t\t\tYou have selected for Others Purpose");
        printf("\n\t\tEnter amount: ");
        scanf("%lf",&am);
        printf("\t\tEnter desired months: ");
        scanf("%d",&m);
        res=cal(m,am,ir) ;
        printf("\n\tCongratulations!!!\n\tYou are eligible for loan!!!\n\tYou have to pay BDT %.2lf/= per month.\n",res);
        printf("\tYou have to come to our bank with necessary documents and complete the formalities to take loan.\n");
        printf("\tWe are eager to give you the loan.\nThank You!!!\n");
        getchar();
        printf("Press Enter for Menu: ");
        getchar();
        menu();
    }
    else if(l==2)
        menu();
}
int cal(int m,double am,double ir)
{
    double s,mm;
    s=am/m;
    if(m<=12)
    {
        mm=(ir*s)/100;
        s+=mm;
    }
    else if(m>12&&m<=24)
    {
        ir+=1.50;
        mm=(ir*s)/100;
        s+=mm;
    }
    else if(m>24&&m<=36)
    {
        ir+=1.50;
        mm=(ir*s)/100;
        s+=mm;
    }
    return s;
}
void transaction()
{
    system("cls");
    int opt,a,i,am,z,p=0;
    int prev=1000;
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO OUR BANKING APP \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t\t      **********Transaction**********\n\n\n\n");
    printf("\t\t\t\t[1] Deposit\n\t\t\t\t[2] Withdraw\n\t\t\t\t[3] Fund Transfer\n\t\t\t\t[4] Main menu\n\n\nEnter your choice: ");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1:
        cash(1);
        break;
    case 2:
        cash(2);
        break;
    case 3:
        cash(3);
        break;
    case 4:
        menu();
        break;
    }

}
void cash(int oparetion)
{
    system("cls");
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO YOUR BANKING APP \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    if(oparetion==3)
        printf("\n\n\t\t\t\t\t  **********Fund Transferring**********\n\n\n");
    else  if(oparetion==1)
        printf("\n\n\t\t\t\t\t\t**********Deposit**********\n\n\n");
    else
        printf("\n\n\t\t\t\t\t\t**********Withdraw**********\n\n\n");
    char id[100];
    printf("\t\tEnter Your Account ID: ");
    scanf("%s",id);
    struct account *temp,*temp2;
    temp=start;
    while(temp!=NULL)
    {

        int compare;
        compare=strcmp(id,temp->id);
        if(compare==0)
            break;
        temp=temp->next;

    }
    if(temp==NULL)
    {
        printf("\n\n\t\t\t\tAccount is not found!!!\n\n\t\t\t\tPlease create your account first ^_^ \n\n");
        printf("Press Enter for Menu: ");
        getchar();
        menu();
        return;
    }
    else
    {
        if(temp->account_validation!=0)
        {
            int compare,limit_of_password=0;
wrong:
            printf("\t\tEnter Your Password: ");
            char password[100];
            scanf("%s",password);
            compare=strcmp(password,temp->password);
            if(compare!=0)
            {
                limit_of_password++;
                printf("\t*****************Wrong Password!!!\n");
                if(limit_of_password==3)
                {
                    printf("\n\n\t\tYour Account Has been Deactivated!!!\n\t\t****You have to remind your original password.\n\n\n");
                    printf("");
                    temp->account_validation=0;
                    close();
                    printf("Press Enter for Menu: ");
                    getchar();
                    getchar();
                    menu();
                    return;
                }
                goto wrong;
            }
            else
            {
                double money;
                char transfer_id[1000];
try_aging:
                if(oparetion==3)
                    printf("\n\n\t\tEnter Transfer Money: ");
                else if(oparetion==2)
                    printf("\n\n\t\tEnter Withdraw Money: ");
                else
                    printf("\n\n\t\tEnter Deposit Money: ");
                scanf("%lf",&money);

                if(money+500>temp->cash&&(oparetion==2||oparetion==3))
                {
                    printf("\n\t***Sorry you do not have enough money \n");
                    printf("\tYour Balance : BDT %.2lf/=\n\n",temp->cash);

                    printf("\t\t\t[1] Try again\t\t[2] Return\nEnter your choice : ");
                    int opt;
                    scanf("%d",&opt);
                    switch(opt)
                    {
                    case 1:
                        goto try_aging;
                    }
                    transaction();
                    return;
                }
                else if(oparetion==1)
                {
                    temp->cash+=money;
                    close();
                    getchar();
                    printf("\n\n\t\t\t\t\t.:*:. Congratulations .:*:.");
                    printf("\n\n\t\t\t\tYour Money is Deposited Successfully:\n\n");
                    printf("\n\t\t\t\tNow your Balance : BDT %.2lf/=\n\n",temp->cash);
                    printf("Press Enter for Home : ");
                    getchar();
                    transaction();
                    return;
                }
                else if(oparetion==2)
                {
                    temp->cash-=money;
                    close();
                    getchar();
                    printf("\n\n\t\t\t\t\t.:*:. Congratulations .:*:.");
                    printf("\n\n\t\t\t\tYour Money is Withdrawn successfully:\n\n");
                    printf("\n\t\t\t\tNow your Balance : BDT %.2lf/=\n\n",temp->cash);
                    printf("Press Enter for Home : ");
                    getchar();
                    transaction();
                    return;
                }
                while (1)
                {
                    printf("\t\tEnter Transfer Account ID: ");
                    scanf("%s",transfer_id);
                    temp2=start;
                    while(temp2!=NULL)
                    {
                        int compear;
                        compare=strcmp(transfer_id,temp2->id);
                        if(compare==0)
                            break;
                        temp2=temp2->next;

                    }
                    if(temp2==NULL)
                    {
                        printf("\n\n\t\t\t\tAccount is not found!!!\n\n");
                    }
                    else
                        break;
                }
                temp2->cash+=money;
                temp->cash-=money;
                printf("\n\n\t\t\t\t\t.:*:. Congratulations .:*:.");
                printf("\n\t\t\t\tYour Money has been transferred successfully!!\n");
                close();
                getchar();
                printf("\n\t\t\t\tNow your Balance : %.2lf/=\n\n",temp->cash);
                printf("Press Enter for Home:");
                getchar();
                transaction();
                return;
            }
        }
        else
        {
            printf("Your account is Inactive\n");
            printf("Press [1] Account Activation *ADMIN :");
            int atv;
            scanf("%d",&atv);
            system("cls");
            if(atv==1)
            {
                admin_panel();
                return;
            }
            else
            {
                menu();
                return;
            }
        }
    }
}
void update()
{
    system("cls");
    struct account *temp=start;
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO YOUR BANKING APP \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t\t****UPDATE PASSWORD OR PHONE NUMBER****\n");
    char id[100];
    printf("\n\n\t\tEnter Your Account ID: ");
    scanf("%s",id);
    getchar();
    while(temp!=NULL)
    {
        if(strcmp(id,temp->id)==0)
            break;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\n\n\t\t\t\tAccount is not found!!!\n\n\t\t\t\tPlease create your account first ^_^ \n\n");
        printf("Press Enter for Home: ");
        getchar();
        menu();
        return;
    }
    int limite=0;
    while(1)
    {
        printf("\t\tEnter Your password: ");
        char pass[1000];
        scanf("%s",pass);
        if(strcmp(temp->password,pass)!=0)
        {
            limite++;
            printf("\t*****************Wrong Password!!!\n");
            if(limite==3)
            {
                getchar();
                printf("\n\n\t\t****You have to remind your original password.\n\n\n");
                printf("Press Enter for Home: ");
                getchar();
                system("cls");
                break;
            }
        }
        else
        {
            printf("\n\n\t\tPress [1] Password or [2] Phone : ");
            int oparetion;
            scanf("%d",&oparetion);
            if(oparetion==1)
            {
                printf("\n\t\tEnter Your New password: ");
                scanf("%s",temp->password);
                printf("\n\n\t\t\t\t\t.:*:. Congratulations .:*:.");
                printf("\n\t\t\t\tYour Password is Changed Successfully!!!\n");
            }
            else
            {
                printf("\n\tEnter Your New Phone Number: ");
                scanf("%s",temp->phone);
                printf("\n\n\t\t\t\t\t.:*:. Congratulations .:*:.");
                printf("\n\t\t\t\tYour Phone Number is Changed Successfully!!!\n");
            }
            close();
            getchar();
            printf("Press Enter for Menu: ");
            getchar();
            menu();
            return;
        }
    }
}
void remove_account()
{
    system("cls");
    struct account *temp=start,*temp2;
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO YOUR BANKING APP \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t\t\t****REMOVE ACCOUNT****");
    char id[100];
    printf("\n\n\t\tEnter your ID: ");
    scanf("%s",id);
    getchar();
    while(temp!=NULL)
    {
        if(strcmp(id,temp->id)==0)
            break;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\n\n\t\t\t\tAccount is not found!!!\n\n\t\t\t\tPlease create your account first ^_^ \n\n");
        printf("Press Enter for Menu: ");
        getchar();
        menu();
        return;
    }
    int limite=0;
    while(1)
    {
        printf("\t\tEnter Your password: ");
        char pass[1000];
        scanf("%s",pass);
        if(strcmp(temp->password,pass)!=0)
        {
            limite++;
            printf("\t*****************Wrong Password!!!\n");
            if(limite==3)
            {
                getchar();
                printf("\n\n\t\t****You have to remind your original password.\n\n\n");
                printf("Press Enter for Menu: ");
                getchar();
                menu();
                return;
            }
        }
        else
            break;
    }
    if(temp->next==NULL)
        temp->previous->next=NULL;
    else if(temp->previous==NULL)
        start=temp->next;
    else
    {
        temp->next->previous=temp->previous;
        temp->previous->next=temp->next;
    }
    num_of_account--;
    close();
    printf("\n\t\t\tYour Account is Removed Successfully!!!");
    getchar();
    printf("\n\n\nPress Enter for Menu: ");
    getchar();
    menu();
    return;

}
void display_account_created(int oparetion)
{
    system("cls");
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO YOUR BANKING APP \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    struct account *temp=start;
    if(oparetion==1)
    {
        printf("\n\n\n\t\t\t\t\t\t All ACCOUNT Details \n\n\n");
        printf("\t\t\t\t\t  Numbers of created accounts: %d\n\n",num_of_account);
        while(temp!=NULL)
        {
            printf("\t\tName : %s\n",temp->name);
            printf("\t\tACCOUNT ID : %s\n",temp->id);
            printf("\t\tPassword : %s\n",temp->password);
            printf("\t\tATM ID : %lld\n",temp->atm_id);
            printf("\t\tATM PIN : %d\n",temp->pin);
            printf("\t\tAge : %d\n",temp->age);
            printf("\t\tPhone : %s\n",temp->phone);
            printf("\t\tBalance : BDT %.2lf/=\n",temp->cash);
            if(temp->account_validation==1)
                printf("\t\tAccount is Active\n");
            else
                printf("\t\tAccount is Inactive\n");
            printf("\n\n");
            temp=temp->next;
        }
    }
    else
    {
        printf("\n\n\n\t\t\t\t ****Fill up these correctly for seeing ACCOUNT Details**** \n");
        char id[100];
        printf("\n\tEnter your ID: ");
        scanf("%s",id);
        getchar();
        while(temp!=NULL)
        {
            if(strcmp(id,temp->id)==0)
                break;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("\n\n\t\t\t\tAccount is not found!!!\n\n\t\t\t\tPlease create your account first ^_^ \n\n");
            printf("Press Enter for Menu: ");
            getchar();
            menu();
            return;
        }
        int limite=0;
        while(1)
        {
            printf("\tEnter Your password: ");
            char pass[1000];
            scanf("%s",pass);
            if(strcmp(temp->password,pass)!=0)
            {
                limite++;
                printf("\t*****************Wrong Password!!!\n");
                if(limite==3)
                {
                    getchar();
                    printf("\n\n\t\t****You have to remind your original password.\n\n\n");
                    printf("Press Enter for Menu: ");
                    getchar();
                    menu();
                    break;
                }
            }
            else
            {
                printf("\n\n\n\t\t\t\t\t Here is your ACCOUNT Details \n\n");
                printf("\t\tName : %s\n",temp->name);
                printf("\t\tACCOUNT ID : %s\n",temp->id);
                printf("\t\tPassword : %s\n",temp->password);
                printf("\t\tATM ID : %lld\n",temp->atm_id);
                printf("\t\tATM PIN : %d\n",temp->pin);
                printf("\t\tAge : %d\n",temp->age);
                printf("\t\tPhone : %s\n",temp->phone);
                printf("\t\tBalance : TK %.2lf/=\n",temp->cash);
                if(temp->account_validation==1)
                    printf("\t\tAccount is Active\n");
                else
                    printf("\t\tAccount is Inactive\n");
                printf("\n\n");
                getchar();
                printf("Press Enter for Menu: ");
                getchar();
                menu();
                return;
            }
        }
    }
}
void create_acc()
{
    num_of_account++;
    int date,month,year;
    struct account *new_account;
    new_account=(struct account*)malloc(sizeof(struct account));
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO YOUR BANKING APP \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t\t****Fill up and Create your own Account****\n\n");
    printf("\n\t\t\tEnter Today's Date \n\t\t\t(DD/MM/YYYY): ");
    scanf("%d/%d/%d",&date,&month,&year);
    getchar();
    printf("\n\t\t\tEnter Your Name: ");
    gets(new_account->name);
    printf("\n\t\t\tEnter Your Password: ");
    scanf("%s",&new_account->password);
    sprintf(new_account->id,"%d",year*10000+num_of_account);
    srand(time(0));
    new_account->atm_id = rand() % 99999999999 + 2345678934;
    srand(time(0));
    new_account->pin = rand() % 9999 + 1000;
    printf("\n\t\t\tEnter Your Phone number: ");
    scanf("%s",&new_account->phone);
    printf("\n\t\t\tEnter Your Age: ");
    scanf("%d",&new_account->age);
    printf("\n\t\t\tFirst Deposit(more than 500/=): ");
    new_account->cash=0;
    scanf("%lf",&new_account->cash);
    printf("\n\t\t\t\t\t.:*:. Congratulations .:*:.");
    printf("\n\t\tYour Account is successfully created, Here is your Account ID : \n");
    printf("\n\t\t\t\tYour ACCOUNT ID is -> %s\n",new_account->id);
    printf("\n\t\t\t\tYour ATM ID is -> %lld\n",new_account->atm_id);
    printf("\n\t\t\t\tYour ATM PIN is -> %d\n",new_account->pin);
    new_account->account_validation=1;
    new_account->next=NULL;
    new_account->previous=NULL;
    if(start==NULL)
    {
        start=new_account;
        current=new_account;
    }
    else
    {
        current->next=new_account;
        new_account->previous=current;
        current=new_account;
        end=current;
    }
    close();
    getchar();
    printf("\nPress Enter for Menu: ");
    getchar();
    menu();
    return;
}
void menu()
{
    system("cls");
    int choice;
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO YOUR BANKING APP \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t[1] Create New Account\n\t\t\t\t[2] Check Your Details\n\t\t\t\t[3] Transaction\n\t\t\t\t[4] Loan\n\t\t\t\t[5] Update Password or Phone Number\n\t\t\t\t[6] Remove Existing Account\n\t\t\t\t[7] Password Recovery or Account Activation\n\t\t\t\t[8] Main Menu\n\n\n\n\n\t\t\t\t Enter your choice: ");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
    case 1:
        create_acc();
        return;
    case 2:
        display_account_created(2);
        return;
    case 3:
        transaction();
        return;
    case 4:
        loan();
        return;
    case 5:
        update();
        return;
    case 6:
        remove_account();
        return;
    case 7:
        recover();
        return;
    }
    f_menu();
    return;
}
///BANK SECTION END


void f_menu()
{
    system("cls");
    int c;
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO YOUR BANKING APP \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t[1] BANK SECTION \t[2] ATM SECTION \t[3] ADMIN PANEL\n\t\t\n\n\n\n\n\n\nEnter your choice & Enter [4] to EXIT: ");
    scanf("%d",&c);
    system("cls");
    switch(c)
    {
    case 1:
        menu();
        return;
    case 2:
        atm();
        return;
    case 3:
        admin_panel();
        return;
    case 4:
        return;
    }
}

void Start()
{
    FILE *ptr;
    ptr=fopen("number_of_account.txt","a+");
    fscanf(ptr,"%d",&num_of_account);
    create_created_acccount();
    fclose(ptr);
}
int main()
{
    Start();
    system("color 0F");
    ///struct account *temp=start;
    f_menu();
    ///printf("\n\n\t\t\t\t\t.:*:. Congratulations .:*:.\n\n");
    printf("\n\n\n\n\t\t\t****Wish you a very good day form DUMBS Banking. Hope I'll see you again.****\n\n\n\t\t\t\tThe Project successfully Shutdown ^_^ ^_^ ^_^\n\n\n\n");
    close();
    return 0;
}




///ATM SECTION START
void atm()
{
    system("cls");
    int opt;
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO OUR 24x7 ATM BOOTH \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    long long int  id;
    printf("\n\n\n\t\t\tEnter your ATM ID: ");
    scanf("%lld",&id);
    getchar();
    struct account *temp,*temp2;
    temp=start;
    while(temp!=NULL)
    {

        int compare;
        compare=(temp->atm_id)-id;
        if(compare==0)
            break;
        temp=temp->next;

    }
    if(temp==NULL)
    {
        printf("\n\n\t\t\t\tATM ID is not found!!!\n\n\t\t\t\tPlease create your account first ^_^ \n\n");
        printf("Press Enter for Menu: ");
        getchar();
        menu();
        return;
    }
    else
    {

        if(temp->account_validation!=0)
        {
            int compare;
wrong:
            printf("\n\n\t\t\tEnter Your Password: ");
            int password;
            scanf("%d",&password);
            compare=(password-temp->pin);
            if(compare!=0)
            {
                printf("\t*****************Wrong Password!!!\n");
                goto wrong;
            }
        }
        else
        {
            printf("Your account is Inactive\n");
            printf("Press [1] Account Activation *ADMIN : ");
            int atv;
            scanf("%d",&atv);
            system("cls");
            if(atv==1)
            {
                admin_panel();
                return;
            }
            else
            {
                menu();
                return;
            }
        }
    }
    system("cls");
jump3:
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO OUR 24x7 ATM BOOTH \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\t\t[1] Withdraw\n\t\t\t\t[2] Balance \n\t\t\t\t[3] Main menu\n\n\nEnter your choice: ");
    scanf("%d",&opt);
    if(opt==1)
    {
        double money;
jump4:
        printf("\n\t\tEnter Amount for Withdraw: ");
        scanf("%lf",&money);
        if(money+500>temp->cash)
        {
            printf("\n\t\t\tSorry you do not have enough money \n");
            printf("\t\t\tYour Balance is : BDT %.2lf/=\n",temp->cash);

            printf("\t\t\t[1] Try Again\t\t[2] Return\nEnter your choice : ");
            int opt;
            scanf("%d",&opt);

            switch(opt)
            {
            case 1:
                goto jump4;
            }
            atm();
            return;
        }
        else
        {
            temp->cash-=money;
            close();
            getchar();
            printf("\n\n\t\t\t\tMoney is Withdrawn successfully:\n\n");
            printf("\n\t\t\t\tNow your Balance : BDT %.2lf/=\n\n",temp->cash);
            printf("Press Enter for Return : ");
            getchar();
            system("cls");
            goto jump3;
        }

    }
    else if(opt==2)
    {
        printf("\n\n\t\t\t\tYour Balance is: BDT %.2lf/=\n\n",temp->cash);
        getchar();
        printf("Press Enter For ATM: ");
        getchar();
        system("cls");
        goto jump3;
    }
    else
    {
        f_menu();
        return;
    }
}
///ATM SECTION END




///ADMIN PANEL START


void admin_panel()
{
    system("cls");
    printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO YOUR BANKING APP \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\t\t\t*****Administration*****");
    printf("\n\n\t\t***Only Bank Administration can access this, Please go to the Bank then the Admin can help you.\n");
    char admin[]="Dumbs_Rocking",pass[100];
    char blocking_id[100];
    getchar();
jump:
    printf("\n\n\n\t\t\t\tEnter Password: " );
    gets(pass);
    if(strcmp(pass,admin)==0)
    {
jump1:
        system("cls");
        printf("\n\n\t\t\t\t\t\t  THE DUMBS NATIONAL BANK");
        printf("\n\n\n\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADMIN PANEL \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\n\n\t\t\t\t[1] Bank Accounts\n\t\t\t\t[2] Account Blocking\n\t\t\t\t[3] Account Activating\n\n\n\n\n\n\n\nEnter your choice & Enter [4] for main menu: ");
        int option;
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            system("cls");
            display_account_created(1);
            printf("Press Enter for Back: ");
            getchar();
            getchar();
            goto jump1;
            break;
        case 2:
block:
            printf("\n\n\n\t\t\tEnter Account ID:");
            scanf("%s",blocking_id);
            struct account *temp=start;
            while(temp!=NULL)
            {
                if(strcmp(temp->id,blocking_id)==0)
                    break;
                temp=temp->next;
            }
            if(temp==NULL)
            {
                printf("\n\n\t\t\t\tAccount is not found!!!\n\n");
                printf("\t\t\tPress [1] Try again [2] Menu: ");
                int opt;
                scanf("%d",&opt);
                switch(opt)
                {
                case 1:
                    goto block;
                }
                goto jump1;
                return;
            }
            else
            {
                printf("Press [1] CONFIRM : ");
                int cfr;
                scanf("%d",&cfr);
                switch(cfr)
                {
                case 1:
                    temp->account_validation=0;
                    close();
                    printf("Account has been BLOCKED\n");
                    printf("Press Enter to Back: ");
                    getchar();
                    getchar();
                    close();
                    goto jump1;
                }
                goto jump1;
                return;
            case 4:
                f_menu();
                return;
            case 3:
active:
                printf("\n\n\t\t\tEnter Account ID: ");
                char search_id[100];

                scanf("%s",search_id);
                struct account *temp=start;
                while(temp!=NULL)
                {
                    if(strcmp(search_id,temp->id)==0)
                        break;
                    temp=temp->next;
                }
                if(temp==NULL)
                    printf("\n\n\t\t\t\tAccount is not found!!!");
                else
                {
                    printf("\t\t\tAccount is Activated\n");
                    temp->account_validation=1;
                    close();
                }
                getchar();
                printf("\t\t\tPress Enter for Menu: ");
                getchar();
                goto jump1;
            }

        }
    }
    else
    {
        printf("\t\t\t\tWrong Password\n");
        printf("\t\t\t\tPress [1] Try Again [2] Menu: ");
        int opt;
        scanf("%d",&opt);
        if(opt==1)
        {
            getchar();
            system("cls");
            goto jump;
        }
        else
        {
            f_menu();
            return;
        }
    }
}
///ADMIN PANEL END
