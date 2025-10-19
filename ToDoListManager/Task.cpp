#include "Task.h"

/*
 * This file contains the actual code for how each Task behaves.
 * Here we "build" the functions that were only declared in Task.h.
 * In simple terms, Task.h says "what" the class can do,
 * and Task.cpp says "how" it does it.
 */

 // Constructor initializes the description and sets completion to false
Task::Task(string desc) {
    description = desc;
    completed = false;
}

// This method marks the task as done (changes completed to true)
void Task::markAsDone() {
    completed = true;
}

// Returns the description of the task
string Task::getDescription() const {
    return description;
}

// Returns whether the task is completed or not
bool Task::isCompleted() const {
    return completed;
}

// Displays the task in a formatted way
void Task::display(int index) const {
    cout << index + 1 << ". " << description;
    if (completed)
        cout << " [DONE]"; // Adds a label if the task is completed
    cout << endl;
}