#include "Jogador.h"

Jogador::Jogador() : Personagem()
{
 
}

Jogador::~Jogador()
{
  destroy_bitmap(img);  // Destrói a imagem;                     
}

/* Movimentação */
    void Jogador::Movimento()    
    {
         if ((key[KEY_UP])&&( y > 0 )) y = y - vy;                             
             //  |Se a seta para cima for pressionada 
             //  |o Jogador tem sua posição em Y 
             // -|reduzida (no Allegro o eixo Y é oposto)
             //  |e se desloca para cima tantos pixels
             //  |quanto for o valor da velocidade do Jogador em Y.
             //  |A imagem só se movimentará caso o Y do personagem 
             //  |for maior que 0 -> COLISÃO COM A TELA 
         if ((key[KEY_DOWN])&&( (y+h) < 600)) y = y + vy;  
             // Análogo ao anterior, porém, para baixo. 
             // a colisão com a tela ocorre quando o Y do 
             // personagem somado com a altura dele for menor que o limite 
             // inferior da tela. Essa soma é necessária porque as coordenadas
             // X e Y são obtidas do canto superior esquerdo da imagem.
         if ((key[KEY_RIGHT])&&( (x+l) < 800)) x = x + vx; 
             // Em x o eixo é padrão, portanto para a direita é positivo.
             // colisão análoga ao anterior, porém, na direção X 
             // a posição é somada com a Largura do objeto.
         if ((key[KEY_LEFT])&&( x > 0)) x = x - vx;  
             // E para a esquerda, em x, é negativo.                      
    }


