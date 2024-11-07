// Mithat Uçar - 05/11/2024
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Generates a random array of integers between -1000 and 1000
void generateRandomArray(std::vector<int> &arr, int size)
{
  for (int i = 0; i < size; ++i)
  {
    arr.push_back((rand() % 2001) - 1000); // Range: -1000 to 1000
  }
}

// Finds pairs of indices where the sum is divisible by k
void findDivisiblePairs(const std::vector<int> &arr, int divisor)
{
  bool found = false;
  for (size_t i = 0; i < arr.size(); ++i)
  {
    for (size_t j = i + 1; j < arr.size(); ++j)
    {
      if ((arr[i] + arr[j]) % divisor == 0)
      {
        std::cout << "(" << i << ", " << j << ") ";
        found = true;
      }
    }
  }
  if (!found)
  {
    std::cout << "No divisible pairs found.\n";
  }
}

// Validates user input for n and k, returning true if valid
bool validateInput(int n, int k)
{
  if (n <= 2 || n >= 1000 || k <= 1 || k >= 100)
  {
    std::cout << "Invalid input! Please enter n between 3 and 999, and k between 2 and 99.\n";
    return false;
  }
  return true;
}

int main()
{
  int n, k;
  std::cout << "Enter the array size (n): ";
  std::cin >> n;
  std::cout << "Enter a positive divisor (k): ";
  std::cin >> k;

  if (!validateInput(n, k))
  {
    std::cout << "Press any key to exit...";
    std::cin.ignore();
    std::cin.get();
    return 1;
  }

  srand(static_cast<unsigned>(time(0))); // Seed the random number generator

  std::vector<int> arr;
  generateRandomArray(arr, n);

  std::cout << "Generated Array: ";
  for (int num : arr)
  {
    std::cout << num << " ";
  }
  std::cout << "\nDivisible Pairs: ";
  findDivisiblePairs(arr, k);

  std::cout << "\nPress any key to exit...";
  std::cin.ignore();
  std::cin.get();
  return 0;
}
