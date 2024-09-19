#include "STD.h"
#include "SDB.h"
uint32 size = 5;
Bool SDB_isFull()
{
    if(size == 6)
        return True;
    return False;
}
uint8 SDB_GetUsedSize()
{
    return size;
}
Bool validateStudentID(int id)
{
    if(id > 0 && id < 8999)
        return True;
    else
    {
        printf("Invalid Student id!\n");
        return False;
    }
}
Bool validateStudentYear(int year)
{
    if(year >= 2000 && year <= 2025)
        return True;
    else
    {
        printf("Invalid Student Year!\n");
        return False;
    }
}
Bool validateCourseID(int id)
{
    if(id > 0 && id < 20)
        return True;
    else
    {
        printf("Invalid course id!\n");
        return False;
    }
}
Bool validateCourseGrade(int grade)
{
    if(grade >=0 && grade <= 100)
        return True;
    else
    {
        printf("Invalid course grade!\n");
        return False;
    }
}
Bool SDB_AddEntry()
{
    if(SDB_isFull()){
        printf("Database is full cannot add student!");
        return False;
    }
    else
    {
        uint32 x = 0;
        do
        {
            printf("Enter student id: ");
            scanf("%d", &x);
        } while(!validateStudentID(x));
        StudentDB[size].Student_ID = x;
        do
        {
            printf("Enter student year: ");
            scanf("%d", &x);
        } while(!validateStudentYear(x));
        StudentDB[size].Student_year = x;
        do
        {
            printf("Enter course 1 id: ");
            scanf("%d", &x);
        } while(!validateCourseID(x));
        StudentDB[size].Course1_ID = x;
        do
        {
            printf("Enter course 1 grade: ");
            scanf("%d", &x);
        } while(!validateCourseGrade(x));
        StudentDB[size].Course1_grade = x;
        do
        {
            printf("Enter course 2 id: ");
            scanf("%d", &x);
        } while(!validateCourseID(x));
        StudentDB[size].Course2_ID = x;
        do
        {
            printf("Enter course 2 grade: ");
            scanf("%d", &x);
        } while(!validateCourseGrade(x));
        StudentDB[size].Course2_grade = x;
        do
        {
            printf("Enter course 3 id: ");
            scanf("%d", &x);
        } while(!validateCourseID(x));
        StudentDB[size].Course3_ID = x;
        do
        {
            printf("Enter course 3 grade: ");
            scanf("%d", &x);
        } while(!validateCourseGrade(x));
        StudentDB[size].Course3_grade = x;
        size++;
    }
    return True;
}
void SDB_DeleteEntry(uint32 id)
{
    int flag = 0,i;
    for(i=0;i<size;i++)
    {
        if(StudentDB[i].Student_ID == id)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        for(int j=i; j<size-1; j++)
        {
            StudentDB[j] = StudentDB[j+1];
        }
        size--;
    } else printf("Account does not exist\n");
}
Bool SDB_ReadEntry(uint32 id)
{
    int flag = 0,i;
    for(i=0;i<size;i++)
    {
        if(StudentDB[i].Student_ID == id)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        printf("Student id: %d\n", StudentDB[i].Student_ID);
        printf("Student Year: %d\n", StudentDB[i].Student_year);
        printf("Course 1 id: %d\n", StudentDB[i].Course1_ID);
        printf("Course 1 grade: %d\n", StudentDB[i].Course1_grade);
        printf("Course 2 id: %d\n", StudentDB[i].Course2_ID);
        printf("Course 2 grade: %d\n", StudentDB[i].Course2_grade);
        printf("Course 3 id: %d\n", StudentDB[i].Course3_ID);
        printf("Course 3 grade: %d\n", StudentDB[i].Course3_grade);
        return True;
    }
    return False;
}
void SDB_GetList(uint8 *count, uint32 *list)
{
    *count = size;
    for (int i = 0; i < size; i++) {
        list[i] = StudentDB[i].Student_ID;
    }

}
Bool SDB_IsIdExist(uint32 id)
{
    int flag = 0;
    for(int i=0;i<size;i++)
    {
        if(StudentDB[i].Student_ID == id)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
        return True;
    return False;
}

