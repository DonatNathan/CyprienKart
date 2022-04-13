/*
** EPITECH PROJECT, 2021
** Epitech
** File description:
** my_getnbr.c
*/

int count_sign(char *str)
{
    int s = 0;

    for (int i = 0; '\0' != str[i]; i++) {
        if (str[i] == '-')
            s++;
    }
    if (s % 2 == 0)
        return 1;
    else
        return -1;
}

int full_nb(int i, char *str)
{
    int res = 0;
    int temp = 0;

    for (i; str[i] >= '0' && str[i] <= '9'; i++) {
        res = res * 10 + (str[i] - '0');
        if (res < temp) {
            return (0);
        }
        temp = res;
    }
    res = res * count_sign(str);
    return (res);
}

int my_getnbr(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            res = full_nb(i, str);
            return (res);
        }
    }
    return 0;
}
