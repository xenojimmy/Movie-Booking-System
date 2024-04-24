#include "Theater.h"





Theater::Theater(const std::string p_name, const std::vector<MovieRoom> p_movies) {
	m_name = p_name;
	for (auto l_it = p_movies.begin(); l_it != p_movies.end(); l_it++) {
		m_movies.push_back(*l_it);
	}


}

MovieRoom Theater::getMovie(const std::string p_title) {
	MovieRoom l_output;
	for (auto l_movie_it = m_movies.begin(); l_movie_it != m_movies.end(); l_movie_it++) {
		if (l_movie_it->getTitle() == p_title) {
			l_output = *l_movie_it;
		}
	}
	return l_output;
}



std::vector<MovieRoom> Theater::getAllMovies() {
	std::vector<MovieRoom> l_output;
	for (auto l_movie_it = m_movies.begin(); l_movie_it != m_movies.end(); l_movie_it++) {
		l_output.push_back(*l_movie_it);
	}
	return l_output;
}


std::vector<std::string> Theater::getAllMoviesAsString() {
	std::vector<std::string> l_output;
	for (auto l_movie_it = m_movies.begin(); l_movie_it != m_movies.end(); l_movie_it++) {
		l_output.push_back(m_name + " - " + l_movie_it->getMovieAsString());
	}
	return l_output;
}


bool Theater::isMovieinList(const std::string p_movieTitle) {
	bool l_output = false;
	for (auto l_movie_it = m_movies.begin(); l_movie_it != m_movies.end(); l_movie_it++) {
		if (l_movie_it->getTitle() == p_movieTitle) {
			l_output = true;
			break;
		}
	}
	return l_output;
}

