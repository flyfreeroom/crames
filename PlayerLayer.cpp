#include "PlayerLayer.h"
#include "Config.h"

PlayerLayer::PlayerLayer()
{
}

PlayerLayer::~PlayerLayer()
{
}

bool PlayerLayer::init()
{
		
	//加载模型文件
	std::string fileName = "orc.c3t";  //"orc.c3b";
	_player = Sprite3D::create(fileName);
	_player->setScale(3.0f);
	auto s = Director::getInstance()->getWinSize();
	_player->setPosition(Vec2(s.width / 2.f, s.height / 2.f));
	_player->setGlobalZOrder(1);
	_player->setRotation3D(Vec3(0, 180, 0));
	addChild(_player);

	//加载武器
	auto sp = Sprite3D::create("axe.c3b");
	sp->setGlobalZOrder(-1);
	sp->setScale(100.0f);
	sp->setRotation3D(Vec3(0, 90, 0));
	//将武器放到玩家手上
	_player->getAttachNode("Bip001 R Hand")->addChild(sp);
	
	

	//获取骨骼动画信息
	auto animation = Animation3D::create(fileName);
	if (animation)
	{
		_idle = Animate3D::create(animation);
		_idle->retain();
		//让精灵循环播放动作
		Sequence*	pSequence = Sequence::create(_idle, NULL);
		_player->runAction(RepeatForever::create(pSequence));
	}

	// 创建一个事件监听器类型为OneByOne的单点触摸
	auto listener1 = EventListenerTouchOneByOne::create();
	// 设置是否吞没事件，在onTouchBegan方法返回true时吞没
	listener1->setSwallowTouches(true);
	listener1->onTouchBegan = CC_CALLBACK_2(PlayerLayer::onTouchBegan, this);
	listener1->onTouchMoved = CC_CALLBACK_2(PlayerLayer::onTouchMoved, this);
	listener1->onTouchEnded = CC_CALLBACK_2(PlayerLayer::onTouchEnded, this);
	// 添加监听器
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, _player);

	return true;
}

void PlayerLayer::draw(Renderer * renderer, const Mat4 & transform, uint32_t flags)
{
	Node::draw(renderer, transform, flags);
}

bool PlayerLayer::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	log("onTouchBegan");
	return true;
}

void PlayerLayer::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{

}

void PlayerLayer::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	log("onTouchMoved");
	//获得在触点所在的OpenGL坐标
	Vec2 touchLocation = touch->getLocation();
	//转换为当前层的模型坐标系
	touchLocation = this->convertToNodeSpace(touchLocation);
	log("end***** x=%f, y=%f", touchLocation.x, touchLocation.y);
//	auto distance = convertToNodeSpace(_player->getPosition()).getDistance(touchLocation);
	//auto time = distance / walkspeed;
	auto moveByAction = MoveTo::create(2.0f, touchLocation);
	Speed* walk = Speed::create(moveByAction,5);
	//_player->runAction(moveByAction);
	walk->setSpeed(walkspeed);
	this->runAction(walk);

}

