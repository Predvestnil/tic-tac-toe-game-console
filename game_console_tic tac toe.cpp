// game_console_tic tac toe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <stdio.h> // I include this for clearing screen
#define esc 27 //
#define cls printf("%c[2J",esc) //


using namespace std;

//I create a map, declare a two-dimensional array and fill it with empty space, at the end the field is ready for the game
void create_map(char**& map) {
    map = new char* [4];
    for (int i = 0; i < 5; i++)
    {
        map[i] = new char[4];
        if (i % 2 == 1)
        {
            for (int j = 0; j < 5; j++)
            {
                map[i][j] = '#';
            }
        }
        else 
        {
            for (int j = 0; j < 5; j++)
            {
                if (j % 2 == 1)
                {
                    map[i][j] = '#';
                }
                else map[i][j] = ' ';
            }
        }
    }
}
//I put a map on the output
void out_map(char** map) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j]<<' ';
        }
        cout << '\n';
    }
}
//function that updates the map depending on the selected cell
void step(char**& map, char pos, bool& x) {
    switch (pos)
    {
    case 1:
        if (map[0][0] == ' ')
        {
            if (x)
            {
                map[0][0] = 'X';
            }
            else map[0][0] = 'O';
            x = !x;
        }
        break;
    case 2:
        if (map[0][2] == ' ')
        {
            if (x)
            {
                map[0][2] = 'X';
            }
            else map[0][2] = 'O';
            x = !x;
        }
        break;
    case 3:
        if (map[0][4] == ' ')
        {
            if (x)
            {
                map[0][4] = 'X';
            }
            else map[0][4] = 'O';
            x = !x;
        }
        break;
    case 4:
        if (map[2][0] == ' ')
        {
            if (x)
            {
                map[2][0] = 'X';
            }
            else map[2][0] = 'O';
            x = !x;
        }
        break;
    case 5:
        if (map[2][2] == ' ')
        {
            if (x)
            {
                map[2][2] = 'X';
            }
            else map[2][2] = 'O';
            x = !x;
        }
        break;
    case 6:
        if (map[2][4] == ' ')
        {
            if (x)
            {
                map[2][4] = 'X';
            }
            else map[2][4] = 'O';
            x = !x;
        }
        break;
    case 7:
        if (map[4][0] == ' ')
        {
            if (x)
            {
                map[4][0] = 'X';
            }
            else map[4][0] = 'O';
            x = !x;
        }
        break;
    case 8:
        if (map[4][2] == ' ')
        {
            if (x)
            {
                map[4][2] = 'X';
            }
            else map[4][2] = 'O';
            x = !x;
        }
        break;
    case 9:
        if (map[4][4] == ' ')
        {
            if (x)
            {
                map[4][4] = 'X';
            }
            else map[4][4] = 'O';
            x = !x;
        }
        break;
    }
}
//function that checks the entered cell value
void input_correct(char**& map, char a, bool& x) {
    if (a<10 && a>0) {
        step(map, a, x);
    }
}
//function that checks the map for three characters in a row
void line_search(char** a, string& winner, bool &end_game) 
{
    if (((a[0][0] == a[2][0]) && (a[4][0] == a[2][0])) || ((a[0][0] == a[2][2]) && (a[4][4] == a[2][2])) || ((a[0][4] == a[0][2]) && (a[0][4] == a[0][0])))
    {
        if (a[0][0] == 'X')
        {
            winner = "First player(X) - WINNER!!! \n";
            end_game = !end_game;
        }
        else  if (a[0][0] == 'O') { winner = "Second player(O) - WINNER!!! \n"; end_game = !end_game; }
    }
    else if (((a[4][4] == a[4][2]) && (a[4][2] == a[4][0])) || ((a[0][4] == a[2][4]) && (a[4][4] == a[2][4])))
    {
        if (a[4][4] == 'X')
        {
            winner = "First player(X) - WINNER!!! \n";
            end_game = !end_game;
        }
        else if (a[4][4] == 'O') { winner = "Second player(O) - WINNER!!! \n"; end_game = !end_game; }
    }
    else if (((a[4][0] == a[2][2]) && (a[2][2] == a[0][4])) || ((a[2][0] == a[2][2]) && (a[2][4] == a[2][0])) || ((a[0][2] == a[2][2]) && (a[2][2] == a[4][2])))
    {
        if (a[2][2] == 'X')
        {
            winner = "First player(X) - WINNER!!! \n";
            end_game = !end_game;
        }
        else if (a[2][2] == 'O') { winner = "Second player(O) - WINNER!!! \n"; end_game = !end_game; }
    }
}
//function that checks the card for fullness
void EndNear(bool& a, char** map) 
{
    if (a != true) {
        a = true;
        for (int i = 0; i < 5; i += 2)
            for (int j = 0; j < 5; j += 2)
                if (map[i][j] == ' ')
                {
                    a = false;
                    return;
                }
    }
}

int main()
{
    //declaration of variables and their initialization
    int ch;
    string results = "DRAW \n";
    bool isX = true;
    bool isEnd = false;
    char** field;
    create_map(field);
    //game cycle
    while (isEnd == false) {
        out_map(field);
        cin >> ch;
        input_correct(field, ch, isX);
        line_search(field, results, isEnd);
        EndNear(isEnd, field);
        cls;
    }
    cout << results;
    cout << "Please input any key for exit \n";
    cin >> field[0][0];
    return 0;
}