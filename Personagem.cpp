#include "Personagem.h"

Personagem::Personagem()
{
    C = false;
    B = false;
    D = false;
    E = false;
    direcao = 1;
}

Personagem::~Personagem()
{
                        
}

/* Sets */
    void Personagem::setimg( BITMAP* I )
    {
        img = I;         
    }
    
    void Personagem::setx( const short int X )
    {
        x = X; 
    }
    
    void Personagem::sety( const short int Y )
    {
        y = Y;         
    }
    
    void Personagem::seth( const short int H )
    {
        h = H;         
    }
    
    void Personagem::setl( const short int L )
    {
        l = L;         
    }
    
    void Personagem::setvx( const short int VX )
    {
        vx = VX;         
    }
    
    void Personagem::setvy( const short int VY )
    {
        vy = VY;         
    }
    
    void Personagem::setsx( const short int SX )
    {
        Sx = SX;         
    }
    
    void Personagem::setsy( const short int SY )
    {
        Sy = SY;         
    }
    
/* Gets */
    BITMAP* Personagem::getimg()
    {
        return img;
    }
    
    const short int Personagem::getx()
    {
        return x;
    }
    
    const short int Personagem::gety()
    {
        return y;
    }
    
    const short int Personagem::geth()
    {
        return h;
    }
    
    const short int Personagem::getl()
    {
        return l;
    }
    
    const short int Personagem::getvx()
    {
        return vx;
    }
    
    const short int Personagem::getvy()
    {
        return vy;
    }
    
    const short int Personagem::getsx()
    {
        return Sx;
    }
    
    const short int Personagem::getsy()
    {
        return Sy;
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
    masked_stretch_blit(img, buffer, Sx, Sy, l*2, h*2, x, y, l, h); // (Imagem, Buffer, Xinicial na IMG maior. Yinicial na IMG maior, Largura do subsprite, Altura do Subsprite, posiçãoX, posiçãoY, TamanhoX, TamanhoY);
}
