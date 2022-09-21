#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
struct contact
{
    int seriol_no;
    char category[20];
    char name[30];
    char gender;
    int age;
    char address[30];
    char phone[12];
    char gmail[30];
    char pass[10];

} user;
void Edit_contact();
void search_contact();
void add_contact();
void delete_contact();
void list_of_contact();
int main()
{
    int i = 0;
    char pass[10], original[10], ch;
    FILE *passw;
    system("cls");
    printf(ANSI_COLOR_BLUE "\n\t\t\t\t\t\tCONTACT MANAGER\n\n");
    printf(ANSI_COLOR_GREEN "\t\t\t\t\t      Developed by c kumar\n\n");
    printf("\n\t\t\t\t    please wait");
    for (int k = 0; k < 25; k++)
    {
        printf("%c", 220);
        usleep(105000); // used like sleep function.
    }
    while (1)
    {
        system("cls");
        printf(ANSI_COLOR_GREEN "\n\t\t\t\t-:MAIN MENU:-\n\n" ANSI_COLOR_RESET);
        printf("\t\t\t     1.  add new contact\n");
        printf("\t\t\t     2.  delete contact\n");
        printf("\t\t\t     3.  Editing      not fount working process\n");
        printf("\t\t\t     4.  searching\n");
        printf("\t\t\t     5.  view list of contact\n");
        printf("\t\t\t     6.  exit\n");
        printf("\n\t\t---------------------------------------------\n\n\t");
        printf(ANSI_COLOR_YELLOW "\t\tEnter your choice ?   ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_contact();
            break;
        case 2:
            delete_contact();
            break;
        // case 3:
        //// Edit_contact();//working process
        // break;
        case 4:
            system("cls");
        RE_enter: // level
            fflush(stdin);
            printf(ANSI_COLOR_CYAN "\n\t\tEnter your password:  " ANSI_COLOR_RESET);
            while (1)
            {
                ch = getch();
                if (ch == 13)
                {                   // 13 is ascii code of enter.
                    pass[i] = '\0'; // last character is null assigned.
                    break;
                }
                pass[i++] = ch;
                printf("*");
            }
            // reading password from the file
            passw = fopen("password.txt", "r");
            fgets(original, 10, passw);
            if (strcmp(original, pass) == 0)
            {
                search_contact();
            }
            else
            {
                printf(ANSI_COLOR_YELLOW "\n\t\t\t\t\tinvalid password...!" ANSI_COLOR_RESET);
                printf("\n\npress E or e to exit & other key to reEnter password..!");
                ch = getch();
                if (ch == 'E' || ch == 'e')
                    break;
                else
                {
                    i = 0;
                    fclose(passw);
                    system("cls");
                    goto RE_enter;
                }
            }
            fclose(passw);
            break;
        case 5: // case 5 start
            system("cls");
        re_enter: // level
            fflush(stdin);
            printf(ANSI_COLOR_CYAN "\n\t\tEnter your password:  " ANSI_COLOR_RESET);
            while (1)
            {
                ch = getch();
                // printf("%d", ch);
                if (ch == 13)
                {                   // 13 is ascii code of enter.
                    pass[i] = '\0'; // last character is null assigned.
                    break;
                }
                pass[i++] = ch;
                printf("*");
            }
            // reading password from the file
            passw = fopen("password.txt", "r");
            fgets(original, 10, passw);
            if (strcmp(original, pass) == 0)
            {
                list_of_contact();
                printf(ANSI_COLOR_YELLOW "\n\t\tlogic successfull...." ANSI_COLOR_RESET);
                printf(ANSI_COLOR_GREEN "\n\t\t\tpress any key to continue...." ANSI_COLOR_RESET);
                getch();
            }
            else
            {
                printf(ANSI_COLOR_YELLOW "\n\t\t\t\t\tinvalid password...!" ANSI_COLOR_RESET);
                printf("\n\npress E or e to exit & other key to reEnter password..!");
                ch = getch();
                if (ch == 'E' || ch == 'e')
                    break;
                else
                {
                    i = 0;
                    fclose(passw);
                    system("cls");
                    goto re_enter;
                }
            }
            fclose(passw);
            break; // case 5 end....
        case 7:
            exit(0);
        }
    }
    return 0;
} // main function end......
void add_contact()
{
    system("cls");
    printf(ANSI_COLOR_BLUE "\t\t\t\t-:add contanct:-\n" ANSI_COLOR_RESET);
    printf("\t\t________________________________________________");
    printf("\n\t\tEnter seriol number: ");
    scanf("%d", &user.seriol_no);
    fflush(stdin);
    printf("\n\t\tEnter you category: ");
    fgets(user.category, 20, stdin);
    fflush(stdin);
    printf("\n\t\tEnter your name: ");
    fgets(user.name, 20, stdin);
    fflush(stdin);
    printf("\n\t\tEnter gender: ");
    scanf("%c", &user.gender);
    fflush(stdin);
    printf("\n\t\tEnter Age: ");
    scanf("%d", &user.age);
    fflush(stdin);
    printf("\n\t\tEnter your address: ");
    fgets(user.address, 20, stdin);
    fflush(stdin);
    printf("\n\t\tEnter your phone: ");
    fgets(user.phone, 12, stdin);
    fflush(stdin);
    printf("\n\t\tEnter your email: ");
    fgets(user.gmail, 30, stdin);

    strcpy(user.pass, "CHHO");
    int len = strlen(user.phone);
    int j = 4;
    len -= 2;
    for (; j <= 7; len--, j++)
    {
        user.pass[j + 1] = user.pass[j];
        user.pass[j] = user.phone[len];
    }
    FILE *fp;
    fp = fopen("info.txt", "a");
    fwrite(&user, sizeof(user), 1, fp);
    fclose(fp);
    printf(ANSI_COLOR_YELLOW "\n\n\t\tRecord is successfully saved");
    printf(ANSI_COLOR_GREEN "\n\n\t\tYour ID       : %s ", user.phone);
    printf("\t\tYour Password : %s" ANSI_COLOR_RESET, user.pass);
    printf(ANSI_COLOR_BLUE "\npress any key to continue..." ANSI_COLOR_RESET);
    getch();
} // add contact function end......
void list_of_contact()
{
    system("cls");
    printf(ANSI_COLOR_BLUE "\t\t\t\t-:List of contanct:-\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "\t__________________________________________________________________________\n");
    FILE *fp;
    fp = fopen("info.txt", "r");
    while (fread(&user, sizeof(user), 1, fp) != NULL)
    {
        printf(ANSI_COLOR_GREEN "Seriol no: %d\n" ANSI_COLOR_RESET, user.seriol_no);
        printf("\t\tcategory : %s", user.category);
        printf("\t\tName     : %s", user.name);
        printf("\t\tgender  : %c\n", user.gender);
        printf("\t\tAGE      : %d\n", user.age);
        printf("\t\tAddress  : %s", user.address);
        printf("\t\tphone:   : %s", user.phone);
        printf("\t\tEmail    : %s", user.gmail);
        printf("\t\tpassword : %s\n\n", user.pass);
    }
    fclose(fp);

} // list of contact function end....
void delete_contact()
{
    system("cls");
    char userID[12], userPass[10];
    fflush(stdin);
    printf(ANSI_COLOR_CYAN "Enter your ID: ");
    fgets(userID, 12, stdin);
    fflush(stdin);
    printf("Enter Your Password: ");
    fgets(userPass, 12, stdin);
    FILE *ftemp, *fp;
    ftemp = fopen("temp.txt", "a");

    int len = strlen(userPass);
    len = len - 2;
    fp = fopen("info.txt", "a+");
    while (fread(&user, sizeof(user), 1, fp) != NULL)
    {
        if (strcmp(user.phone, userID) == 0 && strncmp(userPass, user.pass, len) == 0)
        {
            printf(ANSI_COLOR_GREEN "Seriol no: %d\n" ANSI_COLOR_RESET, user.seriol_no);
            printf("\t\tcategory : %s", user.category);
            printf("\t\tName     : %s", user.name);
            printf("\t\tgender  : %c\n", user.gender);
            printf("\t\tAGE      : %d\n", user.age);
            printf("\t\tAddress  : %s", user.address);
            printf("\t\tphone:   : %s", user.phone);
            printf("\t\tEmail    : %s", user.gmail);
            printf("\t\tpassword : %s\n\n", user.pass);
            char check;
            printf("you are confom your record deleted: (y,N):  ");
            fflush(stdin);
            scanf("%c", &check);
            if (check == 'N' || check == 'n')
                goto store;
        } // if condition end....
        else
        {
            // getch();
        store: // lavel
            fwrite(&user, sizeof(user), 1, ftemp);
        }
    }
    int a, b, c;
    fclose(fp);
    fclose(ftemp);
    a = remove("info.txt");
    b = rename("temp.txt", "info.txt");
    c = remove("temp.txt");
    if (a == b == c == 0)
        printf("record deleted successfully...");
    else
        printf("record deleting failed..!");
    printf(ANSI_COLOR_YELLOW "\npress any key to continue..." ANSI_COLOR_RESET);
    getch();
} // delete contact end.....
void search_contact()
{
    // this is continue.....
    system("cls");
    char userID[12], Name[20], gender;
    int age, ch, check;
    fflush(stdin);
    printf(ANSI_COLOR_GREEN "\t\t\t\tSearch_Contact:-\n\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "\n\t\t1.  serach thought ID.");
    printf("\n\t\t2.  search thought Name.");
    printf("\n\t\t3.  search thought Age.");
    printf("\n\t\t4.  search thought Gender.");
    printf("\n\t\t5.  Goto Main Manu");
    printf(ANSI_COLOR_BLUE "\n\n\t\t\tEnter your choice ?    " ANSI_COLOR_RESET);
    fflush(stdin);
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\n\n\t\tEnter ID: ");
        fflush(stdin);
        fgets(userID, 12, stdin);
        break;
    case 2:
        printf("\n\n\t\tEnter Name: ");
        fflush(stdin);
        fgets(Name, 20, stdin);
        break;
    case 3:
        printf("\n\n\t\tEnter Age: ");
        fflush(stdin);
        scanf("%d", &age);
        break;
    case 4:
        printf("\n\n\t\tEnter gender: ");
        fflush(stdin);
        scanf("%c", &gender);
        break;
    }
    FILE *fp;
    fp = fopen("info.txt", "r");
recheck:
    if (ch == 4)
    {
        while (fread(&user, sizeof(user), 1, fp) != NULL)
        {
            if (user.gender == gender)
            {
                check = 9;
                goto data;
            }
        }
    }
    if (ch == 3)
    {

        while (fread(&user, sizeof(user), 1, fp) != NULL)
        {
            if (user.age == age)
            {
                check = 9;
                goto data;
            }
        }
    }
    if (ch == 1)
    {
        while (fread(&user, sizeof(user), 1, fp) != NULL)
        {
            if (strcmp(user.phone, userID) == 0)
            {
                check = 9;
                goto data;
            }
        }
    }
    else if (2)
    {
        while (fread(&user, sizeof(user), 1, fp) != NULL)
        {
            if (strcmp(user.name, Name) == 0)
            {
                check = 9;
                goto data;
            }
        }
    }
data:
    if (check == 9)
    {
        printf(ANSI_COLOR_GREEN "\nSeriol no: %d\n" ANSI_COLOR_RESET, user.seriol_no);
        printf("\t\tcategory : %s", user.category);
        printf("\t\tName     : %s", user.name);
        printf("\t\tgender  : %c\n", user.gender);
        printf("\t\tAGE      : %d\n", user.age);
        printf("\t\tAddress  : %s", user.address);
        printf("\t\tphone:   : %s", user.phone);
        printf("\t\tEmail    : %s", user.gmail);
        printf("\t\tpassword : %s\n\n", user.pass);
        check = 5;
        goto recheck;
    }
    fclose(fp);
    printf(ANSI_COLOR_YELLOW "\n\n\t\tpress any key to continue...." ANSI_COLOR_RESET);
    getch(); // if condition end....
} // searching function end......!
void Edit_contact()
{
    system("cls");
    int choice;
    char phone[12], name[30], address[30], email[30];
    printf(ANSI_COLOR_GREEN "\t\t\t\tEdit_Contact:-\n\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED "\n[Note: " ANSI_COLOR_YELLOW "Specilly can`t change password. you edit phone no. password automatically changed" ANSI_COLOR_RED "]");
    char userID[12], userPass[10];
    fflush(stdin);
    printf(ANSI_COLOR_CYAN "\nEnter your ID: ");
    fgets(userID, 12, stdin);
    fflush(stdin);
    printf("\nEnter Your Password: ");
    fgets(userPass, 12, stdin);
    FILE *fp;
    int len = strlen(user.pass);
    len = len - 2;
    fp = fopen("info.txt", "r+");
    int Show_wrong = 0;
    while (fread(&user, sizeof(user), 1, fp) != NULL)
    {
        if (strcmp(user.phone, userID) == 0 && strncmp(userPass, user.pass, len) == 0)
        {
            printf(ANSI_COLOR_GREEN "Seriol no: %d\n" ANSI_COLOR_RESET, user.seriol_no);
            printf("\t\tcategory : %s", user.category);
            printf("\t\tName     : %s", user.name);
            printf("\t\tgender  : %c\n", user.gender);
            printf("\t\tAGE      : %d\n", user.age);
            printf("\t\tAddress  : %s", user.address);
            printf("\t\tphone:   : %s", user.phone);
            printf("\t\tEmail    : %s", user.gmail);
            printf("\t\tpassword : %s\n\n", user.pass);
            char check;
            printf("you are confom your record changed: (y,N):  ");
            fflush(stdin);
            Show_wrong = 9;
            scanf("%c", &check);
            if (check == 'Y' || check == 'y')
            {
                Show_wrong = 5;
                break;
            }
        }
    }
    int pos = ftell(fp);
    fseek(fp, pos - sizeof(user), SEEK_CUR);
    printf(ANSI_COLOR_BLUE "\n\n\t\t\tWhat do you want to change ?.\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n\t\t\t1.   Phone." ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n\t\t\t2.   Name." ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n\t\t\t3.   Address." ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n\t\t\t4.   Email." ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n\t\t\t5.   Goto Main Manu." ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA "\n\n\t\t\tEnter you choice?   " ANSI_COLOR_RESET);
    fflush(stdin);
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf(ANSI_COLOR_GREEN "Enter Phone no.:    " ANSI_COLOR_RESET);
        fflush(stdin);
        fgets(user.phone, 12, stdin);
    }
    else if (choice == 2)
    {
        printf(ANSI_COLOR_GREEN "Enter Name:    " ANSI_COLOR_RESET);
        fflush(stdin);
        fgets(user.name, 30, stdin);
    }
    else if (choice == 3)
    {
        printf(ANSI_COLOR_GREEN "Enter Address:    " ANSI_COLOR_RESET);
        fflush(stdin);
        fgets(user.address, 30, stdin);
    }
    else if (choice == 4)
    {
        printf(ANSI_COLOR_GREEN "Enter Email:    " ANSI_COLOR_RESET);
        fflush(stdin);
        fgets(user.gmail, 30, stdin);
    }
    if (Show_wrong == 5)
        fwrite(&user, sizeof(user), 1, fp);
    fclose(fp);
    if (Show_wrong == 0)
        printf(ANSI_COLOR_MAGENTA "\nthis record does not exist...!");
    else if (Show_wrong == 5)
        printf(ANSI_COLOR_YELLOW "\n\t\t\tsuccessfully updated");
    getch();
}