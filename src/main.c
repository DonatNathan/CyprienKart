/*
** EPITECH PROJECT, 2022
** MY_PROJECT
** File description:
** It's the main file of my project
*/

#include "../includes/ai.h"

void launch_car(void)
{
    printf("START_SIMULATION\n");
    printf("CAR_FORWARD:0.6\n");
}

void game_loop(void)
{
    char *buffer;
    struct stat st;

    while (1) {
        fstat(STDIN_FILENO, &st);
        buffer = malloc(sizeof(char) * st.st_size);
        read(STDIN_FILENO, buffer, st.st_size);
        printf("GET_INFO_LIDAR\n");
    }
}

void stop_car(void)
{
    printf("CAR_FORWARD:0\n");
    printf("STOP_SIMULATION\n");
}

int main(int argc, char **argv)
{
    launch_car();
    game_loop();
    stop_car();
    return (0);
}
