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
    	if (flag == 0)
    	{
    		int maxHP = mProgressBarPlayerAHP.getMax();
    		int curHP = mProgressBarPlayerAHP.getProgress();
    		curHP += 10;
    		if (curHP > maxHP) curHP = maxHP;
    		mPlayerAHP.setText("HP():");
    		mProgressBarPlayerAHP.setProgress(curHP);
    	}
    	else
    	{
    		
    	}
    }
    
    private void attack(int flag)
    {
    	if (flag == 0)
    	{
    		
    	}
    	else
    	{
    		
    	}
    }
    
    private void refresh()
    {
    	
    }
}
