all:main_menu asciiclick 


asciiclick: ./asciiclick/main.cpp 
	g++ ./asciiclick/main.cpp -I./VA-untils/include -o ./build/asciiclick

main_menu: ./main_menu/fun_enum.hpp	./main_menu/funs.cpp	./main_menu/main.cpp
	g++ ./main_menu/main.cpp -I./VA-untils/include -o ./build/main_menu

