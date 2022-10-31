#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
    FILE* f;
    int a = 190;
    int b = 290;
    int c = 390;

    f = fopen("data.bin", "w");

    if (f==NULL)
    {
        //error
    }
    else
    {
        fwrite(&a, sizeof(int), 1, f);
        fwrite(&b, sizeof(int), 1, f);
        fwrite(&c, sizeof(int), 1, f);
        fclose(f);
    }


    f = fopen("data.bin", "r");
    if (f == NULL)
    {
        //error
    }
    else
    {
        int read = fread(&c, sizeof(int), 1, f);
        printf("%d", c); // 190
        read = fread(&c, sizeof(int), 1, f);
        printf("%d", c); // 290
        read = fread(&c, sizeof(int), 1, f);
        printf("%d", c); // 390
        fclose(f);
    }
    
    struct studend
    {
        char name[100];
        int age;
    };

    f = fopen("data1.bin", "w");

    struct studend stu;
    strcpy(stu.name, "achiya");
    stu.age = 18;

    if (f == NULL)
    {
        //error
    }
    else
    {
        fwrite(&stu, sizeof(struct studend), 1, f);
        fclose(f);
    }

    struct studend newstu;

    f = fopen("data1.bin", "r");
    if (f == NULL)
    {
        //error
    }
    else
    {
        int read = fread(& newstu, sizeof(struct studend), 1, f);
        fclose(f);
    }

    return 0;
}