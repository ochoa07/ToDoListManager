#include <iostream>
#include <vector>
#include <fstream>
#include "Task.h"
using namespace std;


// This is the "brain" or control center of the entire program.
 
// It handles the user menu, input, output, and uses the Task class
// to store and manage all tasks inside a vector (STL data structure).
 
// It also demonstrates key C++ concepts:
// - Conditionals (if / else if)
// - Loops (while / for)
// - Functions (modular structure)
// - Classes (Task class)
// - STL (vector<Task>)
// - File I/O (saving and loading tasks)
 

 // Function declarations (prototypes)
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskDone(vector<Task>& tasks);
void saveTasksToFile(const vector<Task>& tasks);
void loadTasksFromFile(vector<Task>& tasks);

int main() {
    // Vector from STL used to store all Task objects dynamically
    vector<Task> tasks;
    int choice;

    // When the program starts, try loading any existing tasks from file
    loadTasksFromFile(tasks);

    // Main program loop - repeats until the user chooses Exit (5)
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        // CONDITIONALS: decide what to do based on user input
        if (choice == 1)
            addTask(tasks);
        else if (choice == 2)
            viewTasks(tasks);
        else if (choice == 3)
            markTaskDone(tasks);
        else if (choice == 4)
            saveTasksToFile(tasks);
        else if (choice == 5) {
            cout << "Saving tasks and exiting..." << endl;
            saveTasksToFile(tasks); // Auto-save before exit
            break; // Exit loop → end program
        }
        else
            cout << "Invalid choice. Please try again." << endl;

        cout << endl;
    }

    return 0; // Program finished successfully
}

/*
 * =============================
 *  FUNCTION DEFINITIONS
 * =============================
 * These functions make the code modular and easier to read.
 * Each one performs a small, specific job.
 */

 // Displays the main menu options
void displayMenu() {
    cout << "==========================" << endl;
    cout << "   TO-DO LIST MANAGER " << endl;
    cout << "==========================" << endl;
    cout << "1. Add a new task" << endl;
    cout << "2. View all tasks" << endl;
    cout << "3. Mark a task as done" << endl;
    cout << "4. Save tasks to file" << endl;
    cout << "5. Exit" << endl;
}

// Adds a new task entered by the user
void addTask(vector<Task>& tasks) {
    cin.ignore(); // Clear leftover input
    string description;
    cout << "Enter task description: ";
    getline(cin, description);

    // Create a new Task object using the constructor
    Task newTask(description);

    // Add the new Task to the vector
    tasks.push_back(newTask);

    cout << "Task added successfully!" << endl;
}

// Displays all tasks currently in the list
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks yet." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;

    // LOOP: go through each task in the vector
    for (int i = 0; i < tasks.size(); i++) {
        tasks[i].display(i); // Uses the Task::display function
    }
}

// Marks a specific task as completed
void markTaskDone(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as done." << endl;
        return;
    }

    int taskNumber;
    viewTasks(tasks);
    cout << "Enter the task number to mark as done: ";
    cin >> taskNumber;

    // CONDITIONAL: validate user input
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].markAsDone();
        cout << "Task marked as done!" << endl;
    }
    else {
        cout << "Invalid task number." << endl;
    }
}

// Saves the current list of tasks into a text file
void saveTasksToFile(const vector<Task>& tasks) {
    ofstream outFile("tasks.txt"); // Output file stream
    if (!outFile) {
        cout << "Error saving tasks!" << endl;
        return;
    }

    // LOOP: write each task and its status to the file
    for (const Task& task : tasks) {
        outFile << task.getDescription() << "|" << task.isCompleted() << endl;
    }

    outFile.close();
    cout << "Tasks saved to file successfully." << endl;
}

// Loads tasks from file when program starts
void loadTasksFromFile(vector<Task>& tasks) {
    ifstream inFile("tasks.txt"); // Input file stream
    if (!inFile) return; // If no file exists yet, just skip

    string line;
    while (getline(inFile, line)) {
        size_t delimiter = line.find('|');
        string desc = line.substr(0, delimiter);
        bool done = stoi(line.substr(delimiter + 1));

        Task loadedTask(desc);
        if (done)
            loadedTask.markAsDone();

        tasks.push_back(loadedTask);
    }

    inFile.close();
}