#pragma once
//enum players { PLAYER1, PLAYER2 };
enum screens { IGNORE, EXIT, GAME, PLAYERS, END, START_AGAIN };
enum directions { DOWN, LEFT , RIGHT, UP};
enum symbols { ROBOT = '/', GUARD = '!', WALL = '#', DOOR = 'D', ROCK = '@',/* GIFT = '&'*/ VOID = ' ' };
enum typeGuard { SMART, RANDOM };
enum todo {NOTHING, MOVE_BACK, ROBOT_DIED, GUARD_DIED, NEXT_LEVEL, DELETE, END_GAME};
enum WhoImI{I_IM_ROBOT, I_IM_GUARD};
enum key{B, SPACE_ENDGAME, ARROW, SPACE_RESTARTLEVEL, UNDEFINED, NEXT};

int const PIXEL_SIZE = 40;


