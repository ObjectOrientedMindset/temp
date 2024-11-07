// Mithat Uçar - 06/11/2024
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <windows.h>
#include <algorithm>
// Function to read the content of a text file into a string
void read_text(std::string &text)
{
  std::ifstream file("metin.txt");
  if (file.is_open())
  {
    std::getline(file, text, '\0');
    file.close();
  }
  else
  {
    std::cerr << "Dosya açılamadı!" << std::endl;
  }
}
// Function to remove all spaces from the text
void remove_spaces(std::string &text)
{
  text.erase(std::remove(text.begin(), text.end(), ' '), text.end());
}
// Function to determine the dimensions of the matrix (m x n)
void find_matrix_dimensions(int length, int &m, int &n)
{
  int sqrt_l = std::sqrt(length);
  m = sqrt_l;
  n = (sqrt_l * sqrt_l < length) ? sqrt_l + 1 : sqrt_l;
  while (m * n < length)
  {
    ++m;
  }
}
// Function to display the matrix of text, formatted with m rows and n columns
void display_matrix(const std::string &text, int m, int n)
{
  std::cout << std::endl;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int index = i * n + j;
      if (index < text.size())
      {
        std::cout << text[index];
      }
      else
      {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }
}
int main()
{
  system("chcp 65001"); // Change the code page to UTF-8 for proper character encoding
  std::string text;
  read_text(text);

  remove_spaces(text);
  std::cout << "Metin: " << text << std::endl;

  int m, n;
  find_matrix_dimensions(text.length(), m, n);

  std::cout << "m = " << m << ", n = " << n << std::endl;
  display_matrix(text, m, n);
  std::cin.get();

  return 0;
}
