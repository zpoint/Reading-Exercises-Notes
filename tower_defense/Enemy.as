package  {
	
	import flash.display.Sprite;
	import flash.display.Graphics;
	import flash.text.TextField;
	import flash.display.Shape;
	import flash.geom.ColorTransform;
	
	public class Enemy extends Sprite
	{

		private var speed_x;Number;
		private var speed_y:Number;
		private var health_txt:TextField;
		private var health:int;
		private var initial_health:Number;
		private var precent:Number;
		public var money:Number;
		public var color:int;
		public var size:int;
		var bar:Shape = new Shape();
		//for color transform
		var trans:ColorTransform = bar.transform.colorTransform;
		
		public function Enemy(mon:Number = 1,health_arg:int = 5, spd_x:Number = -1.5,spd_y:Number = 0) 
		{
			// constructor code
			speed_x = spd_x;
			speed_y = spd_y;
			health = initial_health = health_arg;
			money = health;
			draw();
		}
		
		private function draw():void
		{
			if(initial_health < 10)
				{
					var monst = new monster();
					addChild(monst);
					/*
					color = 0xff3333;
					size = 15;
					*/
				}
			else if(initial_health < 20)
				{
					color = 0x000080;
					size = 17;
				}
			else
				{
					color = 0x2F4F4F;
					size = 20;
				}

			var g:Graphics = this.graphics;
			g.beginFill(color);
			g.drawCircle(0,0,size);
			g.endFill();
			//health
			health_txt = new TextField;
			health_txt.height = 20;
			health_txt.width = 15;
			health_txt.textColor = 0xffffff;
			health_txt.x = -5;
			health_txt.y = -8;
			health_txt.text = health + "";
			addChild(health_txt);
			
			//health bar
			bar.graphics.beginFill(0x00CD00);
			bar.graphics.drawRect(-15, -19,30,2);
			bar.graphics.endFill();
			addChild(bar);
		}
		
		public function update():void
		{
			x += speed_x;
			y += speed_y;
		}
		
		public function updateHealth(amount:int):int
		{
			health += amount;
			health_txt.text = health + "";
			precent = health / initial_health;
			bar.width = bar.width * precent;
			if(precent != 1)
			{
				if(precent < 0.2)
					trans.color = uint(0xCD5555);
				else if(precent < 0.5)
					trans.color = uint(0xFFB90F);
				else if(precent < 0.8)
					trans.color = uint(0xB3EE3A);
				bar.transform.colorTransform = trans;
			}
			return health;
		}

	}
	
}
