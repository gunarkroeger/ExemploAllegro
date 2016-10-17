#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico()
{

}

GerenciadorGrafico::~GerenciadorGrafico()
{
                       
}

void GerenciadorGrafico::init()
{
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
	if (res != 0) 
    {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */    
}

void GerenciadorGrafico::deinit()
{
	clear_keybuf();
	/* add other deinitializations here */    
}
