#pragma once
#include <vector>
#include "Theater.h"

/**
 * @brief Class representing a manager for theaters.
 */
class TheaterManager {
	std::vector<Theater> m_theaters; /**< Vector containing all the theaters managed by the manager. */
	Theater m_selectedTheater; /**< The currently selected theater. */
	//MovieRoom m_selectedMovie; // Uncomment if needed in the future

public:
	/**
	 * @brief Constructor for the TheaterManager class.
	 *
	 * Initializes the manager with a vector of theaters.
	 *
	 * @param p_theaters A reference to a vector of theaters.
	 */
	TheaterManager(std::vector<Theater>& p_theaters);

	/**
	 * @brief Get all the movies from the managed theaters.
	 *
	 * @return A vector of MovieRoom containing all the movies from the managed theaters.
	 */
	std::vector<MovieRoom> getAllMovies();

	/**
	 * @brief Get all the movie titles from the managed theaters.
	 *
	 * @return A vector of strings containing all the movie titles from the managed theaters.
	 */
	std::vector<std::string> getAllMoviesAsString();

	/**
	 * @brief Find the theaters that show a specified movie.
	 *
	 * @param p_title The title of the movie to search for.
	 * @return A vector of theaters showing the specified movie.
	 */
	std::vector<Theater> selectMovie(const std::string p_title);

	/**
	 * @brief Select a theater.
	 *
	 * Sets the currently selected theater.
	 *
	 * @param p_selectedTheater The theater to select.
	 */
	void selectTheater(const Theater p_selectedTheater) { m_selectedTheater = p_selectedTheater; }

	/**
	 * @brief Get the currently selected theater.
	 *
	 * @return The currently selected theater.
	 */
	Theater getSelectedTheater() { return m_selectedTheater; }

	/**
	 * @brief Book a seat for a specified movie in a theater.
	 *
	 * @param p_name The name of the theater to book the seat in.
	 * @param p_seat The seat to book.
	 * @return True if the booking was successful, otherwise False.
	 */
	bool bookSeat(const std::string p_name, std::string p_seat);
};

