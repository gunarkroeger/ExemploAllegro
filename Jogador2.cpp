#include "Jogador2.h"
#include "Jogador.h"

Jogador2::Jogador2() : Personagem()
{
    
}

Jogador2::~Jogador2()
{
    destroy_bitmap(img);  // Destrói a imagem;                    
}

/* Movimentação */
    void Jogador2::Movimento()    
    {
         if ((key[KEY_W])&&( y > 0 )&&(C == false)) y = y - vy; 
         // Idem ao Jogador1 porém com as teclas W A S D
         if ((key[KEY_S])&&( (y+h) < 600)&&(B == false)) y = y + vy;  
         if ((key[KEY_D])&&( (x+l) < 800)&&(D == false)) x = x + vx; 
         if ((key[KEY_A])&&( x > 0)&&(E == false)) x = x - vx;                      
    }

    void Jogador2::testecolisao(Jogador* P1)
    {    
        // Idem ao Jogador1 
        if ((((x + l) >= P1->getx()))&&(x <= P1->getx())&&((y + h) >= P1->gety())&&( y <= (P1->gety()+P1->geth())))  
        {
            D = true; 
        }
        else if (((x <= (P1->getx()+ P1->getl()))&&(x >= P1->getx()))&&((y + h) >= P1->gety())&&( y <= (P1->gety()+P1->geth())))
        {
            E = true; 
        } 
        if (((y <= (P1->gety()+ P1->geth()))&&(y >= P1->gety()))&&((x + l) >= P1->getx())&&( x <= (P1->getx()+P1->getl())))
        {
            C = true;
        }
        else if ((((y + h) >= P1->gety()))&&(y <= P1->gety())&&((x + l) >= P1->getx())&&( x <= (P1->getx()+P1->getl())))
        {
            B = true;  
        }
        else 
        {
            C = false;
            B = false;  
            D = false;  
            E = false;
        }
    }
