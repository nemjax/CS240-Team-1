# CS240-Team-1

###################################
       TEAM 1'S EDITOR
       Release Date: 03/10/2016
       Version 1.00
###################################


Team 1's Editor is written in C++ used NCursor Library handled by two main functions.


--------------
Funtions:
--------------

UserInterface::UserInterface(std::string p) – takes a string p and creates a UserInterface object using p as the path for the input file. If not string is given, path is not set at object creation

UserInterface::takeInput() - takes user input and adds it to the current line. Returns 1 for successful completion, 0 for unsuccessful

UserInterface::getX() - returns x position of cursor

UserInterface::getY() - returns y position of cursor

UserInterface::getHeight() - returns height of the window

UserInterface::getWidth() - returns width of the window

UserInterface::setX(int x) – takes an integer x and sets the x position of the cursor to x

UserInterface::setY(int y) – takes an integer y and sets the y position of the cursor to y

UserInterface::~UserInterface() - destroys the UserInterface object, as well as the window associated with it

UserInterface::resetScreen() - erases the screen's contents and redraws the contents, preventing screen repeating

document::document(std::string path) – creates a document object, setting the path of the file to path

document::load() - attempts to open the document's path and read the contents into a std::string, which is then added to a std::vector, which is returned.

document::open(std::string path) – changes the current document's path to the inputted path

document::save(std::string contents) - saves the contents of the current document to the document path

document::saveAs(std::string contents, std::string path) – sets the current document's path to path and then saves the contents to that path

document::revert() - provides identical functionality to the load functional

document::~document() - destroys the current document object and then closes the input stream.
