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
		
	//����ģ���ļ�
	std::string fileName = "orc.c3t";  //"orc.c3b";
	_player = Sprite3D::create(fileName);
	_player->setScale(3.0f);
	auto s = Director::getInstance()->getWinSize();
	_player->setPosition(Vec2(s.width / 2.f, s.height / 2.f));
	_player->setGlobalZOrder(1);
	_player->setRotation3D(Vec3(0, 180, 0));
	addChild(_player);

	//��������
	auto sp = Sprite3D::create("axe.c3b");
	sp->setGlobalZOrder(-1);
	sp->setScale(100.0f);
	sp->setRotation3D(Vec3(0, 90, 0));
	//�������ŵ��������
	_player->getAttachNode("Bip001 R Hand")->addChild(sp);
	
	

	//��ȡ����������Ϣ
	auto animation = Animation3D::create(fileName);
	if (animation)
	{
		_idle = Animate3D::create(animation);
		_idle->retain();
		//�þ���ѭ�����Ŷ���
		Sequence*	pSequence = Sequence::create(_idle, NULL);
		_player->runAction(RepeatForever::create(pSequence));
	}

	// ����һ���¼�����������ΪOneByOne�ĵ��㴥��
	auto listener1 = EventListenerTouchOneByOne::create();
	// �����Ƿ���û�¼�����onTouchBegan��������trueʱ��û
	listener1->setSwallowTouches(true);
	listener1->onTouchBegan = CC_CALLBACK_2(PlayerLayer::onTouchBegan, this);
	listener1->onTouchMoved = CC_CALLBACK_2(PlayerLayer::onTouchMoved, this);
	listener1->onTouchEnded = CC_CALLBACK_2(PlayerLayer::onTouchEnded, this);
	// ��Ӽ�����
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
	//����ڴ������ڵ�OpenGL����
	Vec2 touchLocation = touch->getLocation();
	//ת��Ϊ��ǰ���ģ������ϵ
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

