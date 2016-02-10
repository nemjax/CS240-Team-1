/* 
 * File:   document.cpp
 * Author: william
 *
 * Created on February 8, 2016, 6:15 PM
 */

#include <iostream>
#include <fstream>
#include <string>

class document{
    /*
     * possible options in the future:
     * 
     * scroll right/left?
     * "open recent" function? this can come with our double-clickable executable/preferences file
     */
    private:
        std::string documentPath;
        int top;
        int cursorX;
        int cursorY;
        int height;
        int width;
        std::ifstream in;
    
    public:
        
        document(std::string path, int docheight, int docwidth){
            height = docheight;
            width = docwidth;
            open(path);
            top = -1;
            in.open(documentPath.c_str());
        }

        void open(std::string path){
            documentPath = path;
        }

        void save(){
            
        }

        void saveAs(){
            
        }
        
        /*
         * window: a function that takes the current width and height in chars and 
         * returns a std::string containing the text on the screen
         */
        std::string window(){
            if (!in.is_open()){
                printf("error!");//connection to ayca's error code here
            }
            int i = 0;
            std::string window = "";
            while (in.peek() != -1 && i <= height * width){
                if (i > top * width){
                    char c = in.get();
                    window += c;// note the += part...  you need "+=" for chars and "+" for strings
                }
                i++;
            }
            return window;
        }
        
        void scrollUp(){
            if (top > 0){
                top++;
            }
        }
        
        void scrollDown(){
            std::cout << in.end << std::endl;
            
            if (top < 0){
                top--;
            }
        }
        
        void cursorUp(){
            if (cursorY > 1){
                cursorY--;
            }
        }
        
        void cursorDown(){
            if (cursorY < height){
                cursorY++;
            }
        }
        
        void cursorRight(){
            
        }
        
        void cursorLeft(){
            
        }

        ~document(){
            in.close();
        }
};

int main() {
    
    document document("test.txt", 80, 40);
    std::cout << document.window() << std::endl;
    document.scrollDown();
    return 0;
}