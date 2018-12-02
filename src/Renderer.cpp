#include <stdio.h>
#include "../../include/Renderer.h"

Renderer::Renderer(GameStateManager * g) {
	gsm = g;
}

void Renderer::draw(sf::RenderWindow *window) {
	state = gsm->getTop();
	if (currState == MENUSTATE) {
		gsm->window.draw(background);
		text.setCharacterSize(175);
		text.setString("Space Gambit");
		centerText(&text, SCREENHEIGHT * 0.1);
		gsm->window.draw(text);

		text.setCharacterSize(70);

		for (int i = 0; i < 3; i++) {
			if (i == ((MenuState *)state)->currentChoice)
				text.setString("> " + options[i] + " <");
			else
				text.setString(options[i]);
			centerText(&text, SCREENHEIGHT*0.2 + i * 100);
			gsm->window.draw(text);
		}
	}

	if (currState == PICKSTATE) {
		gsm->window.draw(background);

		//set individual health bars
		//TODO: combine setting the bars and drawing
		//TODO: make the bar positions constants and more elegant
		for (int i = 0; i < 2; i++) {
			switch (((PickState *)state)->currentChoicePlayer[i]) {
			case 0:
				sp[i].setTexture(imagePower[0]);
				sp[i].setOrigin(sp[i].getGlobalBounds().width / 2, sp[i].getGlobalBounds().height / 2);
				strength[i].setSize(sf::Vector2f(100, 10));
				speed[i].setSize(sf::Vector2f(80, 10));
				defense[i].setSize(sf::Vector2f(30, 10));
				break;
			case 1:
				sp[i].setTexture(imagePower[1]);
				sp[i].setOrigin(sp[i].getGlobalBounds().width / 2, sp[i].getGlobalBounds().height / 2);
				strength[i].setSize(sf::Vector2f(30, 10));
				speed[i].setSize(sf::Vector2f(100, 10));
				defense[i].setSize(sf::Vector2f(80, 10));
				break;
			case 2:
				sp[i].setTexture(imagePower[2]);
				sp[i].setOrigin(sp[i].getGlobalBounds().width / 2, sp[i].getGlobalBounds().height / 2);
				strength[i].setSize(sf::Vector2f(30, 10));
				speed[i].setSize(sf::Vector2f(80, 10));
				defense[i].setSize(sf::Vector2f(100, 10));
				break;
			}
		}
		text.setCharacterSize(150);
		text.setString("Pick your Ship");
		centerText(&text, 100);
		gsm->window.draw(text);

		text.setCharacterSize(80);

		text.setString("Strength");
		centerText(&text, 600);
		gsm->window.draw(text);

		text.setString("Speed");
		centerText(&text, 700);
		gsm->window.draw(text);

		text.setString("Defense");
		centerText(&text, 800);
		gsm->window.draw(text);

		//draw status bars and ship sprite
		for (int i = 0; i < 2; i++) {
			sp[i].setPosition((SCREENWIDTH / 2 + SCREENWIDTH / 4 * pow(-1, 1 + i)), 300);
			gsm->window.draw(sp[i]);

			strength[i].setPosition((SCREENWIDTH / 2 + SCREENWIDTH / 4 * pow(-1, 1 + i)), 600);
			gsm->window.draw(strength[i]);

			speed[i].setPosition((SCREENWIDTH / 2 + SCREENWIDTH / 4 * pow(-1, 1 + i)), 700);
			gsm->window.draw(speed[i]);

			defense[i].setPosition((SCREENWIDTH / 2 + SCREENWIDTH / 4 * pow(-1, 1 + i)), 800);
			gsm->window.draw(defense[i]);
		}
	}

	if (currState == PLAYSTATE) {
		window->draw(background);
		//window->draw(shipHealth1);

		rocketShipObjects[0].setPosition(((PlayState *)state)->ship1.pos);
		rocketShipObjects[1].setPosition(((PlayState *)state)->ship2.pos);
		window->draw(rocketShipObjects[0]);
		window->draw(rocketShipObjects[1]);

		for (int t = 0; t < ((PlayState *)state)->turrets.size(); t++) {
			window->draw( ((PlayState *)state)->turrets[t]->turretObject );
		}

		//draw bullets
		bulletCircle.setFillColor(sf::Color::Red);

		for (int t = 0; t < ((PlayState *)state)->turrets.size(); t++) {
			Turret * turret = ((PlayState *)state)->turrets[t];
			for (int b = 0; b < turret->bullets.size(); b++) {
				Bullet * bullet = turret->bullets[b];
				bullet->shape = sf::CircleShape();
				float bRadius = turret->bullets[b]->radius;
				bullet->shape.setRadius(bRadius);
				bullet->shape.setPosition(
					bullet->pos - sf::Vector2f(bRadius, bRadius));

				gsm->window.draw(bullet->shape);
			}
		}

		//HUD; later to be refactored into render class
			// position HUD frame

		loadImage(&hudImage, "resources/HP_P1VT.png");
		hudTexture.loadFromImage(hudImage);

		hud.setTexture(hudTexture);
		hud.setPosition(0, 0);
		hud.setScale(0.7f, 0.5f);
		window->draw(hud);

		//Player 1 HUD
		bar.setFillColor(sf::Color::White);
		bar.setSize(sf::Vector2f(100, 50));
		bar.setPosition(10, 20);

		bar.setFillColor(sf::Color::Red);
		health.setSize(sf::Vector2f(100 * (((PlayState *)state)->ship1.currentHealth / ((PlayState *)state)->ship1.maxHealth), 50));
		health.setPosition(10, 20);

		loadFont(&font, "resources/spaceranger.ttf");

		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setPosition(10, 90);
		text.setCharacterSize(40);
		text.setString("  Score: " + std::to_string(((PlayState *)state)->ship1.points));

		window->draw(bar);
		window->draw(health);
		window->draw(text);

		//player 2 HUD
		bar2.setFillColor(sf::Color::White);
		bar2.setSize(sf::Vector2f(100, 50));
		bar2.setPosition(SCREENWIDTH - 250, 20);

		bar2.setFillColor(sf::Color::Red);
		health2.setSize(sf::Vector2f(100 * (((PlayState *)state)->ship2.currentHealth / ((PlayState *)state)->ship2.maxHealth), 50));
		health2.setPosition(SCREENWIDTH - 250, 20);


		text2.setFont(font);
		text2.setFillColor(sf::Color::White);
		text2.setPosition(SCREENWIDTH - 250, 90);
		text2.setCharacterSize(40);
		text2.setString("  Score: " + std::to_string(((PlayState *)state)->ship1.points));

		window->draw(bar2);
		window->draw(health2);
		window->draw(text2);

		//stage counter

		stage.setFont(font);
		stage.setFillColor(sf::Color::White);
		stage.setPosition(10, SCREENHEIGHT - 150);
		stage.setCharacterSize(80);
		stage.setString("Stage: ");
		window->draw(stage);


		timer.setFont(font);
		timer.setFillColor(sf::Color::White);
		timer.setPosition(SCREENWIDTH - 200, SCREENHEIGHT - 150);
		timer.setCharacterSize(80);
		timer.setString(std::to_string(static_cast<int>(((PlayState *)state)->stageTimer)));

		window->draw(timer);

		//level counter

		levelCount.setFont(font);
		levelCount.setFillColor(sf::Color::White);
		levelCount.setCharacterSize(80);
		levelCount.setString(std::to_string(((PlayState *)state)->level));
		levelCount.setPosition(SCREENWIDTH - levelCount.getLocalBounds().width - 50, SCREENHEIGHT - 150);

		window->draw(levelCount);

		//level counter
		levelNumber.setFont(font);
		levelNumber.setFillColor(sf::Color::White);
		levelNumber.setCharacterSize(80);
		levelNumber.setString("Level: ");
		levelNumber.setPosition(SCREENWIDTH - levelCount.getLocalBounds().width - 60 - levelNumber.getLocalBounds().width, SCREENHEIGHT - 150);
		window->draw(levelNumber);
	}
	if (currState == OPTIONSTATE) {
		gsm->window.clear(sf::Color(255, 255, 255));
		gsm->window.draw(background);
		text.setCharacterSize(150);
		text.setString("Welcome to the");
		centerText(&text, SCREENHEIGHT*0.1);
		gsm->window.draw(text);
		text.setString("Options Menu");
		centerText(&text, SCREENHEIGHT*0.2);
		gsm->window.draw(text);

		text.setCharacterSize(70);

		for (int i = 0; i < 5; i++) {
			if (i == ((OptionState *)state)->currentChoice)
				text.setString("> " + oOptions[i] + " <");
			else
				text.setString(oOptions[i]);
			centerText(&text, SCREENHEIGHT*0.3 + i * 100);
			gsm->window.draw(text);
		}
	}
}

