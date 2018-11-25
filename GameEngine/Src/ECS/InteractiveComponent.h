#pragma once

#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"
#include "../AssetManager.h"

class InteractiveComponent : public Component
{
private:
	SpriteComponent *sprite;
	DialogueComponent * dialogue;
	std::string dialogueText;
	Manager * manager;

public:
	bool contactWithPlayer = false;
	InteractiveComponent(std::string text) : dialogueText(text) {}
	~InteractiveComponent(){}

	void init() override
	{
		sprite = &entity->getComponent<SpriteComponent>();
		manager = &entity->getManager();
	}

	void action() {
		std::cout << "INTERACTIVE OBJECT ACTION" << std::endl;
		manager->getGroup(Game::groupDialogues)[0]->getComponent<DialogueComponent>().showDialogue(dialogueText);
	}

	void update() override
	{

	}

	void draw() override
	{
		//TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
	}
};
