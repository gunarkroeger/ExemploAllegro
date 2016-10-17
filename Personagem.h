#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include <allegro.h>

class Personagem
{
    private:
           BITMAP* img; // Imagem
           BITMAP* buffer;
           int x;       // Posição em x.
           int y;       // Posição em y.
           int h;       // Altura da imagem.
           int l;       // Largura da imagem.
           int vx;      // Velocidade em Y.
           int vy;      // Velocidade em X.
            
    public:
           Personagem();
           ~Personagem();
           
           /* Sets */
           void setimg( BITMAP* I );
           void setbuffer( BITMAP* B);
           void setx( int X );
           void sety( int Y );
           void seth( int H );
           void setl( int L );
           void setvx( int VX );
           void setvy( int VY );
           
           /* Gets */
           BITMAP* getimg();
           int getx();
           int gety();
           int geth();
           int getl();
           int getvx();
           int getvy();
           
           /* Movimentação */
           void Movimento();
           
           void Desenha();
           
};

#endif
