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
        Task(std::string name, std::string content, std::string date)
        {
            this-> task_name = name;
            this->task_content = content;
            this->due_date = date;
            std::cout << "New task created: " << task_name << "\n";
        }
        ~Task()
        {
            std::cout << "Task deleted: " << task_name << "\n";
        }

    private:
};
