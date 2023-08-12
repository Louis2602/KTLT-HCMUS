#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

// Hàm kiểm tra xem một số đã tồn tại trong danh sách hay chưa
bool numberExists(int num, const std::vector<int> &numbers) {
  return std::find(numbers.begin(), numbers.end(), num) != numbers.end();
}

// Hàm sinh dãy số ngẫu nhiên không trùng nhau
std::vector<int> generateUniqueNumbers(int count, int range) {
  std::vector<int> uniqueNumbers;
  while (uniqueNumbers.size() < count) {
    int num =
        rand() % range + 1; // Sinh số ngẫu nhiên trong khoảng từ 1 đến range
    if (!numberExists(num, uniqueNumbers)) {
      uniqueNumbers.push_back(num);
    }
  }
  return uniqueNumbers;
}

int main() {
  srand(time(0)); // Khởi tạo seed ngẫu nhiên từ thời gian hệ thống

  const int ticketCount = 6;
  const int maxNumber = 49;
  const int totalTickets = 100; // 1000000

  std::vector<std::vector<int>> soldTickets;

  for (int i = 0; i < totalTickets; ++i) {
    std::vector<int> ticket = generateUniqueNumbers(ticketCount, maxNumber);
    soldTickets.push_back(ticket);
  }

  // In ra danh sách vé số đã bán
  for (const std::vector<int> &ticket : soldTickets) {
    for (int num : ticket) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
