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
         if ((key[KEY_W])&&( y > 0 )&&(C == false)) 
         {
             if (direcao == 2) x = x + ((l/2) - (h/2)); 
             Sx = 173;  
             Sy = 5;    
             l = 65;
             h = 177;          
             y = y - vy;  
             direcao = 1;     
         }
         // Idem ao Jogador1 porém com as teclas W A S D
         else if ((key[KEY_S])&&( (y+h) < 600)&&(B == false))   
         {
             if (direcao == 2) x = x + ((l/2) - (h/2));
             Sx = 11;
             Sy = 5;      
             l = 65;
             h = 177;              
             y = y + vy;      
             direcao = 1;       
         } 
         else if ((key[KEY_D])&&( (x+l) < 800)&&(D == false))  
         {
             if (direcao == 1) y = y + ((h/2) - (l/2));
             Sx = 348;
             Sy = 154;      
             l = 177;
             h = 65;              
             x = x + vx;      
             direcao = 2;        
         }
         else if ((key[KEY_A])&&( x > 0)&&(E == false)) 
         {
             if (direcao == 1) y = y + ((h/2) - (l/2));
             Sx = 349;
             Sy = 3;      
             l = 177;
             h = 65;              
             x = x - vx;      
             direcao = 2;          
         }                   
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
