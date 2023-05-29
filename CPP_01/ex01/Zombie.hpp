#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#define NB_ZOMBIES 5

// ************************************************************************** //
//                               Zombie Class                                 //
// ************************************************************************** //

class Zombie
{

private:
        std::string _name;
public:
        Zombie();
        ~Zombie();
        void announce(void) const;
	Zombie& setName(const std::string& name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif /* ZOMBIE_HPP *********************************************************/
