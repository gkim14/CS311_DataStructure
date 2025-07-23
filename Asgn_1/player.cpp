// player.cpp
// Grace Kim
// Sept 8, 2024
//
// Source for class Player 
// Player: real name, username, and games played

#include "player.hpp"
#include <ostream>
//for ostream and string 
#include <cassert>
//for asserts


// definition of member functions

//constructors
Player::Player()
    :name{"UNKNOWN"},
     username{"UNKNOWN"},
     gamesPlayed{0}
{
    //intentional blank space
}

Player::Player(std::string n, std::string u, int g)
    :name{n}, 
     username{u},
     gamesPlayed{g}
{
    assert(g >= 0);
}

//getters and setters
std::string Player::getRealName() const
{
    return name;
}

std::string Player::getUsername() const
{
    return username;
}

int Player::getGames() const
{
    assert(gamesPlayed>=0);

    return gamesPlayed;
}

void Player::setRealName(std::string n)
{
    name = n;
} 

void Player::setUsername(std::string u)
{
    username = u;
}

void Player::setGames(int g)
{
    assert(g>=0);

    gamesPlayed = g;
}

//member functions
bool Player::inactive() const
{
    assert(gamesPlayed>=0);

    return (gamesPlayed == 0);
}

std::string Player::toString() const
{
    assert(gamesPlayed>=0);

    return name + " (" + username + "): " + std::to_string(gamesPlayed);
}

//operators

//pre
Player& Player::operator++()
{
    assert(gamesPlayed >= 0);

    ++gamesPlayed;
    return *this;
}

//post
Player Player::operator++([[maybe_unused]]int dummy)
{
    assert(gamesPlayed >= 0);

    Player save = *this;
    ++(*this);
    return save;
}

//pre
Player& Player::operator--()
{
    assert(gamesPlayed >= 0);

    if(gamesPlayed!=0)
        --gamesPlayed;

    return *this;
}

//post
Player Player::operator--([[maybe_unused]]int dummy)
{
    assert(gamesPlayed >= 0);

    Player save = *this;
    --(*this);
    return save;
} 


//definition of global functions

//global operators
bool operator==(const Player& a, const Player& b)
{
    assert(a.getGames()>=0 && b.getGames() >= 0);

    return (a.getRealName() == b.getRealName()) && (a.getUsername() == b.getUsername())
                && (a.getGames() == b.getGames());
}

bool operator!=(const Player& a, const Player& b)
{
    assert(a.getGames()>=0 && b.getGames() >= 0);

    return !(a == b);
}


std::ostream& operator<<(std::ostream& os, const Player& p)
{
    assert(p.getGames()>=0);

    os << p.toString();

    return os;
}

