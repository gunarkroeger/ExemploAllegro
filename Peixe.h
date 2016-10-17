#ifndef _PEIXE_H_
#define _PEIXE_H_

#include "Inimigo.h"

class Peixe : public Inimigo
{
    private:
            int A;  // Vari�vel para gerenciar a anima��o do peixe.
            int LA; // Vari�vel que determina a velocidade (lentid�o) da anima��o 
                    // (quanto maior o n�mero mais LENTA � a anima��o)
                   
    public:
            Peixe();
            ~Peixe();
            
            /* Sets */
            void setA(int a);
            void setLA(int la);
            
            /* Gets */ 
            int getA();
            int getLA();
            
            /* Movimenta��o */
            int Animacao();
            void Movimento();
            
            /* Colis�o */
           
};

#endif
