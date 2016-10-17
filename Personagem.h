#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "GerenciadorGrafico.h"


class Personagem
{
    protected:          // Protected para que as classes derivadas possuam esses atributos.
           BITMAP* img; // Imagem.
           BITMAP* buffer; // buffer para que o jogador possa se desenhar na tela.
           short int x;       // Posi��o em x.
           short int y;       // Posi��o em y.
           short int h;       // Altura da imagem.
           short int l;       // Largura da imagem.
           short int vx;      // Velocidade em Y.
           short int vy;      // Velocidade em X.
           short int Sx;      // Posi��o x do sprite na imagem maior.
           short int Sy;      // Posi��o y do sprite na imagem maior.
           short int direcao; // Indica se o personagem est� orientado na vertical ou na horizontal.
           
           bool C,B,D,E; // Vari�veis para detectar o sentido das colis�es.
            
    public:
           Personagem();
           ~Personagem();
           
           /* Sets */
           void setimg( BITMAP* I );
           void setx( const short int X );
           void sety( const short int Y );
           void seth( const short int H );
           void setl( const short int L );
           void setvx( const short int VX );
           void setvy( const short int VY );
           void setsx( const short int SX );
           void setsy( const short int SY );
           
           /* Gets */
           BITMAP* getimg();
           const short int getx();
           const short int gety();
           const short int geth();
           const short int getl();
           const short int getvx();
           const short int getvy();
           const short int getsx();
           const short int getsy();
           
           /* Movimenta��o */
           virtual void Movimento();  // virtual para que o m�todo possa ser redefinido nas subclasses
           
           void setbuffer( BITMAP* B);
           void Desenha();
           
};

#endif
