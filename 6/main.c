//gcc main.c -o bin/test.exe -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer
//bin ou dossier avec SDL2.ddl et SDL2_mixer.ddl pour lancer le programme
//lib ou d'autre dossier doit contenir certains fichier .a pour compiler correctement avec des librairies externes

#include <stdio.h>
#include "unistd.h"
#include "include/SDL2/SDL.h"
#include "include/SDL2/SDL_mixer.h"

int main(int argc, char *argv[]) {

    int M = 1;

        if (SDL_Init(SDL_INIT_AUDIO) < 0) {
            printf("Erreur lors de l'initialisation de SDL: %s\n", SDL_GetError());
            return 1;
        }
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            printf("Erreur lors de l'initialisation de SDL_mixer: %s\n", Mix_GetError());
        }
        Mix_Music *music = Mix_LoadMUS("music/Program in C.mp3");
        if (!music) {
            printf("Erreur lors du chargement du fichier MP3: %s\n", Mix_GetError());
            return 1;
        }
        if (Mix_PlayMusic(music, 1) < 0) {
            printf("Erreur lors de la lecture de la musique: %s\n", Mix_GetError());
            return 1;
        }
        while (Mix_PlayingMusic()) {
            SDL_Delay(100);
        }
    return 0;
}
