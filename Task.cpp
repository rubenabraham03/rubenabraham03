//Ruben Abraham

#include "Task.h"
#include <filesystem>
#include <fstream>
#include <algorithm>

using namespace std;

// Function to save tasks to a file
void saveTasksToFile(const vector<Task>& tasks, const string& fileName)
{
    // Open a file stream for writing
    ofstream ostream(fileName);

    // Write the number of tasks to the file
    ostream << tasks.size();

    // Loop through tasks and write each task to a new line in the file
    for (const Task& task : tasks) {
        // Replace spaces in the description with underscores for formatting
        string description = task.description;
        replace(description.begin(), description.end(), ' ', '_');

        // Write the task details to the file
        ostream << endl << description << ' ' << task.done;
    }
}

// Function to load tasks from a file
vector<Task> loadTasksFromFile(const string& fileName)
{
    // If the file doesn't exist, return an empty vector
    if (!filesystem::exists(fileName)) {
        return vector<Task>();
    }

    // Vector to store loaded tasks
    vector<Task> tasks;

    // Open a file stream for reading
    ifstream istream(fileName);

    // Read the number of tasks from the file
    int n;
    istream >> n;

    // Loop through the tasks in the file and add them to the vector
    for (int i = 0; i < n; i++) {
        // Read task details from the file
        string description;
        bool done;
        istream >> description >> done;

        // Replace underscores in the description with spaces for formatting
        replace(description.begin(), description.end(), '_', ' ');

        // Create a task and add it to the vector
        tasks.push_back(Task{ description, done });
    }

    // Return the vector of loaded tasks
    return tasks;
}
