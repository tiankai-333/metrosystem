#include <iostream>
#include <string>
#include "MetroSystem.h"

class UserInterface {
public:
    // 构造函数，传入地铁系统实例
    explicit UserInterface(MetroSystem &metroSystem);
    
    // 显示主菜单并处理用户输入
    void DisplayMainMenu();
    
    // 示例方法：查询两个站点间的路线
    void QueryRouteBetweenStations();
    
    // 示例方法：显示所有线路信息
    void DisplayAllLines();

private:
    // 地铁系统实例
    MetroSystem &mMetroSystem;
    
    // 辅助方法，用于读取用户输入的整数
    int ReadIntegerFromUser(const std::string &prompt);
    
    // 辅助方法，用于读取用户输入的字符串
    std::string ReadStringFromUser(const std::string &prompt);
};