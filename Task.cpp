#include "Task.h"
#include <filesystem>
#include <fstream>
#include <algorithm>

using namespace std;


void saveTasksToFile(const vector<Task>& tasks, const string& fileName)
{
	ofstream ostream(fileName);
	ostream << tasks.size();

	for (const Task& task : tasks) {
		string description = task.description;
			replace(description.begin(), description.end(), ' ', '_');

			ostream << endl << description << ' ' << task.done;
	}
}

vector<Task> loadTasksFromFile(const string& fileName)
{
	if (!filesystem::exists(fileName)) {
		return vector<Task>();
	}
	vector<Task> tasks;
	ifstream istream(fileName);

	int n;
	istream >> n;

	for (int i = 0; i < n; i++) {
		string description;
		bool done;

		istream >> description >> done;
		replace(description.begin(), description.end(), '_', ' ');
		tasks.push_back(Task{ description, done });

	}
	return tasks;
}
