#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
using namespace std;

int main(int argc, char **argv) {
   SDL_Window* w;
   
    SDL_Init(SDL_INIT_EVERYTHING);
    w=SDL_CreateWindow("wokaka",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,800,SDL_WINDOW_OPENGL);
    
    cout << "Hello, world!" << std::endl;
    return 0;
}
