#include "Jogo.h"

Jogo::Jogo()
{
    buffer = create_bitmap(800, 600);
}

Jogo::~Jogo()
{
   destroy_bitmap(buffer);  // Destrói a imagem;                        
}

void Jogo::Iniciar()
{
    Tela1();
}

void Jogo::Tela1()
{
    while (!key[KEY_ESC]) //loop principal.
    {
        P1->Desenha(); // Chama a função Desenha para desenhar o personagem no buffer.
        P2->Desenha();
        blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
    
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
