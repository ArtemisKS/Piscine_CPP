/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPU.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:51:33 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 20:27:45 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CPU.hpp>

CPU::CPU( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}

CPU::CPU( std::string a, int b, int c ) : ACursesModule(a, b, c)
{
	return ;
}

CPU::CPU( const CPU &toCopy )
{
	*this = toCopy;
}
CPU::~CPU( void )
{
	return ;
}

CPU			&CPU::operator=( const CPU &toCopy )
{
	ACursesModule::operator=(toCopy);

	return *this;
}


void		CPU::display( void ) const
{
	const std::string		proc = strExec("sysctl -n machdep.cpu.brand_string");
	const std::string		proc1 = proc.substr(0, proc.find("(TM) ") + 5);
	const std::string		proc2 = proc.substr(proc.find("(TM) ") + 5);
	const std::string		architecture = strExec("uname -p");
	const std::string		ncores = strExec("sysctl hw.ncpu | sed 's/.*: //'");
	const std::string		usageUser = strExec("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $3;}'");
	const std::string		usageSystem = strExec("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $5;}'");
	const std::string		usageIdle = strExec("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $7;}'");

	int						y = _winStStr;

	mvwprintw(this->_w, y++, (size_x - proc1.length()) / 2, "%s", proc1.c_str());
	mvwprintw(this->_w, y++, (size_x - proc2.length()) / 2, "%s", proc2.c_str());

	mvwprintw(this->_w, y++, 1, "Processor architecture: %s", architecture.c_str());
	mvwprintw(this->_w, y++, 1, "Cores Number: %s", ncores.c_str());
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "CPU usage(user): %s", usageUser.c_str());
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "CPU usage(system): %s", usageSystem.c_str());
	clearLine(y);
	mvwprintw(this->_w, y++, 1, "CPU usage(idle): %s", usageIdle.c_str());
	ACursesModule::refresh();
}

void			CPU::putText(char const *s, int x, int y) const
{
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

void			CPU::displaySDL( void ) const
{
	std::string		proc = strExec("sysctl -n machdep.cpu.brand_string");
	std::string		proc1 = proc.substr(0, proc.find("(TM) ") + 5);
	std::string		proc2 = proc.substr(proc.find("(TM) ") + 5);
	std::string		architecture = strExec("uname -p");
	std::string		ncores = strExec("sysctl hw.ncpu | sed 's/.*: //'");
	std::string		usageUser = strExec("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $3;}'");
	std::string		usageSystem = strExec("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $5;}'");
	std::string		usageIdle = strExec("top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {print $7;}'");

	std::vector<std::string> info;
	info.push_back(proc1);
	info.push_back(proc2);
	info.push_back("Processor architecture: " + architecture);
	info.push_back("Cores Number: " + ncores);
	info.push_back("CPU usage(user): " + usageUser);
	info.push_back("CPU usage(system): " + usageSystem);
	info.push_back("CPU usage(idle): " + usageIdle);

	SDL_Rect rect = {0, frame_y, WIN_X, numCol * 30 + 30};
	SDL_RenderCopy(GUIDisplay::_renderer, GUIDisplay::_frame, NULL, &rect);
	int q = _y;
	for (size_t i = 0; i < info.size(); i++)
	{
		putText(info[i].c_str(), _x, q + 5);
		q += 25;
	}
}
