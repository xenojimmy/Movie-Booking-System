#include"seats.h"


SeatsManager::SeatsManager(const int p_Nseats) {
	m_Nseats = p_Nseats;
	const int l_Ncols = 4;

	for (int i = 0; i < m_Nseats; i++) {		//init seats row is char[A:Z] , col is int [1:Ncol]
		m_seats[
			char(65 + (i % l_Ncols)) + 
			std::to_string((i + 1) / l_Ncols)] 
			= false;	
	}
}


bool SeatsManager::set(const std::string p_seatID) {
	std::lock_guard<std::mutex> lock(m_mutex);  //mutex
	bool l_output = false;
	auto l_seatIt = m_seats.find(p_seatID);
	if (l_seatIt != m_seats.end()) {
		if (l_seatIt->second != true) {			//seat exists and is free
			l_seatIt->second  = true;
			l_output = true;
		}
	}	
	return l_output;
}

bool SeatsManager::get(const std::string p_seatID, bool p_status) {
	std::lock_guard<std::mutex> lock(m_mutex);	//mutex
	bool l_output = false;
	auto l_seatIt = m_seats.find(p_seatID);
	if (l_seatIt != m_seats.end()) {			//seat exists
		p_status = l_seatIt->second;
		l_output = true;
	}
	return l_output;
}


bool SeatsManager::reset(const std::string p_seatID) {
	std::lock_guard<std::mutex> lock(m_mutex);	//mutex
	bool l_output = false;
	auto l_seatIt = m_seats.find(p_seatID);
	if (l_seatIt != m_seats.end()) {			//seat exists and is not free
		if (l_seatIt->second != false) {
			l_seatIt->second = false;
			l_output = true;
		}
	}
	return l_output;
}
std::vector<std::string> SeatsManager::getAllFreeSeats() {
	std::lock_guard<std::mutex> lock(m_mutex); //mutex
	std::vector<std::string> l_availableSeats;
	for (const auto& l_seat_it : m_seats) {
		if (!l_seat_it.second) {
			l_availableSeats.push_back(l_seat_it.first);
		}
	}
	return l_availableSeats;
}
