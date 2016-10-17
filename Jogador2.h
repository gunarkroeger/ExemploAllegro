#ifndef _JOGADOR2_H_
#define _JOGADOR2_H_

#include "Personagem.h"

class Jogador;

class Jogador2 : public Personagem
{
    private:
            
    public:
           Jogador2();
           ~Jogador2();
           
           /* Movimentação */
           void Movimento();
           
           void testecolisao(Jogador* P1);
};

#endif
