#include "Jogador.h"

Jogador::Jogador() : Personagem()
{
 
}

Jogador::~Jogador()
{
  destroy_bitmap(img);  // Destr�i a imagem;                     
}

/* Movimenta��o */
    void Jogador::Movimento()    
    {
         if ((key[KEY_UP])&&( y > 0 )) y = y - vy;                             
             //  |Se a seta para cima for pressionada 
             //  |o Jogador tem sua posi��o em Y 
             // -|reduzida (no Allegro o eixo Y � oposto)
             //  |e se desloca para cima tantos pixels
             //  |quanto for o valor da velocidade do Jogador em Y.
             //  |A imagem s� se movimentar� caso o Y do personagem 
             //  |for maior que 0 -> COLIS�O COM A TELA 
         if ((key[KEY_DOWN])&&( (y+h) < 600)) y = y + vy;  
             // An�logo ao anterior, por�m, para baixo. 
             // a colis�o com a tela ocorre quando o Y do 
             // personagem somado com a altura dele for menor que o limite 
             // inferior da tela. Essa soma � necess�ria porque as coordenadas
             // X e Y s�o obtidas do canto superior esquerdo da imagem.
         if ((key[KEY_RIGHT])&&( (x+l) < 800)) x = x + vx; 
             // Em x o eixo � padr�o, portanto para a direita � positivo.
             // colis�o an�loga ao anterior, por�m, na dire��o X 
             // a posi��o � somada com a Largura do objeto.
         if ((key[KEY_LEFT])&&( x > 0)) x = x - vx;  
             // E para a esquerda, em x, � negativo.                      
    }


