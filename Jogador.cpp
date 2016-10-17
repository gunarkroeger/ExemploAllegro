#include "Jogador.h"

Jogador::Jogador(): num(1), Personagem()
{
 
}

Jogador::Jogador(const short int N) : num(N), Personagem()
{
 
}

Jogador::~Jogador()
{
  img = NULL;      
}

/* Gets */
    const short int Jogador::getnum()
    {
        return num;
    }
            
/* Movimenta��o */
    void Jogador::Movimento()    
    {
         if ((((num == 1)&&(key[KEY_UP]))||((num == 2)&&(key[KEY_W])))&&(C == false)) 
         {
             if (direcao == 2) x = x + ((l/2) - (h/2)); 
             // Ao mudar de dire��o reposiciona a imagem para que a curva
             // aparente ser mais suave.                 
             Sx = 173;     // Modifica a coordenada X da imagem onde o jogo vai pegar o sprite do personagem.
             Sy = 5;       // Modifica a coordenada Y da imagem onde o jogo vai pegar o sprite do personagem.     
             l = 65;       // Modifica a largura.
             h = 177;      // Modifica a altura.                     
             y = y - vy;   // Altera a posi��o.    
             direcao = 1;  // Vertical.   
         }                           
             //  |Se a seta para cima for pressionada 
             //  |o Jogador tem sua posi��o em Y 
             //  |reduzida (no Allegro o eixo Y � oposto)
             //  |e se desloca para cima tantos pixels
             // -|quanto for o valor da velocidade do Jogador em Y.
             //  |A imagem s� se movimentar� caso o Y do personagem 
             //  |for maior que 0 -> COLIS�O COM A TELA 
             //  |A imagem n�o se movimentar� para cima caso a vari�vel 
             //  |de colis�o C esteja ativa (true)
         else if ((((num == 1)&&(key[KEY_DOWN]))||((num == 2)&&(key[KEY_S])))&&(B == false))
         {
             if (direcao == 2) x = x + ((l/2) - (h/2)); 
             Sx = 11;
             Sy = 5;      
             l = 65;
             h = 177;                           
             y = y + vy;      
             direcao = 1;
         } 
             //  |An�logo ao anterior, por�m, para baixo. 
             //  |a colis�o com a tela ocorre quando o Y do 
             //  |personagem somado com a altura dele for menor que o limite 
             // -|inferior da tela. Essa soma � necess�ria porque as coordenadas
             //  |X e Y s�o obtidas do canto superior esquerdo da imagem.
             //  |A imagem n�o se movimentar� para baixo caso a vari�vel 
             //  |de colis�o B esteja ativa (true)
         else if ((((num == 1)&&(key[KEY_RIGHT]))||((num == 2)&&(key[KEY_D])))&&(D == false))
         {
             if (direcao == 1) y = y + ((h/2) - (l/2));                     
             Sx = 348;
             Sy = 154;      
             l = 177;
             h = 65;              
             x = x + vx;        
             direcao = 2;
         } 
             // Em x o eixo � padr�o, portanto para a direita � positivo.
             // colis�o com a tela an�loga ao anterior, por�m, na dire��o X 
             // a posi��o � somada com a Largura do objeto.
             // colis�o com objetos an�loga � anterior.
         else if ((((num == 1)&&(key[KEY_LEFT]))||((num == 2)&&(key[KEY_A])))&&(E == false))
         {
             if (direcao == 1) y = y + ((h/2) - (l/2));                     
             Sx = 349;
             Sy = 3;      
             l = 177;
             h = 65;              
             x = x - vx; 
             direcao = 2;         
         }                    
             // E para a esquerda, em x, � negativo.         
             // colis�o com objetos an�loga � anterior.             
    }

    void Jogador::testecolisao(Jogador* P2, int Xmin, int Xmax, int Ymin, int Ymax)
    {
        
        // Colis�o com o outro jogador.
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
        
        // Colis�o com a tela.
        if ( y < Ymin )      C = true;
        if ( (y+h) > Ymax) B = true;
        if ( (x+l) > Xmax) D = true;   
        if ( x < Xmin)       E = true;
    
    }
