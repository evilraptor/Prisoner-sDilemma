#include "DilemmaHeader.h" 


StrategyFactory::StrategyFactory() {
    add<StrategyRand>(1);
    add<StrategyAlwaysC>(2);
    add<StrategyAlwaysD>(3);
    add<StrategyWinRound>(4);
    add<StrategyTeamplay>(5);
    add<StrategyRevengeful>(6);
};
IStrategy* StrategyFactory::create(const int& id) {

    typename FactoryMap::iterator it = _factory.find(id);
    if (it != _factory.end())
        return it->second->create();
    return 0;
}
bool StrategyFactory::check(int a) {
    typename FactoryMap::iterator it = _factory.find(a);
    if (it == _factory.end())
        return false;
    else
        return true;
}
