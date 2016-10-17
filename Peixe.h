#ifndef _PEIXE_H_
#define _PEIXE_H_

#include "Inimigo.h"

class Peixe : public Inimigo
{
    private:
            int A;  // Variável para gerenciar a animação do peixe.
            int LA; // Variável que determina a velocidade (lentidão) da animação 
                    // (quanto maior o número mais LENTA é a animação)
                   
    public:
            Peixe();
            ~Peixe();
            
            /* Sets */
            void setA(int a);
            void setLA(int la);
            
            /* Gets */ 
            int getA();
            int getLA();
            
            /* Movimentação */
            int Animacao();
            void Movimento();
            
            /* Colisão */
           
};

#endif
