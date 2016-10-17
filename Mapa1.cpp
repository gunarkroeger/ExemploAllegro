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
    
    
    T1.setbuffer(buffer); // Associa o buffer ao personagem para que ele possa se desenhar na tela.
    T1.setimg(load_bitmap("Arquivos//Imagens//Tanque1.bmp", NULL));  //carrega a imagem a partir da pasta onde ela está.
    T1.seth(31);  // inicializa a altura da imagem/personagem.
    T1.setl(31);  // inicializa a largura da imagem/personagem.
    T1.setx(670); // Posição inicial em x.
    T1.sety(470); // Posição incial em y.
    T1.setvx(0);  // Velocidade incial do objeto em x.
    T1.setvy(1);  // Velocidade incial do objeto em y.
    T1.setsx(0);  // Posição x do sprite na imagem maior.
    T1.setsy(0);  // Posição y do sprite na imagem maior.
    
    Px1.setbuffer(buffer); 
    Px1.setimg(load_bitmap("Arquivos//Imagens//Aquatico1.bmp", NULL)); 
    Px1.seth(30); 
    Px1.setl(30); 
    Px1.setx(50); 
    Px1.sety(50);  // Inicialização dos atributos do inimigo peixe.
    Px1.setvx(0);  
    Px1.setvy(0);  
    Px1.setsx(3);
    Px1.setsy(0);  
    Px1.setA(0);   // Inicialização da variável responsável pelo gerenciamento da animação do peixe.
    Px1.setLA(50); // Inicialização da variável responsável pelo controle de velocidade da animação do peixe.
                   // reparar na Tela03 do jogo que a animação de cada peixe tem uma
                   // velocidade diferente. É esta variável que controla isso.
    
    Px2.setbuffer(buffer); 
    Px2.setimg(load_bitmap("Arquivos//Imagens//Aquatico1.bmp", NULL)); 
    Px2.seth(30); 
    Px2.setl(30); 
    Px2.setx(210); 
    Px2.sety(110);
    Px2.setvx(0);  
    Px2.setvy(0);  
    Px2.setsx(3);
    Px2.setsy(0);  
    Px2.setA(0);
    Px2.setLA(100);
    
    Px3.setbuffer(buffer); 
    Px3.setimg(load_bitmap("Arquivos//Imagens//Aquatico1.bmp", NULL)); 
    Px3.seth(30); 
    Px3.setl(30); 
    Px3.setx(355); 
    Px3.sety(178);
    Px3.setvx(0);  
    Px3.setvy(0);  
    Px3.setsx(3);
    Px3.setsy(0);  
    Px3.setA(0);
    Px3.setLA(250);
    
    /* As funções foram colocardas nesse método "Inicializar",
    porque, caso colocadas na construtora, causam um erro no programa.
    Esse erro ocorre porque a Biblioteca Gráfica está sendo inicializada
    na classe Principal, sendo assim, os objetos agregados nessa classe
    têm suas construtoras 'lidas' antes da inicialização da biblioteca,
    portanto o programa não reconhece as funções e ocorre o erro.
    Desta forma, os objetos são inicializados depois da biblioteca gráfica
    portanto, não há problemas. */          
}

void Mapa1::Entrar()
{
    Tela1();
}

