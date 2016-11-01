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
		private var body:Sprite;
		private var range_circle:Sprite;
		public var money:Number = 10;
		public var sellmoney:Number = money / 2;

		var button_up:Sprite = new Sprite();
		var button_sell:Sprite = new Sprite();
		var up_txt:TextField = new TextField();
		var sell_txt:TextField = new TextField();
		var stag;
		var n = 0;
		
		public function Turret2(Stag = null, time_reload = 30, turr_range = 80,rect = false)
		{
			// constructor code
			reload_time = time_reload;
			range = turr_range;
			stag = Stag;
			draw(rect);
			body.addEventListener(MouseEvent.MOUSE_OVER, onMouseOver);
			body.addEventListener(MouseEvent.MOUSE_OUT, onMouseOut);
		}
		
		private function draw(rect = false):void
		{
			range_circle = new Sprite();
			var g = range_circle.graphics;
			g.beginFill(0x00D700);
			g.drawCircle(0,0,range);
			g.endFill();
			range_circle.alpha = 0.2;
			range_circle.visible = false;
			addChild(range_circle);
			
			//button
			
			button_up.graphics.beginFill(0xFF1493);
			button_up.graphics.drawCircle(0,0,30);
			button_up.graphics.endFill();
			up_txt.width = 70;
			up_txt.height = 50;
			up_txt.text = "升级";
			button_up.alpha = 0.5;
			button_up.x = 200;
			button_up.y = stag.stageHeight - 100;
			
			button_up.addChild(up_txt);
			addChild(button_up);
			
			button_sell.graphics.beginFill(0xFF1493);
			button_sell.graphics.drawCircle(0,0,30);
			button_sell.graphics.endFill();
			sell_txt.width = 60;
			sell_txt.height = 50;
			sell_txt.text = "出售";
			button_sell.x = 50;
			button_sell.y = stag.stageHeight - 50;
			button_sell.addChild(sell_txt);
			addChild(button_sell);
			
			
			
			
			
			body = new Sprite;
			g = body.graphics;
			if(rect)
			{
				g.beginFill(0xF0FFFF);
				g.drawRect(-20,-21,42,42);
				g.endFill();
				g.beginFill(0xEE7AE9);
				g.drawRect(0,-5,30,10);
				g.endFill();
			}
			else
			{
				g.beginFill(0x9932CC);
				g.drawCircle(0,0,20);
				g.endFill();
				g.beginFill(0xCDC0B0);
				g.drawRect(0,-5,25,10);
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
			range_circle.parent.removeChild(range_circle);
			range_circle = null;
			range_circle = new Sprite();
			range += 10;
			var g = range_circle.graphics;
			g.beginFill(0x54FF9F);
			g.drawCircle(0,0,range);
			g.endFill();
			range_circle.alpha = 0.2;
			range_circle.visible = false;
			addChildAt(range_circle, 0);
		}
			
		private function onMouseOver(e:MouseEvent):void
		{
			range_circle.visible = true;
		}
		
		private function onMouseOut(e:MouseEvent):void
		{
			range_circle.visible = false;
		}
		
		
		public function clear_listener()
		{
			body.removeEventListener(MouseEvent.MOUSE_OVER, onMouseOver);
			body.removeEventListener(MouseEvent.MOUSE_OUT, onMouseOut);
			
		}
		
		//button
		
		
/*		private function init(e:Event):void
		{
			draw();
		}
*/
	}
	
}
