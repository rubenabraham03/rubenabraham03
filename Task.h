//Ruben Abraham
#pragma once

#include <string>
#include <vector>
using namespace std;

// Structure representing a task with a description and completion status
struct Task
{
    string description;  // Description of the task
    bool done;           // Completion status of the task
};

// Function declarations for managing tasks
void saveTasksToFile(const vector<Task>& tasks, const string& fileName);
vector<Task> loadTasksFromFile(const string& fileName);
