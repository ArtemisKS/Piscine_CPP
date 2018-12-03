#include "Window.hpp"

Window::Window(): sound(1), score(0), level(1), delay(30000), hero(Hero()), input(ERR), lastInput(ERR), timeFrame(0), HEIGHT(WINH), WIDTH(WINW), WSTARTX(STARTX), WSTARTY(STARTY) {
    for (int i = 0; i < 1000; i++)
    {
        if (i < 100)
        {
            elements[i] = NULL;
            stars[i] = NULL;
        }
        bullets[i] = NULL;
        ebullets[i] = NULL;
    }
	initscr();
    keypad(stdscr, true);
    noecho();
    timeout(0);
    cbreak();
    gettimeofday(&start_time, NULL);
    curs_set(false);
    refresh();
    window = newwin(HEIGHT, WIDTH, WSTARTY, WSTARTX);
    box(window, 0 , 0);
    wrefresh(window);;
    printScreen();
}

Window const &	Window::operator=(Window const & rhs) {
    this->input = rhs.input;
    this->lastInput = rhs.lastInput;
    this->start_time = rhs.start_time;
    this->curr_time = rhs.curr_time;
	return *this;
}

Window::Window(Window const & src): sound(1), score(0), level(1), delay(30000), hero(Hero()), input(ERR), lastInput(ERR), HEIGHT(WINH), WIDTH(WINW), WSTARTX(STARTX), WSTARTY(STARTY) {
    for (int i = 0; i < 1000; i++)
    {
        if (i < 100)
        {
            elements[i] = NULL;
            stars[i] = NULL;
        }
        bullets[i] = NULL;
        ebullets[i] = NULL;
    }
	initscr();
    keypad(stdscr, true);
    noecho();
    timeout(0);
    cbreak();
    gettimeofday(&start_time, NULL);
    curs_set(false);
    refresh();
    window = newwin(HEIGHT, WIDTH, WSTARTY, WSTARTX);
    box(window, 0 , 0);
    wrefresh(window);
    printScreen();
	*this = src;
}

Window::~Window() {
    wrefresh(window);
    clear();
    refresh();
    delwin(window);
    endwin();
}

void    Window::shoot_yeah(int x, int y) {
    for (int i = 0; i < 1000; i++) {
        if(bullets[i] == NULL)
        {
            bullets[i] = new Bullet(x, y);
            return;
        }
    }
}

void    Window::enemyBullets(int x, int y) {
    int i = -1;
    while (++i < 1000)
        if(ebullets[i] == NULL)
        {
            ebullets[i] = new EnemyBullet(x - 2, y);
            return ;
        }
}

void    Window::moveScreenObj(AObject* elem[], int num) {
    int i = -1;
    while (++i < num)
        if (elem[i] && (!elem[i]->move(timeFrame)))
        {
           	delete elem[i];
            elem[i] = NULL;
        }
}

void    Window::moveElems(int const input) {
    hero.move(input, timeFrame);
    if (input == 32){
        shoot_yeah(hero.getX(), hero.getY());
        if (sound)
            system("afplay BLAST.mp3 &");
    }
    moveScreenObj(stars, 100);
    moveScreenObj(elements, 100);
    moveScreenObj(bullets, 1000);
    moveScreenObj(ebullets, 1000);
    for (int i = 0; i < 100; i++)
        if (elements[i] && ((rand() % 125) == 1))
            enemyBullets(elements[i]->getX(), elements[i]->getY());
}

void    Window::printScreen() {
    mvprintw(4, 5, "YOUR SCORE: ");
    mvprintw(4, 17, "%d", score);
    mvprintw(4, WIDTH/2 - 3, "LEVEL: ");
    mvprintw(4, WIDTH/2 + 4, "%d", level);
    mvprintw(4, WIDTH + 2, "%d", hero.lives);
    mvprintw(4, WIDTH - 7, "YOUR HP: ");
    hero.print();
    int i = -1;
    while (++i < 1000)
    {
        if (i < 100)
        {
            if (elements[i])
                elements[i]->print();
            if (stars[i])
                stars[i]->print();
        }
        if (ebullets[i])
            ebullets[i]->print();
        if (bullets[i])
            bullets[i]->print();
    }
}

void    Window::delScreen() {
    char s[4] = {' ', ' ', ' ', 0};
    mvprintw(4, 17, s);
    mvprintw(4, WIDTH/2 + 4, s);
    mvprintw(4, WIDTH + 2, s);
    hero.del();
    int i = -1;
    while (++i < 1000)
    {
        if (i < 100)
        {
            if (elements[i])
                elements[i]->del();
            if (stars[i])
                stars[i]->del();
        }
        if (ebullets[i])
            ebullets[i]->del();
        if (bullets[i])
            bullets[i]->del();
    }
}

