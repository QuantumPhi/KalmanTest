#include <stdio.h>

#include "kalman.h"

int main(int argc, char** argv)
{
    double number;

    Kalman* kalman = kalman_init(0.1);

    int i;
    for(i = 0; i < 10; i++)
    {
        do {
            printf("Enter a double: ");
            scanf("%*c");
        } while (1 != scanf("%lf", &number));
        kalman_update(kalman, number);
        printf("Estimate: %f, Covariance: %f", kalman->value, kalman->covariance);
    }
}
