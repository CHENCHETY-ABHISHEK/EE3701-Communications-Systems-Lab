void LowPassFilter(float f_c, float f_s, int N,float *h_d,float *h);
void WriteToTxtFile(float *h, int size, char *s);
void BandPassFilter(float f_c1, float f_c2, float f_s, int N, float  *h_d, float *h);