int     Window::collide_bullets() {
    int j;
    int i = -1;
    while (++i < 1000)
    {
        j = -1;
        while (++j < 100 && bullets[i])
            if (elements[j] && bullets[i]->colision(elements[j]))
            {
                delete bullets[i];
                bullets[i] = NULL;  
                delete elements[j];
                elements[j] = NULL;
                score += 5;
            }
    }
    return (0);
}

int     Window::collide_enemies() {
    for (int i = 0; i < 1000; i++)
    {
        if (ebullets[i] && hero.colision(ebullets[i]))
        {
            delete ebullets[i];
            ebullets[i] = NULL;
            hero.lives--;
            if (sound)
                system("afplay SCREAM_4.mp3 &");
        }
    }
    for (int i = 0; i < 100; i++) {
        if (elements[i] && hero.colision(elements[i]))
        {
            delete elements[i];
            elements[i] = NULL;
            hero.lives--;
            if (sound )
                system("afplay SCREAM_4.mp3 &");
        }
    }
    return (0);
}

int     Window::collide() {
    collide_bullets();
    collide_enemies();
    if (score && score % NEXTLVL == 0)     {
        level++;
        score += 5;
        delay = (delay > 5000) ? delay - 5000 : 5000;
    }
    if (hero.lives < 1)
            return (1);
    return (0);
}

int   Window::pause() {
    mvprintw(HEIGHT/2, WIDTH/2 + WIDTH/30, "PAUSE");
    while (1) 
    {
        input = getch();
        if (input == 112)
            break;
        else if (input == 27)
            return (1); 
    }
    mvprintw(HEIGHT/2, WIDTH/2 + WIDTH/30, "     ");
    return (0);
}

int    Window::checkTime() {
    delScreen();
    int y;
    int i;
    if (timeFrame % 21 == 0)
    {
        y = (rand() % (HEIGHT - 2)) + 6;
        i = -1;
        while (++i < 100)
            if (!elements[i]) {
                elements[i] = new Enemy(WIDTH + STARTX - 2, y);
                break ;
            }
    }
    if (timeFrame % 11 == 0)
    {
        y = (rand() % (HEIGHT - 2)) + 6;
        i = -1;
        while (++i < 100)
            if (!stars[i]) {
                stars[i] = new Star(WIDTH - 1, y);
                break ;
            }
    }
    moveElems(lastInput);
    printScreen();
    if (collide())
        return (1);
    lastInput = ERR;
    start_time = curr_time;
    timeFrame++;
    return (0);
}

void    Window::check_result(int lose, int win) {
    int input;
    printScreen();
    if (lose) {
        mvprintw(25 + 1, 63, "__   __            _           _   _ ");
        mvprintw(25 + 2, 63, "\\ \\ / /           | |         | | | |");
        mvprintw(25 + 3, 63, " \\ V /___  _   _  | | ___  ___| |_| |");
        mvprintw(25 + 4, 63, "  \\ // _ \\| | | | | |/ _ \\/ __| __| |");
        mvprintw(25 + 5, 63, "  | | (_) | |_| | | | (_) \\__ \\ |_|_|");
        mvprintw(25 + 6, 63, "  \\_/\\___/ \\__,_| |_|\\___/|___/\\__(_)");
        input = getch();
        while (input != 27)
            input = getch();  
    }
    else if (win) {
        mvprintw(25 + 1, 63, "__   __                     _       _ ");
        mvprintw(25 + 2, 63, "\\ \\ / /                    (_)     | |");
        mvprintw(25 + 3, 63, " \\ V /___  _   _  __      ___ _ __ | |");
        mvprintw(25 + 4, 63, "  \\ // _ \\| | | | \\ \\ /\\ / / | '_ \\| |");
        mvprintw(25 + 5, 63, "  | | (_) | |_| |  \\ V  V /| | | | |_|");
        mvprintw(25 + 6, 63, "  \\_/\\___/ \\__,_|   \\_/\\_/ |_|_| |_(_)");
        input = getch();
        while (input != 27)
            input = getch();    
    }
}

void	Window::play() {

    bool win = false;
    bool lose = false;
    input = getch();
    while (input != 27) {
        if (score >= WIN_SCORE) {
            win = true;
            break;
        }
        int x = 0;
        int y = 0;
        getmaxyx(stdscr, y, x);
        if (x < WIDTH || y < HEIGHT)
            return ;
        input = getch();
        if (input == KEY_HOME)
            sound = (sound) ? 0 : 1;
        if (input == 112)
            if (pause())
                break; 
        if (input != ERR)
            lastInput = input;
        gettimeofday(&curr_time, NULL);
        if (TIME_VAL(start_time, curr_time) >= delay) 
            if (checkTime()) {
                lose = true;
                break;
            }
    }
    check_result(lose, win);
}
