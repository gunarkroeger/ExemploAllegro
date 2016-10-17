#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Personagem.h"
class Jogador2;

class Jogador : public Personagem
{
    private:
            
    public:
           Jogador();
           ~Jogador();
           
           /* Movimentação */
           void Movimento();
           
           /* Colisão */
           void testecolisao(Jogador2* P2);
           
};

#endif
