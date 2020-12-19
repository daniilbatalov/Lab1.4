#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include <time.h>

float getFloat (int mode);
void clear_stdin();
int getInt ();
void output_array (float **arr, int arr_size);
float sum_sec_array (float **arr, int arr_size);
float** alloc_array (int arr_size);
void free_array (float** arr, int arr_size);
void print (int i, int j, float mean, float** arr);

int main()
{
    float **a = NULL;
    int n = 0, c, ch = 0;
    float s = 0.0, a_mean = 0.0;
    int r = (unsigned int)(time(NULL));
    srand(r);
    do
    {

        c = 0;

        system("cls");
        printf("A. INPUT ARRAY\n");
        printf("B. PROCESS ARRAY\n");
        printf("C. OUTPUT ARRAY\n");
        printf("D. EXIT\n");
        c = getchar();
        switch (c)
        {
        case 97 :   //a
        {
            system("cls");
            printf("ENTER THE SIZE OF ARRAY: ");
            clear_stdin();
            n = getInt();
            a = alloc_array(n);
            printf("FILL THE ARRAY WITH RANDOM VALUES? (y/n) ");
            ch = getchar();
            clear_stdin();
            switch (ch)
            {
            case 121 :   //y
            {
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        a[i][j] = getFloat(2);
                        printf("%-7.2f ", a[i][j]);
                    }
                    printf("\n");
                }
                getchar();
                clear_stdin();
                break;
            }
            case 110 :   //n
            {
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        a[i][j] = getFloat(1);
                    }
                    printf("\n");
                }
                break;
            }
            }
            ch = 0;
            c = 0;
            continue;
        }
        case 98 :   //b
        {
            if ((n <= 0) || (a == NULL))
            {
                printf("THE ARRAY IS EMPTY!\n");
                getchar();
                clear_stdin();
            }
            else
            {
                s = sum_sec_array(a, n);
                a_mean = s / n;
            }
            c = 0;
            continue;
        }
        case 99 :   //c
        {
            system("cls");
            printf("INPUT ARRAY: \n");
            output_array(a, n);
            printf("\n");
            printf("OUTPUT ARRAY: \n");

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                print(i, j, a_mean, a);
                }
                printf("\n");
            }
            c = 0;
            getchar();
            clear_stdin();
            free_array(a, n);
            s = 0.0;
            a_mean = 0.0;
            n = 0;
            continue;
        }
        }
    }
    while(c != 100);

    return 0;
}

void clear_stdin()
{
    int ch = getchar();
    while (ch != '\n' && ch != EOF)
    {
        ch = getchar();
    }
}

float getFloat (int mode)
{
    char str[512];
    int r;
    float x;
    switch(mode)
    {
    case 1 :
    {
        fgets(str, sizeof(str), stdin);
        while (sscanf (str, "%d", &r) != 1)
        {
            printf("Enter correct value!\n");
            fgets(str, sizeof(str), stdin);
        }
        x = (float)r;
        break;
    }
    case 2 :
    {
        x = (float)(rand() % 256 - 128);
        break;
    }
    default :
    {
        x = 0.1;
    }

    }
    return x;
}


int getInt ()
{
    char str[512];
    int x;

    fgets(str, sizeof(str), stdin);
    while (sscanf (str, "%d", &x) != 1)
    {
        printf("Enter correct value!\n");
        fgets(str, sizeof(str), stdin);
    }
    return x;
}

void output_array (float **arr, int arr_size)
{
    for(int i = 0; i < arr_size; i++)
    {
        for (int j = 0; j < arr_size; j++)
            printf("%-7.2f ", arr[i][j]);
        printf("\n");
    }
}
float sum_sec_array (float **arr, int arr_size)
{
    float s = 0.0;
    for(int i = 0; i < arr_size; i++)
    {
        s += arr[i][arr_size-i-1];
    }
    return s;
}

float** alloc_array (int arr_size)
{
    float** arr;
    arr = (float**)malloc(arr_size * sizeof(float*));
    for(int i = 0; i < arr_size; i++)
    {
        arr[i] = (float*)malloc(arr_size * sizeof(float));
    }
    return arr;
}

void free_array (float** arr, int arr_size)
{
    for(int i = 0; i < arr_size; i++)
    {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;
}
void print (int i, int j, float mean, float** arr)
{
    if (i > j)
    {
        printf("%-7.2f ", mean);
    }
    else
    {
        printf("%-7.2f ", arr[i][j]);
    }
}
