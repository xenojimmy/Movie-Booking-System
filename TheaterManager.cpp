#include "TheaterManager.h"



TheaterManager::TheaterManager(std::vector<Theater>& p_theaters) {

	for (auto l_theater_it = p_theaters.begin(); l_theater_it != p_theaters.end(); l_theater_it++) {
		m_theaters.push_back(*l_theater_it);
	}
}

std::vector<MovieRoom>  TheaterManager::getAllMovies() {
	std::vector<MovieRoom> l_output;
	for (auto l_theater_it = m_theaters.begin(); l_theater_it != m_theaters.end(); l_theater_it++) {
		std::vector<MovieRoom> l_moviesPart = l_theater_it->getAllMovies();
		l_output.insert(l_output.end(), l_moviesPart.begin(), l_moviesPart.end());
	}

	return l_output;
}


std::vector<std::string>  TheaterManager::getAllMoviesAsString() {
	std::vector<std::string> l_output;
	for (auto l_theater_it = m_theaters.begin(); l_theater_it != m_theaters.end(); l_theater_it++) {
		std::vector<std::string> l_moviesPart = l_theater_it->getAllMoviesAsString();
		l_output.insert(l_output.end(), l_moviesPart.begin(), l_moviesPart.end());
	}
	return l_output;
}

std::vector<Theater>  TheaterManager::selectMovie(const std::string p_title) {
	std::vector<Theater> l_output;
	for (auto l_theater_it = m_theaters.begin(); l_theater_it != m_theaters.end(); l_theater_it++) {
		if ((*l_theater_it).isMovieinList(p_title))
			l_output.push_back(*l_theater_it);
	}
	return l_output;
}

