#pragma once
#include <string>
#include <vector>
#include <map>
#include <mutex>


class SeatsManager {
private:
	std::map<std::string,bool> m_seats;
	int m_Nseats;	
	std::mutex m_mutex;

public:
	SeatsManager(const int p_Nseats);
	bool set(const std::string p_ID);
	bool get(const std::string p_ID, bool p_status);
	bool reset(const std::string p_ID);

	std::vector<std::string> getAllFreeSeats();
};
