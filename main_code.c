#include <stdio.h>

typedef struct {
    int x;
    int y;
    int z;
    char direction;
} Spacecraft;

void move_forward(Spacecraft* spacecraft) {
    switch (spacecraft->direction) {
        case 'N':
            spacecraft->y++;
            break;
        case 'S':
            spacecraft->y--;
            break;
        case 'E':
            spacecraft->x++;
            break;
        case 'W':
            spacecraft->x--;
            break;
        case 'U':
            spacecraft->z++;
            break;
        case 'D':
            spacecraft->z--;
            break;
    }
}

void move_backward(Spacecraft* spacecraft) {
    switch (spacecraft->direction) {
        case 'N':
            spacecraft->y--;
            break;
        case 'S':
            spacecraft->y++;
            break;
        case 'E':
            spacecraft->x--;
            break;
        case 'W':
            spacecraft->x++;
            break;
        case 'U':
            spacecraft->z--;
            break;
        case 'D':
            spacecraft->z++;
            break;
    }
}

void turn_left(Spacecraft* spacecraft) {
    switch (spacecraft->direction) {
        case 'N':
            spacecraft->direction = 'W';
            break;
        case 'S':
            spacecraft->direction = 'E';
            break;
        case 'E':
            spacecraft->direction = 'N';
            break;
        case 'W':
            spacecraft->direction = 'S';
            break;
        case 'U':
        case 'D':
            spacecraft->direction = 'N'; // Assumes up and down don't change direction
            break;
    }
}

void turn_right(Spacecraft* spacecraft) {
    switch (spacecraft->direction) {
        case 'N':
            spacecraft->direction = 'E';
            break;
        case 'S':
            spacecraft->direction = 'W';
            break;
        case 'E':
            spacecraft->direction = 'S';
            break;
        case 'W':
            spacecraft->direction = 'N';
            break;
        case 'U':
        case 'D':
            spacecraft->direction = 'N'; // Assumes up and down don't change direction
            break;
    }
}

void turn_up(Spacecraft* spacecraft) {
    switch (spacecraft->direction) {
        case 'N':
        case 'S':
        case 'E':
        case 'W':
            spacecraft->direction = 'U';
            break;
    }
}

void turn_down(Spacecraft* spacecraft) {
    switch (spacecraft->direction) {
        case 'N':
        case 'S':
        case 'E':
        case 'W':
            spacecraft->direction = 'D';
            break;
    }
}

void process_commands(Spacecraft* spacecraft, char commands[], int length) {
    for (int i = 0; i < length; i++) {
        char command = commands[i];
        switch (command) {
            case 'f':
                move_forward(spacecraft);
                break;
            case 'b':
                move_backward(spacecraft);
                break;
            case 'l':
                turn_left(spacecraft);
                break;
            case 'r':
                turn_right(spacecraft);
                break;
            case 'u':
                turn_up(spacecraft);
                break;
            case 'd':
                turn_down(spacecraft);
                break;
        }
    }
}

int main() {
    Spacecraft spacecraft;
    spacecraft.x = 0;
    spacecraft.y = 0;
    spacecraft.z = 0;
    spacecraft.direction = 'N';

    char commands[] = {'f', 'r', 'u', 'b', 'l'};
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    process_commands(&spacecraft, commands, num_commands);

    printf("Final Position: (%d, %d, %d)\n", spacecraft.x, spacecraft.y, spacecraft.z);
    printf("Final Direction: %c\n", spacecraft.direction);

    return 0;
}
