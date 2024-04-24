#include "movie.h"

std::string MovieRoom::getMovieAsString() { 
	std::string l_out =
		"Title: " + m_title +
		", Year: " + std::to_string(m_releaseYear) +
		", Duration: " + std::to_string(m_duration);
	return l_out;
};

