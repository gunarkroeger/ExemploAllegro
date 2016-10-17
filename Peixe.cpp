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


/* Movimentação */
    int Peixe::Animacao() // Método para gerenciar a animação do peixe.
    {
      A++;     // Incrementa a variável de animação.
      
      if (A > 4*LA) A = 0;    // Se a variável de animação for maior que 4x 
                              // o valor da variável da velocidade da animação
                              // a variável A volta para 0.
      
      if (A <= LA) return 0;  // Se a variável da animação for menor que a de controle de velocidade, retora 0.
      else if (((A > LA)&&(A <= 2*LA))||(A > 3*LA)) return 1; // Se estiver entre 2*LA e 3*LA ou se for maior que 3*LA, retorna 1.
      else if ((A > 2*LA)&&(A <= 3*LA)) return 2; // Se estiver entre 2*LA e 3*LA, retorna 2.
      else return 2;   // Retorno padrão = 2.
      
      // Cada retorno se refere a uma imagem da animação, no caso, a
      // animação do peixe tem apenas 3 imagens, portanto 3 retornos (0,1 e 2)
      
    }
      
    void Peixe::Movimento()    
    {
        if (Animacao() == 0) //28,28
        {
            Sx = 3;     // Modifica a coordenada X da imagem onde o jogo vai pegar o sprite do personagem,
                        // modificando a imagem de acordo com o estágio da animação.
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
 












