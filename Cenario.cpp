#include "Cenario.h"

Cenario::Cenario()
{
     
}

Cenario::~Cenario()
{
    destroy_bitmap(fundo);  // Destrói a imagem;                     
}

void Cenario::Desenha()
{
   draw_sprite(buffer,fundo, x, y);  
}

/* Sets */
    void Cenario::setimg( BITMAP* IMG)
    {
         fundo = IMG;
    }
    
    void Cenario::setx( const short int X )
    {
         x = X;
    }
    
    void Cenario::sety( const short int Y )
    {
         y = Y;
    }
    
    void Cenario::setv( const short int V )
    {
         v = V;
    }
    
    void Cenario::setRV( const short int RV )
    {
         redutor_velocidade = RV;
    }
    
    void Cenario::setbuffer(BITMAP* B)
    {
         buffer = B;
    }
                
/* Movimentação */
    void Cenario::Movimento()    
    {
        if (redutor_velocidade %15 < 7) y = y + v;
        // O cenário se movimentará somente se a divisão por 15 do redutor 
        // de velocidade (que é uma variável que possui valor de 0 a 1000
        // e fica constantemente se incrementando em 1 a cada loop) obtiver
        // um resto inferior a 7.
        if (y >= -615) y = -1200; 
        // Quando a imagem chega em um determinado ponto volta a sua posição
        // original, isso faz com que ela deslize infinitamente.
        redutor_velocidade++; // Incrementa o redutor (em 1).
        if ( redutor_velocidade >= 1000) redutor_velocidade = 0;
        // Quando o redutor chega a 1000 no seu valor é novamente atribuido 0;
                          
    }
