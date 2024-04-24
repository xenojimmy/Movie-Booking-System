### Movie Booking System

The movie booking system allows users to view available movies, select a movie, choose a theater, see available seats, and book seats for a movie.

project_root/
│
├── include/
│   ├── seats.h
│   ├── movie.h
│   ├── Theater.h
│   └── TheaterManager.h
│
├── src/
│   ├── seats.cpp
│   ├── movie.cpp
│   ├── Theater.cpp
│   └── TheaterManager.cpp
│
└── example/
    ├── MainMenu.cpp
    └── CMakeLists.txt


### Instructions

#### Prerequisites
- C++ compiler (e.g., g++, clang++)
- CMake

#### Steps to Compile and Run

1. Clone the repository:

   ```bash
   gh repo clone xenojimmy/Movie-Booking-System
   ```

2. Navigate to the project directory:

   ```bash
   cd MainMenu
   ```

3. Create a build directory:

   ```bash
   mkdir build
   ```

4. Navigate to the build directory:

   ```bash
   cd build
   ```

5. Run CMake to generate build files:

   ```bash
   cmake ..
   ```

6. Compile the project:

   ```bash
   cmake --build .
   ```

7. Run the executable:

   ```bash
   ./MainMenu
   ```

#### Usage

Follow the on-screen instructions to navigate through the movie booking system menu. You can view available movies, select a movie, choose a theater, see available seats, and book seats for a movie.

### Repository Structure

- `src/`: Contains the source code files.
- `CMakeLists.txt`: CMake configuration file for building the project.
- `README.md`: Instructions and information about the project.

### Dependencies

- C++ Standard Library

### License

This project is licensed under the MIT License. See the `LICENSE` file for details.

Feel free to reach out if you have any questions or need further assistance!
