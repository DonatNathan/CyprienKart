/*
** EPITECH PROJECT, 2022
** MY_PROJECT
** File description:
** It's the file that contain functions to move my car
*/

#include "../includes/ai.h"

void launch_car(char *buffer, ssize_t mt)
{
    dprintf(1, "START_SIMULATION\n");
    getline(&buffer, &mt, stdin);
}

float check_speed(char *buffer, values_t values, ssize_t mt)
{
    char **stats;

    dprintf(1, "GET_CURRENT_SPEED\n");
    getline(&buffer, &mt, stdin);
    stats = my_str_to_word_array(buffer, ":");
    values->speed = atoi(stats[3]);
    dprintf(2, "Speed : %d\n", values->speed);
}

void stop_car(char *buffer, ssize_t mt, values_t values)
{
    check_speed(buffer, values, mt);
    while (values->speed != 0) {
        check_speed(buffer, values, mt);
        dprintf(1, "CAR_FORWARD:0\n");
        getline(&buffer, &mt, stdin);
    }
    dprintf(1, "STOP_SIMULATION\n");
    getline(&buffer, &mt, stdin);
}

void check_values(char *buffer, values_t values, ssize_t mt)
{
    char **stats = my_str_to_word_array(buffer, ":");

    values->start = atoi(stats[3]);
    values->middle = atoi(stats[18]);
    values->last = atoi(stats[34]);
}
