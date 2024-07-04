#include <string>
#include <vector>

struct TransferableStation {
    int mLineId;  // 可换乘线路的id
    int mStationId;  // 换成后的站点id
    int mTimeWeight;  // 可换乘站的换乘时间
};

/**
 * 站点类
 * 这个类是类似顶点的存在，但是可以出现在多条线路中，但不需要维护线路id，因为线路类中已经维护了线路id
 */
struct Station {
    std::string mName;  // 站点名称
    int mStop;  // 站点编号
    bool mIsTransfer;  // 标记该站点是否为换乘站
    bool mIsClosed;  // 标记该站点是否允许出入和换乘
    std::vector<TransferableStation> mTransferableStations{};  // 可换乘站及换乘时间
    
    Station(std::string &theName, int theStop, bool ifIsTransfer, bool ifIsClosed);
};