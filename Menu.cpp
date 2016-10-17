#include "Menu.h"

Menu::Menu()
{
     
}

Menu::~Menu()
{
   buffer = NULL; // Aterra o ponteiro para o buffer;  
}

void Menu::Inicializar()
{
     /* As funções foram colocardas nesse método "Inicializar",
     porque, caso colocadas na construtora, causam um erro no programa.
     Esse erro ocorre porque a Biblioteca Gráfica está sendo inicializada
     na classe Principal, sendo assim, os objetos agregados nessa classe
     têm suas construtoras 'lidas' antes da inicialização da biblioteca,
     portanto o programa não reconhece as funções e ocorre o erro.
        Desta forma, os objetos são inicializados depois da biblioteca gráfica
     portanto, não há problemas. */          
}

void Menu::Iniciar()
{
    show_mouse(screen); 
    Raiz();
}

void Menu::Raiz()
{
    int opt = 1;          // Variável para o menu saber qual opção está
                          // o cursor, qual opção está selecionada.
                          
    while (!key[KEY_ESC]) // Loop principal.
    {
        draw_sprite(buffer, fundoR, 0, 0); // Desenha a imagem de fundo.
        if (opt == 1) // Se o cursor estiver na opção 1 (jogar).
        {
            masked_stretch_blit(cursor, buffer, 348, 154, 177*2, 65*2, 153, 275, 111, 40); // (Imagem, Buffer, Xinicial na IMG maior. Yinicial na IMG maior, Largura do subsprite, Altura do Subsprite, posiçãoX, posiçãoY, TamanhoX, TamanhoY);  
            // Desenha o barco na posição que sinalizará a opção 1.
            if (key[KEY_ENTER]) J->Iniciar();
            // Se ENTER for pressionado iniciará o jogo.
        }
        
        if (opt == 2) // Se o cursor estiver na opção 2 (creditos).
        {
            masked_stretch_blit(cursor, buffer, 348, 154, 177*2, 65*2, 90, 340, 111, 40);
            // Desenha o barco na posição que sinalizará a opção 2.
            if (key[KEY_ENTER]) Creditos();
            // Se ENTER for pressionado irá para a tela de créditos.
        }
        
        if (opt == 3) // Se o cursor estiver na opção 3 (sair).
        {
            masked_stretch_blit(cursor, buffer, 348, 154, 177*2, 65*2, 176, 403, 111, 40);
            // Desenha o barco na posição que sinalizará a opção 3.
            if (key[KEY_ENTER]) break;
            // Se ENTER for pressionado sairá do while do menu.
        }
        
        if (key[KEY_UP]) // Se a seta para CIMA for pressionada...
        {
            rest(200); // Rest para que a tecla seja pressionada apenas uma vez.
            if (opt == 1) opt = 3; 
            // Se a corsor estiver na opção 1 irá para a opção 3.
            else opt = opt - 1; // Senão ira para a opção acima.          
        }
        else if (key[KEY_DOWN]) // Se a seta para BAIXO for pressionada...
        {
            rest(200);
            if (opt == 3) opt = 1; 
            // Se a corsor estiver na opção 3 irá para a opção 1.
            else opt = opt + 1; // Senão ira para a opção abaixo.
            // Isso faz com que as opções do menu sejam cíclicas
            // se o cursor chegar à última posição e a seta para
            // baixo for pressionada novamente, voltará para a 
            // primeira opção.                 
        }
        if ((mouse_x > 259)&&(mouse_x < 535)&&(mouse_y > 265)&&(mouse_y < 321)) // 259-265/535-321 Botão Jogar.
        {
            // mouse_x indica a posição 'X' do mouse, mouse_y a posição 'Y'
            // os números indicam as coordenadas dos pontos superior esquerdo
            // e inferior direito do botão.
            // Lembrando que o eixo 'Y' no Allegro é invertido, o topo da tela 
            // indica o zero e 'y' é incrementado para baixo
            opt = 1;          
            if (mouse_b & 1) J->Iniciar();  
            // Se o botão 1 (esquerdo) do mouse for pressionado... inicia o jogo
            // Obs: o botão 2 é o direito e o botão 3 o do meio.     
        }
        if ((mouse_x > 199)&&(mouse_x < 604)&&(mouse_y > 334)&&(mouse_y < 385)) // 199-334/604-385 Botão Créditos.
        {
            opt = 2;  
            if (mouse_b & 1) Creditos();      
        }
        if ((mouse_x > 289)&&(mouse_x < 482)&&(mouse_y > 401)&&(mouse_y < 449)) // 289-401/482-449 Botão Sair.
        {
            opt = 3;
            if (mouse_b & 1) break;
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
        if ((mouse_x > 259)&&(mouse_x < 525)&&(mouse_y > 532)&&(mouse_y < 576)) // 259-532/525-576 Botão 'Voltar'.
        // Se o mouse estiver sobre o botão voltar...
        {
            if ((mouse_b & 1)||(key[KEY_ENTER])) break;
            // Se o botão esquerdo oo mouse for pressionado ou se enter for 
            // pressionado sai do while e volta para o menu de raíz.
        }
        blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
        clear( buffer ); // Limpa o buffer;
    } 
    rest(100); // Rest para evitar que o programa reconheça que o botão de 
               // voltar foi pressionado várias vezes e acabe saindo do 
               // jogo inteiro. 
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

    void Menu::setcursor( BITMAP* C)
    {
         cursor = C;
    }
    
    void Menu::setjogo(Jogo* Jo)
    {
         J = Jo;
    }
/* Gets */



