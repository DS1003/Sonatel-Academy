#include <stdio.h>

int main()
{
    float r1, r2, r3, rs, rp;
    printf("Saisissez 3 résistances\n");
    printf("R1: ");
    scanf("%f", &r1);
    printf("R2: ");
    scanf("%f", &r2);
    printf("R3: ");
    scanf("%f", &r3);
    rs = r1 + r2 + r3;
    rp = (r1 * r2 * r3) / ((r1*r2)+(r2*r3)+(r1*r3));
    printf("\nLa résistance en série est %f Ohms.\n", rs);
    printf("La résistance en parallele est %f Ohms.\n", rp);
    return 0;
}