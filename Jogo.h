#ifndef _JOGO_H_
#define _JOGO_H_

#include "Jogador.h"
#include "Jogador2.h"
#include "Cenario.h"

class Jogo
{
    private:
           BITMAP* buffer;
           // Bitmap de buffer para desenhar todas as imagens nele
           // e logo em seguida jogá-lo inteiro na tela, isso evita
           // que a tela ou as imagens fiquem piscando.
           Jogador* P1;  // Jogador 1;
           Jogador2* P2; // Jogaodr 2;
           Cenario C;    // Cenário do jogo.
           
           
    public:
           Jogo();
           ~Jogo();
           
           void Inicializar();
           void Iniciar();
           void Tela1();
           
           /* Sets */
           void setjogadores(Jogador* P, Jogador2* PP);
           
           /* Gets */
           BITMAP* getbuffer();
};

#endif
