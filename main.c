#include <stdio.h>
#include "cmd.h"
#include <windows.h>
#include "string.h"
#include <conio.h>

#define MAX_WORD_LENGTH 11

/*
* Make shure you set file-encoding to CP 437 before building.
*/

void spritz(char *word){
    static int factor = 3;
    int ovp = 0;
    int ovp_pos = 0;
    int str_lenth = strlen(word);
    int sleep_time = (30 + strlen(word)*3)*factor;

    if(strlen(word) == 1){
        if(word[0] >= '1' && word[0] <= '9'){
            factor = 10 -  (word[0] - '0');
        }
    }

    switch(word[strlen(word)-1]){
        case '.':
        case '!':
        case '?':
        case ':':
            sleep_time += 30*factor;
            break;
        case ',':
        case ';':
            sleep_time += 0;
            break;
    }


    char buffer[1024];

    ovp = (str_lenth - 1 + (4 - 1)) / 4;
    ovp_pos = (MAX_WORD_LENGTH - 1 + (4 - 1)) / 4;
    


    sprintf(buffer,"\033[2J\033[1;1H"); 
    sprintf(buffer+strlen(buffer),ESC_BLACK);
    sprintf(buffer+strlen(buffer),"闡闡闡闡闡闡薩闡闡闡闡闡闡闡闡闡闡闡闡孀n");

    for(int i = 0; i <= MAX_WORD_LENGTH - ovp; i++){
        sprintf(buffer+strlen(buffer)," ");
    }

    for(int i = 0; i < ovp; i++){
        sprintf(buffer+strlen(buffer),"%c",word[i]);
    }

    sprintf(buffer+strlen(buffer),ESC_LIGHT_RED);
    sprintf(buffer+strlen(buffer),"%c",word[ovp]);
    sprintf(buffer+strlen(buffer),ESC_BLACK);

    for(int i = ovp+1; i < strlen(word); i++){
        sprintf(buffer+strlen(buffer),"%c",word[i]);
    }

    for(int i = strlen(word); i <= MAX_WORD_LENGTH; i++){
        sprintf(buffer+strlen(buffer)," ");
    }

    sprintf(buffer+strlen(buffer),"\n闡闡闡闡闡闡謐闡闡闡闡闡闡闡闡闡闡闡闡孀n");

    printf("%s",buffer);
    Sleep(sleep_time);
}

int main(int argc, char const *argv[])
{
    system("mode 40,5");
    char input[1024];
    int i = 0;
    char ch;


    static HANDLE inh;
    DWORD dw;

    inh = GetStdHandle(STD_INPUT_HANDLE);

    //utf8();
    hide_cursor();
    set_cmd_color(CMD_COLOR_BLACK, CMD_COLOR_WHITE);
    
    spritz("");
    printf(ESC_DARK_GRAY);
    printf("Paste text to spritz.\n");
    printf("Press 1-9 to set speed.");

    
    while(1){

            ch = _getch();
            GetNumberOfConsoleInputEvents(inh,&dw);

            if(ch == '\n' || ch == ' ' || ch=='\0' || ch == 13){
                input[i] = '\0';
                spritz(input);
                i = 0;
                input[0] = '\0';
            }
            else{
                input[i] = ch;
                i++;
            }

            if((int)dw <= 1){
                input[i] = '\0';
                spritz(input);
                i = 0;
                input[0] = '\0';
            }

    }

    return 0;
}
