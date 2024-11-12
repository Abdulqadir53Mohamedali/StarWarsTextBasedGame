#include <iostream>
#include <thread>   
#include <chrono>
#include <fstream>
#include <string>
#include <windows.h>
#include <map>
#include<memory>
using string = std::string;
struct GameSate {
	bool isPlayerDead;
	bool isPlayerAlive;
	bool isRunning;
};


void delay(int seconds) {
	std::this_thread::sleep_for(std::chrono::seconds(seconds));

}
void typeText(const string& text, int delayMs = 50) {
	for (char c : text) {
		std::cout << c << std::flush;  
		std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));  
	}
	std::cout << std::endl;  
}
void displayAsciiArt(const string& filePath) {
	std::ifstream file(filePath);
	if (file.is_open()) {
		std::string content((std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());

		std::cout  << content << std::endl;
		file.close();
	}
}
void storyIntro() {
	displayAsciiArt("title.txt");
	typeText("\nAs you drift in and out of consciousness...\n");
	delay(2);
	typeText("\nfleeting images flash before you. Cold metal arms grip you under your shoulders, dragging you through a dimly lit corridor. You catch glimpses of towering figures on either side, their movements rigid, voices mechanical. Echoes of metallic footsteps mix with the hum of distant machinery, like a heartbeat pulsing through the walls. Before you can fully process where you are, your vision fades to black.");
	delay(2);
	typeText("\nMoments or hours later ,it's hard to tell, you awaken, groggy and disoriented, slumped against the cold floor of a confined cell. The silence is broken only by the low hum of the ship around you. You are onboard the Genesis, and somehow,youknow you need to escape.");
}
void titleMarkings(const string& marking) {
	std::cout << marking << "\n";

}
void exampleInventoryStore() {

	std::map<std::string, std::unique_ptr<Item>> inventory;

	// Adding weapons to the inventory
	inventory["pistol"] = std::make_unique<Pistol>(15, 10); // Damage 15, Ammo Capacity 10
	inventory["rifle"] = std::make_unique<Rifle>(25, 30);   // Damage 25, Ammo Capacity 30

	// Dynamic casting to Weapon for actions specific to weapons
	auto pistol = dynamic_cast<Weapon*>(inventory["pistol"].get());
	if (pistol) {
		pistol->shoot();
		pistol->checkAmmo();
		pistol->reload();
	}

	auto rifle = dynamic_cast<Weapon*>(inventory["rifle"].get());
	if (rifle) {
		rifle->shoot();
		rifle->checkAmmo();
		rifle->reload();
	}
}


/*
Starting Point
- Wake up in seperatist holding / prision cell 
	- or wake up while being dragged there or carried
- you rember the battle thta iccured maye a few days ago or weeks
	- you may panic a bit 
- still working on how you will get out of the prision cell , thinking of a somewhat believeable escape

- will do checkpoints at the start of every floor , so withint he same run program they cna exit and continue 
- will think of adding stats such as kills , weapons used / collected , objectives etcm
*/
int main()
{
	displayAsciiArt("title.txt");

	titleMarkings("====");
	std::cout << "MENU\n";
	titleMarkings("====");

	std::cout << "1. Start Game\n";
	std::cout << "2. Load Game\n";
	std::cout << "3. Exit\n";




		
  		return 0;
	
}

/*
As you drift in and out of consciousness, fleeting images flash before you. Cold metal arms grip you under your shoulders, dragging you through a dimly lit corridor. You catch glimpses of towering figures on either side, their movements rigid, voices mechanical. Echoes of metallic footsteps mix with the hum of distant machinery, like a heartbeat pulsing through the walls. Before you can fully process where you are, your vision fades to black.

Moments or hours later—it's hard to tell—you awaken, groggy and disoriented, slumped against the cold floor of a confined cell. The silence is broken only by the low hum of the ship around you. You’re onboard the Genesis, and somehow, you know you need to escape.


patorjk.com

ht://github.com/aafulei/color-console
*/
