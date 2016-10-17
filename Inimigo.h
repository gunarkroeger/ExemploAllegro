#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include "Personagem.h"

class Inimigo : public Personagem
{
    private:
            
    public:
            Inimigo();
            ~Inimigo();
            
            /* Movimentação */
            virtual void Movimento();
            void Desenha();
            /* Colisão */
           
};

#endif
