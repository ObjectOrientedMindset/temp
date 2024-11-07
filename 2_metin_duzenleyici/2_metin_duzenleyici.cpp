// Mithat Uçar - 06/11/2024
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

std::string input;          // Stores the main text
std::string last_operation; // Stores last operation for undo
// Append text to the end of the main text
void append(const std::string &text)
{
  last_operation = input;
  input += text;
}
// Delete last k characters from the main text
void delete_k(int k)
{
  if (input.empty() || k <= 0 || k > static_cast<int>(input.size()))
  {
    std::cout << "Invalid delete operation." << std::endl;
    return;
  }
  last_operation = input;
  input.erase(input.size() - k);
}
// Print first k characters of the main text
void print_k(int k)
{
  if (input.empty() || k <= 0 || k > static_cast<int>(input.size()))
  {
    std::cout << "Invalid print operation." << std::endl;
    return;
  }
  std::cout << input.substr(0, k) << std::endl;
}
// Undo the last operation
void undo()
{
  if (last_operation.empty())
  {
    std::cout << "No operation to undo." << std::endl;
    return;
  }
  input = last_operation;
  last_operation.clear();
}
// Save the main text to a file and exit the program
void save(const std::string &file_name)
{
  std::ofstream file(file_name);
  if (!file)
  {
    std::cout << "Error opening file." << std::endl;
    return;
  }
  file << input;
  file.close();
  std::cout << "File saved. Program terminating." << std::endl;
  exit(0);
}

int main()
{
  // Bu 3 satır Konsolu ve input/output işlemlerini Türkçe yapar
  setlocale(LC_ALL, "Turkish");
  SetConsoleOutputCP(1254);
  SetConsoleCP(1254);
  std::string command;
  std::cout << "Commands:\n"
            << "1 - Append text\n"
            << "2 - Delete last k characters\n"
            << "3 - Print first k characters\n"
            << "4 - Undo last operation\n"
            << "5 - Save and exit\n"
            << "Enter your command: ";

  while (std::cin >> command) // Loop until user enters command 5
  {
    if (command == "1")
    {
      std::cout << "Enter text to append: ";
      std::cin.ignore();
      std::string text;
      std::getline(std::cin, text); // Read the whole line
      append(text);
    }
    else if (command == "2")
    {
      std::cout << "Enter number of characters to delete: ";
      int k;
      std::cin >> k;
      delete_k(k);
    }
    else if (command == "3")
    {
      std::cout << "Enter number of characters to print: ";
      int k;
      std::cin >> k;
      print_k(k);
    }
    else if (command == "4")
    {
      undo();
    }
    else if (command == "5")
    {
      std::cout << "Enter file name to save (e.g., text.txt): ";
      std::string file_name;
      std::cin >> file_name;
      save(file_name);
    }
    else
    {
      std::cout << "Invalid command. Try again." << std::endl;
    }
    std::cout << "Enter your command: ";
  }
  return 0;
}
