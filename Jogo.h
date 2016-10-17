#ifndef _JOGO_H_
#define _JOGO_H_

#include "Jogador.h"

class Jogo
{
    private:
           BITMAP* buffer;
           Jogador* P1;
           Jogador2* P2;
           // Bitmap de buffer para desenhar todas as imagens nele
           // e logo em seguida jogá-lo inteiro na tela, isso evita
           // que a tela ou as imagens fiquem piscando.
    public:
           Jogo();
           ~Jogo();
           
           void Iniciar();
           void Tela1();
           
           /* Sets */
           void setjogadores(Jogador* P, Jogador2* PP);
           
           /* Gets */
           BITMAP* getbuffer();
};

#endif
