#include "Menu.h"

Menu::Menu()
{
     Inicializar();
}

Menu::~Menu()
{
   buffer = NULL; // Aterra o ponteiro para o buffer;  
}

void Menu::Inicializar()
{
     /* As fun��es foram colocardas nesse m�todo "Inicializar",
     porque, caso colocadas na construtora, causam um erro no programa.
     Esse erro ocorre porque a Biblioteca Gr�fica est� sendo inicializada
     na classe Principal, sendo assim, os objetos agregados nessa classe
     t�m suas construtoras 'lidas' antes da inicializa��o da biblioteca,
     portanto o programa n�o reconhece as fun��es e ocorre o erro.
        Desta forma, os objetos s�o inicializados depois da biblioteca gr�fica
     portanto, n�o h� problemas. */    
     sair = false;      
}

void Menu::Iniciar()
{
    show_mouse(screen); 
    Raiz();
}

void Menu::Raiz()
{
    rest (200);
    int opt = 1;          // Vari�vel para o menu saber qual op��o est�
                          // o cursor, qual op��o est� selecionada.
    while (sair == false) // Loop principal.
    {
        draw_sprite(buffer, fundoR, 0, 0); // Desenha a imagem de fundo.
        if (opt == 1) // Se o cursor estiver na op��o 1 (jogar).
        {
            masked_stretch_blit(cursor, buffer, 348, 154, 177*2, 65*2, 153, 275, 111, 40); // (Imagem, Buffer, Xinicial na IMG maior. Yinicial na IMG maior, Largura do subsprite, Altura do Subsprite, posi��oX, posi��oY, TamanhoX, TamanhoY);  
            // Desenha o barco na posi��o que sinalizar� a op��o 1.
            if (key[KEY_ENTER]) 
            { 
                J->Iniciar();
                rest(10);
                break;
            }
            // Se ENTER for pressionado iniciar� o jogo.
            // O break faz sair do while e do jogo. Isso evita que 
            // o programa volte para o menu quando a op��o sair 
            // for selecionada.
        }
        
        if (opt == 2) // Se o cursor estiver na op��o 2 (creditos).
        {
            masked_stretch_blit(cursor, buffer, 348, 154, 177*2, 65*2, 90, 340, 111, 40);
            // Desenha o barco na posi��o que sinalizar� a op��o 2.
            if (key[KEY_ENTER]) Creditos();
            // Se ENTER for pressionado ir� para a tela de cr�ditos.
        }
        
        if (opt == 3) // Se o cursor estiver na op��o 3 (sair).
        {
            masked_stretch_blit(cursor, buffer, 348, 154, 177*2, 65*2, 176, 403, 111, 40);
            // Desenha o barco na posi��o que sinalizar� a op��o 3.
            if (key[KEY_ENTER]) 
            {
                sair = true;
                break;
            }
            // Se ENTER for pressionado sair� do while do menu.
        }

        if (key[KEY_ESC]) 
        {
            sair = true;
            break;
        }
        
        if (key[KEY_UP]) // Se a seta para CIMA for pressionada...
        {
            rest(200); // Rest para que a tecla seja pressionada apenas uma vez.
            if (opt == 1) opt = 3; 
            // Se a corsor estiver na op��o 1 ir� para a op��o 3.
            else opt = opt - 1; // Sen�o ira para a op��o acima.          
        }
        else if (key[KEY_DOWN]) // Se a seta para BAIXO for pressionada...
        {
            rest(200);
            if (opt == 3) opt = 1; 
            // Se a corsor estiver na op��o 3 ir� para a op��o 1.
            else opt = opt + 1; // Sen�o ira para a op��o abaixo.
            // Isso faz com que as op��es do menu sejam c�clicas
            // se o cursor chegar � �ltima posi��o e a seta para
            // baixo for pressionada novamente, voltar� para a 
            // primeira op��o.                 
        }
        if ((mouse_x > 259)&&(mouse_x < 535)&&(mouse_y > 265)&&(mouse_y < 321)) // 259-265/535-321 Bot�o Jogar.
        {
            // mouse_x indica a posi��o 'X' do mouse, mouse_y a posi��o 'Y'
            // os n�meros indicam as coordenadas dos pontos superior esquerdo
            // e inferior direito do bot�o.
            // Lembrando que o eixo 'Y' no Allegro � invertido, o topo da tela 
            // indica o zero e 'y' � incrementado para baixo
            opt = 1;          
            if (mouse_b & 1) J->Iniciar();  
            // Se o bot�o 1 (esquerdo) do mouse for pressionado... inicia o jogo
            // Obs: o bot�o 2 � o direito e o bot�o 3 o do meio.     
        }
        if ((mouse_x > 199)&&(mouse_x < 604)&&(mouse_y > 334)&&(mouse_y < 385)) // 199-334/604-385 Bot�o Cr�ditos.
        {
            opt = 2;  
            if (mouse_b & 1) Creditos();      
        }
        if ((mouse_x > 289)&&(mouse_x < 482)&&(mouse_y > 401)&&(mouse_y < 449)) // 289-401/482-449 Bot�o Sair.
        {
            opt = 3;
            if (mouse_b & 1) 
            {
                sair = true;
                break;
            }
        }
        
        blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
        clear( buffer ); // Limpa o buffer;
    }
}

