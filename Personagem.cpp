#include "Personagem.h"

Personagem::Personagem()
{
    C = false;
    B = false;
    D = false;
    E = false;
    direcao = 1;
    img = NULL;
    buffer = NULL;
}

Personagem::~Personagem()
{
   buffer = NULL;   
   destroy_bitmap(img);  // Destrói a imagem;                   
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
    
    void Personagem::setbuffer(BITMAP* B)
    {
         buffer = B;
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

void Personagem::Desenha()
{
    masked_stretch_blit(img, buffer, Sx, Sy, l*2, h*2, x, y, l, h); // (Imagem, Buffer, Xinicial na IMG maior. Yinicial na IMG maior, Largura do subsprite, Altura do Subsprite, posiçãoX, posiçãoY, TamanhoX, TamanhoY);
}
