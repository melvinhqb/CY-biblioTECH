#include "biblio.h"

// Encoding of Vigenere

void Encode(char chaine[], char cle[]){

    int i, dec_char, x=0;

    for (i=0;i<strlen(chaine);i++){

        if ((int)chaine[i] > 32 && (int)chaine[i] < 127){

            dec_char = (int)chaine[i] + (int)cle[x] - 33;

            while (dec_char > 126){

                dec_char -= 94;

            }

            chaine[i] = (char)dec_char;

        }

        if (x == strlen(cle) - 1){

            x = 0;

        }
        else{

            x += 1;

        }

    }

}

// Decoding of Vigenere

void Decode(char chaine[], char cle[]){

    int i, dec_char, x=0;

    for (i=0;i<strlen(chaine);i++){

        if ((int)chaine[i] > 32 && (int)chaine[i] < 127){

            dec_char = (int)chaine[i] - (int)cle[x] + 33;

            while (dec_char < 33){

                dec_char += 94;

            }

            chaine[i] = (char)dec_char;

        }

        if (x == strlen(cle) - 1){

            x = 0;

        }
        else{

            x += 1;

        }

    }

}