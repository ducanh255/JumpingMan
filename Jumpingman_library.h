#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void TextColor (int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
int t=0; /// t là tọa độ người chơi
int time=60,score=0,highscore=0;
char s[80],a[120];

void Walls(char a[120]){
    //clrscr();
    for(int i=0;i<120;i++)
        a[i]=a[i+1];
    a[119]=' ';
    for(int i=0;i<80;i++){
        if(a[59]==char(219)){
            a[80+rand()%40]=char(219);
            break;
        }
        s[i]=a[i];
    }
    gotoXY(0,16);
    cout << s;
    gotoXY(0,17);
    cout << s;
}
void Runner(int status){ /// Tạo người chơi
    TextColor(15);
    switch(status){
        case 0: t=0; break;
        case 1: t++; break; /// Nhảy lên
        case 2: t--; break; /// Rơi xuống
    }
    gotoXY(1,15-t);
    cout << ' ' << char(2) << ' ' ;
    gotoXY(1,16-t);
    cout << '|' << char(219) << '|' ;
    gotoXY(1,17-t);
    cout << ' ' << char(186) << ' ' ;
    if(status==1){
        gotoXY(2,18-t);
        cout << ' ' ;
    }
    else if(status==2){
        gotoXY(2,14-t);
        cout << ' ' ;
    }
    if(score%100==0) time-=time*0.1;
    Sleep(time);
}
void Background(){
    /// Vẽ đường chạy
    TextColor(10);
    gotoXY(0,18);
    char R[80];
    for(int i=0;i<80;i++){
        if(i%2==0) R[i]=char(176);
        else R[i]=char(178);
    }
    cout << R;
    /// Điểm
    score++;
    TextColor(11);
    gotoXY(65,12);
    cout << "SCORE: " << score;
    gotoXY(45,12);
    cout << "HIGH SCORE: " << highscore;
    /// Xử lý va chạm
    if(t==0&&s[4]!=' '||t<1&&s[3]!=' '){
        if(highscore<score) highscore=score;
        gotoXY(57,12);
        cout << highscore;
        score=0;
        time=100;
        gotoXY(35,10);
        cout << "GAME OVER";
        TextColor(15);
        gotoXY(1,15-t);
        cout << ' ' << char(2) << ' ' ;
        gotoXY(1,16-t);
        cout << '|' << char(219) << '|' ;
        gotoXY(1,17-t);
        cout << ' ' << char(186) << ' ' ;
        getch();
    }
}
