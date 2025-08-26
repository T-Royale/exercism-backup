#include "robot_simulator.h"
#include <string.h>
robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_status_t robot;
    robot.direction = direction;
    robot.position.x = x;
    robot.position.y = y;
    return robot;
}

robot_position_t avanzar(robot_status_t rob){
    robot_position_t robot = rob.position;
    switch(rob.direction){
        case DIRECTION_NORTH:
            robot.y++;
            break;
        case DIRECTION_SOUTH:
            robot.y--;
            break;
        case DIRECTION_EAST:
            robot.x++;
            break;
        case DIRECTION_WEST:
            robot.x--;
            break;
        default: break;
    }
    return robot;
}

void robot_move(robot_status_t *robot, const char *commands){
    int len = strlen(commands);
    for(int i = 0; i < len; i++){
        switch(commands[i]){
            case 'R':
                robot->direction++;
                if(robot->direction == DIRECTION_MAX) robot->direction = DIRECTION_NORTH;
                break;
            case 'L':
                if(robot->direction == DIRECTION_NORTH) robot->direction = DIRECTION_WEST;
                else robot->direction--;
                break;  
            case 'A':
                robot->position = avanzar(*robot);
                break;
            default: break;
        }
    }
}