#include <ctype.h>
#include <stdio.h>
#include <math.h>

// atof: convert string s to double

double atof(char s[])
{
    double val, power, multiplier;
    int i, sign, mul_sign;

    for (i = 0; isspace(s[i]); i++) // skip whitespace
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        float mul_val;
        mul_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;

        for (int m = i; isdigit(s[m]); m++)
        {
            for (mul_val = 0.0; isdigit(s[m]); m++)
                mul_val = 10.0 * mul_val + (s[m] - '0');
            multiplier = mul_val * mul_sign;
        }
    }

    return (sign * val / power ) * pow(10, multiplier);
}
int main()
{
    char s[] = "123.45e6"; // output is 78.930000
    printf("atof equals %lf\n", atof(s));
    return 0;
}