
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


/* Console Escape Sequences */ 
#define ESC_RESET_ALL           "\033[0m"
#define ESC_BOLD                "\033[1m"
#define ESC_DIM                 "\033[2m"
#define ESC_UNDERLINED          "\033[4m"
#define ESC_BLINK               "\033[5m"
#define ESC_REVERSE             "\033[7m"
#define ESC_HIDDEN              "\033[8m"
#define ESC_RESET_BOLD          "\033[21m"
#define ESC_RESET_DIM           "\033[22m"
#define ESC_RESET_UNDERLINED    "\033[24m"
#define ESC_RESET_BLINK         "\033[25m"
#define ESC_RESET_REVERSE       "\033[27m"
#define ESC_RESET_HIDDEN        "\033[28m"
#define ESC_DEFAULT             "\033[39m"
#define ESC_BLACK               "\033[30m"
#define ESC_RED                 "\033[31m"
#define ESC_GREEN               "\033[32m"
#define ESC_YELLOW              "\033[33m"
#define ESC_BLUE                "\033[34m"
#define ESC_MAGENTA             "\033[35m"
#define ESC_CYAN                "\033[36m"
#define ESC_LIGHT_GRAY          "\033[37m"
#define ESC_DARK_GRAY           "\033[90m"
#define ESC_LIGHT_RED           "\033[91m"
#define ESC_LIGHT_GREEN         "\033[92m"
#define ESC_LIGHT_YELLOW        "\033[93m"
#define ESC_LIGHT_BLUE          "\033[94m"
#define ESC_LIGHT_MAGENTA       "\033[95m"
#define ESC_LIGHT_CYAN          "\033[96m"
#define ESC_WHITE               "\033[97m"
#define ESC_BG_DEFAULT          "\033[49m"
#define ESC_BG_BLACK            "\033[40m"
#define ESC_BG_RED              "\033[41m"
#define ESC_BG_GREEN            "\033[42m"
#define ESC_BG_YELLOW           "\033[43m"
#define ESC_BG_BLUE             "\033[44m"
#define ESC_BG_MAGENTA          "\033[45m"
#define ESC_BG_CYAN             "\033[46m"
#define ESC_BG_LIGHT_GRAY       "\033[47m"
#define ESC_BG_DARK_GRAY        "\033[100m"
#define ESC_BG_LIGHT_RED        "\033[101m"
#define ESC_BG_LIGHT_GREEN      "\033[102m"
#define ESC_BG_LIGHT_YELLOW     "\033[103m"
#define ESC_BG_LIGHT_BLUE       "\033[104m"
#define ESC_BG_LIGHT_MAGENTA    "\033[105m"
#define ESC_BG_LIGHT_CYAN       "\033[106m"
#define ESC_BG_WHITE            "\033[107m"

/* define color command color codes */

#define CMD_COLOR_BLACK 0x0
#define CMD_COLOR_DARK_BLUE 0x1
#define CMD_COLOR_DARK_GREEN 0x2
#define CMD_COLOR_DARK_CYAN 0x3
#define CMD_COLOR_DARK_RED 0x4
#define CMD_COLOR_DARK_MAGENTA 0x5
#define CMD_COLOR_DARK_YELLOW 0x6
#define CMD_COLOR_DARK_WHITE 0x7
#define CMD_COLOR_BRIGHT_BLACK 0x8
#define CMD_COLOR_BRIGHT_BLUE 0x9
#define CMD_COLOR_BRIGHT_GREEN 0xa
#define CMD_COLOR_BRIGHT_CYAN 0xb
#define CMD_COLOR_BRIGHT_RED 0xc
#define CMD_COLOR_BRIGHT_MAGENTA 0xd
#define CMD_COLOR_BRIGHT_YELLOW 0xe
#define CMD_COLOR_WHITE 0xf



void hide_cursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void show_cursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}


void set_cmd_color(int background, int foreground){
    char command[80];
    sprintf(command,"color %x%x", foreground, background);
    system(command);
}



int get_cmd_width(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ret;
    ret = GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi);
    return csbi.dwSize.X;
}

int get_cmd_height(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ret;
    ret = GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi);
    return csbi.dwSize.Y;
}

int cls(){
    system("cls");
    return 1;
}


void set_cursor_position(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void utf8(){
    system("chcp 65001");
    cls();
}


    


