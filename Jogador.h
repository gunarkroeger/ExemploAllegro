#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Personagem.h"
#include "Jogador2.h"

class Jogador : public Personagem
{
    private:
            
    public:
           Jogador();
           ~Jogador();
           
           /* Movimentação */
           void Movimento();
           
};

#endif
