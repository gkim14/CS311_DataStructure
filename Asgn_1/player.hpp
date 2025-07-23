/** 
 * player.hpp
 * Grace Kim
 * Sept 8, 2024
 * 
 * Header class for player
 * 
 * Functions are all defined in source file
 */

#ifndef FILE_PLAYER_HPP_INCLUDED
#define FILE_PLAYER_HPP_INCLUDED

#include <ostream>
//for ostream and string

class Player
{
    public:

        //constructors
        Player(); //default ctor
        Player(std::string n, std::string u, int g); //ctor takes name, username, games played

        //getters and setters
        std::string getRealName() const;
        std::string getUsername() const;
        int getGames() const;

        void setRealName(std::string n);
        void setUsername(std::string u);
        void setGames(int g);

        //member functions
        bool inactive() const; //checks gamesPlayed = 0

        std::string toString() const; // returns "name (username): gamesPlayed"

        //operators
        Player& operator++(); //pre; increments gamesPlayed
        Player operator++(int dummy); //post

        Player& operator--(); //pre; decrements gamesPlayed (can't be < 0)
        Player operator--(int dummy); //post


    private:
        //private variables
        std::string name;
        std::string username;
        int gamesPlayed;

}; //end of class

//global operators
bool operator==(const Player& a, const Player& b); //checks if name, username, games are equal
bool operator!=(const Player& a, const Player& b); //opposite of operator==

std::ostream& operator<<(std::ostream& os, const Player& p); //puts p.toString() in ostream

#endif  //#ifndef FILE_PLAYER_HPP_INCLUDED
