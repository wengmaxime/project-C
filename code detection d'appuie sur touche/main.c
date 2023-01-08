#include <stdio.h>
//#include <pthread.h>
//#include <synchapi.h> //sleep
#include <windows.h> //getkeystate
#include <time.h>
#include <math.h>
//#include <conio.h> //getch

int press_button(char button){
    time_t start= time(NULL);
    float limit = 5.0f;
    fflush(stdin);
    printf("%c\n",button);
    while((time(NULL)-start) < limit) {
        int key = 0;
        key = GetKeyState(button);
        if(key==-128 || key==-127){
            printf("a : true\n",key);
            return 1;
        }
    }

    return 0;
}

int main ()
{
    //time_t start= time(NULL);
    //time_t limit=start+5;
    //float limit = 5.0f;
    //pthread_t t;

    //int game=1;

    for(int game=1;game;) {

        int random = rand() % 4;
        char button1 = 65;
        char button2 = 65+25;
        //char button = 65;
        char button[4]={65,90,69,82};
        //char pressed;
        //fflush(stdin);

        //time_t start= time(NULL);
        //float limit = 5.0f;
        //printf("5sec pour appuiez\n");
        //while((time(NULL)-start) < limit && pressed=='\0') {
        //    printf("vite\n");
        //    pressed=getch();
        //}

        //printf("%c\n",pressed);
        //printf("%c\n",button);

        //if(pressed!=button){
        //    printf("noob\n");
        //} else {
        //    printf("GG\n");
        //}

        //game=press_button(button1);
        game=press_button(button[random]);

        //puts ("main init");

        //while ( (time(NULL) - start) < limit )
        //{
        //printf("1)time : %ld | limit : %ld\n",(time(NULL)-start), limit);
        //}

        //pthread_create (&t, NULL, timer, NULL);
        //pthread_join(t,NULL);

    }

    //puts ("main end");

    return 0;
}
