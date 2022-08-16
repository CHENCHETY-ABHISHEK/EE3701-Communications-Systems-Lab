void Convolution(double *x, double *h, double *y, int x_size, int h_size,int y_size);
void Correlation(double *x, double *y, double *R, int x_size, int y_size);
void Downsample(double *x, double *y,int y_size,int factor);
void Upsample(double *x, double *y, int y_size, int factor);