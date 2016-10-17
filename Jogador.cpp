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
         if ((key[KEY_UP])&&( y > 0 )&&(C == false)) 
         {
             if (direcao == 2) x = x + ((l/2) - (h/2)); 
             // Ao mudar de direção reposiciona a imagem para que a curva
             // aparente ser mais suave.                 
             Sx = 173;     // Modifica a coordenada X da imagem onde o jogo vai pegar o sprite do personagem.
             Sy = 5;       // Modifica a coordenada Y da imagem onde o jogo vai pegar o sprite do personagem.     
             l = 65;       // Modifica a largura.
             h = 177;      // Modifica a altura.                     
             y = y - vy;   // Altera a posição.    
             direcao = 1;  // Vertical.   
         }                           
             //  |Se a seta para cima for pressionada 
             //  |o Jogador tem sua posição em Y 
             //  |reduzida (no Allegro o eixo Y é oposto)
             //  |e se desloca para cima tantos pixels
             // -|quanto for o valor da velocidade do Jogador em Y.
             //  |A imagem só se movimentará caso o Y do personagem 
             //  |for maior que 0 -> COLISÃO COM A TELA 
             //  |A imagem não se movimentará para cima caso a variável 
             //  |de colisão C esteja ativa (true)
         else if ((key[KEY_DOWN])&&( (y+h) < 600)&&(B == false))   
         {
             if (direcao == 2) x = x + ((l/2) - (h/2)); 
             Sx = 11;
             Sy = 5;      
             l = 65;
             h = 177;                           
             y = y + vy;      
             direcao = 1;
         } 
             //  |Análogo ao anterior, porém, para baixo. 
             //  |a colisão com a tela ocorre quando o Y do 
             //  |personagem somado com a altura dele for menor que o limite 
             // -|inferior da tela. Essa soma é necessária porque as coordenadas
             //  |X e Y são obtidas do canto superior esquerdo da imagem.
             //  |A imagem não se movimentará para baixo caso a variável 
             //  |de colisão B esteja ativa (true)
         else if ((key[KEY_RIGHT])&&( (x+l) < 800)&&(D == false))  
         {
             if (direcao == 1) y = y + ((h/2) - (l/2));                     
             Sx = 348;
             Sy = 154;      
             l = 177;
             h = 65;              
             x = x + vx;        
             direcao = 2;
         } 
             // Em x o eixo é padrão, portanto para a direita é positivo.
             // colisão com a tela análoga ao anterior, porém, na direção X 
             // a posição é somada com a Largura do objeto.
             // colisão com objetos análoga à anterior.
         else if ((key[KEY_LEFT])&&( x > 0)&&(E == false)) 
         {
             if (direcao == 1) y = y + ((h/2) - (l/2));                     
             Sx = 349;
             Sy = 3;      
             l = 177;
             h = 65;              
             x = x - vx; 
             direcao = 2;         
         }                    
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
