package com.example.calculator;

import java.math.BigDecimal;

import android.os.Bundle;
import android.view.View;
import android.app.Activity;
import android.view.Menu;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.content.Intent;

public class MainActivity extends Activity {
	
	EditText firstNum, secondNum;
	TextView answer;
	Button addButton, subButton, multButton, divButton;
	BigDecimal first, second;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		addButton = (Button) findViewById(R.id.addButton);
		subButton = (Button) findViewById(R.id.subButton);
		multButton = (Button) findViewById(R.id.multButton);
		divButton = (Button) findViewById(R.id.divButton);
		firstNum = (EditText) findViewById(R.id.editText1);
		secondNum = (EditText) findViewById(R.id.editText2);
		answer = (TextView) findViewById (R.id.textView1);
		
		addButton.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				first = new BigDecimal(firstNum.getText().toString());
				second = new BigDecimal(secondNum.getText().toString()); 
				answer.setText(first.add(second).toString());
			}
		});
		subButton.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				first = new BigDecimal(firstNum.getText().toString());
				second = new BigDecimal(secondNum.getText().toString()); 
				answer.setText(first.subtract(second).toString());
			}
		});
		
		multButton.setOnClickListener(new View.OnClickListener() {
		
		@Override
		public void onClick(View v) {
			// TODO Auto-generated method stub
			first = new BigDecimal(firstNum.getText().toString());
			second = new BigDecimal(secondNum.getText().toString()); 
			answer.setText(first.multiply(second).toString());
		}
	});
	
		divButton.setOnClickListener(new View.OnClickListener() {
		
		@Override
		public void onClick(View v) {
			// TODO Auto-generated method stub
			first = new BigDecimal(firstNum.getText().toString());
			second = new BigDecimal(secondNum.getText().toString()); 
			answer.setText(first.divide(second).toString());
		}
	});
	
		
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
