#pragma once

#include <string>
#include "seats.h"

/**
 * @brief Class representing a movie room.
 */
class MovieRoom {
private:
	std::string m_title; /**< The title of the movie. */
	int m_releaseYear; /**< The release year of the movie. */
	int m_duration; /**< The duration of the movie in minutes. */

public:
	/**
	 * @brief Default constructor for the MovieRoom class.
	 *
	 * Initializes the movie room with default values and creates a SeatsManager object for managing seats.
	 */
	MovieRoom() :
		m_title(),
		m_releaseYear(),
		m_duration() {
		m_seats = new SeatsManager(20);
	}

	/**
	 * @brief Parameterized constructor for the MovieRoom class.
	 *
	 * Initializes the movie room with the specified title, release year, duration, and creates a SeatsManager object for managing seats.
	 *
	 * @param p_title The title of the movie.
	 * @param p_releaseYear The release year of the movie.
	 * @param p_lengthMinutes The duration of the movie in minutes.
	 */
	MovieRoom(const std::string p_title, const int p_releaseYear, const int p_lengthMinutes) :
		m_title(p_title),
		m_releaseYear(p_releaseYear),
		m_duration(p_lengthMinutes) {
		m_seats = new SeatsManager(20);
	};

	/**
	 * @brief Copy constructor for the MovieRoom class.
	 *
	 * Performs a deep copy of another MovieRoom object, including its SeatsManager object.
	 *
	 * @param other The MovieRoom object to copy.
	 */
	MovieRoom(const MovieRoom& other) :
		m_title(other.m_title),
		m_releaseYear(other.m_releaseYear),
		m_duration(other.m_duration) {
		m_seats = other.m_seats;
	}

	/**
	 * @brief Assignment operator for the MovieRoom class.
	 *
	 * Performs a deep copy of another MovieRoom object, including its SeatsManager object.
	 *
	 * @param other The MovieRoom object to copy.
	 * @return A reference to the current MovieRoom object.
	 */
	MovieRoom& operator=(const MovieRoom& other) {
		if (this != &other) {
			m_title = other.m_title;
			m_releaseYear = other.m_releaseYear;
			m_duration = other.m_duration;
			m_seats = other.m_seats;
		}
		return *this;
	}

	/**
	 * @brief Get the title of the movie.
	 *
	 * @return The title of the movie.
	 */
	std::string getTitle() { return m_title; }

	/**
	 * @brief Get a string representation of the movie.
	 *
	 * @return A string containing information about the movie.
	 */
	std::string getMovieAsString();

	SeatsManager *m_seats; /**< Pointer to the SeatsManager object for managing seats in the movie room. */

};

