#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

vector<Task> tasks;

// Function to display tasks
void displayTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\nYour To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[✔] " : "[ ] ") << tasks[i].description << endl;
    }
}

// Function to add a task
void addTask() {
    cout << "Enter the task description: ";
    cin.ignore();
    string desc;
    getline(cin, desc);
    tasks.push_back(Task(desc));
    cout << "Task added!\n";
}

// Function to mark a task as completed
void completeTask() {
    displayTasks();
    if (tasks.empty()) return;

    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

// Function to delete a task
void deleteTask() {
    displayTasks();
    if (tasks.empty()) return;

    int index;
    cout << "Enter task number to delete: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

// Function to save tasks to a file
void saveTasks() {
    ofstream file("tasks.txt");
    for (Task& task : tasks) {
        file << task.description << ";" << task.completed << endl;
    }
    file.close();
    cout << "Tasks saved to file!\n";
}

// Function to load tasks from a file
void loadTasks() {
    ifstream file("tasks.txt");
    if (!file) return;

    string desc;
    bool completed;
    while (getline(file, desc, ';') && file >> completed) {
        tasks.push_back(Task(desc));
        tasks.back().completed = completed;
        file.ignore();  // Ignore newline character
    }
    file.close();
}

// Main function
int main() {
    loadTasks();
    int choice;
    do {
        cout << "\nTo-Do List Menu\n";
        cout << "1. View Tasks\n2. Add Task\n3. Mark Task Completed\n4. Delete Task\n5. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayTasks(); break;
            
            case 2: addTask(); break;
            case 3: completeTask(); break;
            case 4: deleteTask(); break;
            case 5: saveTasks(); cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again!\n";
        }
    } while (choice != 5);

    return 0;
}