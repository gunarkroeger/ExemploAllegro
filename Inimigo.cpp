#include "Inimigo.h"

Inimigo::Inimigo() : Personagem()
{
 
}

Inimigo::~Inimigo()
{
  //destroy_bitmap(img);  // Destr�i a imagem;                     
}

void Inimigo::Desenha()
{
    masked_stretch_blit(img, buffer, Sx, Sy, l, h, x, y, l*2, h*2); // (Imagem, Buffer, Xinicial na IMG maior. Yinicial na IMG maior, Largura do subsprite, Altura do Subsprite, posi��oX, posi��oY, TamanhoX, TamanhoY);
}

/* Movimenta��o */
    void Inimigo::Movimento()    
    {
         
    }
 
