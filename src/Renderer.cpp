#include <stdio.h>
#include "../include/Renderer.h"

Renderer::Renderer(GameStateManager * g) {
	gsm = g;
	if (!playMusic.openFromFile("resources/SpaceGambit_SampleLoop1.wav"))
    	printf("Failed to get music.\n");
    playMusic.setLoop(true);
    if (!menuMusic.openFromFile("resources/SpaceGambit_SampleLoop2.wav"))
    	printf("Failed to get music.\n");
    menuMusic.setLoop(true);
    if (!pauseMusic.openFromFile("resources/SpaceGambit_SampleLoop3.wav"))
    	printf("Failed to get music.\n");
    pauseMusic.setLoop(true);
}

void Renderer::draw(sf::RenderWindow *window) {
	state = gsm->getTop();

	if (currState == MENUSTATE) {
		//TODO: This really only needs to be called when actually changed, but whatever
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
		//TODO: needs major refactoring.
		//	why multiple sf::Texts? Either pre-declare each one or use a single sf::Text
		gsm->window.draw(background);

		//set individual health bars
		//TODO: combine setting the bars and drawing
		//TODO: make the bar positions constants and more elegant
		for (int i = 0; i < 2; i++) {
			switch (((PickState *)state)->currentChoicePlayer[i]) {
			case 0:
				sp[i].setTexture(imagePower[0]);
				sp[i].setOrigin(sp[i].getGlobalBounds().width / 2, sp[i].getGlobalBounds().height / 2);
				strength[i].setSize(sf::Vector2f(150, 40));
				speed[i].setSize(sf::Vector2f(150, 40));
				defense[i].setSize(sf::Vector2f(150, 40));
				break;
			case 1:
				sp[i].setTexture(imagePower[1]);
				sp[i].setOrigin(sp[i].getGlobalBounds().width / 2, sp[i].getGlobalBounds().height / 2);
				strength[i].setSize(sf::Vector2f(200, 40));
				speed[i].setSize(sf::Vector2f(100, 40));
				defense[i].setSize(sf::Vector2f(150, 40));
				break;
			case 2:
				sp[i].setTexture(imagePower[2]);
				sp[i].setOrigin(sp[i].getGlobalBounds().width / 2, sp[i].getGlobalBounds().height / 2);
				strength[i].setSize(sf::Vector2f(100, 40));
				speed[i].setSize(sf::Vector2f(200, 40));
				defense[i].setSize(sf::Vector2f(150, 40));
				break;
			}
		}
		text.setCharacterSize(150);
		text.setString("Pick your Ship");
		centerText(&text, 100);
		gsm->window.draw(text);
		text.setCharacterSize(80);

        if (((PickState *)state)->players == 2)
        {
            text.setString("Strength");
            centerText(&text, 600);
            gsm->window.draw(text);

            text.setString("Speed");
            centerText(&text, 700);
            gsm->window.draw(text);

            text.setString("Defense");
            centerText(&text, 800);
            gsm->window.draw(text);
        }
        else
        {
            text.setString("Strength");
            centerText(&text, 600);
            text.setPosition (SCREENWIDTH/4 + text.getGlobalBounds().width/2, 600);
            gsm->window.draw(text);

            text.setString("Speed");
            centerText(&text, 700);
            text.setPosition (SCREENWIDTH/4 + text.getGlobalBounds().width/2, 700);
            gsm->window.draw(text);

            text.setString("Defense");
            centerText(&text, 800);
            text.setPosition (SCREENWIDTH/4 + text.getGlobalBounds().width/2, 800);
            gsm->window.draw(text);
        }

		//draw status bars and ship sprite

        for (int i = 0; i < ((PickState *)state) ->players; i++) {
            sp[i].setPosition(  (  (SCREENWIDTH*3/2)/(((PickState *)state)->players + 1)*(i+1)   ) - ( (SCREENWIDTH*3/2)/2 - SCREENWIDTH/2 ), 300);
            gsm->window.draw(sp[i]);

            strength[i].setPosition( (sp[i].getPosition().x), 600);
            gsm->window.draw(strength[i]);

            speed[i].setPosition(sp[i].getPosition().x, 700);
            gsm->window.draw(speed[i]);

            defense[i].setPosition(sp[i].getPosition().x, 800);
            gsm->window.draw(defense[i]);
        }

        for (int i = 0; i < ((PickState *)state)->players; i++) {
            if (((PickState *)state)->playerConfirmation[i] == 1)
                text.setString("Selected");
            else
                text.setString("Unselected");
            centerText(&text, 1000);
            text.setPosition((sp[i].getPosition().x), text.getPosition().y);
            gsm->window.draw(text);
        }


        text.setCharacterSize(60);
        text.setString("Use the Left/Right Keys to Select Rocket");
        centerText(&text, SCREENHEIGHT - (text.getGlobalBounds().height*3) - 10);
        gsm->window.draw(text);
        text.setString("Use the Down Key to Confirm Selction");
        centerText(&text, SCREENHEIGHT - (text.getGlobalBounds().height*2) - 10);
        gsm->window.draw(text);
        text.setString("Press P Key to Add or Remove Player 2");
        centerText(&text, SCREENHEIGHT - text.getGlobalBounds().height - 10);
        gsm->window.draw(text);
	}

	if (currState == PLAYSTATE) {
		if (((PlayState *)state)->pause) {
			window->draw(pauseState);
			window->draw(pauseSprite);
			sf::Text pauseNotif;
			pauseNotif.setFont(font);
			pauseNotif.setFillColor(sf::Color::Black);
			pauseNotif.setString("Game Paused");
			pauseNotif.setCharacterSize(80);
			pauseNotif.setPosition(SCREENWIDTH / 2 - pauseNotif.getGlobalBounds().width / 2, SCREENHEIGHT / 2 - 200);
			window->draw(pauseNotif);
		}

		if (((PlayState *) state) -> nextStage){
			window->draw(pauseState);
			sf::Text nextNotif;
			nextNotif.setFont(font);
			nextNotif.setFillColor(sf::Color::Black);
			nextNotif.setString("Get Ready For Next Stage\nPress Space Twice to Continue");

			nextNotif.setCharacterSize(80);

			nextNotif.setPosition(SCREENWIDTH / 2 - nextNotif.getGlobalBounds().width / 2, SCREENHEIGHT / 2 - 200);

			window->draw(nextNotif);

			((PlayState *) state) -> nextStageCounter  = 1;
		}
		else{

		//window->clear(sf::Color::);
		window->draw(background);
		//window->draw(shipHealth1);
		sf::ConvexShape triangle;
		triangle.setPointCount(3);
		triangle.setFillColor(sf::Color::Black);
		triangle.setPoint(0, sf::Vector2f(0, 0));
		triangle.setPoint(1, sf::Vector2f(0,SCREENHEIGHT/3));
		triangle.setPoint(2,sf::Vector2f(SCREENWIDTH/3, 0));
		window->draw(triangle);

		triangle.setPoint(0,sf::Vector2f(0,2*SCREENHEIGHT/3));
		triangle.setPoint(1,sf::Vector2f(0,SCREENHEIGHT));
		triangle.setPoint(2,sf::Vector2f(SCREENWIDTH/3, SCREENHEIGHT));
		window->draw(triangle);

		triangle.setPoint(0,sf::Vector2f(SCREENWIDTH*2/3, 0));
		triangle.setPoint(1,sf::Vector2f(SCREENWIDTH,0));
		triangle.setPoint(2,sf::Vector2f(SCREENWIDTH, SCREENHEIGHT/3));
		window->draw(triangle);

		triangle.setPoint(0,sf::Vector2f(SCREENWIDTH, SCREENHEIGHT*2/3));
		triangle.setPoint(1,sf::Vector2f(SCREENWIDTH,SCREENHEIGHT));
		triangle.setPoint(2,sf::Vector2f(SCREENWIDTH*2/3, SCREENHEIGHT));
		window->draw(triangle);
		rocketShipObjects[0].setPosition(((PlayState *)state)->ship1.pos);
		window->draw(rocketShipObjects[0]);
		if (((PlayState *)state)->twoPlayerMode) {
			rocketShipObjects[1].setPosition(((PlayState *)state)->ship2.pos);
			window->draw(rocketShipObjects[1]);
		}

		for (int p = 0; p < ((PlayState *)state)->powerups.size(); p++) {
			window->draw(((PlayState *)state)->powerups[p]->pSprite);
		}
		sf::Image turretbase;
		if (!turretbase.loadFromFile("resources/base_allgun.png")) {
				printf("Could not load turret\n");
		}
		for (int t = 0; t < ((PlayState *)state)->turrets.size(); t++) {
			((PlayState *)state)->turrets[t]->turretObjectbase.setPosition(((PlayState *)state)->turrets[t]->pos);
			window->draw(((PlayState *)state)->turrets[t]->turretObjectbase);
			((PlayState *)state)->turrets[t]->turretObject.setPosition(((PlayState *)state)->turrets[t]->pos);
			window->draw(((PlayState *)state)->turrets[t]->turretObject);
		}

		//draw bullets
		//sf::CircleShape bulletCircle;
		//bulletCircle.setFillColor(sf::Color::Red);

		for (int t = 0; t < ((PlayState *)state)->turrets.size(); t++) {

			for (int b = 0; b < ((PlayState *)state)->turrets[t]->bullets.size(); b++) {
				//Bullet * bullet = ((PlayState *)state)->turrets[t]->bullets[b];

				// sprite/texture code for bullets
			 	//turrets[t]->bullets[b]->shape =  sf::CircleShape();
				float bRadius = ((PlayState *)state)->turrets[t]->bullets[b]->radius;
				((PlayState *)state)->turrets[t]->bullets[b]->bulletObject.setScale(.01f*bRadius,.01f*bRadius);
				((PlayState *)state)->turrets[t]->bullets[b]->bulletObject.setPosition(
					((PlayState *)state)->turrets[t]->bullets[b]->pos - sf::Vector2f(.01f*bRadius, .01f*bRadius));
				gsm->window.draw(((PlayState *)state)->turrets[t]->bullets[b]->bulletObject);

				//bulletCircle.setRadius(radius);
				//bulletCircle.setPosition(bullet->pos - sf::Vector2f(radius, radius));

				//gsm->window.draw(bulletCircle);
			}
		}

		//HUD; later to be refactored into render class
		// position HUD frame
		if (!((PlayState *)state)->twoPlayerMode) {
		loadTexture(&hudTexture, "resources/HUD_1player.png");
	}
	else{
		loadTexture(&hudTexture, "resources/HUD_2player.png");
	}
		//hudTexture.loadFromImage(hudImage);
		sf::Sprite hud;
		hud.setTexture(hudTexture);
		hud.setPosition(0, 0);
		hud.setScale(SCREENWIDTH / 1800.f, SCREENWIDTH / 1800.f);
		window->draw(hud);


		//Player 1 HUD
		// bar.setFillColor(sf::Color::White);
		// bar.setSize(sf::Vector2f(100, 50));
		// bar.setPosition(10, 20);

		health.setFillColor(sf::Color::Red);

		health.setSize(sf::Vector2f(600*(((PlayState *)state)->ship1.currentHealth / ((PlayState *)state)->ship1.maxHealth), 50));
		health.setPosition(110, 20);

		loadFont(&font, "resources/spaceranger.ttf");

		text.setFont(font);
		text.setFillColor(sf::Color::White);
		text.setPosition(10, 90);
		text.setCharacterSize(40);
		text.setString("Score: " + std::to_string(((PlayState *)state)->ship1.points));

		window->draw(bar);
		window->draw(health);
		window->draw(text);

		//player 2 HUD
		if (((PlayState *)state)->twoPlayerMode) {
			// sf::RectangleShape bar2;
			// bar2.setFillColor(sf::Color::White);
			// bar2.setSize(sf::Vector2f(100, 50));
			// bar2.setPosition(SCREENWIDTH - 500, 20);

			sf::RectangleShape health2;
			health2.setFillColor(sf::Color::Red);
			health2.setSize(sf::Vector2f(600 * (((PlayState *)state)->ship2.currentHealth / ((PlayState *)state)->ship2.maxHealth), 50));
			health2.setPosition(SCREENWIDTH - 730, 20);

			text2.setFont(font);
			text2.setFillColor(sf::Color::White);
			text2.setPosition(SCREENWIDTH - 200, 90);
			text2.setCharacterSize(40);
			text2.setString("  Score: " + std::to_string(((PlayState *)state)->ship1.points));

			window->draw(bar2);
			window->draw(health2);
			window->draw(text2);
		}

		//stage counter
		stage.setFont(font);
		stage.setFillColor(sf::Color::White);
		stage.setString("Stage: ");
		stage.setCharacterSize(80);
		stage.setPosition(10, SCREENHEIGHT - 200);
		window->draw(stage);

		stageCount.setFont(font);
		stageCount.setFillColor(sf::Color::White);
		stageCount.setString(std::to_string(((PlayState *)state)->level));
		stageCount.setCharacterSize(80);
		stageCount.setPosition(stage.getPosition().x + stage.getGlobalBounds().width / 2 - stageCount.getGlobalBounds().width / 2, stage.getPosition().y + stageCount.getGlobalBounds().height + 10);
		window->draw(stageCount);

		//level Timer
		levelTimer.setFont(font);
		levelTimer.setFillColor(sf::Color::White);
		levelTimer.setString("Timer: ");
		levelTimer.setCharacterSize(80);
		levelTimer.setPosition(SCREENWIDTH - levelTimer.getGlobalBounds().width - 10, SCREENHEIGHT - 200);
		window->draw(levelTimer);

		timerCount.setFont(font);
		timerCount.setFillColor(sf::Color::White);
		if (((PlayState *)state)->stageTimer >= 10)
			timerCount.setString(std::to_string(static_cast<int>(((PlayState *)state)->stageTimer)));
		else
			timerCount.setString("0" + std::to_string(static_cast<int>(((PlayState *)state)->stageTimer)));
		timerCount.setCharacterSize(80);
		timerCount.setPosition(levelTimer.getPosition().x + levelTimer.getGlobalBounds().width / 2 - timerCount.getGlobalBounds().width / 2, levelTimer.getPosition().y + timerCount.getGlobalBounds().height + 10);
		window->draw(timerCount);
	}

	}
	if (currState == OPTIONSTATE) {
		//TODO: This really only needs to be called when actually changed, but whatever
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
            {
                int j = ((OptionState *)state)->hor_CurrentChoice;

                if(i == 0)
                {
                    text.setString(oOptions[i] + "> " + resolution[j]  +" <");
                }
                else
                {
                text.setString("> " + oOptions[i] + " <");
                }
            }
			else
				text.setString(oOptions[i]);
			centerText(&text, SCREENHEIGHT*0.3 + i * 100);
			gsm->window.draw(text);
		}

		sf::RectangleShape volumeSlider;
		volumeSlider.setFillColor(sf::Color(100,100,100));
		volumeSlider.setSize(sf::Vector2f(150, 50));
		volumeSlider.setPosition(SCREENWIDTH / 2 + 325, SCREENHEIGHT*0.3 + 75);
		window->draw(volumeSlider);

		volumeSlider.setFillColor(sf::Color::Red);
		volumeSlider.setSize(sf::Vector2f(((OptionState *)state)->volumeLevel*1.5, 50));
		window->draw(volumeSlider);
	}
	if (currState == FINISHSTATE) {
		gsm->window.draw(background);
		text.setFillColor(sf::Color::White);
		text.setCharacterSize(150);
		if (((FinishState *)state)->winner == 0){
 			text.setString("No!  You Died!");
 		}

 		else if (((FinishState *)state)->winner == 1) {

 			text.setString("Player 2 Wins!");
 		}
 		else {
 			text.setString("Player 1 Wins!");
 		}
		centerText(&text, 150);
		gsm->window.draw(text);

		text.setCharacterSize(80);
		for (int i = 0; i < 2; i++) {
			if (i == ((FinishState *)state)->currentChoice) {
				text.setString("> " + fOptions[i] + " <");
			}
			else {
				text.setString(fOptions[i]);
			}
			centerText(&text, 500 + i * 100);
			gsm->window.draw(text);
		}
	}
}

