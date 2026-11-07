# 🗓️ C++ Task Scheduler

A console-based **Task Scheduler** developed in C++ as part of OOP Practice 10. This application allows users to create, manage, and view tasks based on their scheduled date and time.

The project demonstrates practical implementation of Object-Oriented Programming concepts, dynamic memory allocation, composition, and arrays of objects.

## ✨ Features

- 📝 **Add Tasks:** Create tasks with a date, time, and message.
- 📅 **View Tasks:** Display tasks scheduled for a specific date.
- 📌 **Today's Tasks:** View tasks scheduled for the current date.
- 🔄 **Dynamic Resizing:** Automatically increase array capacity when needed.
- 📂 **Task Management:** Store and manage multiple tasks.
- 🧠 **Memory Management:** Handle dynamic memory allocation and deallocation.

## 🧩 OOP Concepts

| Concept | Implementation |
|---|---|
| 🧱 Composition | Task contains Date, Time, and String objects. |
| 💾 Dynamic Memory Allocation | Scheduler manages a dynamic array of Task objects. |
| 📦 Array of Objects | Multiple tasks are stored in an array. |
| 🔒 Encapsulation | Data and functions are organized into classes. |
| 📋 Deep Copying | Properly handles objects containing dynamic memory. |
| ♻️ Reusability | Reuses existing String, Date, and Time classes. |

## 🏗️ Class Structure

- 🔤 **String:** Manages task messages.
- 📅 **Date:** Handles day, month, and year.
- ⏰ **Time:** Manages hours, minutes, and seconds.
- 📋 **Task:** Combines Date, Time, and String objects to represent a task.
- 🗂️ **Scheduler:** Stores, manages, and displays tasks using a dynamic array.
- 🖥️ **SchedulerApp:** Handles user interaction and application flow.

## 📁 Project Structure

```text
CPP-Task-Scheduler/
│
├── String.h / String.cpp
├── Date.h / Date.cpp
├── Time.h / Time.cpp
├── Task.h / Task.cpp
├── Scheduler.h / Scheduler.cpp
├── SchedulerApp.h / SchedulerApp.cpp
│
├── main.cpp
└── README.md
```

## 🛠️ Technologies Used

- 💻 C++
- 🧩 Object-Oriented Programming (OOP)
- 💾 Dynamic Memory Allocation
- 📦 Arrays of Objects

## 🚀 Key Highlights

- Modular design using multiple interconnected classes.
- Composition to build complex objects.
- Dynamic arrays to manage tasks.
- Proper object copying and memory management.
- Reusable and maintainable class structure.

## 🎓 Assignment Information

- **Course:** CC-211 – Object Oriented Programming
- **Practice:** Practice 10
- **Task:** Task 2 – Scheduler
- **Semester:** Fall 2026
- **Department:** Department of Software Engineering

## 👨‍💻 Author

Developed as part of academic OOP coursework to strengthen C++ programming, memory management, and object-oriented design skills.
