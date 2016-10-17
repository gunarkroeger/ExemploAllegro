#ifndef _CENARIO_H_
#define _CENARIO_H_

#include <allegro.h>

class Cenario
{
    private:
            BITMAP* buffer;   // Buffer.
            BITMAP* fundo;    // Imagem de fundo (cenario).
            short int x;
            short int y;      // Posições e velocidade.
            short int v;
            short int redutor_velocidade;  
            // Variável que faz com que a imagem se mova menos de um pixel
            // por loop.        
   
    public:
            Cenario();
            ~Cenario();
            
            /* Sets */
            void setimg( BITMAP* IMG);
            void setx( const short int X );
            void sety( const short int Y );
            void setv( const short int V );
            void setRV( const short int RV );
            void setbuffer( BITMAP* B );
            
            void Desenha();
            /* Movimentação */
            void Movimento();
            
};

#endif
