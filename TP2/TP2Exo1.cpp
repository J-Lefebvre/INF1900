/*
* Nom : Exo 1 TP2
* Table des états
*/

#include <avr/io.h>

const uint8_t ETEINT = 0;
const uint8_t ROUGE = 2;

//fonction qui effectue la lecture du bouton poussoir avec anti-rebond
bool lecture_bouton_poussoir(){

    //lecture 1 bouton
    bool etat_bouton_poussoir_1 = PIND & 0x04;

    //delai (antirebond) d'environ 10 millisecondes 
    _delay_ms(10);
    //lecture 2 bouton
    bool etat_bouton_poussoir_2 = PIND & 0x04;

    return etat_bouton_poussoir_1 && etat_bouton_poussoir_2;
}

int main(){
    DDRD = 0;   // PORT D est en mode entrée
    DDRB = 0xff // PORT B est en mode sortie

    for(;;){
        PORTB = ETEINT; // La DEL est éteinte par défaut
        
        // La boucle for se répête tant que le bouton-pressoir n'a pas été pressé et relâché 5 fois
        for(int compteurBouton = 0; i < 5;){ 
            if(lecture_bouton_poussoir){        
                if(!lecture_bouton_poussoir){ 
                    compteurBouton++;   // Si le bouton est enfoncé et relâché le compteur est incrémenté.
                }
            }
        }

        // La DEL passe au rouge pour 8 192 000 cycles d'horloge (1 sec à 8,192 MHz) 
        PORTB = ROUGE; 
        for(int compteurDelai = 0; i < 8192000; i++){}
    }    

    return 0;
}