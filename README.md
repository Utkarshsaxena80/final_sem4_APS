
# 🧳 Travel Management System (C++)

Welcome to the **Travel Management System** — a command-line C++ program that simplifies the management of your travel needs including **Flights ✈️**, **Hotels 🏨**, **Buses 🚌**, and **Trains 🚆**. It serves as a single-window interface for users to register, search, and book travel and accommodation with ease.

---

## 📋 Table of Contents

1. [About](#about)
2. [Features](#features)
3. [Technologies Used](#technologies-used)
4. [System Requirements](#system-requirements)
5. [Installation & Run Instructions](#installation--run-instructions)
6. [File Structure](#file-structure)
7. [Modules Overview](#modules-overview)
8. [Code Snippets](#code-snippets)
9. [Sample Output](#sample-output)
10. [Limitations](#limitations)
11. [Future Scope](#future-scope)
12. [Credits](#credits)
13. [License](#license)

---

## 📌 About

The Travel Management System is a console-based C++ application built for students and hobbyists who want to practice object-oriented programming (OOP) and understand how management systems are structured. It includes a user-friendly menu-driven interface, mock databases, and animated loading sequences to simulate real-world usage.

---

## ✨ Features

- ✅ Beautiful Welcome Screen with Animation
- ✅ User Registration & Login System
- ✅ Flight Booking & Availability
- ✅ Hotel Listing & Reservation
- ✅ Bus and Train Search Functionality
- ✅ Modular Design Using Classes
- ✅ File-based Data Storage (Optional)
- ✅ Loading and Transition Effects
- ✅ Console Formatting with ASCII Styling

---

## 🛠 Technologies Used

- **Language**: C++
- **Concepts**: OOP (Inheritance, Encapsulation), File I/O, std::thread, std::chrono
- **Compiler**: g++, MinGW, MSVC
- **IDE**: Code::Blocks / Visual Studio / Terminal-based

---

## 💻 System Requirements

- OS: Windows, Linux, or macOS
- Compiler: GCC 4.8+ / MinGW / Visual Studio C++
- RAM: Minimum 512MB
- C++11 or higher support

---

## 🚀 Installation & Run Instructions

### 🧱 Step 1: Clone or Download
```bash
git clone https://github.com/yourusername/travel-management-system.git
cd travel-management-system
```

### ⚙️ Step 2: Compile

#### On Linux/Mac using `g++`
```bash
g++ -std=c++11 main.cpp -o travel
./travel
```

#### On Windows using MinGW
```bash
g++ -std=c++11 main.cpp -o travel.exe
travel.exe
```

#### On Windows using Visual Studio
- Open `main.cpp` in Visual Studio
- Set project settings to use `/std:c++11` or later
- Build and run the project

---

## 🗂 File Structure

```
📁 travel-management-system/
│
├── main.cpp              # Main application logic
├── README.md             # Project documentation
├── flights.cpp/.h        # Handles flight booking (optional)
├── hotels.cpp/.h         # Hotel management module (optional)
├── buses.cpp/.h          # Bus booking module (optional)
├── trains.cpp/.h         # Train schedules (optional)
├── users.cpp/.h          # User registration and login
├── data/                 # Folder to store booking data (optional)
│   ├── flights.txt
│   ├── hotels.txt
│   └── users.txt
└── assets/               # ASCII logos or sample data
```

---

## 🧩 Modules Overview

### 🔐 User Module
- Register new users
- Simple login system
- Basic input validation

### ✈️ Flights Module
- Show available flights
- Book or cancel a seat
- View travel summary

### 🏨 Hotels Module
- Search by city
- Reserve hotel rooms
- Price comparison

### 🚌 Bus & 🚆 Train Module
- Schedule display
- Seat selection
- Booking confirmation

---

## 🔎 Code Snippets

### Welcome Animation

```cpp
std::cout << "Loading system";
for (int i = 0; i < 3; ++i) {
    std::cout << ".";
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
```

### Simple User Class

```cpp
class User {
public:
    string name, email;
    void registerUser();
    void loginUser();
};
```

### Booking Summary Output

```cpp
cout << "Flight booked to: " << destination << endl;
cout << "Passenger Name : " << user.name << endl;
cout << "Departure Time : " << time << endl;
```

---

## 🖥 Sample Output

```
===============================================
         WELCOME TO TRAVEL MANAGEMENT SYSTEM   
===============================================
   ✈️  Flights   🏨 Hotels   🚌 Buses   🚆 Trains   
-----------------------------------------------
Explore. Book. Travel — All in one place!
===============================================

Loading system...

Main Menu:
1. Register
2. Login
3. Book Flight
4. Search Hotels
5. Exit
```

---

## ⚠️ Limitations

- No actual API or live ticket booking
- Not connected to a database (uses dummy data or text files)
- No encryption in user login
- Works on terminal only (no GUI)

---

## 🌱 Future Scope

- GUI version using Qt or SFML
- Real-time data via REST API
- Cross-platform desktop app
- Add payment gateway simulation
- Add travel history and cancellation policies

---

## 🙌 Credits

- Built by: **Utkarsh Saxena , Gaurav Rao , Mrigank Rai , Sharad **
- Institution: Jaypee Institute of Information Technology
- Inspired by: Real-world ticketing platforms (IRCTC, MakeMyTrip, RedBus)
- Special thanks to: C++ Community, Stack Overflow, and Open Source Contributors

---

## 📝 License

This project is open-source and available under the [MIT License](LICENSE).
