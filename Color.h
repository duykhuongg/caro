#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h> // sleep function

#include "config.h"
#include "botbaseline.h"

using namespace std;

//int board_game[HEIGHT][WIDTH];
Point win_path[15];

void go_to_xy(Point p){// dich con tro vi tri
    COORD coord;
    coord.X = p.x;
    coord.Y = p.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void set_text_color(ll color)//doi mau chu
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void draw_tile(Point p, ll color){
    go_to_xy(p);
    set_text_color(color);
    if(color == WHITE_COLOR) cout<<"O";
    else cout<<"X";
}

void draw_win_path(ll winner){//ve duong thang

    bool turn = true;
    ll color;
    ll blink_count = 10;
    while(blink_count >= 0){
        if(winner == 1){
            if(turn) color = WHITE_COLOR;
            else color = BLACK_COLOR;
        } else {
            if(turn) color = RED_COLOR;
            else color = BLACK_COLOR;
        }
        for(ll j = 0; j < 5; j++){
            draw_tile(win_path[j], color);
        }
        Sleep(500);
        turn = !turn;
        blink_count--;
    }

}

//goc toa do (0;0) o goc tren ben trai
void draw_background(){
    set_text_color(AQUA_COLOR);

    //Ve khung cho ban co
    for(ll i=0; i <= WIDTH; i++){
        go_to_xy(Point(10+i, 3));
        cout << char(220);
        go_to_xy(Point(10+i, HEIGHT));
        cout << char(220);
    }

    for(ll i=4 ;i<= HEIGHT;i++){
        go_to_xy(Point(10, i));
        cout << char(219);
        go_to_xy(Point(10+WIDTH,i));
        cout << char(219);
    }

    // Ve cac o trong ban co
    Point p;
    ll x, y;
    for(ll i = 11; i <= WIDTH; i += 2){
        for(ll j = 4; j <= HEIGHT; j++){
            x = (i-1)/2;
            y = j;
            p.x = i;
            p.y = j;
            if(x % 2==0){
                if(y % 2==0){
                    draw_tile(p, BLACK_COLOR);
                }else{
                    draw_tile(p, WHITE_COLOR);
                }
            }
            else{
                if(y % 2==0){
                    draw_tile(p, WHITE_COLOR);
                }
                else{
                    draw_tile(p, BLACK_COLOR);
                }
            }
        }
    }
    set_text_color(AQUA_COLOR);
}
