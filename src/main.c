/*
** EPITECH PROJECT, 2022
** MY_PROJECT
** File description:
** It's the main file of my project
*/

#include "../includes/ai.h"

void launch_car(char *buffer, ssize_t mt)
{
    dprintf(1, "START_SIMULATION\n");
    getline(&buffer, &mt, stdin);
}

void stop_car(char *buffer, ssize_t mt)
{
    dprintf(1, "CAR_FORWARD:0\n");
    getline(&buffer, &mt, stdin);
    dprintf(1, "STOP_SIMULATION\n");
    getline(&buffer, &mt, stdin);
}

void game_loop(void)
{
    char *buffer;
    struct stat st;
    ssize_t mt = PATH_MAX;

    buffer = malloc(sizeof(char) * mt);
    launch_car(buffer, mt);
    while (1) {
        dprintf(1, "GET_INFO_LIDAR\n");
        getline(&buffer, &mt, stdin);
        dprintf(2, "%s\n", buffer);
        dprintf(1, "CAR_FORWARD:0.6\n");
        getline(&buffer, &mt, stdin);
    }
    stop_car(buffer, mt);
}


int main(int argc, char **argv)
{
    game_loop();
    return (0);
}
