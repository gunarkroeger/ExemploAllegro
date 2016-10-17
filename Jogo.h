#ifndef _JOGO_H_
#define _JOGO_H_

#include "Mapa1.h"

class Jogo
{
    private:
           BITMAP* buffer;
           Menu* M;
           // Bitmap de buffer para desenhar todas as imagens nele
           // e logo em seguida jogá-lo inteiro na tela, isso evita
           // que a tela ou as imagens fiquem piscando.
           Jogador* P1;  // Jogador 1;
           Jogador* P2; //  Jogaodr 2;
           Mapa1 M1;   //   Mapa 1;
           
    public:
           Jogo();
           ~Jogo();
           
           void Inicializar();
           void Iniciar();
           
           /* Sets */
           void setjogadores(Jogador* P, Jogador* PP);
           void setmenu( Menu* ME);
           
           /* Gets */
           BITMAP* getbuffer();
};

#endif
