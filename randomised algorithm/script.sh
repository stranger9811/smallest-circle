input="8000"
echo $input > inp
g++ random_point_generator.cpp
./a.out < inp
g++ -I$LEDAROOT/incl circle.cpp -c
g++ -L$LEDAROOT circle.o -lleda -lX11 -lm
./a.out 

