typedef struct
{
    double value; //Estimate
    double covariance; //Error Covariance
    double noise; //Environment noise
} Kalman;

Kalman* kalman_init(double noise);
double kalman_update(Kalman* kalman, double data);
