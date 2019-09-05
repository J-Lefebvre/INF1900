/*
* Exercice 2 du TP2
*
* TABLE DES ÉTATS
*
* ÉTAT PRÉSENT | BOUTON | ÉTAT SUIVANT | DEL
*     INIT     |   0    |     INIT     |  R
*     INIT     |   1    |      E1      |  A
*      E1      |   0    |      E2      |  V
*      E1      |   1    |      E1      |  A
*      E2      |   0    |      E2      |  V
*      E2      |   1    |      E3      |  R
*      E3      |   0    |      E4      |  0
*      E3      |   1    |      E3      |  R
*      E4      |   0    |      E4      |  0
*      E4      |   1    |      E5      |  V
*      E5      |   0    |     INIT     |  R
*      E5      |   1    |      E5      |  V
*
* BOUTON : 1 signifie que le bouton est enfoncé, 0 qu'il est relâché
* DEL : 0 éteinte, V vert, R rouge, A ambre.
*/

#define F_CPU 8192000UL
#include <avr/io.h>
#include <util/delay_basic.h>
#include <util/delay.h>

const uint8_t ETEINT = 0;
const uint8_t VERT = 1;
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
        PORTB = ROUGE; // La DEL est rouge lorsque la carte mère démarre

        while(lecture_bouton_poussoir()){ // La DEL passe au ambre lorsque le bouton est enfoncé
            PORTB = vert;
            _delay_loop_1(0);
            PORTB = rouge;
            _delay_loop_1(125);
        }
        
    }    

    return 0;
}