package com.qq.Demo;

import android.app.Activity;
import android.os.Bundle;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.view.View;

public class MainActivity extends Activity
	implements View.OnClickListener
{
	private TextView mPlayerAHP;
	private TextView mPlayerAMP;
	private TextView mPlayerAAttack;
	private TextView mPlayerADefense;
	
	private ProgressBar mProgressBarPlayerAHP;
	private ProgressBar mProgressBarPlayerAMP;
	private ProgressBar mProgressBarPlayerAAttack;
	private ProgressBar mProgressBarPlayerADefense;
	
	private TextView mPlayerBHP;
	private TextView mPlayerBMP;
	private TextView mPlayerBAttack;
	private TextView mPlayerBDefense;
	
	private ProgressBar mProgressBarPlayerBHP;
	private ProgressBar mProgressBarPlayerBMP;
	private ProgressBar mProgressBarPlayerBAttack;
	private ProgressBar mProgressBarPlayerBDefense;
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        NativeInterface.GameInit();
        initUI();
    }
    
    private void initUI()
    {
    	mPlayerAHP = (TextView)findViewById(R.id.main_text_a_hp);
    	mPlayerAMP = (TextView)findViewById(R.id.main_text_a_mp);
    	mPlayerAAttack = (TextView)findViewById(R.id.main_text_a_attack);
    	mPlayerADefense = (TextView)findViewById(R.id.main_text_a_defense);
    	
    	mProgressBarPlayerAHP = (ProgressBar)findViewById(R.id.main_a_hp);
    	mProgressBarPlayerAMP = (ProgressBar)findViewById(R.id.main_a_mp);
    	mProgressBarPlayerAAttack = (ProgressBar)findViewById(R.id.main_a_attack);
    	mProgressBarPlayerADefense = (ProgressBar)findViewById(R.id.main_a_defense);
    	
    	mPlayerBHP = (TextView)findViewById(R.id.main_text_b_hp);
    	mPlayerBMP = (TextView)findViewById(R.id.main_text_b_mp);
    	mPlayerBAttack = (TextView)findViewById(R.id.main_text_b_attack);
    	mPlayerBDefense = (TextView)findViewById(R.id.main_text_b_defense);
    	
    	mProgressBarPlayerBHP = (ProgressBar)findViewById(R.id.main_b_hp);
    	mProgressBarPlayerBMP = (ProgressBar)findViewById(R.id.main_b_mp);
    	mProgressBarPlayerBAttack = (ProgressBar)findViewById(R.id.main_b_attack);
    	mProgressBarPlayerBDefense = (ProgressBar)findViewById(R.id.main_b_defense);
    	
    	findViewById(R.id.main_refresh).setOnClickListener(this);
    	findViewById(R.id.main_btn_add_a).setOnClickListener(this);
    	findViewById(R.id.main_btn_add_b).setOnClickListener(this);
    	findViewById(R.id.main_btn_a2b).setOnClickListener(this);
    	findViewById(R.id.main_btn_b2a).setOnClickListener(this);
    	
    	refresh();
    }
    
    
    public void onClick(View v)
    {
    	switch(v.getId())
    	{
    	default:
    		break;
    	case R.id.main_refresh:
    		refresh();
    		break;
    	case R.id.main_btn_add_a:
    		addHP(0);
    		break;
    	case R.id.main_btn_add_b:
    		addHP(1);
    		break;
    	case R.id.main_btn_a2b:
    		attack(0);
    		break;
    	case R.id.main_btn_b2a:
    		attack(1);
    		break;
    	}
    }
    
    private void addHP(int flag)
    {
    	NativeInterface.AddHP(flag);
    	refresh();
    }
    
    private void attack(int flag)
    {
    	NativeInterface.Attack(flag);
    	refresh();
    }
    
    private void refresh()
    {
    	int aHP = NativeInterface.GetHP(0);
    	float aMP = NativeInterface.GetMP(0);
    	int aAttack = NativeInterface.GetAttack(0);
    	long aDefense = NativeInterface.GetDefense(0);
    	
		mPlayerAHP.setText(String.format("HP(%d):",aHP));
		mProgressBarPlayerAHP.setProgress(aHP);
		
		mPlayerAMP.setText(String.format("MP(%d):",(int)aMP));
		mProgressBarPlayerAMP.setProgress((int)aMP);
		
		mPlayerAAttack.setText(String.format("攻击力(%d):",aAttack));
		mProgressBarPlayerAAttack.setProgress(aAttack);
		
		mPlayerADefense.setText(String.format("防御(%d):",(int)aDefense));
		mProgressBarPlayerADefense.setProgress((int)aDefense);
    	
    	
    	int bHP = NativeInterface.GetHP(1);
    	float bMP = NativeInterface.GetMP(1);
    	int bAttack = NativeInterface.GetAttack(1);
    	long bDefense = NativeInterface.GetDefense(1);
    	
		mPlayerBHP.setText(String.format("HP(%d):",bHP));
		mProgressBarPlayerBHP.setProgress(bHP);
		
		mPlayerBMP.setText(String.format("MP(%d):",(int)bMP));
		mProgressBarPlayerBMP.setProgress((int)bMP);
		
		mPlayerBAttack.setText(String.format("攻击力(%d):",bAttack));
		mProgressBarPlayerBAttack.setProgress(bAttack);
		
		mPlayerBDefense.setText(String.format("防御(%d):",(int)bDefense));
		mProgressBarPlayerBDefense.setProgress((int)bDefense);
    }
}
