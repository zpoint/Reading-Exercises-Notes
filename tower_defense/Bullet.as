package  {
	
	import flash.display.Sprite;
	import flash.display.Graphics;
	
	public class Bullet extends Sprite
	{

		public var speed : Number;
		private var speed_x :Number;
		private var speed_y : Number;
		public var bullet_damage : int;
		
		public function Bullet(angle:Number, speed:Number = 8, damage:Number = 1) 
		{
			// constructor code
			speed_x = Math.cos(angle * Math.PI / 180) * speed;
			speed_y = Math.sin(angle * Math.PI / 180) * speed;
			bullet_damage = damage;
			draw();
		}
		
		private function draw():void
		{
			var g:Graphics = this.graphics;
			g.beginFill(0xEEEEE);
			g.drawCircle(0,0,5);
			g.endFill();
		}
		
		public function update():void
		{
			x += speed_x;
			y += speed_y;
		}

	}
	
}
