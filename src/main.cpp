#include <iostream>
#include <vector>
#include <string>
#include "lib/Task.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <Windows.h>
#include <wincrypt.h>



//#include <filesystem>



// This is a simple personal task management application in C++


// Create the general task vectors for storing the tasks
std::vector<Task> Task_List;

std::string global_username = ""; // Default username




void from_json(const nlohmann::json& jsonData, Task& to_Task)
{
    jsonData.at("name").get_to(to_Task.task_name);
    jsonData.at("content").get_to(to_Task.task_content);
    jsonData.at("date").get_to(to_Task.due_date);
    jsonData.at("id").get_to(to_Task.task_id);

}

void to_json(nlohmann::json& jsonData, const Task& from_Task)
{
    jsonData = nlohmann::json{
        {"id", from_Task.task_id},
        {"name", from_Task.task_name},
        {"content", from_Task.task_content},
        {"date", from_Task.due_date}
    };
}
static void lOAD_TASKS_VECTOR()
{
    std::ifstream tasksJSON("./crypt.json");

    // Check if our(?) .json file exists, if not create a new one
    if (tasksJSON.good()) 
    {
        try
        {
            nlohmann::json taskData = nlohmann::json::parse(tasksJSON);
            Task_List = taskData.get<std::vector<Task>>();
        }
        catch (const nlohmann::json::parse_error& e)
        {
            std::cerr << "Json  Parse Error: " << e.what() << "\n";
        }
    }
    else
    {
        //create a new one
        std::ofstream newcrypt("crypt.json");
        //do nothing
    }

}



static void save_tasks_to_file(const std::vector<Task>& Task_List, const std::string& filename) {
    nlohmann::json j = Task_List;  

    std::ofstream file("./crypt.json");
    if (!file) {
        std::cerr << "Failed to open " << filename << " for writing\n";
        return;
    }
    file << j.dump(4);  // Save pretty JSON
    file.close();
}



static void greet_user()
{
    if (global_username == "")
    {
        std::cout << "> Welcome to your Personal Task Management app!\n> Let's get to know you.\n> Name: ";
        std::getline(std::cin, global_username);
        std::cout << "> Nice to meet you, " << global_username << "!\n";
        std::ofstream new_file("cred.txt");
        if (new_file.is_open()) {
            new_file << global_username << std::endl;
            new_file.close();
            std::cout << "> Username Saved" << std::endl;
        }
    }
    else
    {
        std::cout << "> Welcome " << global_username << std::endl;
    }
}


static void Input_Task()
{
    std::string new_task;
    std::string new_date;
    std::string new_content;
    std::cin.ignore();
    std::cout << "> Task Name : ";
    std::getline(std::cin, new_task);
    if (new_task.empty()) {
        std::cout << "> Task name cannot be empty. Please try again.\n";
        Input_Task();
        return;
    }
    std::cout << "\n> Details : ";
    std::getline(std::cin, new_content);
    std::cout << "\n> Due Date(yy/mm/dd) : ";
    std::getline(std::cin, new_date);
    Task_List.push_back(Task(new_task, new_content, new_date));
    std::cout <<"> Task Created: "<< std::endl;
    save_tasks_to_file(Task_List, "./crypt.json");
}

static void view_all_tasks()
{
    
    if (Task_List.size())
    {
        std::cout << "All Tasks" << std::endl;
        for (int i = 0; i < Task_List.size(); i++)
        {
            std::cout << i + 1 << ". " << Task_List[i].task_name << std::endl;
        }
        // do a for loop to iterate through the Task_List vector and print out their names, maybe with the due dates
    }
    else
    {
        std::cout << "> No Tasks!" << std::endl;
    }
}
static void remove_tasks(int i)
{
    Task_List.erase(Task_List.begin() + i);
}
static void display_options()
{
    int option;
    std::cout << "> \n> Select an action from the list below: \n> 1. Create a new task\n> 2. View all tasks\n> 3. Remove a task\n> 4. Change Username\n> 5. Exit\n> ";
    std::cin >> option;
    if (option == 1)
    {
        Input_Task();
        display_options();
        
    }
    else if (option == 2)
    {
        view_all_tasks();
        display_options();
    }
    else if (option == 3)
    {
        int i;
        std::cout << "> Input the number of the task to be deleted(Press ENTER and view all tasks to see its number : ";
        std::cin >> i;
        remove_tasks(i - 1);
        display_options();
    }

    else if (option == 4)
    {
        std::cout << "Input a new username: ";
        std::cin.ignore();
        std::getline(std::cin, global_username);
        std::ofstream inFile("cred.txt", std::ios::trunc);
        if (inFile.is_open()) {
            inFile << global_username << std::endl;
            inFile.close();
            std::cout << "> Username Saved" << std::endl;
        }
        display_options();
    }
        
    else if (option == 5)
    {
        exit(0);
    }
        
    else if (option == 6)
    {
        std::cout << "Invalid Option\n";
        display_options();
    }        
}



int main(int argc, char* argv[])
{

    // Initializations
    // 
    // Load the data stored in the .json file into the Task_List vector
    
    lOAD_TASKS_VECTOR();

    // Create an output file for writing to 
    // check if theres a file like that named already
    
    //write user name to it
    std::ifstream inFile("cred.txt");
    if (!inFile.is_open())
    {
        greet_user();
    }
    else
    {
        std::getline(inFile, global_username);
        inFile.close();
        greet_user();
    }
    display_options();
    return 0;
}