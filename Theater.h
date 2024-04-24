#pragma once

#include <vector>
#include "movie.h"
#include "seats.h"

/**
 * @brief Class representing a theater.
 */
class Theater {
private:
	std::string m_name; /**< The name of the theater. */
	std::vector<MovieRoom> m_movies; /**< Vector containing all the movies in the theater. */

public:
	/**
	 * @brief Default constructor for the Theater class.
	 */
	Theater() : m_name(), m_movies() {};

	/**
	 * @brief Constructor for the Theater class.
	 *
	 * @param p_name The name of the theater.
	 * @param p_movies A vector of MovieRoom representing the movies in the theater.
	 */
	Theater(const std::string p_name, std::vector<MovieRoom> p_movies);

	/**
	 * @brief Get all the movies in the theater.
	 *
	 * @return A vector of MovieRoom containing all the movies in the theater.
	 */
	std::vector<MovieRoom> getAllMovies();

	/**
	 * @brief Get all the movie titles in the theater.
	 *
	 * @return A vector of strings containing all the movie titles in the theater.
	 */
	std::vector<std::string> getAllMoviesAsString();

	/**
	 * @brief Get a specific movie by its title.
	 *
	 * @param p_title The title of the movie to retrieve.
	 * @return The MovieRoom object representing the movie with the given title.
	 */
	MovieRoom getMovie(const std::string p_title);

	/**
	 * @brief Check if a movie is in the theater's movie list.
	 *
	 * @param p_movieTitle The title of the movie to search for.
	 * @return True if the movie is in the list, otherwise False.
	 */
	bool isMovieinList(const std::string p_movieTitle);

	/**
	 * @brief Get the name of the theater.
	 *
	 * @return The name of the theater.
	 */
	std::string getName() { return m_name; }
};
