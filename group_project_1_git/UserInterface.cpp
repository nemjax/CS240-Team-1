#include <curses.h>

class UserInterface{

    public:
        UserInterface();
        int takeInput(); //returns 0 if the user is finished
        void insertFile();
        int getX();
        int getY();
        int getHeight();
        int getWidth();
        void setX(int);
        void setY(int);
        ~UserInterface();

    private:
        WINDOW* window;
        int x;
        int y;
        int height; //Use these height and width variables for document.cpp as well
        int width; //As the UI changes these may become different than just the size of the screen
        int input; //We may want to do something with this. However I'm not sure we need it. Thoughts?
};

UserInterface::UserInterface(){
    initscr();
    noecho();
    keypad(window, TRUE);

	window = NULL;
    x = 0;
    y = 0;
	height = getmaxy(stdscr);
	width = getmaxx(stdscr);

	window = newwin(height, width, x, y);

	wrefresh(stdscr);
}

int UserInterface::takeInput(){
    input = wgetch(window);

    if(input == KEY_DOWN){
        if(y + 1 < height){
            y++;
        }
        else{
            y = 0;
        }
        wmove(window, y, x);
    }
    else if(input == KEY_UP){
        if(y - 1 >= 0){
            y++;
        }
        else{
            y = height;
        }
        wmove(window, y, x);
    }
    else if(input == KEY_LEFT){
        if(x - 1 >= 0){
            x++;
        }
        else{
            x = width;
        }
        wmove(window, y, x);
    }
    else if(input == KEY_RIGHT){
        if(x + 1 < width){
            x++;
        }
        else{
            x = 0;
        }
        wmove(window, y, x);
    }
    else if(input == KEY_BACKSPACE){
        wdelch(window);
    }
    //else if(input == ???){  Need an idea for a quit key.
    //    return 0;
    //}
    else{
        waddch(window, input);
    }

    wrefresh(window);
    getyx(window, y, x); //updates x and y if char added or deleted

    return 1;
}

void UserInterface::insertFile(){
    //Coming soon after me and William decide exactly how to handle scrolling
}

int UserInterface::getX(){
    return x;
}

int UserInterface::getY(){
    return y;
}

int UserInterface::getHeight(){
    return height;
}

int UserInterface::getWidth(){
    return width;
}

void UserInterface::setX(int x){
    this->x = x;
}

void UserInterface::setY(int y){
    this->y = y
}

UserInterface::~UserInterface(){
    delwin(window);
	endwin();
}

int main(){
    return 0;
}
