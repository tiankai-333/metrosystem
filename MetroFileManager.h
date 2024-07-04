#include "MetroSystem.h"

class MetroFileManager {
public:
    static bool SaveMetroSystem(const MetroSystem &system, const std::string &fileName);
    static bool LoadMetroSystem(MetroSystem &system, const std::string &fileName);
};