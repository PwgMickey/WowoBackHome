//
//  ScrollPage.cpp
//  PortraitScroll
//
//  Created by student on 16-1-7.
//
//

#include "ScrollPage.h"

ScrollPage* ScrollPage::create(Size size, Node* container/* = nullptr*/)
{
    
    ScrollPage* pRet = new (std::nothrow) ScrollPage();
    if (pRet && pRet->initWithViewSize(size, container))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}


bool ScrollPage::onTouchBegan(Touch *touch, Event *event)
{
    
     ScrollView::onTouchBegan(touch, event);
   
    return true;
    
}

void ScrollPage::onTouchMoved(Touch *touch, Event *event)
{
  ScrollView::onTouchMoved(touch, event);
    
}
void ScrollPage::onTouchEnded(Touch *touch, Event *event)
{
    
    ScrollView::onTouchEnded(touch, event);
    
    if (_direction==Direction::VERTICAL) {
        
        beginOffset=getContentOffset().y;
        log("beginOffset:%f",beginOffset);
    }

    
    float height=getViewSize().height;
     log("height:%f",height);
    
    
    
    float page=beginOffset/height;
    log("page:%f",page);
    
    
    
    int page1=beginOffset/height;
     log("page1:%d",page1);
    
    
    
    
    if ((fabs(page)-fabs(page1))>0.5){
      setContentOffset(Vec2(0,(page1-1)*height));
    }else
    {
      setContentOffset(Vec2(0,page1*height));
    }
    

    
}

void ScrollPage::onTouchCancelled(Touch *touch, Event *event)
{
    
}

void ScrollPage::setTouchEnabledPage(bool enabled)
{
    _eventDispatcher->removeEventListener(_touchListener);
    _touchListener = nullptr;
    
    if (enabled)
    {
        _touchListener = EventListenerTouchOneByOne::create();
        
        _touchListener->onTouchBegan = CC_CALLBACK_2(ScrollPage::onTouchBegan, this);
        _touchListener->onTouchMoved = CC_CALLBACK_2(ScrollPage::onTouchMoved, this);
        _touchListener->onTouchEnded = CC_CALLBACK_2(ScrollPage::onTouchEnded, this);
        _touchListener->onTouchCancelled = CC_CALLBACK_2(ScrollPage::onTouchCancelled, this);
        
        _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    }
    else
    {
        _dragging = false;
        _touchMoved = false;
        _touches.clear();
    }
}

void ScrollPage::setTouchEnabled(bool enabled)
{
    
}

