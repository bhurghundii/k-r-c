#include <stdio.h>

// Modify the temperature conversion program to print a heading above the table

/* print Fahrenheit-Celsius table
for fahr = 0, 20, .., 300; floating-point version */
main()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0; /* lower limit of temperature table */
    upper = 300;
    // upper limit
    step = 20;
    // stepsize
    fahr = upper;
    printf("Celcius Fahr\n");

    while (fahr >= lower)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%6.1f %3.0f\n", celsius, fahr);
        fahr = fahr - step;
    }
}