void Renderer::handleInput(sf::Event event) {

}

void Renderer::loadFont(sf::Font * font, std::string filename) {
	if (!font->loadFromFile(filename))
		// printf("Failed to load %s.\n", filename);
		printf("Failed to load File.\n");
}

void Renderer::loadTexture(sf::Texture * texture, std::string filename) {
	if (!texture->loadFromFile(filename))
		printf("Failed to load texture.\n");
}

void Renderer::loadImage(sf::Image * image, std::string filename) {
	if (!image->loadFromFile(filename))
		printf("Failed to load image.\n");
}

void Renderer::setState(int newState) {
	currState = newState;

	// playMusic.stop();
	// pauseMusic.stop();
	// menuMusic.stop();

	if (newState == MENUSTATE) {
		pauseMusic.stop();
		menuMusic.pause();
		menuMusic.setVolume(volume);
		menuMusic.play();

		loadFont(&font, "resources/spaceranger.ttf");
		loadTexture(&texture, "resources/LV2.JPG");
		background.setTexture(texture);
		auto size = background.getTexture()->getSize();
		background.setScale(float(SCREENWIDTH)/size.x, float(SCREENHEIGHT)/size.y);
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
		menuMusic.stop();
		pauseMusic.stop();
		playMusic.setVolume(volume);
		playMusic.play();

		loadImage(&image, "resources/LV1.JPG");

		printf("newState PLAYSTATE: %d %d\n", shipTypes[0], shipTypes[1]);
		for (int i = 0; i < 2; i++) {
			switch (shipTypes[i]) {
				printf("SHIPS %i %i\n", shipTypes[0], shipTypes[1]);
				case 0:
					loadTexture(&rocketShipTextures[i], "resources/SHIP_ATTACK.png");
					break;
				case 1:
					loadTexture(&rocketShipTextures[i], "resources/SHIP_DEFENSE.png");
					break;
				case 2:
					loadTexture(&rocketShipTextures[i], "resources/SHIP_SPEED.png");
					break;
			}
		}

		texture.loadFromImage(image);
		background.setTexture(texture);
		auto size = background.getTexture()->getSize();
		background.setScale(float(SCREENWIDTH)/size.x, float(SCREENHEIGHT)/size.y);

		for (int i = 0; i < 2; i++) {
			rocketShipObjects[i].setTexture(rocketShipTextures[i]);
			rocketShipObjects[i].setScale(0.1f, 0.1f);
			rocketShipObjects[i].setOrigin(
				(rocketShipObjects[i].getTexture()->getSize().x) / 2,
				(rocketShipObjects[i].getTexture()->getSize().y) / 2);
		}

		// load pause fonts
		loadTexture(&pauseTexture, "resources/pause.png");
		pauseSprite.setTexture(pauseTexture);

		pauseSprite.setScale(0.3f, 0.3f);
		pauseSprite.setPosition(SCREENHEIGHT / 2 - pauseSprite.getGlobalBounds().width / 2, SCREENWIDTH / 2);
		sf::Color color(220, 220, 220);
		color.a = 90;
		pauseState.setFillColor(color);
		pauseState.setPosition(0, 0);
		pauseState.setSize(sf::Vector2f(SCREENWIDTH, SCREENHEIGHT));
	}

	else if (newState == OPTIONSTATE) {
		loadFont(&font, "resources/spaceranger.ttf");
		loadTexture(&texture, "resources/LV2.JPG");
		background.setTexture(texture);
		background.setPosition(0, 0);
		auto size = background.getTexture()->getSize();
   		background.setScale(float(SCREENWIDTH)/size.x, float(SCREENHEIGHT) / size.y);
		text.setFont(font);
	}

	else if (newState == FINISHSTATE) {
		playMusic.stop();
		pauseMusic.setVolume(volume);
		pauseMusic.play();

		loadFont(&font, "resources/spaceranger.ttf");
		loadTexture(&texture, "resources/LV1.JPG");
		//texture.loadFromImage(image);
		background.setTexture(texture);
		auto size = background.getTexture()->getSize();
		background.setScale(float(SCREENWIDTH)/size.x, float(SCREENHEIGHT)/size.y);

		text.setFont(font);
		text.setFillColor(sf::Color::Red);
	}
}

void Renderer::centerText(sf::Text *text, int y) {
	sf::FloatRect textRect = text->getLocalBounds();
	text->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text->setPosition(sf::Vector2f(SCREENWIDTH/2.0f, y));
}

/*void Renderer::loadPauseFonts() {
	loadTexture(&pauseTexture, "resources/pause.png");
	pauseSprite.setTexture(pauseTexture);
	pauseSprite.setScale(0.3f, 0.3f);
	pauseSprite.setPosition(SCREENHEIGHT / 2 - pauseSprite.getGlobalBounds().width / 2, SCREENWIDTH / 2);
	sf::Color color(220, 220, 220);
	color.a = 90;
	pauseState.setFillColor(color);
	pauseState.setPosition(0, 0);
	pauseState.setSize(sf::Vector2f(SCREENWIDTH, SCREENHEIGHT));
}*/
