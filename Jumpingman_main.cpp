#include "Jumpingman_library.h";

int main(){
    char key;
    a[119]=char(219);
    for(int i=0;i<119;i++)
        a[i]=' ';
    while(1){
        clrscr();
        while(!kbhit()){
            Walls(a);
            Background();
            Runner(0);
        }
        key=getch();
        if(key==' '){
            for(int i=0;i<7;i++){
                Walls(a);
                Background();
                Runner(1);
                }
            for(int i=0;i<7;i++){
                Walls(a);
                Background();
                Runner(2);
                }
        }
    }
    return 0;
}
