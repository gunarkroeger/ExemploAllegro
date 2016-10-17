#include "Principal.h"

Principal::Principal()
{
    Executar();                      
}

Principal::~Principal()
{
    Allegro.deinit();                   
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
    Allegro.init(); 
    J.Inicializar();
    
    P1.setimg(load_bitmap("Arquivos//Imagens//Objeto1b.bmp", NULL));  //carrega a imagem a partir da pasta onde ela está.
    P1.setbuffer(J.getbuffer()); // Associa o buffer ao jogador para que possa se desenhar na tela.
    P1.seth(177); // inicializa a altura da imagem/personagem.
    P1.setl(65); // inicializa a largura da imagem/personagem.
    P1.setx(250); // Posição inicial em x.
    P1.sety(250); // Posição icial em y.
    P1.setvx(1);  // Velocidade icial do objeto em x.
    P1.setvy(1);  // Velocidade icial do objeto em y.
    P1.setsx(11); // Posição x do sprite na imagem maior.
    P1.setsy(5);  // Posição y do sprite na imagem maior.
    
    P2.setimg(load_bitmap("Arquivos//Imagens//Objeto2b.bmp", NULL));  
    P2.setbuffer(J.getbuffer());
    P2.seth(177); 
    P2.setl(65); 
    P2.setx(450); 
    P2.sety(250); 
    P2.setvx(1);  
    P2.setvy(1);  
    P2.setsx(11);  
    P2.setsy(5); 
    
    J.setjogadores(&P1, &P2); // Associa os jogadores ao jogo.
}
