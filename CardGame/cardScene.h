#ifndef CARDSCENE_H
#define CARDSCENE_H

#include <src/Core/scene.h>
#include "CardGame/card.h"
#include "CardGame/deck.h"
#include <src/Presets/inputfield.h>

class CardScene : public Scene
{
public:
    CardScene();
    virtual ~CardScene();

    virtual void Update(float deltaTime);

private:
    Card* _card;
    Presets::InputField* _inputField;
};

#endif