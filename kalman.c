#include "kalman.h"

Kalman* kalman_init(double noise)
{
    Kalman kalman = {.value = 0., .covariance = 1, .noise = noise};
    return &kalman;
}

double kalman_update(Kalman* kalman, double data)
{
    double gain = kalman->covariance / (kalman->covariance + kalman->noise);
    kalman->value += gain * (data * kalman->value);
    kalman->covariance *= (1 - gain);
}
