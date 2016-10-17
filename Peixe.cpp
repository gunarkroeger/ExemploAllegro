#include "Peixe.h"

Peixe::Peixe() : Inimigo()
{
 
}

Peixe::~Peixe()
{
               
}


/* Sets */
    void Peixe::setA(int a)
    {
        A = a;
    }
    
    void Peixe::setLA(int la)
    {
        LA = la;         
    }

/* Gets */ 
    int Peixe::getA()
    {
        return A;         
    }
    
    int Peixe::getLA()
    {
        return LA;         
    }


/* Movimenta��o */
    int Peixe::Animacao() // M�todo para gerenciar a anima��o do peixe.
    {
      A++;     // Incrementa a vari�vel de anima��o.
      
      if (A > 4*LA) A = 0;    // Se a vari�vel de anima��o for maior que 4x 
                              // o valor da vari�vel da velocidade da anima��o
                              // a vari�vel A volta para 0.
      
      if (A <= LA) return 0;  // Se a vari�vel da anima��o for menor que a de controle de velocidade, retora 0.
      else if (((A > LA)&&(A <= 2*LA))||(A > 3*LA)) return 1; // Se estiver entre 2*LA e 3*LA ou se for maior que 3*LA, retorna 1.
      else if ((A > 2*LA)&&(A <= 3*LA)) return 2; // Se estiver entre 2*LA e 3*LA, retorna 2.
      else return 2;   // Retorno padr�o = 2.
      
      // Cada retorno se refere a uma imagem da anima��o, no caso, a
      // anima��o do peixe tem apenas 3 imagens, portanto 3 retornos (0,1 e 2)
      
    }
      
    void Peixe::Movimento()    
    {
        if (Animacao() == 0) //28,28
        {
            Sx = 3;     // Modifica a coordenada X da imagem onde o jogo vai pegar o sprite do personagem,
                        // modificando a imagem de acordo com o est�gio da anima��o.
        }  
        else if (Animacao() == 1) //28,28
        {
            Sx = 35; 
        }
        else if (Animacao() == 2)
        {
            Sx = 66; 
        }
        else
        {
            Sx = 66; 
        }
    }
 












