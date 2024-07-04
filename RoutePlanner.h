#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "MetroLine.h"

class RoutePlanner {
public:
    // 构造函数，传入地铁系统所有线路信息
    RoutePlanner(const std::vector<MetroLine> &metroLines);

    // 计算从startStationId到endStationId的最短路线，返回路线详情或错误信息
    std::string CalculateShortestRoute(int startStationId, int endStationId, const std::string &criteria = "time");

private:
    std::vector<MetroLine> mMetroLines;  // 地铁系统所有线路信息
    std::unordered_map<int, std::string> mStationIdToName;  // 站点ID到站点名称的映射
    std::unordered_map<std::string, int> mStationNameToId;  // 站点名称到站点ID的映射

    // 辅助方法
    std::vector<std::string> FindRouteBetweenStations(int from, int to, const std::string &criteria);

    bool IsTransferStation(int stationId);

    int CalculateWeight(int fromStationId, int toStationId);  // 根据criteria计算两站间权重
};

