#include "Personagem.h"

Personagem::Personagem()
{
    C = false;
    B = false;
    D = false;
    E = false;
}

Personagem::~Personagem()
{
                        
}

/* Sets */
    void Personagem::setimg( BITMAP* I )
    {
        img = I;         
    }
    
    void Personagem::setx( const int X )
    {
        x = X; 
    }
    
    void Personagem::sety( const int Y )
    {
        y = Y;         
    }
    
    void Personagem::seth( const int H )
    {
        h = H;         
    }
    
    void Personagem::setl( const int L )
    {
        l = L;         
    }
    
    void Personagem::setvx( const int VX )
    {
        vx = VX;         
    }
    
    void Personagem::setvy( const int VY )
    {
        vy = VY;         
    }
    
/* Gets */
    BITMAP* Personagem::getimg()
    {
        return img;
    }
    
    const int Personagem::getx()
    {
        return x;
    }
    
    const int Personagem::gety()
    {
        return y;
    }
    
    const int Personagem::geth()
    {
        return h;
    }
    
    const int Personagem::getl()
    {
        return l;
    }
    
    const int Personagem::getvx()
    {
        return vx;
    }
    
    const int Personagem::getvy()
    {
        return vy;
    }

/* Movimentação */
    void Personagem::Movimento()    
    {
                                                                 //  |Se a seta para cima for pressionada 
                                                                 //  |o personagem tem sua posição em Y 
         if ((key[KEY_UP])&&( y > 0 )&&(C == false)) y = y - vy; // -|reduzida (no Allegro o eixo Y é oposto)
                                                                 //  |e se desloca para cima tantos pixels
                                                                 //  |quanto for o valor da velocidade do personagem em Y.
         if ((key[KEY_DOWN])&&( (y+h) < 600)&&(B == false)) y = y + vy;  // Análogo ao anterior, porém, para baixo. 
         if ((key[KEY_RIGHT])&&( (x+l) < 800)&&(D == false)) x = x + vx; // Em x o eixo é padrão, portanto para a direita é positivo.
         if ((key[KEY_LEFT])&&( x > 0)&&(E == false)) x = x - vx;        // E para a esquerda negativo.                      
    }

void Personagem::setbuffer(BITMAP* B)
{
     buffer = B;
}

void Personagem::Desenha()
{
    draw_sprite(buffer, img, x, y);  // Desenha no buffer  
}
