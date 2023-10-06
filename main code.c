#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct student
{
    char fname[26], mname[26], lname[26], name[100];
    int id;
    float assign_1, assign_2, ct_1, ct_2, attn, pro, mid, final;
};
struct student s;

void add_data();
void display_data();
void search_data();
void delete_data();

int main()
{
    printf("\t\t\t\t-----------------------------------------\n\t\t\t\t|\t\t\t\t\t|\n\t\t\t\t|\tSPL LAB STUDENT MARK DATABASE\t|\n\t\t\t\t|");
    printf("\t\t\t\t\t|\n\t\t\t\t-----------------------------------------\n\n\n\n\n\n");

    int ch;
    while (ch != 6)
    {
        printf("\n\n\n\t\t\t\t\t1. Add A STUDENT'S MARK.\n\t\t\t\t\t2. SHOW ALL STUDENT MARKS.\n\t\t\t\t\t3. SEARCH A STUDENT'S MARK.\n\t\t\t\t\t4. DELETE A STUDENT'S DATA.\n\t\t\t\t\t5. EXIT.\n\n\n\t\t\t\t\tWhat do you want?-  ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add_data();
            break;
        case 2:
            display_data();
            break;
        case 3:
            search_data();
            break;
        case 4:
            delete_data();
            break;

        case 5:
            exit(0);
        default:
            printf("Choose wrong option. Please Enter the right option which is shown in the display.");
        }
        if (ch != 5)
            printf("\n\t\t\t\t\tPRESS ANY KEY TO CONTINUE: ");
        else
            printf("\n\t\t\t\t\tPRESS ANY KEY TO Exit: ");
        getch();
    }
    return 0;
}

