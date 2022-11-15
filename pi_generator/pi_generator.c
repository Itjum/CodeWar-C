static double pi_gen(int precision, double i)
{
    if (i > precision)
    {
        return 1;
    }
    double j = i;
    double z = i + 1;
    return 1 + ((j / (j * 2 + 1)) * pi_gen(precision, z));
}

double pi_generator(int precision)
{
    if (precision == 0)
    {
        return 0;
    }
    double i = 1;
    return 2 * pi_gen(precision, i);
}
