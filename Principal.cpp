#include "Principal.h"

Principal::Principal()
{
    Executar();                      
}

Principal::~Principal()
{
                       
}

void Principal::Executar()
{
    Inicializar(); // método que inicializa os jogadores 
    J.Iniciar(); 
    // cria o jogo e envia como parâmetro (por referência)
    // os dois jogadores.
}

void Principal::Inicializar()
{
    P1.setimg(load_bitmap("Arquivos//Imagens//Objeto1.bmp", NULL));  //carrega a imagem a partir da pasta onde ela está.
    P1.setbuffer(J.getbuffer()); // Associa o buffer ao jogador para que possa se desenhar na tela.
    P1.seth(100); // inicializa a altura da imagem/personagem.
    P1.setl(100); // inicializa a largura da imagem/personagem.
    P1.setx(250); // Posição inicial em x.
    P1.sety(250); // Posição icial em y.
    P1.setvx(1);  // Velocidade icial do objeto em x.
    P1.setvy(1);  // Velocidade icial do objeto em y.
    
    P2.setimg(load_bitmap("Arquivos//Imagens//Objeto2.bmp", NULL));  
    P2.setbuffer(J.getbuffer());
    P2.seth(100); 
    P2.setl(100); 
    P2.setx(450); 
    P2.sety(250); 
    P2.setvx(1);  
    P2.setvy(1);  
    
    J.setjogadores(&P1, &P2); // Associa os jogadores ao jogo.
}
