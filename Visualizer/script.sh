g++ -I$LEDAROOT/incl circle.cpp -c
g++ -L$LEDAROOT circle.o -lleda -lX11 -lm
./a.out
