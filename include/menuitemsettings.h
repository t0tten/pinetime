#ifndef MENU_ITEM_SETTINGS_H
#define MENU_ITEM_SETTINGS_H

#include <iostream>
#include <string>
#include "menuitem.h"

class MenuItemSettings : public MenuItem {
        private:
                void executeSpecific();
        public:
                MenuItemSettings(std::string title);
                ~MenuItemSettings();

                void execute();
};

MenuItemSettings::MenuItemSettings(std::string title) : MenuItem(title) {}
MenuItemSettings::~MenuItemSettings() {}
void MenuItemSettings::execute() { this->executeSpecific(); }
void MenuItemSettings::executeSpecific() {
        std::cout << "EXECUTE!!!" << std::endl;
}

#endif // MENU_ITEM_SETTINGS_H
