#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
  int cols;
  std::string input;
  std::cin >> cols;

  while (cols != 0)
  {
    std::cin >> input;

    int length = input.length();
    int numRows = length / cols;
    char message[length];
    int first = 2 * cols - 1;
    int second = 1;

    for (int i = 0; i < cols; i++)
    {
      int current = i;
      int next = first;

      for (int j = 0; j < numRows; j++)
      {
          message[numRows * i + j] = input[current];
          current += next;

          next = (next == first) ? second : first;
      }

      first -= 2;
      second += 2;
    }

    for (int i = 0; i < length; i++)
    {
      std::cout << message[i];
    }

    std::cout << std::endl;
    std::cin >> cols;
  }

  return 0;
}
