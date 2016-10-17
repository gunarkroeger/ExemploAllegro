#include "Jogo.h"

Jogo::Jogo()
{
     
}

Jogo::~Jogo()
{
   destroy_bitmap(buffer);  // Destr�i a imagem;                        
}

void Jogo::Inicializar()
{
     buffer = create_bitmap(800, 600);     
     /* As fun��es foram colocardas nesse m�todo "Inicializar",
     porque, caso colocadas na construtora, causam um erro no programa.
     Esse erro ocorre porque a Biblioteca Gr�fica est� sendo inicializada
     na classe Principal, sendo assim, os objetos agregados nessa classe
     t�m suas construtoras 'lidas' antes da inicializa��o da biblioteca,
     portanto o programa n�o reconhece as fun��es e ocorre o erro.
        Desta forma, os objetos s�o inicializados depois da biblioteca gr�fica
     portanto, n�o h� problemas. */          
}

void Jogo::Iniciar()
{
    Tela1();
}

void Jogo::Tela1()
{
    while (!key[KEY_ESC]) //loop principal.
    {
        P1->Desenha(); // Chama a fun��o Desenha para desenhar o personagem no buffer.
        P2->Desenha();
        blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
        P1->testecolisao(P2);
        P2->testecolisao(P1);
        P1->Movimento(); // Aciona o movimento do personagem.
        P2->Movimento();
        clear( buffer ); // Limpa o buffer;
    }
}

/* Sets */
void Jogo::setjogadores(Jogador* P, Jogador2* PP)
{
    P1 = P;
    P2 = PP;
}

/* Gets */
BITMAP* Jogo::getbuffer()
{
    return buffer;        
}
