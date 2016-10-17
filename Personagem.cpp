#include "Personagem.h"

Personagem::Personagem()
{
    img = load_bitmap("Arquivos//Imagens//Objeto1.bmp", NULL);  //carrega a imagem a partir da pasta onde ela est�.
    h = 100; // inicializa a altura da imagem/personagem.
    l = 100; // inicializa a largura da imagem/personagem.
    x = 350; // Posi��o inicial em x.
    y = 250; // Posi��o icial em y.
    vx = 1;  // Velocidade icial do objeto em x.
    vy = 1;  // Velocidade icial do objeto em y.
}

Personagem::~Personagem()
{
    destroy_bitmap(img);  // Destr�i a imagem;    
}

/* Sets */
    void Personagem::setimg( BITMAP* I )
    {
        img = I;         
    }
    
    void Personagem::setbuffer( BITMAP* B )
    {
        buffer = B;         
    }
    
    void Personagem::setx( int X )
    {
        x = X; 
    }
    
    void Personagem::sety( int Y )
    {
        y = Y;         
    }
    
    void Personagem::seth( int H )
    {
        h = H;         
    }
    
    void Personagem::setl( int L )
    {
        l = L;         
    }
    
    void Personagem::setvx( int VX )
    {
        vx = VX;         
    }
    
    void Personagem::setvy( int VY )
    {
        vy = VY;         
    }
    
/* Gets */
    BITMAP* Personagem::getimg()
    {
        return img;
    }
    
    int Personagem::getx()
    {
        return x;
    }
    
    int Personagem::gety()
    {
        return y;
    }
    
    int Personagem::geth()
    {
        return h;
    }
    
    int Personagem::getl()
    {
        return l;
    }
    
    int Personagem::getvx()
    {
        return vx;
    }
    
    int Personagem::getvy()
    {
        return vy;
    }

/* Movimenta��o */
    void Personagem::Movimento()    
    {
                                      //  |Se a seta para cima for pressionada 
                                      //  |o personagem tem sua posi��o em Y 
         if (key[KEY_UP]) y = y - vy; // -|reduzida (no Allegro o eixo Y � oposto)
                                      //  |e se desloca para cima tantos pixels
                                      //  |quanto for o valor da velocidade do personagem em Y.
         if (key[KEY_DOWN]) y = y + vy;  // An�logo ao anterior, por�m, para baixo. 
         if (key[KEY_RIGHT]) x = x + vx; // Em x o eixo � padr�o, portanto para a direita � positivo.
         if (key[KEY_LEFT]) x = x - vx;  // E para a esquerda negativo.                      
    }

void Personagem::Desenha()
{
    draw_sprite(buffer, img, x, y);  // Desenha no buffer  
}
