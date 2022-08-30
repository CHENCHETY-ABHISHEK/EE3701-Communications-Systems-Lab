#include <stdio.h>
#include "common_functions.h"
#include <math.h>
#include<string.h>
#define pi 3.1428
void LowPassFilter(int f_c, double w_c, int N, double *h)
{
    //  Here N is no.of taps or samples
    //  f_c is the cutoff frequency (analog) and w_c is the digital cutoff frequency

    for (int n = -(N - 1) / 2; n <= (N - 1) / 2; n++)
    {
        if (n == 0)
        {
            h[(N - 1) / 2 + n] = w_c / pi;
        }
        else
        {
            h[(N - 1) / 2 + n] = sin(w_c * n) / (pi * n);
        }
    }
}
void WriteToTxtFile(double *h,int size,char *s)
{
    FILE *fptr;
    fptr = (fopen(s, "w"));

    for (int i = 0; i < size; i++)
    {
        fprintf(fptr, "%lf\n", h[i]);
    }
    printf("Data written to %s \n", s);
    fclose(fptr);
}