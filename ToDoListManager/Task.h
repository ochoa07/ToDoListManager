#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
using namespace std;

/*
 * This header file defines the structure of the Task class.
 * Think of it like a "blueprint" that tells the program what
 * each Task object looks like and what actions (methods) it can perform.
 * The implementation (how these methods actually work)
 * is found in Task.cpp.
 */

class Task {
private:
    // Each task has two pieces of information:
    string description; // Text describing what needs to be done
    bool completed;     // True if the task is finished

public:
    // Constructor: called when a new Task object is created
    Task(string desc);

    // Marks this task as completed
    void markAsDone();

    // Returns the text description of the task
    string getDescription() const;

    // Returns whether this task is completed or not
    bool isCompleted() const;

    // Displays the task neatly in the console with a number
    void display(int index) const;
};

#endif
