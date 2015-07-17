#include "Coke.h"

Coke* Coke::cokeItem = NULL;

Coke::Coke(int itemId) : Item(itemId) {
	this->setMaxStackSize(64);
	this->setIcon("coke", 0);
	this->setNameID("coke");
}
