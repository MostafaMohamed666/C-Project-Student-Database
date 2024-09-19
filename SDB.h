#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
#include "STD.h"
typedef struct
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
} student;

student StudentDB[6] = {
    {8829, 2024, 1, 89, 2, 92, 3, 87},
    {8830, 2023, 1, 64, 2, 90, 3, 84},
    {8831, 2022, 1, 19, 2, 48, 3, 80},
    {8832, 2022, 1, 89, 2, 59, 3, 83},
    {8833, 2021, 1, 91, 2, 100, 3, 91},
};
Bool SDB_isFull();
uint8 SDB_GetUsedSize();
Bool SDB_AddEntry();
void SDB_DeleteEntry(uint32 id);
Bool SDB_ReadEntry(uint32 id);
Bool SDB_IsIdExist(uint32 id);
void SDP_APP();
void SDB_action(uint8 choice);
void SDB_GetList(uint8 *count, uint32 *list);
#endif // SDB_H_INCLUDED
