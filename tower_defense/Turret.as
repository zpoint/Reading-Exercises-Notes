package  {

	import flash.display.Sprite;
	import flash.display.Graphics;
	import fl.motion.MotionEvent;
	import flash.events.MouseEvent;
	import flash.events.Event;
	import flash.display.Shape;
	import flash.display.SimpleButton;
	import flash.text.TextField;
	import flash.ui.Mouse;
	
	public class Turret extends Sprite
	{

		private var local_time:Number = 0;
		private var reload_time:int;
		private var reload_time_rate:Number = 0.1;
		
		private var range:int;
		private var range_rate:Number = 0.1;
		
		private var body:Sprite;
		private var range_circle:Sprite;
		private var button_circle:Sprite;
		public var money:Number = 10;
		public var upgrade_money:Number = 5;
		public var sellmoney:Number = money / 2;
		public var color:uint = 0x54FF9F;

		public var button_up:Sprite = new Sprite();
		public var button_sell:Sprite = new Sprite();
		public var up_txt:TextField = new TextField();
		public var sell_txt:TextField = new TextField();
		public var up_explain_txt:TextField = new TextField();
		public var sell_explain_txt:TextField = new TextField();
		
		public var bullet_speed:Number = 8;
		public var bullet_speed_rate:Number = 0.1;
		public var bullet_damage:Number = 1;
		public var bullet_damage_rate:Number = 0.1;
		
		public var rect:Boolean = false;
		public var mouse:Boolean = false;
		public var mouse_shoot:Boolean = false;
		public var mouse_rotate:Boolean = false;
		public var big:Boolean = false; 
		public var buttons:Array;
		public var button_length:int = 5; 
		public var mouse_reload_time:Number = 40;
		public var mouse_reload_time_rate:Number = 0.1;
		public var mouse_local_time:Number = 0;
		public var shape:String;
		/************************************
		 buttons[0] ==> money, 
		 buttons[1] ==> array turrets, 
		 buttons[2]==> array placeholder_turret_order, 
		 buttons[3] ==> array turret_arg
		 buttons[4] ==> candidates_turret.button_circle;
		*************************************/
		public function Turret(bts:Array, time_reload = 30, turr_range = 80,rectangle = false, mouse_arg = false,big_arg = false)
		{
			// constructor code
			buttons = bts;
			reload_time = time_reload;
			range = turr_range;
			rect = rectangle;
			mouse = mouse_arg;
			big = big_arg;
			if(rect)
			{
				shape = "rect";
				money = 20;
				range = 80;
				range_rate = 0.1;
				upgrade_money = 8;
				sellmoney = money / 2;
				bullet_speed = 9;
				bullet_speed_rate = 0.1;
				bullet_damage = 2;
				bullet_damage_rate = 0.1;
				reload_time = 35;
				reload_time_rate = 0.02;
			}
			else if(big)
			{
					shape = "big";
					money = 40;
					range = 110;
					range_rate = 0.1;
					upgrade_money = 15;
					sellmoney = money / 2;
					bullet_speed = 10;
					bullet_speed_rate = 0.05;
				 	bullet_damage = 4;
					bullet_damage_rate = 0.1;
					reload_time = 40;
					reload_time_rate = 0.02;
			}
			else if(mouse)
			{
					shape = "mouse";
					money = 50;
					range = 50;
					range_rate = 0.1;
					upgrade_money = 15;
					sellmoney = money / 2;
					bullet_speed = 8;
					bullet_speed_rate = 0.15;
				 	bullet_damage = 1;
					bullet_damage_rate = 0.1;
					mouse_reload_time = 60;
					mouse_reload_time_rate = 0.01;
			}
			else //default
			{
					shape = "default";
					money = 10;
					range = 80;
					range_rate = 0.1;
					upgrade_money = 5;
					sellmoney = money / 2;
					bullet_speed = 8;
					bullet_speed_rate = 0.15;
				 	bullet_damage = 1;
					bullet_damage_rate = 0.1;
					reload_time = 30;
					reload_time_rate = 0.02;
			}
			draw();
			if(mouse)
			{
				range_circle.addEventListener(MouseEvent.MOUSE_OVER, range_circle_onMouseOver);
				range_circle.addEventListener(MouseEvent.MOUSE_DOWN, range_circle_onMouseDown);
				range_circle.addEventListener(MouseEvent.MOUSE_UP, range_circle_onMouseUp);
				range_circle.addEventListener(MouseEvent.MOUSE_OUT, range_circle_onMouseOut);
				range_circle.alpha = 0.1;
			}
			else
			{
				body.addEventListener(MouseEvent.MOUSE_OVER, onMouseOver);
				body.addEventListener(MouseEvent.MOUSE_OUT, onMouseOut);
				body.addEventListener(MouseEvent.CLICK, onMouseClick);
			}
			
		}
		
		private function draw():void
		{
			range_circle = new Sprite();
			var g = range_circle.graphics;
			g.beginFill(0x00D700);
			g.drawCircle(0,0,range);
			g.endFill();
			range_circle.alpha = 0.2;
			if(mouse)
				range_circle.visible = true;
			else
				range_circle.visible = false;
			addChild(range_circle);
			
			//button
			button_up.graphics.beginFill(0xF5DEB3);
			button_up.graphics.drawCircle(0,0,30);
			/*
			button_up.graphics.moveTo(stag.stageWidth,stag.stageHeight - 10);
			button_up.graphics.lineTo(stag.stageWidth - 30,stag.stageHeight - 10);
			button_up.graphics.lineTo(stag.stageWidth - 15 + 20,stag.stageHeight - 10 - (15 * 1.732));
			button_up.graphics.lineTo(stag.stageWidth ,stag.stageHeight - 10);
			*/
			button_up.graphics.endFill();
			up_txt.width = 28;
			up_txt.height = 18;
			up_txt.x = -10;
			up_txt.y = -8;
			up_txt.text = "升级";
			
			up_explain_txt.width = 100;
			up_explain_txt.height = 80;
			up_explain_txt.x = -35;
			up_explain_txt.y = -115;
			if(mouse)
				up_explain_txt.text = "需要金钱: $"+ upgrade_money + "\n" + "子弹速度:*" + (1 + bullet_speed_rate) + "\n伤害:*" + (1 + bullet_damage_rate) + "\n控制范围:*" + (1 + range_rate) + "\n发射间隔:*" + (1 + mouse_reload_time_rate);
			else
				up_explain_txt.text = "需要金钱: $"+ upgrade_money + "\n" + "子弹速度:*" + (1 + bullet_speed_rate) + "\n伤害:*" + (1 + bullet_damage_rate) + "\n射程:*" + (1 + range_rate) + "\n发射速率:*" + (1 + reload_time_rate);
			up_explain_txt.visible = false;
			
			button_up.alpha = 0.5;
			button_up.addChildAt(up_txt,0);
			button_up.addChildAt(up_explain_txt,0);
			button_up.addEventListener(MouseEvent.CLICK, button_up_onMouseClick);
			button_up.addEventListener(MouseEvent.MOUSE_OVER, button_up_Hover);
			button_up.addEventListener(MouseEvent.MOUSE_OUT, button_up_onMouseOut);
			
			button_sell.graphics.beginFill(0xEEA9B8);
			button_sell.graphics.drawCircle(0,0,30);
			button_sell.graphics.endFill();
			sell_txt.width = 28;
			sell_txt.height = 18;
			sell_txt.x = -10;
			sell_txt.y = -8;
			sell_txt.text = "出售";
			
			sell_explain_txt.width = 100;
			sell_explain_txt.height = 30;
			sell_explain_txt.x = -20;
			sell_explain_txt.y = -55;
			sell_explain_txt.text = "金钱 + " + sellmoney;
			sell_explain_txt.alpha = 0.5;
			sell_explain_txt.visible = false;
			
			button_sell.addChildAt(sell_txt,0);
			button_sell.addChildAt(sell_explain_txt,0);
			button_sell.addEventListener(MouseEvent.CLICK, button_sell_onMouseClick);
			button_sell.addEventListener(MouseEvent.MOUSE_OVER, button_sell_Hover);
			button_sell.addEventListener(MouseEvent.MOUSE_OUT, button_sell_onMouseOut);
			
			body = new Sprite;
			g = body.graphics;
			if(rect)
			{
				g.beginFill(0x8B8989);
				g.drawRect(-20,-21,42,42);
				g.endFill();
				g.beginFill(0xEE7AE9);
				g.drawRect(0,-5,30,10);
				g.endFill();
				
				button_circle = new Sprite();
				g = button_circle.graphics;
				g.beginFill(0x363636);
				g.drawRect(-22,-23,46,46);
				g.endFill();
				button_circle.alpha = 0.3;
				button_circle.visible = false;
				addChild(button_circle);
			}
			else
			{
				if(big)
				{
					g.beginFill(0xFF6347);
					g.drawCircle(0,0,30);
					g.endFill();
					g.beginFill(0xCDC0B0);
					g.drawRect(0,-5,45,10);
					
					button_circle = new Sprite();
					g = button_circle.graphics;
					g.beginFill(0x363636);
					g.drawCircle(0,0,33);
					g.endFill();
					button_circle.alpha = 0.3;
					button_circle.visible = false;
					addChild(button_circle);
				}
				else if(mouse)
				{
					g.beginFill(0xFFFF00);
					g.drawCircle(0,0,23);
					g.endFill();
					g.beginFill(0xCDC0B0);
					g.drawRect(0,-4,35,10);
					g.endFill();
					
					button_circle = new Sprite();
					g = button_circle.graphics;
					g.beginFill(0xFF3E96);
					g.drawCircle(0,0,25);
					g.endFill();
					button_circle.alpha = 0.3;
					button_circle.visible = false;
					addChild(button_circle);
				}
				else //default
				{
					g.beginFill(0xFFF5EE);
					g.drawCircle(0,0,22);
					g.endFill();
					g.beginFill(0xCDC0B0);
					g.drawRect(0,-5,25,10);
					
					button_circle = new Sprite();
					g = button_circle.graphics;
					g.beginFill(0x363636);
					g.drawCircle(0,0,24);
					g.endFill();
					button_circle.alpha = 0.3;
					button_circle.visible = false;
					addChild(button_circle);
				}
				g.endFill();
			}
			
			addChild(body);
			
		}
		
/********************************
MouseEvent version
**********************************/
		/*
		public function update():void
		{
			var angle:Number = Math.atan2(stage.mouseY - this.y, stage.mouseX - this.x) / Math.PI * 180;
			this.rotation = angle;
		}
		*/
		
		public function update():void
		{
			if(mouse)
			{
				if(mouse_rotate)
				{
					var angle:Number = Math.atan2(stage.mouseY - this.y, stage.mouseX - this.x) / Math.PI * 180;
					this.rotation = angle;
				}
				mouse_local_time++;
			}
			else
				local_time++;
		}
		
		public function isReady():Boolean
		{
			if(mouse)
				return  mouse_local_time > mouse_reload_time;
			else
				return local_time > reload_time;
		}
		
		public function reset():void
		{
			if(mouse)
				mouse_local_time = 0;
			else
				local_time = 0;
		}
		
		public function canShoot(enemy:Enemy):Boolean
		{
			if(mouse)
				return mouse_shoot;
			else
			{
				var dx:Number = enemy.x - x;
				var dy:Number = enemy.y - y;
				if(Math.sqrt(dx * dx + dy * dy) <= range)
					return true;
				else
				return false;
			}
		}
		
		private function rand()
		{
			return Math.round((Math.random() * 350));
		}
		
			
		private function onMouseOver(e:MouseEvent):void
		{
			range_circle.visible = true;
		}
		
		private function onMouseOut(e:MouseEvent):void
		{
			range_circle.visible = false;
		}
		
		private function onMouseClick(e:MouseEvent = null):void
		{
			if(buttons.length > button_length)
			{
				//recent click here
				for(var i:int = buttons.length - 1;i >= button_length; i--)
					{
						if(i == button_length + 2)
							buttons[i].visible = false;
						else
							buttons[i].parent.removeChild(buttons[i]);
						buttons.pop();
					}
			}
			
			else if(buttons[4] != false)
			{
				//recent click not here
				buttons[4].visible = false;
				buttons[4] = false;
			}
			
			
			button_circle.visible = true;
			
			parent.addChild(button_up);
			button_up.x = 50;
			button_up.y = 550;
			parent.addChild(button_sell);
			button_sell.x = 130;
			button_sell.y = 550;
			buttons.push(button_up);
			buttons.push(button_sell);
			buttons.push(button_circle);
			
		}
		
		//below are button function
		
		private function upgrade()
		{
			range *= (1 + range_rate);
			bullet_speed *= (1 + bullet_speed_rate);
			bullet_damage *= (1 + bullet_damage_rate);
			upgrade_money = int(upgrade_money * 1.1);
			sellmoney = int(sellmoney * 1.1);
			
			range_circle.parent.removeChild(range_circle);
			range_circle = null;
			range_circle = new Sprite();
			var g = range_circle.graphics;
			color -= 0x0000ff;
			g.beginFill(color);
			g.drawCircle(0,0,range);
			g.endFill();
			addChildAt(range_circle, 0);
			if(mouse)
			{
				mouse_reload_time *= (1 - mouse_reload_time_rate);
				range_circle.alpha = 0.1;
				range_circle.visible = true;
				up_explain_txt.text = "需要金钱: $"+ upgrade_money + "\n" + "子弹速度:*" + (1 + bullet_speed_rate) + "\n伤害:*" + (1 + bullet_damage_rate) + "\n控制范围:*" + (1 + range_rate) + "\n发射间隔:*" + (1 + mouse_reload_time_rate);
				
			}
			else
			{
				reload_time *= (1 - reload_time_rate);
				range_circle.alpha = 0.2;
				range_circle.visible = false;
				up_explain_txt.text = "需要金钱: $"+ upgrade_money + "\n" + "子弹速度:*" + (1 + bullet_speed_rate) + "\n伤害:*" + (1 + bullet_damage_rate) + "\n射程:*" + (1 + range_rate) + "\n发射速率:*" + (1 + reload_time_rate);
			}
		}
		
		
		private function button_up_onMouseClick(e:MouseEvent):void
		{
			//buttons[0] ===> user_money
			if(buttons[0] >= upgrade_money)
			{
				buttons[0] -= upgrade_money;
				upgrade();
				up_explain_txt.text = "\n\n\n\n升级成功！！！";
			}
			else
				up_explain_txt.text = "\n\n\n\n金钱不足！！！";
			
		}
		
		private function button_up_Hover(e:MouseEvent):void
		{
			button_up.graphics.clear();
			button_up.graphics.beginFill(0xCD2626);
			button_up.graphics.drawCircle(0,0,35);
			up_explain_txt.visible = true;
		}
		
		private function button_up_onMouseOut(e:MouseEvent):void
		{
			button_up.graphics.clear();
			button_up.graphics.beginFill(0xF5DEB3);
			button_up.graphics.drawCircle(0,0,30);
			up_explain_txt.visible = false;
			if(mouse)
				up_explain_txt.text = "需要金钱: $"+ upgrade_money + "\n" + "子弹速度:*" + (1 + bullet_speed_rate) + "\n伤害:*" + (1 + bullet_damage_rate) + "\n控制范围:*" + (1 + range_rate) + "\n发射间隔:*" + (1 + mouse_reload_time_rate);
			else
				up_explain_txt.text = "需要金钱: $"+ upgrade_money + "\n" + "子弹速度:*" + (1 + bullet_speed_rate) + "\n伤害:*" + (1 + bullet_damage_rate) + "\n射程:*" + (1 + range_rate) + "\n发射速率:*" + (1 + reload_time_rate);
				
		}
		////
		private function button_sell_onMouseClick(e:MouseEvent):void
		{
			var turrets = buttons[1];
			var placeholder_turret_order =  buttons[2];
			for (var i = turrets.length - 1;i >= 0; i--)
			{
				if(turrets[i] == this)
					{
						buttons[0] += sellmoney;
						turrets[i].parent.removeChild(turrets[i]);
						turrets.splice(i,1);
						
						placeholder_turret_order[i].mouseEnabled = true;
						placeholder_turret_order[i].mouseChildren = true;
						placeholder_turret_order.splice(i,1);
						
						clear_listener();
					}
			}
		}
		
		private function button_sell_Hover(e:MouseEvent):void
		{
			sell_explain_txt.visible = true;
			button_sell.graphics.clear();
			button_sell.graphics.beginFill(0xFF0000);
			button_sell.graphics.drawCircle(0,0,35);
		}
		
		private function button_sell_onMouseOut(e:MouseEvent):void
		{
			sell_explain_txt.visible = false;
			button_sell.graphics.clear();
			button_sell.graphics.beginFill(0xEEA9B8);
			button_sell.graphics.drawCircle(0,0,30);
		}
		
		private function range_circle_onMouseOut(e:MouseEvent):void
		{
			mouse_rotate = false;
		}
		
		private function range_circle_onMouseOver(e:MouseEvent):void
		{
			mouse_rotate = true;
			onMouseClick();
		}
		
		private function range_circle_onMouseDown(e:MouseEvent):void
		{
			mouse_shoot = true;
		}
		
		private function range_circle_onMouseUp(e:MouseEvent):void
		{
			mouse_shoot = false;
		}
		
		
		public function clear_listener()
		{
			
			for(var i:int = buttons.length - 1; i >= button_length ; i--)
			{
				if(buttons[i] == button_circle || buttons[i] == button_up || buttons[i] == button_sell)
					buttons.splice(i,1);
			}
			
			
			if(mouse)
			{
				range_circle.removeEventListener(MouseEvent.MOUSE_OVER, range_circle_onMouseOver);
				range_circle.removeEventListener(MouseEvent.MOUSE_DOWN, range_circle_onMouseDown);
				range_circle.removeEventListener(MouseEvent.MOUSE_UP, range_circle_onMouseUp);
				range_circle.removeEventListener(MouseEvent.MOUSE_OUT, range_circle_onMouseOut);
			}
			else
			{
				body.removeEventListener(MouseEvent.MOUSE_OVER, onMouseOver);
				body.removeEventListener(MouseEvent.MOUSE_OUT, onMouseOut);
				body.removeEventListener(MouseEvent.CLICK, onMouseClick);
			}
			body.parent.removeChild(body);
			body = null;
			
			range_circle.parent.removeChild(range_circle);
			button_circle.parent.removeChild(button_circle);
			range_circle = null;
			button_circle = null;
			
			up_txt.parent.removeChild(up_txt);
			up_explain_txt.parent.removeChild(up_explain_txt);
			up_txt = null;
			up_explain_txt = null;
			
			sell_txt.parent.removeChild(sell_txt);
			sell_explain_txt.parent.removeChild(sell_explain_txt);
			sell_txt = null;
			sell_explain_txt = null;

			button_up.removeEventListener(MouseEvent.CLICK, button_up_onMouseClick);
			button_up.removeEventListener(MouseEvent.MOUSE_OVER, button_up_Hover);
			button_up.removeEventListener(MouseEvent.MOUSE_OUT, button_up_onMouseOut);
			
			button_sell.removeEventListener(MouseEvent.CLICK, button_sell_onMouseClick);
			button_sell.removeEventListener(MouseEvent.MOUSE_OVER, button_sell_Hover);
			button_sell.removeEventListener(MouseEvent.MOUSE_OUT, button_sell_onMouseOut);
			
			if(button_up.parent != null)
				button_up.parent.removeChild(button_up);
			if(button_sell.parent != null)
				button_sell.parent.removeChild(button_sell);
			button_up = null;
			button_sell = null;
		}
		
		//button
		
		
/*		private function init(e:Event):void
		{
			draw();
		}
*/
	}
	
}
