#include <vector>
#include <string>
#include <unordered_map>
#include "MetroLine.h"

class MetroSystem {
public:
    // 构造函数，可以初始化地铁系统的基本信息
    MetroSystem();
    
    // 通过站点名查找站点所在的线路id
    const std::vector<int> &GetLineIdsByStationName(const std::string &theStationName) const;

    // 添加一条地铁线路到系统中，换乘的信息需要额外添加
    void AddMetroLine(const MetroLine &theLine);
    
    // 添加站点换乘信息，需要先检查站点在线路中是否存在
    bool AddTransferStation(std::string &theStationName, int theLineId1, int theLineId2, int theTimeWeight);

    // 删除指定编号的地铁线路
    bool RemoveMetroLine(int theLineId);

    // 扩大某条线路的站点数量，注意这里要还要处理关联的站点和线路之间的信息，下同
    void ExpandRoute(int theLineId, vector<Station> &theStations, vector<int> &theTimeWeights);
    
    // 缩小某条线路的站点数量
    void ShrinkRoute(int theLineId, int theNewCountOfStations);

    // 站点的关闭，需要同时处理线路和站点之间的信息
    void CloseStation(int theLineId, std::string &theStationName);
    void CloseStation(int theLineId, vector<int> &theStationId);
    
    // 站点的恢复，需要同时处理线路和站点之间的信息
    void RecoverStation(int theLineId, std::string &theStationName);
    void RecoverStation(int theLineId, vector<int> &theStationId);
    
    // 其他可能的方法，如查询线路之间的换乘信息、站点搜索等

private:
    std::vector<MetroLine> mMetroLines;  // 按编号排序存储所有地铁线路
    std::unordered_map<std::string, vector<int>> mStationMap;  // 站点名称到站点所属线路编号的映射，便于快速查找

    // 辅助方法，如验证并添加站点到映射表等
};




