#include "../include/menuitem.h"

MenuItem::MenuItem(std::string title) :
        title(title),
        description(""),
        icon(0),
        subMenu(NULL) {}

MenuItem::~MenuItem() {
        if (subMenu != NULL)
                delete subMenu;
}

std::string MenuItem::getTitle() { return this->title; }
std::string MenuItem::getDescription() { return this->description; }
int MenuItem::getIcon() { return this->icon; }
RoundLinkedList<MenuItem>* MenuItem::getSubMenu() { return this->subMenu; }
bool MenuItem::hasSubMenu() { return this->subMenu != NULL; }

void MenuItem::setDescription(std::string description) {
        this->description = description;
}
void MenuItem::setIcon(int icon) {
        this->icon = icon;
}
void MenuItem::addSubMenu(RoundLinkedList<MenuItem>* subMenu) {
        this->subMenu = subMenu;
}
