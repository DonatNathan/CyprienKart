/*
** EPITECH PROJECT, 2022
** MY_PROJECT
** File description:
** It's the file that contain functions to move my car
*/

#include "../includes/ai.h"

void check_wheels(values_t values, char *buffer, ssize_t mt)
{
    char **stats;

    dprintf(1, "WHEELS_DIR:0.0\n");
    getline(&buffer, &mt, stdin);
    stats = my_str_to_word_array(buffer, ":");
    values->wheels = atoi(stats[3]);
}

void critical_turn(values_t values, char *buffer, ssize_t mt)
{
    if (values->start < 130 && values->start < values->last) {
        dprintf(1, "WHEELS_DIR:-0.5\n");
        getline(&buffer, &mt, stdin);
    } else if (values->last < 130 && values->start > values->last) {
        dprintf(1, "WHEELS_DIR:0.5\n");
        getline(&buffer, &mt, stdin);
    } else {
        turn_wheels(values, buffer, mt);
    }
}

void turn_wheels(values_t values, char *buffer, ssize_t mt)
{
    if (values->start < 650 && values->middle < 800 && values->start <
    values->last) {
        dprintf(1, "WHEELS_DIR:-0.3\n");
        getline(&buffer, &mt, stdin);
    } else if (values->last < 650 && values->middle < 800 && values->start >
    values->last) {
        dprintf(1, "WHEELS_DIR:0.3\n");
        getline(&buffer, &mt, stdin);
    } else {
        dprintf(1, "WHEELS_DIR:0.0\n");
        getline(&buffer, &mt, stdin);
    }
}

void change_speed(values_t values, char *buffer, ssize_t mt)
{
    if (values->middle < 650)
        dprintf(1, "CAR_FORWARD:0.1\n");
    else if (values->middle > 850 && values->start > 130 && values->last > 130)
        dprintf(1, "CAR_FORWARD:0.4\n");
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
        if (values->middle < 200 && values->start < 300 && values->last < 300)
            stop_car(buffer, mt, values);
        else {
            change_speed(values, buffer, mt);
            critical_turn(values, buffer, mt);
        }
    }
}
