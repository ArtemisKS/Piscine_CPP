/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Name.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:51:44 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/14 22:54:47 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Name.hpp>

Name::Name( void )
{
	return ;
}
Name::Name( std::string a, int b ) : ACursesModule(a, b)
{
	return ;
}
Name::Name( std::string a, int b, int c) : ACursesModule(a, b, c)
{
	return ;
}
Name::Name( const Name &toCopy )
{
	*this = toCopy;
}
Name::~Name( void )
{
	return ;
}

Name			&Name::operator=( const Name &toCopy )
{
	ACursesModule::operator=(toCopy);

	return *this;
}

void			Name::display( void ) const
{
	char	hostname[1024];
	size_t	len = sizeof(hostname);
	struct 	passwd *pwd;

	pwd = getpwuid(geteuid());
	mvwprintw(this->_w, _winStStr + 2, 1, "Username: %s", pwd->pw_name);
	if (!sysctlbyname("kern.hostname", &hostname, &len, NULL, 0))
		mvwprintw(this->_w, _winStStr + 4, 1, "Hostname: %s", hostname);

	this->refresh();
}

void			Name::putText(char *s, int x, int y) const
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

void			Name::displaySDL( void ) const
{
	const std::size_t		len = size_x - strlen("Hostname: ") - 1;
	char					name[len];

	gethostname(name, len);
	// std::cout << frame_y << std::endl;
	SDL_Rect rect = {0, frame_y, WIN_X, numCol * s_y_sdl + 30};
	SDL_RenderCopy(GUIDisplay::_renderer, GUIDisplay::_frame, NULL, &rect);
	putText(name, _x, _y + 5);
	putText(getenv("USER"), _x, _y + 25);
}
