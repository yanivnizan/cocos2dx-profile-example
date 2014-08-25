//
// Created by Fedor Shubin on 6/14/14.
//

#include "ProfileEventHandler.h"

#define TAG "ProfileEventHandler >>>"

USING_NS_CC;

void ProfileEventHandler::onLoginFailed(soomla::CCProvider provider, cocos2d::__String *errorDescription) {
    log("%s Login to %s has failed: %s", TAG, soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString(), errorDescription->getCString());
}

void ProfileEventHandler::onLoginFinished(soomla::CCUserProfile *userProfile) {
    log("%s %s", TAG, "onLoginFinished");
    
    EventCustom customEvent(soomla::CCProfileConsts::EVENT_LOGIN_FINISHED);
    customEvent.setUserData(userProfile);
    Director::getInstance()->getEventDispatcher()->dispatchEvent(&customEvent);
}

void ProfileEventHandler::onLoginStarted(soomla::CCProvider provider) {
    log("%s Login to %s has started", TAG, soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString());
}

void ProfileEventHandler::onLoginCancelledEvent(soomla::CCProvider provider) {
    log("%s Login to %s has cancelled", TAG, soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString());
}

void ProfileEventHandler::onLogoutFailed(soomla::CCProvider provider, cocos2d::__String *errorDescription) {
    log("%s Login to %s has FAILED: %s", TAG, soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString(), errorDescription->getCString());
}

void ProfileEventHandler::onLogoutFinished(soomla::CCProvider provider) {
    log("%s Logout from %s has finished", TAG, soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString());
    
    EventCustom customEvent(soomla::CCProfileConsts::EVENT_LOGIN_FINISHED);
    customEvent.setUserData(&provider);
    Director::getInstance()->getEventDispatcher()->dispatchEvent(&customEvent);
}

void ProfileEventHandler::onLogoutStarted(soomla::CCProvider provider) {
    log("%s Logout from %s has started", TAG, soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString());
}

void ProfileEventHandler::onGetContactsFailed(soomla::CCProvider provider, cocos2d::__String *errorDescription) {
    log("%s Get contacts from %s has FAILED: %s", TAG, soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString(),
        errorDescription->getCString());
}

void ProfileEventHandler::onGetContactsFinished(soomla::CCProvider provider, cocos2d::__Array *contactsDict) {
    log("%s Get contacts from %s has finished", TAG, soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString());
}

void ProfileEventHandler::onGetContactsStarted(soomla::CCProvider provider) {
    log("%s Get contacts from %s has started", TAG, soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString());
}

void ProfileEventHandler::onGetFeedFailed(soomla::CCProvider provider, cocos2d::__String *errorDescription) {
    log("%s Get feed from %s has FAILED: %s", TAG, soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString(),
         errorDescription->getCString());
}

void ProfileEventHandler::onGetFeedFinished(soomla::CCProvider provider, cocos2d::__Array *feedList) {
    log("%s Get feed from %s has finished", TAG, soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString());
    
    for (int i = 0; i < feedList->count(); ++i){
        log("FEED %s", (dynamic_cast<__String*>(feedList->getObjectAtIndex(i))->getCString()));
    }
}

void ProfileEventHandler::onGetFeedStarted(soomla::CCProvider provider) {
    log("%s Get feed from %s has started", TAG, soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString());
}

void ProfileEventHandler::onSocialActionFailedEvent(soomla::CCProvider provider, soomla::CCSocialActionType socialActionType, cocos2d::__String *errorDescription) {
    log("%s Social action %s on %s has FAILED: %s", TAG, soomla::CCSocialActionUtils::actionEnumToString(socialActionType)->getCString(),
        soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString(),
        errorDescription->getCString());
}

void ProfileEventHandler::onSocialActionFinishedEvent(soomla::CCProvider provider, soomla::CCSocialActionType socialActionType) {
    log("%s Social action %s on %s has finished", TAG, soomla::CCSocialActionUtils::actionEnumToString(socialActionType)->getCString(),
        soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString());
}

void ProfileEventHandler::onSocialActionStartedEvent(soomla::CCProvider provider, soomla::CCSocialActionType socialActionType) {
    log("%s Social action %s on %s has started", TAG, soomla::CCSocialActionUtils::actionEnumToString(socialActionType)->getCString(),
        soomla::CCUserProfileUtils::providerEnumToString(provider)->getCString());
}

void ProfileEventHandler::onRewardGivenEvent(soomla::CCReward *reward) {
    log("%s %s", TAG, "onRewardGivenEvent");
}

void ProfileEventHandler::onUserProfileUpdatedEvent(soomla::CCUserProfile *userProfile) {
    log("%s %s", TAG, "onUserProfileUpdatedEvent");
    
    EventCustom customEvent(soomla::CCProfileConsts::EVENT_USER_PROFILE_UPDATED);
    customEvent.setUserData(userProfile);
    Director::getInstance()->getEventDispatcher()->dispatchEvent(&customEvent);
}
