#include "BrownCoal.h"

BrownCoal* BrownCoal::brownCoalItem = NULL;

BrownCoal::BrownCoal(int itemId) : Item(itemId) {
	this->setMaxStackSize(64);
	this->setIcon("brownCoal", 0);
	this->setNameID("brownCoal");
}
