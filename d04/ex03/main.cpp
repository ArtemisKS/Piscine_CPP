/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:17:32 by akupriia          #+#    #+#             */
/*   Updated: 2018/10/06 22:19:02 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int 	main()
{
	IMateriaSource* src = new MateriaSource();
	AMateria* tmp;

	std::cout << "---> Try to create new Materias from Materia Source:" << std::endl;
	tmp = src->createMateria("ice");

	std::cout << std::endl << "---> Fill up Materia Source with new Materias:" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter* zaz = new Character("zaz");
	ICharacter* bob = new Character("bob");

	std::cout << std::endl << "---> Equip Character with new Materias created from Materia Source:" << std::endl;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);
	zaz->equip(tmp);
	zaz->equip(tmp);
	zaz->equip(tmp);

	std::cout << std::endl << "---> Attack Bob with Materias :" << std::endl;
	zaz->use(0, *bob);
	zaz->use(1, *bob);
	zaz->use(2, *bob);
	zaz->use(2, *bob);
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	zaz->use(0, *bob);

	std::cout << std::endl << "---> Unequip all Materias :" << std::endl;
	zaz->unequip(3);
	zaz->unequip(2);

	delete bob;
	delete zaz;
	delete src;

	return 0;
}