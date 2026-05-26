#include "Item.h"

#include <random>

#include "LogManager.h"
#include "Player.h"

ItemType Item::GetRandomType(const std::vector<ItemType>& types)
{
    if (types.empty()) return ItemType::None;

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dis(0, types.size() - 1);

    return types[dis(gen)];
}

bool Item::Use(Player& player, ItemType itemType)
{
    if (itemType == ItemType::None)
    {
        return false;
    }

    const auto& inventory = player.GetInventory();

    auto pred = [itemType](const auto& item)
    {
        return item->GetType() == itemType;
    };

    const auto it = std::find_if(inventory.begin(), inventory.end(), pred);

    if (it == inventory.end())
    {
        return false;
    }

    Item& findItem = *(*it);

    findItem.UseItem(player);

    LogManager::GetInstance().PrintUseItem(findItem);

    player.RemoveItem(findItem.GetName());

    return true;
}

bool Item::UseRandom(Player& player)
{
    const auto& inventory = player.GetInventory();

    if (inventory.empty())
    {
        return false;
    }

    std::vector<ItemType> itemTypes;

    itemTypes.reserve(inventory.size());
    for (const auto& item : inventory)
    {
        itemTypes.push_back(item->GetType());
    }

    const ItemType randomType = GetRandomType(itemTypes);

    return Use(player, randomType);
}
