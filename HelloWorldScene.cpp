#include "HelloWorldScene.h"
#include "MainScene.h"
#include "TianScene.h"
#include "astar\MapLayer.h"
#include "hwk\HKScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

 
    auto closeItem = MenuItemImage::create("CloseNormal.png","CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


    /////////////////////////////
    // 3. add your codes below...    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("wsbg.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	playBackgroundMusic("login.mp3", true);

	auto startItem = MenuItemImage::create(
		"login-1.png",
		"login-2.png",
		CC_CALLBACK_0(HelloWorld::startGame, this));
	auto menu2 = Menu::create(startItem, NULL);
	menu2->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(menu2, 1);
    
    return true;
}

void HelloWorld::playBackgroundMusic(const char* pszFilePath, bool bLoop)
{
	SimpleAudioEngine::getInstance()->playBackgroundMusic(pszFilePath, bLoop); //²¥·Å±³¾°ÒôÀÖ
}

void HelloWorld::startGame()
{
	auto tf = TransitionFade::create(0.2f, HKScene::createScene());
	Director::getInstance()->replaceScene(tf);

}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
