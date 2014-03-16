LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
		../../Classes/PointGrid.cpp \
	../../Classes/Grid.cpp \
	../../Classes/Sphere.cpp \
  ../../Classes/Board.cpp \
  ../../Classes/BoardPopulaterRandom.cpp \
  ../../Classes/GameTestArcadeScene.cpp \
  ../../Classes/MenuScene.cpp \
  ../../Classes/ArcadeScene.cpp \
  ../../Classes/ArcadeSceneMenu.cpp \
  ../../Classes/Indian.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += extensions_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,2d)
$(call import-module,audio/android)
$(call import-module,Box2D)
