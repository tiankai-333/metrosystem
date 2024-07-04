#include "Station.h"

Station::Station(std::string &theName, int theStop, bool ifIsTransfer = false, bool ifIsClosed = false)
        : mName(theName), mStop(theStop), mIsTransfer(ifIsTransfer), mIsClosed(ifIsClosed) {
    
}
        