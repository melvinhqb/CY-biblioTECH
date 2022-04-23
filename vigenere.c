#include "biblio.h"

void Encode(char chaine[], char cle[]){
    int i, dec_char, x=0;

    for (i=0;i<strlen(chaine);i++){
        if ((int)chaine[i] > 96 && (int)chaine[i] < 123){
            dec_char = (int)chaine[i] + (int)cle[x] - 97;
            while (dec_char > 122){
                dec_char -= 26;
            };
            chaine[i] = (char)dec_char;
        }
        else if ((int)chaine[i] > 64 && (int)chaine[i] < 91){
            dec_char = (int)chaine[i] + (int)cle[x] - 32 - 65; //On soustrait 32 car (int)cle[x] renvoie la valeure decimale de la letttre minuscule
            while (dec_char > 90){
                dec_char -= 26;
            };
            chaine[i] = (char)dec_char;
        };

        if (x == strlen(cle) - 1){
            x = 0;
        }
        else{
            x += 1;
        }
    }
}

void Decode(char chaine[], char cle[]){
    int i, dec_char, x=0;

    for (i=0;i<strlen(chaine);i++){
        if ((int)chaine[i] > 96 && (int)chaine[i] < 123){
            dec_char = (int)chaine[i] - (int)cle[x] + 97;
            while (dec_char < 97){
                dec_char += 26;
            };
            chaine[i] = (char)dec_char;
        }
        else if ((int)chaine[i] > 64 && (int)chaine[i] < 91){
            dec_char = (int)chaine[i] - (int)cle[x] + 32 + 65; //On ajoute 32 car (int)cle[x] renvoie la valeure decimale de la letttre minuscule
            while (dec_char < 65){
                dec_char += 26;
            };
            chaine[i] = (char)dec_char;
        };

        if (x == strlen(cle) - 1){
            x = 0;
        }
        else{
            x += 1;
        }
    }
}