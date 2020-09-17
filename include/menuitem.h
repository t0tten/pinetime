#ifndef MENU_ITEM_H
#define MENU_ITEM_H

/*
 * Abstract base class for all menu items
 * */

#include <string>

#include "roundlinkedlist.h"

class MenuItem {
        private:
                std::string title;
                std::string description;
                int icon;
                RoundLinkedList<MenuItem>* subMenu;

        public:
                MenuItem(std::string title);
                virtual ~MenuItem();

                std::string getTitle();
                std::string getDescription();
                int getIcon();
                RoundLinkedList<MenuItem>* getSubMenu();
                bool hasSubMenu();

                void setDescription(std::string description);
                void setIcon(int icon);
                void addSubMenu(RoundLinkedList<MenuItem>* subMenu);

                virtual void execute() = 0;
};

#endif // MENU_ITEM_H
