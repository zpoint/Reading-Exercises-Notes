package  {

	import flash.display.Sprite;
	import flash.display.Graphics;
	import fl.motion.MotionEvent;
	import flash.events.MouseEvent;
	import flash.events.Event;
	import flash.display.Shape;
	import flash.display.SimpleButton;
	import flash.text.TextField;
	
	public class Turret2 extends Sprite
	{

		private var local_time:Number = 0;
		private var reload_time:int;
		private var range:int;
		public var bullet_speed:Number = 8;
		//public var bullet_speed_rate:Number = 0.1;
		public var bullet_damage:Number = 1;
		//public var bullet_damage_rate:Number = 0.1;
		
		private var body:Sprite;
		private var range_circle:Sprite;
		public var money:Number = 10;
		private var button_circle:Sprite;
		public var sellmoney:Number = money / 2;
		public var rect:Boolean = false;
		public var mouse:Boolean = false;
		public var big:Boolean = false; 
		public var explain_txt:TextField = new TextField();
		public var turret_arg:Array;
		public var buttons:Array;
		public var button_length:int = 5; 
		public var mouse_reload_time:Number = 40;
		public var turr_arg_shape_position:int = 6; 
		public var shape:String; 
		
		public function Turret2(bts:Array = null, time_reload = 30, turr_range = 80,rectangle = false,mouse_arg = false, big_arg = false)
		{
			// constructor code
			reload_time = time_reload;
			range = turr_range;
			mouse = mouse_arg;
			rect = rectangle;
			big = big_arg;
			if(bts != null) //not main 0 or die
				{
					turret_arg = bts[3];
					buttons = bts;
				}
			if(rect)
			{
				money = 20;
				range = 80;
				bullet_speed = 9;
				bullet_damage = 2;
				reload_time = 35;
			}
			else if(big)
			{
					money = 40;
					range = 110;
					bullet_speed = 10;
				 	bullet_damage = 4;
					reload_time = 40;
			}
			else if(mouse)
			{
					money = 50;
					range = 50;
					bullet_speed = 8;
				 	bullet_damage = 1;
					mouse_reload_time = 60;
			}
			else //default
			{
					money = 10;
					range = 80;
					bullet_speed = 8;
				 	bullet_damage = 1;
					reload_time = 30;
			}
			draw();
			body.addEventListener(MouseEvent.MOUSE_OVER, onMouseOver);
			body.addEventListener(MouseEvent.MOUSE_OUT, onMouseOut);
			body.addEventListener(MouseEvent.CLICK, onMouseClick);
		}
		
		private function draw():void
		{
			
			var g;
			/*
			range_circle = new Sprite();
			var g = range_circle.graphics;
			g.beginFill(0x00D700);
			g.drawCircle(0,0,range);
			g.endFill();
			range_circle.alpha = 0.2;
			range_circle.visible = false;
			addChild(range_circle);
			*/
			
			body = new Sprite;
			g = body.graphics;
			if(rect)
			{
				shape = "rect";
				g.beginFill(0x8B8989);
				g.drawRect(-20,-21,42,42);
				g.endFill();
				g.beginFill(0xEE7AE9);
				g.drawRect(0,-5,30,10);
				g.endFill();
				//bt circle
				button_circle = new Sprite();
				g = button_circle.graphics;
				g.beginFill(0x363636);
				g.drawRect(-22,-23,46,46);
				g.endFill();
				button_circle.alpha = 0.3;
				button_circle.visible = true;
				addChild(button_circle);
			}
			else
			{
				if(big)
				{
					shape = "big";
					g.beginFill(0xFF6347);
					g.drawCircle(0,0,30);
					g.endFill();
					g.beginFill(0xCDC0B0);
					g.drawRect(0,-5,45,10);
					button_circle = new Sprite();
					g.endFill();
					
					g = button_circle.graphics;
					g.beginFill(0x363636);
					g.drawCircle(0,0,33);
					g.endFill();
					button_circle.alpha = 0.3;
					button_circle.visible = true;
					addChild(button_circle);
				}
				else if(mouse)
				{
					shape = "mouse";
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
					button_circle.visible = true;
					addChild(button_circle);
				}
				else
				{
					shape = "default";
					g.beginFill(0xFFF5EE);
					g.drawCircle(0,0,22);
					g.endFill();
					g.beginFill(0xCDC0B0);
					g.drawRect(0,-5,25,10);
					g.endFill();
					
					button_circle = new Sprite();
					g = button_circle.graphics;
					g.beginFill(0x363636);
					g.drawCircle(0,0,23);
					g.endFill();
					button_circle.alpha = 0.3;
					button_circle.visible = true;
					addChild(button_circle);
				}
			}
			
			button_circle.visible = false;
			
			explain_txt.width = 130;
			explain_txt.height = 100;
			explain_txt.x = -35;
			explain_txt.y = -115;
			if(mouse)
				explain_txt.text = "随鼠标旋转,点击射击\n" + "购买金钱: $"+ money + "\n" + "子弹速度:" + bullet_speed + "\n伤害:" + bullet_damage + "\n射程: 全场" + "\n发射间隔:" + Math.round(mouse_reload_time / 30 * 10) / 10 + "秒";
			else
				explain_txt.text = "购买金钱: $"+ money + "\n" + "子弹速度:" + bullet_speed + "\n伤害:" + bullet_damage + "\n射程:" + range + "\n发射速率:" + reload_time;
			explain_txt.visible = false;
			addChild(explain_txt);
			
			
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
			local_time++;
		}
		
		public function isReady():Boolean
		{
			return local_time > reload_time;
		}
		
		public function reset():void
		{
			local_time = 0;
		}
		
		public function canShoot(enemy:Enemy):Boolean
		{
			var dx:Number = enemy.x - x;
			var dy:Number = enemy.y - y;
			if(Math.sqrt(dx * dx + dy * dy) <= range)
				return true;
			else
				return false;
		}
		private function rand()
		{
			return Math.round((Math.random() * 350));
		}
		
		public function upgrade(e:Event = null)
		{
			//
		}
			
		private function onMouseOver(e:MouseEvent):void
		{
			//range_circle.visible = true;
			explain_txt.visible = true;
		}
		
		private function onMouseOut(e:MouseEvent):void
		{
			//range_circle.visible = false;
			explain_txt.visible = false;
		}
		
		private function onMouseClick(e:MouseEvent):void
		{
			if(turret_arg != null)
			{
				turret_arg[1] = reload_time;
				turret_arg[2] = range;
				turret_arg[3] = rect;
				turret_arg[4] = mouse;
				turret_arg[5] = big;
				turret_arg[turr_arg_shape_position] = shape;
				
				if(buttons[4] == false) // recent mouse not here
				{
					if(buttons.length != button_length) // recent click in turret
					{
						for(var i:int = buttons.length - 1; i >= button_length; i--)
						{
							if(i == button_length + 2)
								buttons[i].visible = false;
							else
								buttons[i].parent.removeChild(buttons[i]);
							buttons.pop();
						}
					}
					
					button_circle.visible = true;
					buttons[4] = button_circle;
				}
				else
				{
					//recent mouse click here
					buttons[4].visible = false;
					button_circle.visible = true;
					buttons[4] = button_circle;
				}
					
			}
			else
				trace("array turret_arg null");
				
		}
		
		
		public function clear_listener()
		{
			body.removeEventListener(MouseEvent.MOUSE_OVER, onMouseOver);
			body.removeEventListener(MouseEvent.MOUSE_OUT, onMouseOut);
			body.removeEventListener(MouseEvent.CLICK, onMouseClick);
			
			//range_circle.parent.removeChild(range_circle);
			body.parent.removeChild(body);
			explain_txt.parent.removeChild(explain_txt);
		}
		
		//button
		
		
/*		private function init(e:Event):void
		{
			draw();
		}
*/
	}
	
}
