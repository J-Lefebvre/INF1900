/*
 * Nom: exo DEL
 */


#include <avr/io.h> 
#include <util/delay_basic.h>

int main()
{
  DDRB = 0xff; // PORT B est en mode sortie
  
  // uint8_t cycles = 0;
  
  unsigned long compteur = 0;
  uint8_t vert = 1;
  uint8_t rouge = 2;

  for(;;)  // boucle sans fin
  {
    //del a rouge
    for(;compteur<0xfffff;compteur++){
      PORTB = rouge;
    }  
    compteur = 0;
    
    //del a vert
    for(;compteur<0xfffff;compteur++){
      PORTB = vert;
    }
    compteur = 0;

    //del a orange
    for(;compteur<0x2fff;compteur++){
      PORTB = vert;
      _delay_loop_1(0);
      PORTB = rouge;
      _delay_loop_1(0);
    }

    compteur = 0;

  }
  return 0; 
}

