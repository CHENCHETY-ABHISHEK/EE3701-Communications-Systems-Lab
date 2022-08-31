#include <stdio.h>
#include "common_functions.h"
#include <math.h>
#include <string.h>
void LowPassFilter(float f_c, float f_s, int N, float *h_d, float *h)
{
    //  Here N is no.of taps or samples
    //  f_c is the cutoff frequency (analog) and w_c is the digital cutoff frequency

    float W_H[N];

    for (int n = -(N - 1) / 2; n <= (N - 1) / 2; n++)
    {
        W_H[(N - 1) / 2 + n] = 0.54 - 0.46 * cos(2 * M_PI * (n + (N - 1) / 2) / (N - 1));
        if (n == 0)
        {
            h_d[(N - 1) / 2 + n] = 2*f_c/f_s;
        }
        else
        {
            h_d[(N - 1) / 2 + n] = sin(2*M_PI*f_c * n/f_s) / (M_PI * n);
        }
        h[(N - 1) / 2 + n] = W_H[(N - 1) / 2 + n] * h_d[(N - 1) / 2 + n];
    }
}
void WriteToTxtFile(float *h, int size, char *s)
{
    FILE *fptr;
    fptr = (fopen(s, "w"));

    for (int i = 0; i < size; i++)
    {
        fprintf(fptr, "%f\n", h[i]);
    }
    printf("Data written to %s \n", s);
    fclose(fptr);
}
void BandPassFilter(float f_c1, float f_c2, float f_s, int N, float *h_d, float *h)
{
    double W_H[N];
    for (int i = 0; i < N; i++)
    {
        W_H[i] = 0.54 - 0.46 * cos(2 * M_PI * i / (N - 1));
        if (i == (N - 1) / 2)
            h_d[i] = 2.0 * f_c2 / f_s - 2.0 * f_c1 / f_s;
        else
            h_d[i] = sin(2 * M_PI * f_c2 * (i - (N - 1) / 2) / f_s) / (M_PI * (i - ((N - 1) / 2))) - sin(2 * M_PI * f_c1 * (i - (N - 1) / 2) / f_s) / (M_PI * (i - ((N - 1) / 2)));

        h[i] = W_H[i] * h_d[i]; // Finite length BPF impulse response
    }
}