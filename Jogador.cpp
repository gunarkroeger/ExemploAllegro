#include "Jogador.h"
#include "Jogador2.h"

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
         if ((key[KEY_UP])&&( y > 0 )&&(C == false)) y = y - vy;                             
             //  |Se a seta para cima for pressionada 
             //  |o Jogador tem sua posi��o em Y 
             //  |reduzida (no Allegro o eixo Y � oposto)
             //  |e se desloca para cima tantos pixels
             // -|quanto for o valor da velocidade do Jogador em Y.
             //  |A imagem s� se movimentar� caso o Y do personagem 
             //  |for maior que 0 -> COLIS�O COM A TELA 
             //  |A imagem n�o se movimentar� para cima caso a vari�vel 
             //  |de colis�o C esteja ativa (true)
         if ((key[KEY_DOWN])&&( (y+h) < 600)&&(B == false)) y = y + vy;  
             //  |An�logo ao anterior, por�m, para baixo. 
             //  |a colis�o com a tela ocorre quando o Y do 
             //  |personagem somado com a altura dele for menor que o limite 
             // -|inferior da tela. Essa soma � necess�ria porque as coordenadas
             //  |X e Y s�o obtidas do canto superior esquerdo da imagem.
             //  |A imagem n�o se movimentar� para baixo caso a vari�vel 
             //  |de colis�o B esteja ativa (true)
         if ((key[KEY_RIGHT])&&( (x+l) < 800)&&(D == false)) x = x + vx; 
             // Em x o eixo � padr�o, portanto para a direita � positivo.
             // colis�o com a tela an�loga ao anterior, por�m, na dire��o X 
             // a posi��o � somada com a Largura do objeto.
             // colis�o com objetos an�loga � anterior.
         if ((key[KEY_LEFT])&&( x > 0)&&(E == false)) x = x - vx;  
             // E para a esquerda, em x, � negativo.         
             // colis�o com objetos an�loga � anterior.             
    }

    void Jogador::testecolisao(Jogador2* P2)
    {
    
        if ((((x + l) >= P2->getx()))&&(x <= P2->getx())&&((y + h) >= P2->gety())&&( y <= (P2->gety()+P2->geth())))  
        {
            D = true; 
            // Detecta se colidiu pela direita e torna verdadeira a 
            //vari�vel D que � a que vai impedir o movimento para a direita. 
        }
        else if (((x <= (P2->getx()+ P2->getl()))&&(x >= P2->getx()))&&((y + h) >= P2->gety())&&( y <= (P2->gety()+P2->geth())))
        {
            E = true;     
            // Detecta se colidiu pela esquerda e torna verdadeira a 
            //vari�vel E que � a que vai impedir o movimento para a esquerda.        
        } 
        if (((y <= (P2->gety()+ P2->geth()))&&(y >= P2->gety()))&&((x + l) >= P2->getx())&&( x <= (P2->getx()+P2->getl())))
        {
            C = true;         
            // Detecta se colidiu por cima e torna verdadeira a 
            //vari�vel C que � a que vai impedir o movimento para cima.     
        }
        else if ((((y + h) >= P2->gety()))&&(y <= P2->gety())&&((x + l) >= P2->getx())&&( x <= (P2->getx()+P2->getl())))
        {
            B = true;       
            // Detecta se colidiu por baixo e torna verdadeira a 
            //vari�vel B que � a que vai impedir o movimento para baixo.     
        }
        else 
        {
            C = false;
            B = false; // Retorna as vari�veis para falso
            D = false; // para que o objeto possa se mover novamente.
            E = false;
        }
    }
