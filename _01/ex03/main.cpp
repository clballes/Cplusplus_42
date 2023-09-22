#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
// int main()
// {
//     //inicialitzem la weapon amb el tipus de sword
//     std::string initialType = "Sword";
//     Weapon swordWeapon(initialType); 
    
//     //creem typeref per a que retorni el valor de type
//     const std::string& typeRef = swordWeapon.getType();
//     std::cout << "Initial Type: " << typeRef << std::endl;

//     //tenim un altre type q sera martillo y fem que canvii el valor de _type de la class, passantly la ref, no el valor. encara uqe passantli el valor tambe funiciona
//     std::string newType = "martillo";
//     const std::string& refNewtype = newType;
//     swordWeapon.setType(refNewtype);  // Set a new type for the Weapon object

//     //Creem una altre referncia per retornar el valor de fer el get altre cop i retornar el valor de martillo.
//     const std::string& updatedTypeRef = swordWeapon.getType();  // Get the updated type
//     std::cout << "Updated Type: " << updatedTypeRef << std::endl;

//     //call HUMAN_A
//     HumanA humanA("John", "Sword");
//     humanA.attack();

//     //CALL HUMAN_B
//     HumanB humanB("Clara");
//     humanB.attack();
//     return (0);
// }
