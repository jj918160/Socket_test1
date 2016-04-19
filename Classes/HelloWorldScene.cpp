#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
//#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::network;

using namespace cocostudio::timeline;

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
    Size winsize=Director::getInstance()->getWinSize();

    
    edit_userName=EditBox::create(Size(winsize.width/2,30), Scale9Sprite::create("220.png"));
   
    edit_userName->setPosition(Vec2(winsize.width-430, winsize.height-230));
   
    addChild(edit_userName);
    
    edit_userName->setFontColor(Color3B::RED);
    edit_userName->setFontSize(20);
    edit_userName->setInputMode(cocos2d::ui::EditBox::InputMode::ANY);
    
    edit_userPassWord=EditBox::create(Size(winsize.width/2,30), Scale9Sprite::create("220.png"));
    edit_userPassWord->setPosition(Vec2(winsize.width-430, winsize.height-330));
    addChild(edit_userPassWord);
    edit_userPassWord->setFontColor(Color3B::BLUE);
    edit_userPassWord->setFontSize(20);
    edit_userPassWord->setInputMode(cocos2d::ui::EditBox::InputMode::ANY);
    
    

    auto enter=MenuItemImage::create("220.png", "220.png",CC_CALLBACK_1(HelloWorld::menuHandler, this));
    enter->setPosition(Vec2(0,-280));

    
     auto 😊=Menu::create(enter,NULL);
     addChild(😊);

    是否正确();
    
    
    return true;
}

bool HelloWorld::是否正确(){
    CCLOG("正确");
    return true;
}
void HelloWorld::menuHandler(Ref*)
{
    
     sprintf(strName,"%s",edit_userName->getText());
     sprintf(strPassWOrd,"%s",edit_userPassWord->getText());
    
    char strSender[256];
    sprintf(strSender,"%s|%s",strName,strPassWOrd);
    HttpClient*httpclient=HttpClient::getInstance();
    HttpRequest*request=new HttpRequest();
    request->setRequestType(HttpRequest::Type::POST);
    request->setUrl("http://169.154.166.182/cgi-bin/ApacheProject.cgi");
    
    request->setResponseCallback(this,httpresponse_selector(HelloWorld::httpResponse));
    httpclient->setTimeoutForConnect(60);
    httpclient->send(request);
    request->release();
    CCLOG("enter");
    
}
void HelloWorld::httpResponse(HttpClient* client,HttpResponse*response)
{
    CCLOG("123");
    if (!response->isSucceed()) {
        const char*err=response->getErrorBuffer();
        CCLOG("response error=%s",err);
        return;
    }
    std::vector<char>*vChar=response->getResponseData();
    std::string str;
    std::vector<char>::iterator it;
    
    for (it=vChar->begin(); it!=vChar->end();it++) {
        str+=*it;
    }
    CCLOG("%s",str.c_str());
    int num=atoi(str.c_str());
    switch (num) {
        case 0:
            CCLOG("succssful");
            break;
            
        default:
            CCLOG("eorro");
            break;
    }
    
}
