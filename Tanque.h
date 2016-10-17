#ifndef _TANQUE_H_
#define _TANQUE_H_

#include "Inimigo.h"

class Tanque : public Inimigo
{
    private:
            
    public:
            Tanque();
            ~Tanque();
            
            /* Movimentação */
            void Movimento();
            
            /* Colisão */
           
};

#endif
