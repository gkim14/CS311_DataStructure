#include "player.hpp"
#include <iostream>

int main()
{
    const std::string s;
    Player p(s,s,0);
    Player post;
    Player pre;


    //bool b = (p==l);

    std::cout << p++ << " " << ++p << std::endl;
    //returns " (): 0  (): 2"

    return 0;
}