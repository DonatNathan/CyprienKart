/*
** EPITECH PROJECT, 2021
** AI.H
** File description:
** It's just all function's prototype of our library
*/

#ifndef AI_H_
    #define AI_H_

    #include "my.h"
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <limits.h>

    typedef struct values {
        int start;
        int middle;
        int last;
        int speed;
        int wheels;
        int n;
    } *values_t;

void game_loop(void);
void launch_car(char *buffer, ssize_t mt);
void stop_car(char *buffer, ssize_t mt, values_t values);
void turn_wheels(values_t values, char *buffer, ssize_t mt);
void check_values(char *buffer, values_t values, ssize_t mt);

#endif /* AI_H_ */
