/*
** EPITECH PROJECT, 2022
** MY_PROJECT
** File description:
** It's the main file of my project
*/

#include "../includes/ai.h"


void check_values(char *buffer, values_t values, ssize_t mt)
{
    char **stats = my_str_to_word_array(buffer, ":");
    for (int i = 3; stats[i]; i++) {
        values->start = atoi(stats[3]);
        dprintf(2, "value start:%d\n", values->start);
        values->middle = atoi(stats[18]);
        dprintf(2, "value middle:%d\n", values->middle);
        values->last = atoi(stats[34]);
        dprintf(2, "value last:%d\n", values->last);
        dprintf(2, "number of while %d:%s\n", i - 2, stats[i]);
    }
}

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
    ssize_t mt = PATH_MAX;
    values_t values = malloc(sizeof(values_t));
    buffer = malloc(sizeof(char) * mt);
    launch_car(buffer, mt);
    while (1) {
        dprintf(1, "GET_INFO_LIDAR\n");
        getline(&buffer, &mt, stdin);
        dprintf(2, "%s\n", buffer);
        check_values(buffer, values, mt);
        if (values->middle >= 2000 && values->middle <= 3500) {
            dprintf(1, "CAR_FORWARD:0.5\n");
            getline(&buffer, &mt, stdin);
        }
        if (values->start < 500) {
            dprintf(1, "WHEELS_DIR:-0.195\n");
            getline(&buffer, &mt, stdin);
        }
        else if (values->last < 500) {
            dprintf(1, "WHEELS_DIR:0.195\n");
            getline(&buffer, &mt, stdin);
        }
        else {
            dprintf(1, "WHEELS_DIR:0.0\n");
            getline(&buffer, &mt, stdin); 
        }
    }
    stop_car(buffer, mt);
}


int main(int argc, char **argv)
{
    game_loop();
    return (0);
}
