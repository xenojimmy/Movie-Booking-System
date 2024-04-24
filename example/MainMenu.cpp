// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <vector>
#include "TheaterManager.h"

using namespace std;

// Sample movies data for different theaters
std::vector<MovieRoom> movies1 = {
	   {"The Shawshank Redemption", 1994, 142},
	   {"The Godfather", 1972, 175},
	   {"The Dark Knight", 2008, 152},
	   {"Schindler's List", 1993, 195},
	   {"Pulp Fiction", 1994, 154},
	   {"The Lord of the Rings: The Return of the King", 2003, 201},
	   {"The Good, the Bad and the Ugly", 1966, 178},
	   {"Fight Club", 1999, 139},
	   {"City of God", 2002, 130}
};
std::vector<MovieRoom> movies2 = {
   {"The Lord of the Rings: The Return of the King", 2003, 201},
   {"The Good, the Bad and the Ugly", 1966, 178},
   {"Fight Club", 1999, 139},
   {"Forrest Gump", 1994, 142},
   {"Inception", 2010, 148},
   {"The Matrix", 1999, 136},
   {"City of God", 2002, 130}
};

std::vector<MovieRoom> movies3 = {
   {"The Shawshank Redemption", 1994, 142},
   {"The Godfather", 1972, 175},
   {"The Dark Knight", 2008, 152},
   {"Inception", 2010, 148},
   {"The Matrix", 1999, 136},
   {"City of God", 2002, 130}
};

std::vector<Theater> l_theaters = {
  {"Cinema Hall", movies1},
  {"Cinema Arcobaleno", movies2},
  {"Cinema Modernissimo", movies3}
};

// Function to display the main menu
void displayMenu() {
	std::cout << endl << endl << endl;
	std::cout << "Welcome to the Movie Booking System" << std::endl;
	std::cout << "1. View all playing movies" << std::endl;
	std::cout << "2. Select a movie" << std::endl;
	std::cout << "3. See all theaters showing the selected movie" << std::endl;
	std::cout << "4. Select a theater" << std::endl;
	std::cout << "5. See available seats for the selected theater & movie" << std::endl;
	std::cout << "6. Book one or more available seats" << std::endl;
	std::cout << "7. Exit" << std::endl;
}

// Main function
int main()
{

	TheaterManager l_mainMenu(l_theaters); // Initialize TheaterManager with theaters data
	std::vector<Theater> l_theatersWithMovie;
	std::vector<MovieRoom> l_allMovies;
	MovieRoom l_selectedMovie;
	SeatsManager *l_seats = nullptr;
	std::vector<std::string> l_freeSeats;

	int choice;
	int l_movie_index = 0;
	int l_theater_index = 0;
	string l_seatID;

	do {
		displayMenu();
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "View all playing movies" << std::endl;

			l_allMovies = l_mainMenu.getAllMovies();
			for (auto l_string_it = l_allMovies.begin(); l_string_it != l_allMovies.end(); l_string_it++)
				std::cout << l_string_it->getMovieAsString() << endl;
			break;

		case 2:
			std::cout << "Select a movie" << std::endl;

			std::cin >> l_movie_index;
			l_selectedMovie = l_allMovies[l_movie_index];
			cout << "selected: " << l_selectedMovie.getTitle() << endl;
			break;

		case 3:
			std::cout << "See all theaters showing the selected movie" << std::endl;

			l_theatersWithMovie = l_mainMenu.selectMovie(l_selectedMovie.getTitle());

			for (auto l_it = l_theatersWithMovie.begin(); l_it != l_theatersWithMovie.end(); l_it++)
				cout << "this theater has got the movie: " << l_it->getName() << endl;
			break;

		case 4:
			std::cout << "Select a theater" << std::endl;

			std::cin >> l_theater_index;
			l_mainMenu.selectTheater(l_theatersWithMovie[l_theater_index]);
			cout << "you selected " << l_mainMenu.getSelectedTheater().getName() << endl;
			l_seats = l_mainMenu.getSelectedTheater().getMovie(l_selectedMovie.getTitle()).m_seats;


			break;

		case 5:
			std::cout << "See available seats for the selected theater & movie" << std::endl;
			if (l_seats != nullptr) {
				l_freeSeats = l_seats->getAllFreeSeats();
				for (auto l_it = l_freeSeats.begin(); l_it != l_freeSeats.end(); l_it++)
					cout << "this seat is free: " << *l_it << endl;
			}
			break;

		case 6:
			std::cout << "Book one or more available seats" << std::endl;
			if (l_seats != nullptr) {
				std::cin >> l_seatID;
				cout << "Reservation " << l_seatID << (l_seats->set(l_seatID) ? " DONE!" : " FAILED") << endl;

			}
			break;
		case 7:
			std::cout << "Exiting..." << std::endl;
			//setup
			system("PAUSE");
			break;
		default:
			std::cout << "Invalid choice. Please enter a number between 1 and 7." << std::endl;
			choice = 1;
			break;
		}
	} while (choice != 7);

	return 0;
}
