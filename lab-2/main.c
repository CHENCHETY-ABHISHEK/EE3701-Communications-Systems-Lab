#include <stdio.h>
#include "common_functions.c"
int main()
{
    //* * * * * * * * * * * * * * * *  LPF-1 * * * * * * * * * * * * * * * * //

    // Declaring All required variables
    int N, f_c;
    double w_c;

    // Initialising all the variables as per given data
    f_c = 400;
    w_c = pi / 2;
    N = 39;

    // Creating a Array to store the Filter data
    double h[N];

    // Modify the elements as per given formula
    LowPassFilter(f_c, w_c, N, h);

    // Writing to the text file
    WriteToTxtFile(h, N, "h1.txt");

    //* * * * * * * * * * * * LPF-2 * * * * * * * * * * * *//

    f_c = 400, w_c = pi / 4, N = 39;

    // Modify the elements as per given formula
    LowPassFilter(f_c, w_c, N, h);

    // Writing to the text file
    WriteToTxtFile(h, N, "h2.txt");

    return 0;
}