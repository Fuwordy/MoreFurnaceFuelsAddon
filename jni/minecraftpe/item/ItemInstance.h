#pragma once

#include <string>

class Tile;
class Item;
class Entity;
class ItemInstance;
class CompoundTag;
class Mob;
class Player;
class Level;

// Size : 16
class ItemInstance
{
public:
	Item* item;
public:
	ItemInstance(const Item *);
	ItemInstance(const Item *, int);
	ItemInstance(const Item *, int, int);
	ItemInstance(const ItemInstance &);
	ItemInstance(const Tile *);
	ItemInstance(const Tile *, int);
	ItemInstance(const Tile *, int, int);
	ItemInstance(bool);
	ItemInstance(int, int, int);
	ItemInstance();
	void _setItem(int);
	void add(int);
	void canDestroySpecial(Tile *);
	ItemInstance *clone(const ItemInstance *);
	ItemInstance *cloneSafe(const ItemInstance *);
	void fromTag(CompoundTag *);
	int getAttackDamage(Entity *);
	int getAuxValue() const;
	int getDamageValue() const;
	int getDestroySpeed(Tile *);
	void getIcon(int, bool) const;
	int getId() const;
	int getIdAux() const;
	int getMaxDamage() const;
	int getMaxStackSize() const;
	int getMaxUseDuration() const;
	std::string getName() const;
	int getUseAnimation() const;
	void hurtAndBreak(int, Mob *);
	void hurtEnemy(Mob *, Mob *);
	void init(int, int, int);
	void interactEnemy(Mob *, Player *);
	bool isArmorItem(const ItemInstance *);
	bool isDamageableItem() const;
	bool isDamaged() const;
	bool isItem(const ItemInstance *);
	bool isLiquidClipItem();
	bool isNull() const;
	bool isStackable(const ItemInstance *, const ItemInstance *);
	bool isStackable() const;
	bool isStackedByData() const;
	void load(CompoundTag *);
	bool matches(const ItemInstance *) const;
	bool matches(const ItemInstance *, const ItemInstance *);
	bool matchesNulls(ItemInstance const *, const ItemInstance *);
	void mineBlock(int, int, int, int, Mob *);
	bool operator==(const ItemInstance &) const;
	void releaseUsing(Player *, int);
	void remove(int);
	void sameItemAndAux(ItemInstance *) const;
	void save(CompoundTag *);
	void set(int);
	void setAuxValue(int);
	void setDescriptionId(const std::string &);
	void setNull();
	void snap(Player *);
	std::string toString() const;
	void use(Player &);
	void useAsFuel();
	void useOn(Player *, int, int, int, signed char, float, float, float);
	void useTimeDepleted(Level *, Player *);
};
