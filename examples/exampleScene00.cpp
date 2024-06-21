#include "exampleScene00.h"
#include "examples/testobj.h"
#include "src/UI/uielement.h"
#include <src/UI/image.h>

ExampleScene00::ExampleScene00()
{
    canvas = new TestObj();
    Canvas* c = new Canvas(glm::vec2(1280, 720));
    canvas->AddComponent(c);
    canvas->transform->position = glm::vec3(c->GetCanvasWidth()/2, c->GetCanvasHeight()/2, 0.0f);
    testObj = new TestObj();

    testObj->transform->position = glm::vec3(0.0f, 0.0f, 0.0f);
    testObj->AddComponent(new Image());
    testObj->AddComponent(new Button(190, 190));

    Button* b = testObj->GetComponent<Button>();
    b->SetOnHover(std::bind(&ExampleScene00::OnButtonHovered, this));
    b->SetOnPress(std::bind(&ExampleScene00::OnButtonClicked, this));
    b->SetOnRelease(std::bind(&ExampleScene00::OnButtonReleased, this));

    AnimatedSprite* sprite = new AnimatedSprite("assets/Sprite_Sheet_G4.tga", 4, 4, 0.5f);
    Image* i = testObj->GetComponent<Image>();
    i->AddSprite(sprite);
    sprite->AddAnimation({1,2,3,4});
    i = nullptr;

    testObj->AddComponent(new Text());
    Text* t = testObj->GetComponent<Text>();
    t->text = "Heppo World!";

    AddChild(canvas);
    canvas->AddChild(testObj);
}

ExampleScene00::~ExampleScene00()
{
}

void ExampleScene00::Update(float deltaTime)
{
    if(Input()->GetKey(KeyCode::D))
    {
        testObj->transform->position.x += 10.0f * deltaTime;
        dynamic_cast<SpriteSheet*>(testObj->GetComponent<Image>()->GetSprite())->SetCurrentFrame(2);
    }
}

void ExampleScene00::OnButtonClicked()
{
    std::cout << "Button Clicked!" << std::endl;
}

void ExampleScene00::OnButtonHovered()
{
    std::cout << "Button Hovered!" << std::endl;
}

void ExampleScene00::OnButtonReleased()
{
    std::cout << "Button Released!" << std::endl;
}
