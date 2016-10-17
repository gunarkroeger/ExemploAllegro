#include "Mapa1.h"
#include "Menu.h"

Mapa1::Mapa1()
{
     
}

Mapa1::~Mapa1()
{
   buffer = NULL;       
}

void Mapa1::Inicializar()
{
     inicio = true;
     Mar.setbuffer(buffer);
     Mar.setimg(load_bitmap("Arquivos//Imagens//mar.bmp", NULL));
     Mar.setx(0);  
     Mar.sety(-1200);
     Mar.setv(1);              
     Mar.setRV(0);
     Terra.setbuffer(buffer);
     Terra.setimg(load_bitmap("Arquivos//Imagens//Barreira1.bmp", NULL));
     Terra.setx(0);  
     Terra.sety(0);
     Terra.setv(0);              
     Terra.setRV(0);
     /* As fun��es foram colocardas nesse m�todo "Inicializar",
     porque, caso colocadas na construtora, causam um erro no programa.
     Esse erro ocorre porque a Biblioteca Gr�fica est� sendo inicializada
     na classe Principal, sendo assim, os objetos agregados nessa classe
     t�m suas construtoras 'lidas' antes da inicializa��o da biblioteca,
     portanto o programa n�o reconhece as fun��es e ocorre o erro.
        Desta forma, os objetos s�o inicializados depois da biblioteca gr�fica
     portanto, n�o h� problemas. */          
}

void Mapa1::Entrar()
{
    Tela1();
}

/*
    Os loops principais agora rodam na classe Mapa1,
pois esta classe � a que coordena a localiza��o
dos jogadores no mapa.
    Esta classe possui os m�todos Tela, que s�o os loops
de cada tela do mapa. Quando os jogadores ultrapassam os limites 
da tela (saem da tela) o loop passa a rodar no m�todo correspondente
� tela para onde eles foram. Por exemplo, se os jogadores est�o na 
tela inicial do jogo est�o na Tela1 e o loop rodar� no m�todo Tela1(), 
quando os jogadores saem da tela pela direita, se transportam para a 
segunda tela (Tela2) e o loop passar� a rodar no m�todo Tela2(). Caso
estejam na 2 e sairem pela esquerda voltar�o � 1 e o loop voltar� a rodar
em Tela1().
*/
void Mapa1::Tela1()
{

    if(inicio == false) // Se n�o for a primeira vez que os jogadores entram nesta tela...
    {
        P1->setx(750); // Ajusta os valores na entrada da tela
        P2->setx(750); 
        if (P1->gety() >= (506-P1->geth())) P1->sety(505 - P1->geth());
        else if (P1->gety() <= 95) P1->sety(96);
        if (P2->gety() >= (506-P2->geth())) P2->sety(505 - P2->geth());
        else if (P2->gety() <= 95) P2->sety(96);
        // calcula as posi��es para que os jogadores n�o entrem 
        // na tela por uma parte inacess�vel 
        //(por exemplo por cima de uma barreira.
    }
    
    inicio = false;
    
    while (1) //loop principal.
    {
        Mar.Desenha();   // Chama a fun��o Desenha para desenhar o mar no buffer.
        Terra.Desenha();   // Chama a fun��o Desenha para desenhar a terra no buffer.
        P1->Desenha();   // Chama a fun��o Desenha para desenhar o personagem no buffer.
        P2->Desenha();
           
        P1->testecolisao(P2,91,1000,92,502); // Testa a colis�o do Jogador 1 com a tela e com o jogador 2.
        P2->testecolisao(P1,91,1000,92,502); // Testa a colis�o do Jogador 2 com a tela e com o jogador 1.
        Mar.Movimento();   // Aciona o movimento do cen�rio.
        P1->Movimento(); // Aciona o movimento do personagem.
        P2->Movimento();
        
        if ((P1->getx() >= 810)&&(P2->getx() >= 810)) 
        {
            Tela2();
            break;
        }
        
        if (key[KEY_ESC]) 
        {
            if (Sair()) 
            {
                break;
            }
        }
               
        blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
        clear( buffer ); // Limpa o buffer;
        
    }
}

void Mapa1::Tela2()
{
    P1->setx(0);
    P2->setx(0);
    
    while (1) //loop principal.
    {
        Mar.Desenha();   // Chama a fun��o Desenha para desenhar o mar no buffer.
        P1->Desenha();   // Chama a fun��o Desenha para desenhar o personagem no buffer.
        P2->Desenha();
        
        P1->testecolisao(P2,-200,800,0,600); // Testa a colis�o do Jogador 1 com a tela e com o jogador 2.
        P2->testecolisao(P1,-200,800,0,600); // Testa a colis�o do Jogador 2 com a tela e com o jogador 1.
        Mar.Movimento();   // Aciona o movimento do cen�rio.
        P1->Movimento(); // Aciona o movimento do personagem.
        P2->Movimento();
        
        if ((P1->getx() <= -190)&&(P2->getx() <= -190)) 
        {
            Tela1();
            break;
        }
        
        if (key[KEY_ESC]) 
        {
            if (Sair()) 
            {
                break;
                             
            }
        }
               
        blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
        clear( buffer ); // Limpa o buffer;
        
    }
    rest(100); // Rest para evitar que o programa reconhe�a que o bot�o de 
               // voltar foi pressionado v�rias vezes e acabe saindo do 
               // Mapa1 inteiro. 
}

bool Mapa1::Sair()
{
    if (M->Sair()) 
    {  
        inicio = true;
        P1->seth(177); 
        P1->setl(65); 
        P1->setx(250); 
        P1->sety(250); 
        P1->setvx(1);  
        P1->setvy(1);  
        P1->setsx(11);   // Reseta os atributos dos jogadores
        P1->setsy(5);    // isso evita bugs que ocorreriam caso 
        P2->seth(177);   // o usuario clique novamente em 'Jogar' 
        P2->setl(65);    // (no menu) iniciando uma nova partida 
        P2->setx(450);   // sem reiniciar o jogo.
        P2->sety(250); 
        P2->setvx(1);  
        P2->setvy(1);  
        P2->setsx(11);  
        P2->setsy(5);
        M->Raiz();   
        return true;    // Sai do while e sai do jogo.
    }      
    else return false;  // Volta para o Jogo.       
} 

/* Sets */
    void Mapa1::setjogadores(Jogador* P, Jogador* PP)
    {
        P1 = P;
        P2 = PP;
    }
    
    void Mapa1::setbuffer(BITMAP* B)
    {
        buffer = B;
    }
    
    void Mapa1::setmenu(Menu* ME)
    {
        M = ME;
    }


/* Gets */
    BITMAP* Mapa1::getbuffer()
    {
        return buffer;        
    }
