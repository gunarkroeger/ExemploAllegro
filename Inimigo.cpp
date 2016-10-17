#include "Inimigo.h"

Inimigo::Inimigo() : Personagem()
{
 
}

Inimigo::~Inimigo()
{
  //destroy_bitmap(img);  // Destrói a imagem;                     
}

void Inimigo::Desenha()
{
    masked_stretch_blit(img, buffer, Sx, Sy, l, h, x, y, l*2, h*2); // (Imagem, Buffer, Xinicial na IMG maior. Yinicial na IMG maior, Largura do subsprite, Altura do Subsprite, posiçãoX, posiçãoY, TamanhoX, TamanhoY);
}

/* Movimentação */
    void Inimigo::Movimento()    
    {
         
    }
 
