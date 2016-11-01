package  {
	
	import flash.display.Shape;
	import flash.events.Event;
	import flash.display.Sprite;
	import flash.events.MouseEvent;
	import flash.display.Graphics;
	
	
	public class Map_2
	{
		public var map_shape:Shape = new Shape();
		public var placeholders:Array = new Array();

		
		public function Map_2(stag):void
		{
			//initial map
			map_shape.graphics.beginFill(0x90EE90);
			map_shape.graphics.moveTo(stag.stageWidth, stag.stageHeight / 2 + 20); 
			map_shape.graphics.lineTo(0, stag.stageHeight / 2 + 20);
			map_shape.graphics.lineTo(0, stag.stageHeight / 2 - 30);
			map_shape.graphics.lineTo(stag.stageWidth, stag.stageHeight / 2 - 30);
			
			map_shape.graphics.moveTo(stag.stageWidth / 2 - 30, stag.stageHeight); 
			map_shape.graphics.lineTo(stag.stageWidth / 2 + 20, stag.stageHeight);
			map_shape.graphics.lineTo(stag.stageWidth / 2 + 30, 0);
			map_shape.graphics.lineTo(stag.stageWidth / 2 - 20, 0);
			map_shape.graphics.endFill();			
			map_shape.alpha = 0.5;
			
			stag.addChildAt(map_shape,0);
		}
	}
	
}
