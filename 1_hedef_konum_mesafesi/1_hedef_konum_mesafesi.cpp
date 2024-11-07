// Mithat Uçar - 05/11/2024
#include <iostream>
#include <set>
#include <random>

const int TOTAL_POINTS = 20;
const int MIN_DISTANCE = 5;
const int TOTAL_STEPS = 10;
// Rastgele konum üretir, yeni konumun önceki konumdan MIN_DISTANCE kadar uzak olmasını sağlar.
// Yeni konum daha önce ziyaret edilen konumlar arasında olmamalıdır.
int generateRandomPosition(int currentPosition, const std::set<int> &visitedPoints, std::mt19937 &rnd)
{
  std::uniform_int_distribution<> dist(0, TOTAL_POINTS);
  int newPoint;
  do
  {
    newPoint = dist(rnd);
  } while (visitedPoints.count(newPoint) || abs(currentPosition - newPoint) < MIN_DISTANCE);
  return newPoint;
}
// Mini Ada dairesel gezintisini gerçekleştirir.
void miniAda()
{
  int currentPosition = 0;
  std::set<int> visitedPoints{currentPosition};
  std::mt19937 rnd(std::random_device{}());

  for (int i = 0; i < TOTAL_STEPS; ++i) // TOTAL_STEPS boyunca döngü.
  {
    currentPosition = generateRandomPosition(currentPosition, visitedPoints, rnd); // Yeni konumu güncelle.
    visitedPoints.insert(currentPosition);                                         // Yeni konumu ziyaret edilen konumlar listesine ekle.
    std::cout << "Adim " << i + 1 << ": " << currentPosition << std::endl;
  }
}

int main()
{
  std::cout << "Mini Ada dairesel gezintisine basliyor...\n";
  miniAda();
  std::cout << "\nCikmak icin bir tusa basin...";
  std::cin.get(); // Programın kapanmaması için bir tuşa basılmasını bekleyelim.
  return 0;
}
