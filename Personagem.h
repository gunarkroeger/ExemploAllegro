#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "GerenciadorGrafico.h"


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
           
           bool C,B,D,E; // Variáveis para detectar o sentido das colisões.
            
    public:
           Personagem();
           ~Personagem();
           
           /* Sets */
           void setimg( BITMAP* I );
           void setx( const int X );
           void sety( const int Y );
           void seth( const int H );
           void setl( const int L );
           void setvx( const int VX );
           void setvy( const int VY );
           
           /* Gets */
           BITMAP* getimg();
           const int getx();
           const int gety();
           const int geth();
           const int getl();
           const int getvx();
           const int getvy();
           
           /* Movimentação */
           virtual void Movimento();  // virtual para que o método possa ser redefinido nas subclasses
           
           void setbuffer( BITMAP* B);
           void Desenha();
           
};

#endif
