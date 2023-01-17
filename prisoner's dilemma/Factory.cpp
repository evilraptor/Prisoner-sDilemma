#include "DilemmaHeader.h" 


StrategyFactory::StrategyFactory() {
    add<StrategyRand>("StrategyRand");
    add<StrategyAlwaysC>("StrategyAlwaysC");
    add<StrategyAlwaysD>("StrategyAlwaysD");
    add<StrategyWinRound>("StrategyWinRound");
    add<StrategyTeamplay>("StrategyTeamplay");
    add<StrategyRevengeful>("StrategyRevengeful");
};
IStrategy* StrategyFactory::create(const std::string& id) {

    typename FactoryMap::iterator it = _factory.find(id);
    if (it != _factory.end())
        return it->second->create();
    return 0;
}
bool StrategyFactory::check(std::string a) {
    typename FactoryMap::iterator it = _factory.find(a);
    if (it == _factory.end())
        return false;
    else
        return true;
}
