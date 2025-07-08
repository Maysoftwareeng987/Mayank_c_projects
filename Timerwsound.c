#include<stdio.h>
#include<windows.h>
// timer
int hours,minutes,seconds;
void note(int freq, int dur) {
    Beep(freq, dur);
    Sleep(1); // minimal gap to keep rhythm smooth
}
void tan_tan_dan() {
    // Tan tan dan effect
    note(600, 100);  // Tan (A4)
    note(600, 100);  // Tan (A4)
    note(800, 400);  // Dan (C5)
}
int main(){
    printf("Enter the hours : ");
    scanf(" %d",&hours);
    printf("Enter the minutes : ");
    scanf(" %d",&minutes);
    printf("Enter the seconds : ");
    scanf(" %d",&seconds);
    int h = 0, m = 0, s = 0;
    int Tseconds = hours*3600 + minutes*60 + seconds ;
    while (( h*3600 + m*60 + s ) <= Tseconds )
    {
        system("cls");
        printf("\t\t________________\n");
        printf("\t\t| %02d : %02d : %02d |\n", h , m , s);
        printf("\t\t|______________|\n");
        Sleep(1000);
        s++ ;
        if(s == 60) {s = 0 ; m++ ;}
        if(m == 60) {m = 0 ; h++ ;}
    }
    printf("\n\n\t\t   Time's up!\n");
    // Simulating timer finishing, now play the tan tan dan sound
    tan_tan_dan();

    return 0 ;
}