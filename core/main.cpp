#include <iostream>
#include <string>

#include "../include/roundlinkedlist.h"
#include "../include/menuitemsettings.h"

using namespace std;

void populateMenu (RoundLinkedList<MenuItem>* &);
void printCurrent(RoundLinkedList<MenuItem>* &);

int main() {
        RoundLinkedList<MenuItem>* menu = new RoundLinkedList<MenuItem>;
        populateMenu(menu);

        std::string line = "";
        while (line != "q") {
                printCurrent(menu);
                getline(cin, line);

                if (line == "n") { // Next - swipe right -> left
                        menu->rotateNext();
                } else if (line == "p") { // Previous - swipe left -> right
                        menu->rotatePrev();
                } else if (line == "g") { // Enter menu/start - Single tap
                        if (menu->getCurrentItem()->hasSubMenu()) {
                                menu = menu->getCurrentItem()->getSubMenu();
                                menu->reset();
                        } else {
                                menu->getCurrentItem()->execute();
                        }
                } else if (line == "b") { // Back - Double tap?
                        if (menu->hasParent()) {
                                menu = menu->getParent();
                        } else {
                                cout << "You are at root node" << endl;
                        }
                } else if (line == "r") { // Single press button
                        menu->reset();
                } else if (line == "d") { // Double press side button
                        // Go home to clock
                        while (menu->getParent() != NULL) {
                                menu = menu->getParent();
                        }
                        menu->reset();
                }
        }

        delete menu;
        return 0;
}

void populateMenu (RoundLinkedList<MenuItem>*& menu) {
        RoundLinkedList<MenuItem>* settingsSubMenu = new RoundLinkedList<MenuItem>();
        settingsSubMenu->setParent(menu);
        settingsSubMenu->addItem(new MenuItemSettings("Brightness"), true);
        settingsSubMenu->addItem(new MenuItemSettings("Do not disturb"));
        settingsSubMenu->addItem(new MenuItemSettings("System"));
        settingsSubMenu->addItem(new MenuItemSettings("About"));
        settingsSubMenu->reset();

        MenuItem* settings = new MenuItemSettings("Settings");
        settings->addSubMenu(settingsSubMenu);

        menu->addItem(settings);
        menu->addItem(new MenuItemSettings("Flashlight"));
        menu->addItem(new MenuItemSettings("Clock"), true);
        menu->addItem(new MenuItemSettings("Lock"));
        menu->reset();
}

void printCurrent(RoundLinkedList<MenuItem>*& menu) {
        cout << "[ " <<  menu->getPreviousItem()->getTitle();
        cout << " << " << menu->getCurrentItem()->getTitle() << " >> ";
        cout << menu->getNextItem()->getTitle() << " ]" << endl;
}
