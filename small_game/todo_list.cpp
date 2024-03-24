#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
	std::string description;
	bool completed;
	Task(const std::string &desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
	std::vector<Task> tasks;

public:

	void addTask(const std::string &description) {
		tasks.emplace_back(description);
		std::cout << "📝 Task added: " << description << std::endl;
	}

	void viewTasks() const {
		if (tasks.empty()) {
			std::cout << "🌟 No tasks in the magical list. Time for relaxation! 🌟\n";
		} else {
			std::cout << "📋 Tasks in the Magical List:\n";
			for (size_t i = 0; i < tasks.size(); ++i) {
				std::cout << "  " << i + 1 << ". [" << (tasks[i].completed ? "✅" : " ") << "] " << tasks[i].description << std::endl;
			}
		}
	}


	void markTaskAsCompleted(int index) {
		if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
			tasks[index - 1].completed = true;
			std::cout << "✨ Task marked as completed: " << tasks[index - 1].description << " ✨\n";
		} else {
			std::cout << "🚨 Invalid task index. Please choose a valid task. 🚨\n";
		}
	}

	void removeTask(int index) {
		if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
			std::cout << "🗑️ Task removed: " << tasks[index - 1].description << " 🗑️\n";
			tasks.erase(tasks.begin() + index - 1);
		} else {
			std::cout << "🚨 Invalid task index. Please choose a valid task. 🚨\n";
		}
	}

	~ToDoList() {
		tasks.clear();
	}
};


int main() {
	ToDoList toDoList;
	int choice;

	do {
		std::cout << "\n📅 Magical To-Do List Manager 🌟\n";
		std::cout << "1. ✨ Add a Magical Task\n";
		std::cout << "2. 📋 View the Magical Tasks\n";
		std::cout << "3. ✅ Mark a Magical Task as Completed\n";
		std::cout << "4. 🗑️ Remove a Magical Task\n";
		std::cout << "5. 🚪 Exit the Magical Realm\n";
		std::cout << "Enter your magical choice: ";
		std::cin >> choice;

		switch (choice) {
			case 1: {
				std::string taskDescription;
				std::cout << "📝 Enter the magical task description: ";
				std::cin.ignore(); // Clear the newline character from the input buffer
				std::getline(std::cin, taskDescription);
				toDoList.addTask(taskDescription);
				break;
			}

			case 2: {
				toDoList.viewTasks();
				break;
			}

			case 3: {
				int taskIndex;
				std::cout << "✨ Enter the index of the magical task to mark as completed: ";
				std::cin >> taskIndex;
				toDoList.markTaskAsCompleted(taskIndex);
				break;
			}

			case 4: {
				int taskIndex;
				std::cout << "🗑️ Enter the index of the magical task to remove: ";
				std::cin >> taskIndex;
				toDoList.removeTask(taskIndex);
				break;
			}

			case 5: {
				std::cout << "🚪 Exiting the Magical To-Do List Manager. Farewell, Magical Being! 🚪\n";
				break;
			}

			default: {
			std::cout << "🚨 Invalid magical choice. Please choose a valid magical option. 🚨\n";
			}
		}
	} while (choice != 5);

	return 0;
}
