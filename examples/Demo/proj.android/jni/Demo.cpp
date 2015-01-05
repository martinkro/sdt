#include <jni.h>
#include <stdlib.h>

#include "Game.h"

#define JNIREG_CLASS "com/qq/Demo/NativeInterface"

#define sGame Game::getInstance()

void GameInit(JNIEnv* env, jclass clazz)
{

}

void Attack(JNIEnv* env, jclass clazz,jint flag)
{
    sGame->attack(flag);
}

jint GetHP(JNIEnv* env, jclass clazz, jint flag)
{
    return sGame->getHP(flag);
}

jfloat GetMP(JNIEnv* env, jclass clazz, jint flag)
{
    return sGame->getMP(flag);
}

jint GetAttack(JNIEnv* env, jclass clazz, jint flag)
{
    return sGame->getAttack(flag);
}

jlong GetDefense(JNIEnv* env, jclass clazz, jint flag)
{
    return sGame->getDefense(flag);
}

void AddHP(JNIEnv* env, jclass clazz, jint flag)
{
    sGame->addHP(flag,10);
}


JavaVM* g_jvm = NULL;
static JNINativeMethod g_NativeMethod[] = {
        {"GameInit","()V",(void*)GameInit},
        {"Attack","(I)V",(void*)Attack},
        {"AddHP","(I)V",(void*)AddHP},
        {"GetHP","(I)I",(void*)GetHP},
        {"GetMP","(I)F",(void*)GetMP},
        {"GetAttack","(I)I",(void*)GetAttack},
        {"GetDefense","(I)J",(void*)GetDefense}
};

jint JNI_OnLoad(JavaVM* jvm, void* reserved)
{
    jint result = JNI_VERSION_1_4;
    g_jvm = jvm;
    JNIEnv* env;

    if (jvm->GetEnv((void**)&env, JNI_VERSION_1_4) == JNI_OK)
    {
        jclass clazz = env->FindClass(JNIREG_CLASS);
        if (clazz != NULL)
        {
            env->RegisterNatives(clazz, g_NativeMethod, sizeof(g_NativeMethod)/sizeof(g_NativeMethod[0]));
        }
    }
    return result;
}
