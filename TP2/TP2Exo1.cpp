/*
* Exercice 1 du TP2
*
* TABLE DES ÉTATS
*
* ÉTAT PRÉSENT | BOUTON | ÉTAT SUIVANT | DEL
*     INIT     |   0    |     INIT     |  0
*     INIT     |   1    |      E1      |  0
*      E1      |   0    |      E1      |  0
*      E1      |   1    |      E2      |  0
*      E2      |   0    |      E2      |  0
*      E2      |   1    |      E3      |  0
*      E3      |   0    |      E3      |  0
*      E3      |   1    |      E4      |  0
*      E4      |   0    |      E4      |  0
*      E4      |   1    |     INIT     |  1
*
* BOUTON : 1 signifie que le bouton a été pressé et relâché.
* DEL : 1 signifie que la DEL scintille en rouge pour 1 seconde.
*/

#define F_CPU 8192000UL
#include <avr/io.h>
#include <util/delay_basic.h>
#include <util/delay.h>

const uint8_t ETEINT = 0;
const uint8_t ROUGE = 2;

// Fonction qui effectue la lecture du bouton poussoir avec anti-rebond
bool lecture_bouton_poussoir(){
    bool etat_bouton_poussoir_1 = PIND & 0x04; // lecture 1
    _delay_ms(10); // délai (antirebond) d'environ 10 millisecondes 
    bool etat_bouton_poussoir_2 = PIND & 0x04; // lecture 2

    return etat_bouton_poussoir_1 && etat_bouton_poussoir_2;
}

int main(){
    DDRD = 0;   // PORT D est en mode entrée
    DDRB = 0xff; // PORT B est en mode sortie

    for(;;){
        PORTB = ETEINT; // La DEL est éteinte par défaut
        
        // La boucle for se répête tant que le bouton-pressoir n'a pas été pressé et relâché 5 fois
        for(unsigned int compteurBouton = 0; compteurBouton < 5;){ 
            if(lecture_bouton_poussoir()){        
                if(!lecture_bouton_poussoir()){ 
                    compteurBouton++;   // Si le bouton est enfoncé et relâché le compteur est incrémenté.
                }
            }
        }

        // La DEL passe au rouge pour 8 192 000 cycles d'horloge (1 sec à 8,192 MHz) 
        PORTB = ROUGE; 
        for(unsigned long compteurDelai = 0; compteurDelai < 8192000; compteurDelai++){}
    }    

    return 0;
}