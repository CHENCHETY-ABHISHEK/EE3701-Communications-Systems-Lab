#include <stdio.h>
#include "common_functions.c"
int main()
{
    double x[] = {0.5377, 1.8339, -2.2588, 0.8622, 0.3188, -1.3077, -0.4336, 0.3426, 3.5784, 2.7694, -1.3499, 3.0349, 0.7254, -0.0631, 0.7147, -0.2050, -0.1241, 1.4897, 1.4090, 1.4172};
    double h[] = {0.6715, -1.2075, 0.7172, 1.6302, 0.4889, 1.0347, 0.7269, -0.3034, 0.2939, -0.7873, 0.8884, -1.1471, -1.0689, -0.8095, -2.9443};

    int x_size = sizeof(x) / sizeof(double);
    int h_size = sizeof(h) / sizeof(double);

    int y_size = x_size + h_size - 1;
    double y[y_size];

    Convolution(x, h, y, x_size, h_size, y_size);

    FILE *fptr;
    fptr = (fopen("Outputs\\Convolution_Output.txt", "w"));
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr, "y[n] = {");
    for (int i = 0; i < y_size - 1; i++)
    {
        fprintf(fptr, "%lf", y[i]);
        fprintf(fptr, ", ");
    }
    fprintf(fptr, "%lf };", y[y_size - 1]);
    fclose(fptr);

    // * -------------------------------------------------------Coorelation------------------------------------------------ *//

    double y1[] = {0.6715, -1.2075, 0.7172, 1.6302, 0.4889, 1.0347, 0.7269, -0.3034, 0.2939, -0.7873, 0.8884, -1.1471, -1.0689, -0.8095, -2.9443};

    int y1_size = sizeof(y1) / sizeof(double);

    double R[x_size+y_size-1];

    Correlation(x, y1, R, x_size, y1_size);

    FILE *fptr1;
    fptr1 = (fopen("Outputs\\Correlation_Output.txt", "w"));
    if (fptr1 == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr1, "R[n] = {");
    for (int i = 0; i < x_size +y1_size - 2; i++)
    {
        fprintf(fptr1, "%lf", R[i]);
        fprintf(fptr1, ", ");
    }
    fprintf(fptr1, "%lf };", R[x_size+y1_size - 2]);
    fclose(fptr1);

    // *-------------------------------------------------------------------- Downsampling------------------------------------------------------------

    double x1[] = {0.3252, -0.7549, 1.3703, -1.7115, -0.1022, -0.2414, 0.3192, 0.3129, -0.8649, -0.0301, -0.1649, 0.6277, 1.0933, 1.1093, -0.8637, 0.0774, -1.2141, -1.1135, -0.0068, 1.5326, -0.7697, 0.3714, -0.2256, 1.1174, -1.0891, 0.0326, 0.5525, 1.1006, 1.5442, 0.0859, -1.4916, -0.7423, -1.0616, 2.3505, -0.6156, 0.7481};

    int x1_size = sizeof(x1) / sizeof(double);

    int M = 2;

    int y2_size = x1_size / M;
    double y2[y2_size];

    Downsample(x1, y2, y2_size, M);

    FILE *fptr2;
    fptr2 = (fopen("Outputs\\Downsample_Output.txt", "w"));
    if (fptr2 == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr2, "Factor M = 2;\n\ty2[n] = {");
    for (int i = 0; i < y2_size - 1; i++)
    {
        fprintf(fptr2, "%lf", y2[i]);
        fprintf(fptr2, ", ");
    }
    fprintf(fptr2, "%lf };", y2[y2_size - 1]);

    M = 3;
    int y3_size = x1_size / M;
    double y3[y3_size];

    Downsample(x1, y3, y3_size, M);
    fprintf(fptr2, "\n");
    fprintf(fptr2, "Factor M = 3;\n\ty3[n] = {");

    for (int i = 0; i < y3_size - 1; i++)
    {
        fprintf(fptr2, "%lf", y3[i]);
        fprintf(fptr2, ", ");
    }
    fprintf(fptr2, "%lf };", y3[y3_size - 1]);
    fclose(fptr2);

    // * -----------------------------------------------------------Upsampling -----------------------------------------------------
    double x2[] = {0.3252, 1.3703, -0.1022, 0.3192, -0.8649, -0.1649, 1.0933, -0.8637, -1.2141, -0.0068, -0.7697, -0.2256, -1.0891, 0.5525, 1.5442, -1.4916, -1.0616, -0.6156};

    int x2_size = sizeof(x2) / sizeof(double);

    int L = 2;                                                          //*  L = 2 is upsampling factor

    int y4_size = x2_size * L;
    double y4[y4_size]; //* Creating upsample data points

    Upsample(x2, y4, y4_size, L);
    FILE *fptr3;
    fptr3 = (fopen("Outputs\\Upsample_Output.txt", "w"));
    if (fptr3 == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr3, "Factor L = 2;\n\ty4[n] = {");
    for (int i = 0; i < y4_size - 1; i++)
    {
        fprintf(fptr3, "%lf", y4[i]);
        fprintf(fptr3, ", ");
    }
    fprintf(fptr3, "%lf };", y4[y4_size - 1]);
    fprintf(fptr3, "\n");

    L = 3;                                                             //*  L = 3 is upsampling factor

    int y5_size = x2_size * L;
    double y5[y5_size]; 

    Upsample(x2, y5, y5_size, L);

    fprintf(fptr3, "Factor L = 3;\n\ty5[n] = {");    
    for (int i = 0; i < y5_size - 1; i++)
    {
        fprintf(fptr3, "%lf", y5[i]);
        fprintf(fptr3, ", ");
    }
    fprintf(fptr3, "%lf };", y5[y5_size - 1]);
    fclose(fptr3);
    return 0;
}