/*
    Os loops principais agora rodam na classe Mapa1,
pois esta classe é a que coordena a localização
dos jogadores no mapa.
    Esta classe possui os métodos Tela, que são os loops
de cada tela do mapa. Quando os jogadores ultrapassam os limites 
da tela (saem da tela) o loop passa a rodar no método correspondente
à tela para onde eles foram. Por exemplo, se os jogadores estão na 
tela inicial do jogo estão na Tela1 e o loop rodará no método Tela1(), 
quando os jogadores saem da tela pela direita, se transportam para a 
segunda tela (Tela2) e o loop passará a rodar no método Tela2(). Caso
estejam na 2 e sairem pela esquerda voltarão à 1 e o loop voltará a rodar
em Tela1().
*/
void Mapa1::Tela1()
{

    if(inicio == false) // Se não for a primeira vez que os jogadores entram nesta tela...
    {
        P1->setx(750); // Ajusta os valores na entrada da tela
        P2->setx(750); 
        if (P1->gety() >= (506-P1->geth())) P1->sety(505 - P1->geth());
        else if (P1->gety() <= 95) P1->sety(96);
        if (P2->gety() >= (506-P2->geth())) P2->sety(505 - P2->geth());
        else if (P2->gety() <= 95) P2->sety(96);
        // calcula as posições para que os jogadores não entrem 
        // na tela por uma parte inacessível 
        //(por exemplo por cima de uma barreira.
    }
    
    Terra.setimg(load_bitmap("Arquivos//Imagens//Barreira1.bmp", NULL));
    
    inicio = false;
    
    while (1) //loop principal.
    {
        Mar.Desenha();   // Chama a função Desenha para desenhar o mar no buffer.
        Terra.Desenha();   // Chama a função Desenha para desenhar a terra no buffer.
        P1->Desenha();   // Chama a função Desenha para desenhar o personagem no buffer.
        P2->Desenha();
           
        P1->testecolisao(P2,91,1000,92,502); // Testa a colisão do Jogador 1 com a tela e com o jogador 2.
        P2->testecolisao(P1,91,1000,92,502); // Testa a colisão do Jogador 2 com a tela e com o jogador 1.
        Mar.Movimento();   // Aciona o movimento do cenário.
        P1->Movimento(); // Aciona o movimento do personagem.
        P2->Movimento();
        
        if ((P1->getx() >= 810)&&(P2->getx() >= 810))  // Se ambos os jogadores sairem da tela pela direita...
        {
            P1->setx(0);  // Seta as novas posições do personagem na próxima tela.
            P2->setx(0); 
            Tela2();      // Vai para a tela2.
            break;
        }
        
        if (key[KEY_ESC]) // Se esc for pressionado...
        {
            if (Sair())   // Aciona a tela do menu de saída.
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
     
    Terra.setimg(load_bitmap("Arquivos//Imagens//Praia1.bmp", NULL));
    
    while (1) //loop principal.
    {
        Mar.Desenha();   // Chama a função Desenha para desenhar o mar no buffer.
        Terra.Desenha(); // Chama a função Desenha para desenhar a terra no buffer.
        P1->Desenha();   // Chama a função Desenha para desenhar o personagem no buffer.
        P2->Desenha();
        T1.Desenha();    // Desenha Tanque.
        
        P1->testecolisao(P2,-200,600,-200,600); // Testa a colisão do Jogador 1 com a tela e com o jogador 2.
        P2->testecolisao(P1,-200,600,-200,600); // Testa a colisão do Jogador 2 com a tela e com o jogador 1.
        Mar.Movimento();   // Aciona o movimento do cenário.
        P1->Movimento();  // Aciona o movimento do personagem.
        P2->Movimento();
        T1.Movimento();   // Aciona o movimento do inimigo (Tanque)
        
        if ((P1->getx() <= -190)&&(P2->getx() <= -190)) // Se ambos os jogadores sairem da tela pela esquerda...
        {
            Tela1(); // Vai para a tela 1.
            break;
        }
        else if ((P1->gety() <= -190)&&(P2->gety() <= -190)) // Se ambos os jogadores sairem da tela por cima...
        {
            P1->sety(600); // Seta as novas posições dos personagens na proxima tela.
            P2->sety(600);
            Tela3();       // Vai para a tela 3.
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
    rest(100); // Rest para evitar que o programa reconheça que o botão de 
               // voltar foi pressionado várias vezes e acabe saindo do 
               // Mapa1 inteiro. 
}

void Mapa1::Tela3()
{
    
    Terra.setimg(load_bitmap("Arquivos//Imagens//Praia1.bmp", NULL));
    
    while (1) //loop principal.
    {
        Mar.Desenha();   // Chama a função Desenha para desenhar o mar no buffer.
        Terra.Desenha(); // Chama a função Desenha para desenhar a terra no buffer.
        Px1.Desenha();   // Desenha Peixe.
        Px2.Desenha();
        Px3.Desenha();
        P1->Desenha();   // Chama a função Desenha para desenhar o personagem no buffer.
        P2->Desenha();
        
        P1->testecolisao(P2,0,600,0,900); // Testa a colisão do Jogador 1 com a tela e com o jogador 2.
        P2->testecolisao(P1,0,600,0,900); // Testa a colisão do Jogador 2 com a tela e com o jogador 1.
        Mar.Movimento();   // Aciona o movimento do cenário.
        P1->Movimento();   // Aciona o movimento do personagem.
        P2->Movimento();
        Px1.Movimento();   // Aciona o movimento do inimigo (Peixe)
        Px2.Movimento();
        Px3.Movimento();
        
        if ((P1->gety() >= 630)&&(P2->gety() >= 630)) 
        {
            P1->sety(0 - P1->geth());
            P2->sety(0 - P2->geth());
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
    rest(100); // Rest para evitar que o programa reconheça que o botão de 
               // voltar foi pressionado várias vezes e acabe saindo do 
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
