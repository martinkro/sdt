package com.qq.Demo;

public class NativeInterface {
	static
	{
		System.loadLibrary("Demo");
	}
	
	public static native void GameInit();
	public static native int GetHP(int flag);
	public static native float GetMP(int flag);
	public static native long GetDefense(int flag);
	public static native int GetAttack(int flag);
	
	public static native void Attack(int flag);
	public static native void AddHP(int flag);

}
