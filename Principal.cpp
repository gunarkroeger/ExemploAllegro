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
    J.setpersonagem(&P);  // Associa o personagem ao jogo.
    J.Iniciar(); 
    // cria o jogo e envia o personagem como parâmetro (por referência)
    
}
