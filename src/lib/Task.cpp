#include <iostream>
#include <string>

class Task
{
    public:
        int task_id = 0;
        std::string task_name = "Null";
        std::string task_content = "Null";
        std::string due_date = "Null";
        Task()
        {
            std::cout << "New task created: " << task_name << "\n";
        }
        Task(std::string task_name, std::string task_content, std::string due_date)
        {
            this->task_name = task_name;
            this->task_content = task_content;
            this->due_date = due_date;
            std::cout << "New task created: " << task_name << "\n";
        }
        ~Task()
        {
            std::cout << "Task deleted: " << task_name << "\n";
        }

    private:
};
