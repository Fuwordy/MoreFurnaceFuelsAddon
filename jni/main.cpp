#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <string>

#include "Substrate.h"

#include "MoreFurnaceFuels/item/Coke.h"
#include "MoreFurnaceFuels/item/BrownCoal.h"

#include "minecraftpe/item/ItemInstance.h"

#define LOG_TAG "MoreFurnaceFuels"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

static void (*Item$initItems_real)();
static void Item$initItems_hook() {
	Coke::cokeItem = new Coke(1200-256);
	BrownCoal::brownCoalItem = new BrownCoal(1201-256);
	Item$initItems_real();
}

static bool (*FurnaceTileEntity$isFuel_real)(ItemInstance const*);
static bool FurnaceTileEntity$isFuel_hook(ItemInstance const* instance) {
	if (instance->getId() == 1200 || instance->getId() == 1201) {
		return true;
	return FurnaceTileEntity$isFuel_real(instance);
	}
}

static int (*FurnaceTileEntity$getBurnDuration_real)(ItemInstance const*);
static int FurnaceTileEntity$getBurnDuration_hook(ItemInstance const* instance) {
	if (instance->getId() == 1200) {
		return 260;
	}
	if (instance->getId() == 1201) {
		return 140;
	return FurnaceTileEntity$getBurnDuration_real(instance);
	}
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems_hook, (void**) &Item$initItems_real);
	
	void* FurnaceTileEntity$isFuel = dlsym(RTLD_DEFAULT, "_ZN17FurnaceTileEntity6isFuelEPK12ItemInstance");
	MSHookFunction(FurnaceTileEntity$isFuel, (void*) &FurnaceTileEntity$isFuel_hook, (void**) &FurnaceTileEntity$isFuel_real);
	
	void* FurnaceTileEntity$getBurnDuration = dlsym(RTLD_DEFAULT, "_ZN17FurnaceTileEntity15getBurnDurationEPK12ItemInstance");
	MSHookFunction(FurnaceTileEntity$getBurnDuration, (void*) &FurnaceTileEntity$getBurnDuration_hook, (void**) &FurnaceTileEntity$getBurnDuration_real);
	return JNI_VERSION_1_2;
}
