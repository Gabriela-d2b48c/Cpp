/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:34:57 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/17 15:28:25 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
// Should give a compile error about the class being abstract
	// Animal testAnimal;

// Testing animal creation and deletion
	{
		const Animal* aDog = new Dog();
		const Animal* aCat = new Cat();
// should not create a leak
		delete aDog;
		delete aCat;
	}

// Testing deep copy and array of animals
	{
// Creating individual animals and their copies
		Dog dogOriginal;
		Dog dogCopy = dogOriginal;  // Using copy constructor
		Dog dogAssigned;
		dogAssigned = dogOriginal;  // Using copy assignment operator

		Cat catOriginal;
		Cat catCopy = catOriginal;  // Using copy constructor
		Cat catAssigned;
		catAssigned = catOriginal;  // Using copy assignment operator

		// Animal array
		const int numAnimals = 4;
		Animal* animals[numAnimals];
		int i = 0;
		while (i < numAnimals / 2)
		{
			animals[i] = new Dog();
			i++;
		}
		while (i < numAnimals)
		{
			animals[i] = new Cat();
			i++;
		}

		// Show brain address for all animals
		std::cout << "Testing that each cat/dog has it's brain:" << std::endl;
		dogOriginal.brainAddress();
		dogCopy.brainAddress();
		dogAssigned.brainAddress();
		catOriginal.brainAddress();
		catCopy.brainAddress();
		catAssigned.brainAddress();

		std::cout << "Testing animals in array:" << std::endl;
		i = 0;
		while (i < numAnimals)
		{
			animals[i]->brainAddress();
			i++;
		}

		// Clean up
		std::cout << "Deleting animals:" << std::endl;
		i = 0;
		while (i < numAnimals)
		{
			delete animals[i];
			i++;
		}
	}

	return 0;
}
