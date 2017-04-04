#!/bin/bash

g++ -std=c++11 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -framework Carbon -lglfw -lGLEW *.cpp && ./a.out 


