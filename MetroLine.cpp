#include "MetroLine.h"

MetroLine::MetroLine(int theLineId,
                     const std::vector<Station> &theStations,
                     const std::map<std::pair<int, int>, int> &theTimeWeights = {})
        : mLineId(theLineId), mStations(theStations), mTimeWeights(theTimeWeights) {}

int MetroLine::GetLineId() const {
    return mLineId;
}

int MetroLine::GetStationId(const std::string &theStationName) const {
    if (mStationNameToId.find(theStationName) == mStationNameToId.end()) return -1;  // -1表示不存在指定站点
    return mStationNameToId.at(theStationName);
}

const std::vector<Station> &MetroLine::GetStations() const {
    return mStations;
}

const std::vector<TransferableStation> &MetroLine::GetTransfers(int theStationId) const {
    return mStations[theStationId].mTransferableStations;
}

int MetroLine::GetTimeWeight(int theFromStationId, int theToStationId) const {
    auto it = mTimeWeights.find(std::make_pair(theFromStationId, theToStationId));
    if (it == mTimeWeights.end()) it = mTimeWeights.find(std::make_pair(theToStationId, theFromStationId));
    return it != mTimeWeights.end() ? it->second : -1;  // 默认返回-1表示无直接时间权重定义
}

bool MetroLine::HasStation(const std::string &theStationName) const {
    return mStationNameToId.find(theStationName) != mStationNameToId.end();
}

bool MetroLine::AddTransferStation(int theStationId, int theLineId, int theTransferableStationId, int theTimeWeight) {
    mStations[theStationId]  // 获取指定站
            .mTransferableStations  // 获取可换乘站列表
            .push_back(TransferableStation{theLineId,
                                           theTransferableStationId,
                                           theTimeWeight});  // 添加可换乘站
    return true;
}