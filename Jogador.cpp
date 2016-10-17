#include "Jogador.h"
#include "Jogador2.h"

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
         if ((key[KEY_UP])&&( y > 0 )&&(C == false)) y = y - vy;                             
             //  |Se a seta para cima for pressionada 
             //  |o Jogador tem sua posição em Y 
             //  |reduzida (no Allegro o eixo Y é oposto)
             //  |e se desloca para cima tantos pixels
             // -|quanto for o valor da velocidade do Jogador em Y.
             //  |A imagem só se movimentará caso o Y do personagem 
             //  |for maior que 0 -> COLISÃO COM A TELA 
             //  |A imagem não se movimentará para cima caso a variável 
             //  |de colisão C esteja ativa (true)
         if ((key[KEY_DOWN])&&( (y+h) < 600)&&(B == false)) y = y + vy;  
             //  |Análogo ao anterior, porém, para baixo. 
             //  |a colisão com a tela ocorre quando o Y do 
             //  |personagem somado com a altura dele for menor que o limite 
             // -|inferior da tela. Essa soma é necessária porque as coordenadas
             //  |X e Y são obtidas do canto superior esquerdo da imagem.
             //  |A imagem não se movimentará para baixo caso a variável 
             //  |de colisão B esteja ativa (true)
         if ((key[KEY_RIGHT])&&( (x+l) < 800)&&(D == false)) x = x + vx; 
             // Em x o eixo é padrão, portanto para a direita é positivo.
             // colisão com a tela análoga ao anterior, porém, na direção X 
             // a posição é somada com a Largura do objeto.
             // colisão com objetos análoga à anterior.
         if ((key[KEY_LEFT])&&( x > 0)&&(E == false)) x = x - vx;  
             // E para a esquerda, em x, é negativo.         
             // colisão com objetos análoga à anterior.             
    }

    void Jogador::testecolisao(Jogador2* P2)
    {
    
        if ((((x + l) >= P2->getx()))&&(x <= P2->getx())&&((y + h) >= P2->gety())&&( y <= (P2->gety()+P2->geth())))  
        {
            D = true; 
            // Detecta se colidiu pela direita e torna verdadeira a 
            //variável D que é a que vai impedir o movimento para a direita. 
        }
        else if (((x <= (P2->getx()+ P2->getl()))&&(x >= P2->getx()))&&((y + h) >= P2->gety())&&( y <= (P2->gety()+P2->geth())))
        {
            E = true;     
            // Detecta se colidiu pela esquerda e torna verdadeira a 
            //variável E que é a que vai impedir o movimento para a esquerda.        
        } 
        if (((y <= (P2->gety()+ P2->geth()))&&(y >= P2->gety()))&&((x + l) >= P2->getx())&&( x <= (P2->getx()+P2->getl())))
        {
            C = true;         
            // Detecta se colidiu por cima e torna verdadeira a 
            //variável C que é a que vai impedir o movimento para cima.     
        }
        else if ((((y + h) >= P2->gety()))&&(y <= P2->gety())&&((x + l) >= P2->getx())&&( x <= (P2->getx()+P2->getl())))
        {
            B = true;       
            // Detecta se colidiu por baixo e torna verdadeira a 
            //variável B que é a que vai impedir o movimento para baixo.     
        }
        else 
        {
            C = false;
            B = false; // Retorna as variáveis para falso
            D = false; // para que o objeto possa se mover novamente.
            E = false;
        }
    }
