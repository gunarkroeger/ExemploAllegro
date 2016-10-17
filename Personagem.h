#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include <allegro.h>

class Personagem
{
    protected:          // Protected para que as classes derivadas possuam esses atributos.
           BITMAP* img; // Imagem.
           BITMAP* buffer; // buffer para que o jogador possa se desenhar na tela.
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
           virtual void Movimento();  // virtual para que o método possa ser redefinido nas subclasses
           
           void setbuffer( BITMAP* B);
           void Desenha();
           
};

#endif
