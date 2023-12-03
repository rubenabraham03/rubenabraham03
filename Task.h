#pragma once
#include <string>
#include <vector>
using namespace std;

struct Task
{
	string description;
	bool done;
};

void saveTasksToFile(const vector<Task>& tasks, const string& fileName);
vector<Task> loadTasksFromFile(const string& fileName);