#include "Jogo.h"

Jogo::Jogo()
{
    buffer = create_bitmap(800, 600);
}

Jogo::~Jogo()
{
    destroy_bitmap(buffer);                   
}

void Jogo::setpersonagem(Personagem* P)
{
    P1 = P;     
}

void Jogo::Iniciar()
{
    P1->setbuffer(buffer); // Associa o buffer ao jogador
    Tela1();
}

void Jogo::Tela1()
{
    while (!key[KEY_ESC]) //loop principal.
    {
        P1->Desenha(); // Chama a função Desenha para desenhar o personagem no buffer.
        blit(buffer, screen, 0, 0, 0, 0, 800, 600); // Desenha o buffer na tela.
    
        P1->Movimento(); // Aciona o movimento do personagem.
        clear( buffer ); // Limpa o buffer;
    }
}
