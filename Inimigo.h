#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include "Personagem.h"

class Inimigo : public Personagem
{
    private:
            
    public:
            Inimigo();
            ~Inimigo();
            
            /* Movimenta��o */
            virtual void Movimento();
            void Desenha();
            /* Colis�o */
           
};

#endif
