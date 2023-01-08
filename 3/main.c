#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlite/sqlite3.h"
//#include "music/SDL3/SDL_mixer.h"
//#include "SDL_include/SDL.h"
//#include "mixer/SDL_mixer-main/include/SDL3/SDL_mixer.h"
#include "SDL_include/SDL_mixer.h"
//#include "SDL_include/SDL.h"
//#include "C:\Users\WENG\Documents\ESGI\C\projet\1\sqlite\sqlite3.h"

void inputString(char *string, int size) {
    fgets(string, size, stdin);
    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
    else
        fflush(stdin);
}

int main(int argc, char *argv[]){


    //sqlite3 *db;
    //sqlite3_stmt *res;
    sqlite3 *bdd;

    int vtrue = sqlite3_open(
    "test.sqlite",   /* Database filename (UTF-8) */
    &bdd
    );

    char *err_msg;
    char sql[200] = "CREATE TABLE IF NOT EXISTS PLAYERS(ID INTEGER PRIMARY KEY, NOM VARCHAR(50), PRENOM VARCHAR(50));";
    int rc = sqlite3_exec(bdd, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK ) {
        // gérer l'erreur
        printf("erreur");
    }
    printf("quel voulez-vous ?\n1)jouez\n2)inscription\n3)ajoutez une musique");
    char choix[255];
    inputString(choix,3);
    //if (choix == "2\0\0") {
        char nom[50] = "weng";
        char prenom[50] = "m";
        printf("nom :\n");
        inputString(nom, 20);
        puts(nom);
        printf("prenom :\n");
        inputString(prenom, 20);
        puts(prenom);
        //printf("%s",sql);
        strcpy(sql, "INSERT INTO PLAYERS(NOM, PRENOM) VALUES('");
        //sql = "INSERT INTO PLAYERS(NOM, PRENNOM) VALUES('";
        printf("%s", sql);
        //puts(sql);
        strcat(sql, nom);
        strcat(sql, "','");
        strcat(sql, prenom);
        strcat(sql, "')");
        rc = sqlite3_exec(bdd, sql, 0, 0, &err_msg);
        if (rc != SQLITE_OK) {
            // gérer l'erreur
            printf("erreur");
        }
    //}
    return 0;
}


