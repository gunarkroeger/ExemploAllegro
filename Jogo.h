#ifndef _JOGO_H_
#define _JOGO_H_

#include "Personagem.h"

class Jogo
{
    private:
           BITMAP* buffer;
           // Bitmap de buffer para desenhar todas as imagens nele
           // e logo em seguida jogá-lo inteiro na tela, isso evita
           // que a tela ou as imagens fiquem piscando.
           Personagem* P1;
           
    public:
           Jogo();
           ~Jogo();
           
           void Iniciar();
           void Tela1();
           
           void setpersonagem(Personagem* P);
};

#endif
