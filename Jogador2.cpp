#include "Jogador2.h"

Jogador2::Jogador2() : Personagem()
{
    
}

Jogador2::~Jogador2()
{
    destroy_bitmap(img);  // Destr�i a imagem;                    
}

/* Movimenta��o */
    void Jogador2::Movimento()    
    {
         if ((key[KEY_W])&&( y > 0 )) y = y - vy; 
         // Idem ao Jogador1 por�m com as teclas W A S D
         if ((key[KEY_S])&&( (y+h) < 600)) y = y + vy;  
         if ((key[KEY_D])&&( (x+l) < 800)) x = x + vx; 
         if ((key[KEY_A])&&( x > 0)) x = x - vx;                      
    }

