#include <iostream>

// Global Variables
std::string  global_task_name;
std::string global_username;
void greet_user()
{
    int i = 0;
    if (i == 0)
    {
        std::cout << "Welcome to your Personal Task Management app!\nLet's get to know you.\nName: ";
        std::cin >> global_username;
        std::cout << "Nice to meet you, " << global_username << "!\n";
    }
    else
    {
        std::cout << "Welcome " << global_username << std::endl;
    }
}

class Task
{
    public:
        int task_id = 0;
        std::string task_name = global_task_name;
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

    private:
};

void Input_Task()
{
    std::cout << "#New task";
    std::cout << "Task Name : ";
    std::cin >> global_task_name;
    std::cout << std::endl;
}

void view_all_tasks()
{
    std::cout << "All Tasks" << std::endl;
}

void display_options()
{
    int option;
    std::cout << "\nSelect an action from the list below: \n1. Create a new task\n2. View all tasks\n3. Remove a task\n4. Change username\n5. Exit\n";
    std::cin >> option;
    if (option == 1)
    {
        Input_Task();
    }
    else if (option == 2)
    {
        view_all_tasks();
    }
    else if (option == 3)
    {
        //remove tasl
    }
    else if (option == 4)
    {
        std::cout << "Input a new username: ";
        std::cin >> global_username;
    }
    else if (option == 5)
    {
        exit;
    }
}



int main(int argc, char* argv[])
{
    greet_user();
    display_options();
    display_options();
    //Task global_task_name;
    //std::cout << global_task_name << "\n";
    return 0;
}