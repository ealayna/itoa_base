#include<stdlib.h>
#include<string.h>

static void ft_alph(char *s)
{
    if (!(*s))
        return ;
    if (*s > '9')
        *s = *s - 58 + 'a';
    ft_alph(s + 1);
}

static char *ft_base(char *s)
{
    if (s == NULL)
       return(NULL);
    ft_alph(s);
    return(s);
}

static char *ft_nitoa(long long int i, long long int *l,
                      char *s, int k, int base)
{
    if (i / base == 0)
    {
        if (!(s = malloc(sizeof(char) * (k + 2))))
            return(NULL);
        s[0] = '-';
        s[k + 1] = '\0';
    }
    else
        s = ft_nitoa(i / base, l, s, k + 1, base);
    s[k] = '0' - *l % base;
    *l = *l / base;
    return(s);
}

static char *ft_pitoa(long long int i, long long int *l,
                      char *s, int k, int base)
{
    if (i / base == 0)
    {
        if (!(s = malloc(sizeof(char) * (k + 2))))
            return(NULL);
        s[k + 1] = '\0';
    }
    else
        s = ft_pitoa(i / base, l, s, k + 1, base);
    s[k] = '0' + *l % base;
    *l = *l / base;
    return(s);
}

char *itoa_base(long long int i, int base)
{
    char *s;

    if (base > 36 || base < 2)
        return(NULL);
    if (i < 0)
        return(base > 10 ? ft_base(ft_nitoa(i, &i, s, 1, base)) :
               ft_nitoa(i, &i, s, 1, base));
    return(base > 10 ? ft_base(ft_pitoa(i, &i, s, 0, base)) :
           ft_pitoa(i, &i, s, 0, base));
}