void Menu::Creditos()
{
    while (!key[KEY_ESC]) //loop principal.
    {
        draw_sprite(buffer, fundoC, 0, 0); // Desenha a imagem de fundo.
        if ((mouse_x > 259)&&(mouse_x < 525)&&(mouse_y > 532)&&(mouse_y < 576)) // 259-532/525-576 Bot�o 'Voltar'.
        // Se o mouse estiver sobre o bot�o voltar...
        {
            if ((mouse_b & 1)||(key[KEY_ENTER])) break;
            // Se o bot�o esquerdo do mouse for pressionado ou se enter for 
            // pressionado sai do while e volta para o menu de ra�z.
        }
        if (key[KEY_ENTER]) break;
        blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
        clear( buffer ); // Limpa o buffer;
    } 
    rest(100); // Rest para evitar que o programa reconhe�a que o bot�o de 
               // voltar foi pressionado v�rias vezes e acabe saindo do 
               // jogo inteiro. 
}

bool Menu::Sair() // Menu de confirma��o de sa�da.
{
    int opt = 2;          // Vari�vel para o menu saber qual op��o est�
                          // o cursor, qual op��o est� selecionada.
    while (1) // Loop principal.
    {
        draw_sprite(buffer, fundoS, 0, 0); // Desenha a imagem de fundo.
        if (opt == 1) // Se o cursor estiver na op��o 1 (SIM).
        {
            masked_stretch_blit(cursor, buffer, 348, 154, 177*2, 65*2, 114, 509, 111, 40); // (Imagem, Buffer, Xinicial na IMG maior. Yinicial na IMG maior, Largura do subsprite, Altura do Subsprite, posi��oX, posi��oY, TamanhoX, TamanhoY);  
            // Desenha o barco na posi��o que sinalizar� a op��o 1.
            if (key[KEY_ENTER]) return true;
            // Se ENTER for pressionado retornar� o comando para sair do jogo.
        }        
        else if (opt == 2) // Se o cursor estiver na op��o 2 (N�O).
        {
            masked_stretch_blit(cursor, buffer, 348, 154, 177*2, 65*2, 550, 509, 111, 40);
            // Desenha o barco na posi��o que sinalizar� a op��o 2.
            if (key[KEY_ENTER]) return false;
            // Se ENTER for pressionado retornar� ao jogo.
        }
        
        if ((key[KEY_LEFT])||(key[KEY_RIGHT])) // Se a seta para a DIREITA ou ESQUERDA for pressionada...
        {
            rest(200); // Rest para que a tecla seja pressionada apenas uma vez.
            if (opt == 1) opt = 2; 
            else opt = 1;
            // Se a corsor estiver na op��o 1 ir� para a op��o 2 e vice-versa.
        }

        if ((mouse_x > 90)&&(mouse_x < 250)&&(mouse_y > 453)&&(mouse_y < 510)) // 259-265/535-321 Bot�o Jogar.
        {
            // mouse_x indica a posi��o 'X' do mouse, mouse_y a posi��o 'Y'
            // os n�meros indicam as coordenadas dos pontos superior esquerdo
            // e inferior direito do bot�o.
            // Lembrando que o eixo 'Y' no Allegro � invertido, o topo da tela 
            // indica o zero e 'y' � incrementado para baixo
            opt = 1;          
            if (mouse_b & 1) return true;  
            // Se o bot�o 1 (esquerdo) do mouse for pressionado... retorna o comando para sair.
            // Obs: o bot�o 2 � o direito e o bot�o 3 o do meio.     
        }
        if ((mouse_x > 509)&&(mouse_x < 689)&&(mouse_y > 441)&&(mouse_y < 515)) // 199-334/604-385 Bot�o Cr�ditos.
        {
            opt = 2;  
            if (mouse_b & 1) return false;      
        }
        blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
        clear( buffer ); // Limpa o buffer;
    }
}

/* Sets */
    void Menu::setbuffer(BITMAP* B)
    {
         buffer = B;
    }
    
    void Menu::setfundoraiz( BITMAP* R)
    {
         fundoR = R;
    }
    
    void Menu::setfundocreditos( BITMAP* C)
    {
         fundoC = C;
    }
    
    void Menu::setfundosair( BITMAP* S)
    {
         fundoS = S;
    }
    
    void Menu::setcursor( BITMAP* C)
    {
         cursor = C;
    }
    
    void Menu::setjogo(Jogo* Jo)
    {
         J = Jo;
    }
/* Gets */



