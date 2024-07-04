#include "Station.h"
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class MetroLine {
public:
    // 构造函数
    MetroLine(int lineId,
              const std::vector<Station> &stations,
              const std::map<std::pair<int, int>, int> &timeWeights);

    // 获取线路编号
    int GetLineId() const;
    
    // 获取站点编号
    int GetStationId(const std::string &theStationName) const;

    // 获取站点列表（这里直接返回引用，根据实际情况决定是否拷贝）
    const std::vector<Station> &GetStations() const;

    // 获取换乘信息，返回指定站点的换乘信息
    const std::vector<TransferableStation> &GetTransfers(int theStationId) const;

    // 获取站点间时间权重
    int GetTimeWeight(int theFromStationId, int theToStationId) const;
    
    // 查找站点是否存在
    bool HasStation(const std::string &theStationName) const;

    // 添加换乘站，其参数的合法性应该已在前端检查
    bool AddTransferStation(int theStationId, int theLineId, int theTransferableStationId, int theTimeWeight);
    
    // 关闭站点，这里给两个重载版本，既可以通过单个站点名字关闭，也可以通过站编号关闭
    // 注意这里不反馈传入的参数是否合法
    void CloseStation(const std::string &theStationName);
    void CloseStation(vector<int> &theStationId);
    
    // 恢复被关闭的站点，注意这里不反馈传入的参数是否合法
    void RecoverStation(const std::string &theStationName);
    void RecoverStation(vector<int> &theStationId);
    
    // 扩充路线长度，传入n个站和n个时间权重
    // 仅支持在线路末尾添加站
    void ExpandRoute(vector<Station> &theStations, vector<int> &theTimeWeights);
    
    // 缩短路线长度
    // 仅支持在线路末尾删除站
    void ShrinkRoute(int theNewCountOfStations);

private:
    int mLineId;  // 线路编号，默认线路之间的编号不重复
    std::vector<Station> mStations;  // 站点列表
    std::unordered_map<std::string, int> mStationNameToId;  // 站名到站编号的映射，方便根据站名查询某个站是否在该线路
    std::map<std::pair<int, int>, int> mTimeWeights; // 站点间时间权重，将两站之间的时间权重保存到map中，若有n站，则需保存n*(n-1)/2个键值对
};
