/*
** EPITECH PROJECT, 2022
** MY_PROJECT
** File description:
** It's the file that contain functions to move my car
*/

#include "../includes/ai.h"

void check_values(char *buffer, values_t values, ssize_t mt)
{
    char **stats = my_str_to_word_array(buffer, ":");

    values->start = atoi(stats[3]);
    values->middle = atoi(stats[18]);
    values->last = atoi(stats[34]);
}

void check_wheels(values_t values, char *buffer, ssize_t mt)
{
    char **stats;

    dprintf(1, "WHEELS_DIR:0.0\n");
    getline(&buffer, &mt, stdin);
    stats = my_str_to_word_array(buffer, ":");
    values->wheels = atoi(stats[3]);
}

void turn_wheels(values_t values, char *buffer, ssize_t mt)
{
    if (values->start < 500 && values->middle < 700 && values->start <
    values->last) {
        dprintf(1, "WHEELS_DIR:-0.25\n");
        getline(&buffer, &mt, stdin);
    } else if (values->last < 500 && values->middle < 700 && values->start >
    values->last) {
        dprintf(1, "WHEELS_DIR:0.25\n");
        getline(&buffer, &mt, stdin);
    } else {
        dprintf(1, "WHEELS_DIR:0.0\n");
        getline(&buffer, &mt, stdin);
    }
}

void change_speed(values_t values, char *buffer, ssize_t mt)
{
    if (values->middle > 700)
        dprintf(1, "CAR_FORWARD:0.5\n");
    else
        dprintf(1, "CAR_FORWARD:0.2\n");
    getline(&buffer, &mt, stdin);
}

void game_loop(void)
{
    char *buffer;
    ssize_t mt = 0;
    values_t values = malloc(sizeof(values_t));

    buffer = malloc(sizeof(char) * mt);
    launch_car(buffer, mt);
    while (1) {
        dprintf(1, "GET_INFO_LIDAR\n");
        getline(&buffer, &mt, stdin);
        check_values(buffer, values, mt);
        if (values->middle > 300) {
            change_speed(values, buffer, mt);
            turn_wheels(values, buffer, mt);
        } else
            stop_car(buffer, mt, values);
    }
}