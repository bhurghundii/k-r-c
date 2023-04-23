#include <stdio.h>

// Modify the temperature conversion program to print a heading above the table

void fahrToCelcius(int x);

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
    fahr = lower;
    printf("Fahr  Celcius\n");

    while (fahr <= upper)
    {
        celsius = fahrToCelcius(fahr);
        printf("%3.0f %6. 1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

void fahrToCelcius(int fahr){
    return (5.0 / 9.0) * (fahr - 32.0);
}