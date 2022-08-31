#include <stdio.h>
#include "common_functions.c"
int main()
{
    //* * * * * * * * * * * * * * * *  LPF-1 * * * * * * * * * * * * * * * * //

    // Declaring All required variables
    int N;

    float f_c;
    float w_c;
    float f_s;

    // Initialising all the variables as per given data
    f_c = 400;
    w_c = M_PI / 2;
    N = 39;
    f_s = 2 * M_PI * f_c / w_c;

    // Creating a Array to store the Filter data
    float h_d[N];
    float h[N];

    // Modify the elements as per given formula
    LowPassFilter(f_c, f_s, N, h_d, h);

    // Writing to the text file
    WriteToTxtFile(h_d, N, "hd_1.txt");
    WriteToTxtFile(h, N, "h1.txt");

    //* * * * * * * * * * * * * * *  LPF-2 * * * * * * * * * * * * * * * * * * * * *//

    f_c = 400, w_c = M_PI / 4, N = 39;
    f_s = 2 * M_PI * f_c / w_c;
    // Modify the elements as per given formula
    LowPassFilter(f_c, f_s, N, h_d, h);

    // Writing to the text file
    WriteToTxtFile(h_d, N, "hd_2.txt");
    WriteToTxtFile(h, N, "h2.txt");

    // * * * * * * * * * * * * * * * * * BPF* * * * * * * * * * * * * * * * * * * //

    float f_c1, f_c2;
    f_c1 = 500;
    f_c2 = 1200;
    f_s = 6000;

    BandPassFilter(f_c1, f_c2, f_s, N, h_d, h);

    WriteToTxtFile(h_d, N, "hd_3.txt");
    WriteToTxtFile(h, N, "h3.txt");

    return 0;
}