void Renderer::handleInput(sf::Event event) {

}

void Renderer::loadFont(sf::Font * font, std::string filename) {
	if (!font->loadFromFile(filename)) {
		printf("Failed to load font.\n");
	}
}

void Renderer::loadTexture(sf::Texture * texture, std::string filename) {
	if (!texture->loadFromFile(filename)) {
		printf("Failed to load texture.\n");
	}
}

void Renderer::loadImage(sf::Image * image, std::string filename) {
	if (!image->loadFromFile(filename)) {
		printf("Failed to load image.\n");
	}
}

void Renderer::setState(int newState) {
	currState = newState;
	if (newState == MENUSTATE) {
		loadFont(&font, "resources/spaceranger.ttf");
		loadTexture(&texture, "resources/space_real.jpg");
		background.setTexture(texture);
		background.setPosition(0, 0);
		background.setScale(1.5f, 1.5f);
		text.setFont(font);
		text.setFillColor(sf::Color::White);
	}

	else if (newState == PICKSTATE) {
		background.setPosition(0, 0);
		//auto size = background.getTexture()->getSize();
		background.setScale(1.5f, 1.5f);

		text.setFont(font);
		text.setFillColor(sf::Color::White);
		sp[0].setScale(0.2f, 0.2f);
		sp[1].setScale(0.2f, 0.2f);

		sp[1].setOrigin(sp[1].getGlobalBounds().width / 2,
						sp[1].getGlobalBounds().height / 2);

		for (int i = 0; i < 2; i++) {
			strength[i].setSize(sf::Vector2f(100.0f, 100.0f));
			speed[i].setSize(sf::Vector2f(100.0f, 100.0f));
			defense[i].setSize(sf::Vector2f(100.0f, 100.0f));
		}

		loadFont(&font, "resources/spaceranger.ttf");
		loadTexture(&backgroundTexture, "resources/space_real.jpg");
		background.setTexture(backgroundTexture);

		loadTexture(&imagePower[0], "resources/SHIP_ATTACK.png");
		loadTexture(&imagePower[1], "resources/SHIP_DEFENSE.png");
		loadTexture(&imagePower[2], "resources/SHIP_SPEED.png");

		for (int i = 0; i < 2; i++) {
			strength[i].setFillColor(sf::Color::Red);
			speed[i].setFillColor(sf::Color::Green);
			defense[i].setFillColor(sf::Color::Blue);
		}
	}

	else if (newState == PLAYSTATE) {
		loadImage(&image, "resources/space_background.jpg");

		printf("newState PLAYSTATE: %d %d\n", shipTypes[0], shipTypes[1]);
		for (int i = 0; i < 2; i++) {
			switch (shipTypes[i]) {
				case 0:
					loadTexture(&rocketShipTextures[i], "resources/SHIP_SPEED.png");
					break;
				case 1:
					loadTexture(&rocketShipTextures[i], "resources/SHIP_DEFENSE.png");
					break;
				case 2:
					loadTexture(&rocketShipTextures[i], "resources/SHIP_ATTACK.png");
					break;
			}
		}

		texture.loadFromImage(image);
		background.setTexture(texture);
		//background.setPosition(0, 0);
		//background.setScale(0.7f, 0.5f);

		for (int i = 0; i < 2; i++) {
			rocketShipObjects[i].setTexture(rocketShipTextures[i]);
			rocketShipObjects[i].setScale(0.1f, 0.1f);
			rocketShipObjects[i].setOrigin(
				(rocketShipObjects[i].getTexture()->getSize().x) / 2,
				(rocketShipObjects[i].getTexture()->getSize().y) / 2);
		}
	}

	else if (newState == OPTIONSTATE) {
		loadFont(&font, "resources/spaceranger.ttf");
		loadTexture(&texture, "resources/space_real.jpg");
		background.setTexture(texture);
		background.setPosition(0, 0);
		background.setScale(1.5f, 1.5f);
		text.setFont(font);
	}
}

void Renderer::centerText(sf::Text *text, int y) {
	sf::FloatRect textRect = text->getLocalBounds();
	text->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text->setPosition(sf::Vector2f(SCREENWIDTH, y));
}