/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkThro.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:51:56 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 20:28:03 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NetworkThro.hpp>

NetworkThro::NetworkThro( void )
{
	return ;
}
NetworkThro::NetworkThro( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
NetworkThro::NetworkThro( std::string a, int b , int c) : ACursesModule(a, b, c)
{
	return ;
}
NetworkThro::NetworkThro( const NetworkThro &toCopy )
{
	*this = toCopy;
}
NetworkThro::~NetworkThro( void )
{
	return ;
}

NetworkThro			&NetworkThro::operator=( const NetworkThro &toCopy )
{
	ACursesModule::operator=(toCopy);

	return *this;
}

void				NetworkThro::display( void ) const
{
	int									y = _winStStr;
	const std::string					all = strExec("netstat -i -I en0 -b | awk '{print $5, $7, $8, $10}'");
	const std::vector<std::string>		Avec = ft_explode(all, '\n');
	char								*pEnd;
	long int							Ipac = 0, Ibyt = 0, Opac = 0, Obyt = 0;
	static long int						pastIpac = 0, pastIbyt = 0, pastOpac = 0, pastObyt = 0;

	Ipac = strtol (Avec[1].c_str(), &pEnd, 10);
	Ibyt = strtol (pEnd, &pEnd, 10);
	Opac = strtol (pEnd, &pEnd, 10);
	Obyt = strtol (pEnd, NULL, 10);


	mvwprintw(this->_w, y++, 1, "Input packages: %ld MB", Ipac / 1024);
	mvwprintw(this->_w, y++, 1, "Output packages: %ld MB", Opac / 1024);
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "Ipack/sec: %ld B", (Ipac - pastIpac));
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "Opack/sec: %ld B", (Opac - pastOpac));

	mvwprintw(this->_w, y++, 1, "Total input: %ld MB", Ibyt / 1024 / 1024);
	mvwprintw(this->_w, y++, 1, "Total output: %ld MB", Obyt / 1024 / 1024);
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "Itotal/sec: %ld B", (Ibyt - pastIbyt));
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "Ototal/sec: %ld B", (Obyt - pastObyt));


	pastIpac = Ipac;
	pastIbyt = Ibyt;
	pastOpac = Opac;
	pastObyt = Obyt;

	this->refresh();
}

void			NetworkThro::putText(char const *s, int x, int y) const
{
	if (!*s)
		return ;
	SDL_Color textColor = { 0, 0, 0, 0 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(GUIDisplay::_font, s, textColor);
	SDL_Texture* text = SDL_CreateTextureFromSurface(GUIDisplay::_renderer, textSurface);
	int text_width = textSurface->w;
	int text_height = textSurface->h;
	SDL_FreeSurface(textSurface);
	SDL_Rect renderQuad = {x, y, text_width, text_height};
	SDL_RenderCopy(GUIDisplay::_renderer, text, NULL, &renderQuad);
	SDL_DestroyTexture(text);
}

void			NetworkThro::displaySDL( void ) const
{
	const std::string					all = strExec("netstat -i -I en0 -b | awk '{print $5, $7, $8, $10}'");
	const std::vector<std::string>		Avec = ft_explode(all, '\n');
	char								*pEnd;
	long int							Ipac = 0, Ibyt = 0, Opac = 0, Obyt = 0;
	static long int						pastIpac = 0, pastIbyt = 0, pastOpac = 0, pastObyt = 0;

	Ipac = strtol (Avec[1].c_str(), &pEnd, 10);
	Ibyt = strtol (pEnd, &pEnd, 10);
	Opac = strtol (pEnd, &pEnd, 10);
	Obyt = strtol (pEnd, NULL, 10);



	SDL_Rect rect = {0, frame_y, WIN_X, s_y_sdl * numCol + 30};
	SDL_RenderCopy(GUIDisplay::_renderer, GUIDisplay::_frame, NULL, &rect);
	putText(("Input packages:  " + std::to_string(Ipac / 1024) + "MB").c_str(), _x, _y + 5);

	putText(("Output packages: " + std::to_string(Opac / 1024) + "MB").c_str(), _x, _y + 25);
	putText(("Ipack/sec: " + std::to_string((Ipac - pastIpac))  + "B").c_str(), _x, _y + 45);
	putText(("Opack/sec: " + std::to_string(Opac - pastOpac) + "B").c_str(), _x, _y + 65);
	putText(("Total input: " + std::to_string(Ibyt / 1024 / 1024) + "MB").c_str(), _x, _y + 85);
	putText(("Total output: " + std::to_string(Obyt / 1024 / 1024) + "MB").c_str(), _x, _y + 105);
	putText(("Itotal/sec: " + std::to_string(Ibyt - pastIbyt) + "B").c_str(), _x, _y + 125);
	putText(("Ototal/sec: " + std::to_string(Obyt - pastObyt) + "B").c_str(), _x, _y + 145);


	pastIpac = Ipac;
	pastIbyt = Ibyt;
	pastOpac = Opac;
	pastObyt = Obyt;

}
