/*
 * Nom: exo interrupteur
 */


#include <avr/io.h> 
#include <util/delay_basic.h>
#include <util/delay.h>
#define F_CPU 8000000UL


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

int main()
{
  DDRD = 0; // PORT D est en mode entree
  DDRB = 0xff; // PORT B est en mode sortie
  //unsigned long compteur = 0;
  uint8_t vert = 1;
  uint8_t rouge = 2;
  
  // uint8_t cycles = 0;

  for(;;)  
  {
      // tant que la lecture du bouton poussoire redonne vrai, on reste a orange
      if (lecture_bouton_poussoir()){
            //del a orange
            PORTB = vert;
            _delay_loop_1(0);
            PORTB = rouge;
            _delay_loop_1(125);
    
        }
    else {
         PORTB = 0;

        }

  }
  return 0; 
}
