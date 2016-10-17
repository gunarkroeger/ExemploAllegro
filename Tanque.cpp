#include "Tanque.h"

Tanque::Tanque() : Inimigo()
{
 
}

Tanque::~Tanque()
{
//  destroy_bitmap(img);  // Destrói a imagem;                     
}

/* Movimentação */
    void Tanque::Movimento()    
    {
        if(y <= 20)
        {
            vy = -vy;
            Sx = 31;
        }
        if(y >= 470)
        {
            vy = -vy;
            Sx = 0;     
        } 
        y = y + vy;
    }
 
