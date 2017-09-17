#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
  int points;
  std::cin >> points;
  int total;

  while (points != 0)
  {
    total = points;

    double slopes[points];
    double intercepts[points];
    double xints[points];
    double xmins[points];
    double xmaxs[points];
    double ymins[points];
    double ymaxs[points];


    for (int i = 0; i < points; i++)
    {
      slopes[i] = -3.1415926536;
      intercepts[i] = -3.1415926536;
      xints[i] = -3.1415926536;
      xmins[i] = -3.1415926536;
      xmaxs[i] = -3.1415926536;
      ymins[i] = -3.1415926536;
      ymaxs[i] = -3.1415926536;
    }

    for (int i = 0; i < points; i++)
    {
      double x1;
      double y1;
      double x2;
      double y2;

      std::cin >> x1 >> y1 >> x2 >> y2;

      if (y2 < y1)
      {
        double tempX = x1;
        double tempY = y1;

        x1 = x2;
        y1 = y2;
        x2 = tempX;
        y2 = tempY;
      }

      if (x2 - x1 == 0)
      {
        double *match = std::find(&xints[0], &xints[points-1], x1);

        if (match != &xints[points-1])
        {
          int index = (match - &xints[0]) / sizeof(*xints);
          if ((y1 >= ymins[index] && y1 <= ymaxs[index]) || (y2 >= ymins[index] &&  y2 <= ymaxs[index]))
          {
            total--;
          }
        }
        else
        {
          xints[i] = x1;
          ymins[i] = y1 < y2 ? y1 : y2;
          ymaxs[i] = y1 > y2 ? y1 : y2;
        }
      }
      else
      {
        double slope = (y2 - y1) / (x2 - x1);
        double yint = slope * (-x1) + y1;

        double *match = std::find(&slopes[0], &slopes[points-1], slope);

        if (match != &slopes[points-1])
        {
          int index = (match - &slopes[0]) / sizeof(*slopes);
          if (intercepts[index] == yint)
          {
            if ((x1 >= xmins[index] && x1 <= xmaxs[index]) || (x2 >= xmins[index] &&  x2 <= xmaxs[index]))
            {
              total--;
            }
          }
        }
        else
        {
          slopes[i] = slope;
          intercepts[i] = yint;
          xmins[i] = x1 < x2 ? x1 : x2;
          xmaxs[i] = x1 > x2 ? x1 : x2;
        }
      }
    }

    std::cout << total << std::endl;
    std::cin >> points;
  }

  return 0;
}