void add_data()
{
    FILE *file;
    file=fopen("Student's Mark.txt", "ab+");
    if(file==NULL)
    {
        printf("File Creation Unsuccessfull !");
        return;
    }
    else
    {
        printf("Enter Student Id: ");
        scanf("%d", &s.id);
        fflush(stdin);
        printf("Enter Student Full Name: ");
        gets(s.name);
        printf("Enter Student CT-1 Mark(out of 20): ");
        scanf("%f", &s.ct_1);
        printf("Enter Student CT-2 Mark(out of 20): ");
        scanf("%f", &s.ct_2);
        printf("Enter Student Assignment-1 Mark(out of 20): ");
        scanf("%f", &s.assign_1);
        printf("Enter Student Assignment-2 Mark(out of 20): ");
        scanf("%f", &s.assign_2);
        printf("Enter Student Attendence Mark(out of 10): ");
        scanf("%f", &s.attn);
        printf("Enter Student Project Mark(out of 5): ");
        scanf("%f", &s.pro);
        printf("Enter Student Mid Mark(out of 20): ");
        scanf("%f", &s.mid);
        printf("Enter Student Final Mark(out of 25): ");
        scanf("%f", &s.final);
        fwrite(&s, sizeof(s),1,file);
        {
            printf("\n\n\n\t\t\t\t\tData Add Successful.");
        }
        fclose(file);
    }
}
void display_data()
{
    int x=1;
    float c, a, m, total;
    double cg;
    FILE *file;
    file=fopen("Student's Mark.txt", "rb");
    if(file==NULL)
    {
        printf("File Can't open");
        return ;
    }
    else
    {
        while(fread(&s,sizeof(s),1,file)==1)
        {
            if(s.ct_1>=s.ct_2)
            {
                c = s.ct_1/20;
                c = c*30;
            }
            else if(s.ct_2>=s.ct_1)
            {
                c = s.ct_2/20;
                c = c*30;
            }
            if(s.assign_1>=s.assign_2)
            {
                a = s.assign_1/20;
                a = a*10;
            }
            else if(s.assign_2>=s.assign_1)
            {
                a = s.assign_2/20;
                a = a*10;
            }
            m = s.mid;

            total = c+a+m+s.final+s.pro+s.attn;
            if(total>=90 && total<=100)
                cg = 4.00;
            else if(total>85 && total<90)
                cg = 3.67;
            else if(total>81 && total <86)
                cg = 3.33;
            else if(total>77 && total <82)
                cg = 3.00;
            else if(total>73 && total <78)
                cg = 2.67;
            else if(total>69 && total <74)
                cg = 2.33;
            else if(total>65 && total <70)
                cg = 2.00;
            else if(total>61 && total <66)
                cg = 1.67;
            else if(total>57 && total <62)
                cg = 1.33;
            else if(total>54 && total <58)
                cg = 1.00;
            else
                cg = 0.00;

            printf("%d. Student Id: %d\n", x++, s.id);
            printf("    Full Name: %s\n", s.name);
            printf("    CT-1 Mark: %.2f\n", s.ct_1);
            printf("    CT-2 Mark: %.2f\n", s.ct_2);
            printf("    Best CT Mark(Out of 30): %.2f\n", c);
            printf("    Assignment-1 Mark: %.2f\n", s.assign_1);
            printf("    Assignment-2 Mark: %.2f\n", s.assign_2);
            printf("    Best Assignment Mark(Out of 10): %.2f\n", a);
            printf("    Attendance Mark: %.2f\n", s.attn);
            printf("    Project Mark: %.2f\n", s.pro);
            printf("    Mid Exam Mark: %.2f\n", s.mid);
            printf("    Final Exam Mark: %.2f\n", s.final);
            printf("    Total Mark: %.2f\n", total);
            printf("    CGPA: %.2lf\n", cg);
            printf("\n\n\n");
        }
        fclose(file);
    }
}
void search_data()
{
    int roll, flag=0;
    float c, a, m, total,cg;
    FILE *file;
    file=fopen("Student's Mark.txt", "rb");
    if(file==NULL)
    {
        printf("File Can't open");
        return ;
    }
    else
    {
        printf("Enter Student ID: ");
        scanf("%d", &roll);
        while(fread(&s,sizeof(s),1,file)==1)
        {
            if(s.id==roll)
            {
                flag=1;
                if(s.ct_1>=s.ct_2)
                {
                    c = s.ct_1/20;
                    c = c*30;
                }
                else if(s.ct_2>=s.ct_1)
                {
                    c = s.ct_2/20;
                    c = c*30;
                }
                if(s.assign_1>=s.assign_2)
                {
                    a = s.assign_1/20;
                    a = a*10;
                }
                else if(s.assign_2>=s.assign_1)
                {
                    a = s.assign_2/20;
                    a = a*10;
                }
                m = s.mid;

                total = c+a+m+s.final+s.pro+s.attn;

                if(total>=90 && total<=100)
                    cg = 4.00;
                else if(total>85 && total<90)
                    cg = 3.67;
                else if(total>81 && total <86)
                    cg = 3.33;
                else if(total>77 && total <82)
                    cg = 3.00;
                else if(total>73 && total <78)
                    cg = 2.67;
                else if(total>69 && total <74)
                    cg = 2.33;
                else if(total>65 && total <70)
                    cg = 2.00;
                else if(total>61 && total <66)
                    cg = 1.67;
                else if(total>57 && total <62)
                    cg = 1.33;
                else if(total>54 && total <58)
                    cg = 1.00;
                else
                    cg = 0.00;

                printf("\n\n    Student Id: %d\n", s.id);
                printf("    Full Name: %s\n", s.name);
                printf("    CT-1 Mark: %.2f\n", s.ct_1);
                printf("    CT-2 Mark: %.2f\n", s.ct_2);
                printf("    Best CT Mark(Out of 30): %.2f\n", c);
                printf("    Assignment-1 Mark: %.2f\n", s.assign_1);
                printf("    Assignment-2 Mark: %.2f\n", s.assign_2);
                printf("    Best Assignment Mark(Out of 10): %.2f\n", a);
                printf("    Attendance Mark: %.2f\n", s.attn);
                printf("    Project Mark: %.2f\n", s.pro);
                printf("    Mid Exam Mark: %.2f\n", m);
                printf("    Final Exam Mark: %.2f\n", s.final);
                printf("    Total Mark: %.2f\n", total);
                printf("    CGPA: %.2f\n", cg);
            }
        }
        if(flag==0)
            printf("Data is not Available !");
        fclose(file);
    }
}
void delete_data()
{
    int roll, flag = 0;
    FILE *file, *temp;
    file = fopen("Student's Mark.txt", "rb");
    temp = fopen("temp.txt", "wb");
    if (file == NULL)
    {
        printf("File Can't open");
        return;
    }
    else
    {
        printf("Enter Student ID to delete: ");
        scanf("%d", &roll);
        while (fread(&s, sizeof(s), 1, file) == 1)
        {
            if (s.id != roll)
            {
                fwrite(&s, sizeof(s), 1, temp);
            }
            else
            {
                flag = 1;
                printf("Data of Student with ID %d deleted.\n", roll);
            }
        }
        if (flag == 0)
            printf("Data not found for deletion.\n");
        fclose(file);
        fclose(temp);
        remove("Student's Mark.txt");
        rename("temp.txt", "Student's Mark.txt");
    }
}

