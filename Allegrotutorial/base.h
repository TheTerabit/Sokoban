const float FPS = 8;
const int board_width = 20, board_height = 20;
int board[board_width][board_height];
int x, y, tmpx, tmpy, m = 0, score = 0, goal = 0, cursor = 0, level = 1;
bool ex = false, editor = false, lc = false, robot_placed = false;
int build[board_width][board_height];