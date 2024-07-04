#include "UserInterface.h"

// 构造函数实现
UserInterface::UserInterface(MetroSystem &metroSystem)
        : mMetroSystem(metroSystem) {}

// 显示主菜单并处理用户输入的实现
void UserInterface::DisplayMainMenu() {
    std::cout << "地铁查询系统\n";
    std::cout << "1. 查询路线\n";
    std::cout << "2. 显示所有线路\n";
    std::cout << "3. 退出\n";
    int choice = ReadIntegerFromUser("请输入选项: ");
    switch (choice) {
        case 1:
            QueryRouteBetweenStations();
            break;
        case 2:
            DisplayAllLines();
            break;
        case 3:
            std::cout << "感谢使用！\n";
            break;
        default:
            std::cout << "无效选项，请重新选择。\n";
            DisplayMainMenu();  // 递归调用以重新显示菜单
            break;
    }
}

// 查询两个站点间路线的实现示例
void UserInterface::QueryRouteBetweenStations() {
    int startId = ReadIntegerFromUser("请输入起点站ID: ");
    int endId = ReadIntegerFromUser("请输入终点站ID: ");
    // 这里需要调用MetroSystem的相关方法来查询并显示路线
    // 示例逻辑省略，实际应调用mMetroSystem.CalculateShortestRoute等
}

// 显示所有线路信息的实现示例
void UserInterface::DisplayAllLines() {
    const auto &allLines = mMetroSystem.GetAllLines();
    for (const auto &line: allLines) {
        std::cout << "线路名称: " << line.getLineId() << "\n";
        // 可能还需要显示线路的详细信息，如站点列表等
    }
}

// 辅助方法实现
int UserInterface::ReadIntegerFromUser(const std::string &prompt) {
    int value;
    std::cout << prompt;
    std::cin >> value;
    std::cin.ignore();  // 忽略输入流中的剩余字符，如换行符
    return value;
}

std::string UserInterface::ReadStringFromUser(const std::string &prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}