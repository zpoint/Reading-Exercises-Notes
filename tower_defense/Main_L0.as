package  {
	
	import flash.display.Sprite;
	import flash.display.MovieClip;
	import flash.display.Graphics;
	import flash.events.Event;
	import flash.events.MouseEvent;
	import flash.text.TextField;
	import flash.display.Shape;
	import Turret2;
	import Bullet;
	import Enemy;
	
	
	public class Main_L0 extends Sprite
	{
		private var ghost_turret:Turret2;
		private var turrets:Array = new Array();
		private var bullets:Array = new Array();
		private var enemies:Array = new Array();
		private var placeholders:Array = new Array();
		private var global_time:Number = 0;
		private var menu:Shape = new Shape();
		private var menu_txt:TextField = new TextField();
		//private var life:int = 5;
		//public var Name:String = "郭泽平";
		
		private var mid_x:Number;
		private var mid_y:Number;
		//FPS = 30, 3 seconds ===> 30 * 3 = 90
		private var frame:int = 45;
		
		public var pass:Boolean = false;
		public var level:int = 0;
		
		public function Main_L0() :void
		{
			// constructor code
			addEventListener(Event.ADDED_TO_STAGE, init);
		}
		
		private function init(e:Event) :void
		{
			mid_x = stage.stageWidth;
			mid_y = stage.stageHeight / 2;
			var placeholder1:Sprite = createTurretPlaceholder();
			placeholder1.x = mid_x - 130;
			placeholder1.y = mid_y + 60;
			placeholders.push(placeholder1);
			
			var placeholder2:Sprite = createTurretPlaceholder();
			placeholder2.x = mid_x - 280;
			placeholder2.y = mid_y  - 200;
			placeholders.push(placeholder2);
			
			var placeholder3:Sprite = createTurretPlaceholder();
			placeholder3.x = mid_x - 650;
			placeholder3.y = mid_y + 150;
			placeholders.push(placeholder3);
			
			var placeholder4:Sprite = createTurretPlaceholder();
			placeholder4.x = mid_x - 700;
			placeholder4.y = mid_y - 150;
			placeholders.push(placeholder4);
			
			addChild(placeholder1);
			addTurret_show(placeholder1);
			addChild(placeholder2);
			addChild(placeholder3);
			addChild(placeholder4);
			
			//initial menu
			menu.graphics.beginFill(0xFFE4E1);
			menu.graphics.moveTo(stage.stageWidth, stage.stageHeight); 
			menu.graphics.lineTo(stage.stageWidth - 300, stage.stageHeight); 
			menu.graphics.lineTo(stage.stageWidth - 300, stage.stageHeight - 40);
			menu.graphics.lineTo(stage.stageWidth, stage.stageHeight - 40);
			menu.alpha = 0.5;
			//menu txt
			
			menu_txt.height = 30;
			menu_txt.width = 300;
			menu_txt.textColor = 0x363636;
			menu_txt.x = stage.stageWidth - 300;
			menu_txt.y = stage.stageHeight - 25;
			menu_txt.text = "By   Zpoint    ShenZhen   University";
			addChild(menu_txt);
			addChildAt(menu,0);
			
			//create an invisible turret
			ghost_turret = new Turret2();
			ghost_turret.alpha = 0.5;
			ghost_turret.mouseEnabled = false;
			ghost_turret.mouseChildren = false;
			ghost_turret.visible = false;
			addChild(ghost_turret);
			
			//shoot
			//stage.addEventListener(MouseEvent.CLICK, shoot);
			
			//gameloop
			stage.addEventListener(Event.ENTER_FRAME, gameLoop); //EventListener
			removeEventListener(Event.ADDED_TO_STAGE,init);
			
		}
		
		
		private function gameLoop(e:Event):void
		{
			//Timer
			global_time++;
			
			var turret:Turret2;
			var bullet:Bullet;
			var enemy:Enemy;
			
			//if(life <= 0)
			//{
				//trace("Die!");
			//}
			
			//for turret rotate
			for each(turret in turrets)
				{
					turret.update();
					if(!turret.isReady())
						continue;
					for each(enemy in enemies)
					{
						if(turret.canShoot(enemy))
						{
							shoot(turret, enemy);
							turret.reset();
							break;
						}
					}
				}
				
			//move enemy (garbage sys occures when move to leftmost position)
			for(var j:int = enemies.length - 1; j >=0; j--)
			{
				enemy = enemies[j];
				enemy.update();
				if(enemy.x < 0)
				{
					//life--;
					//menu_txt.text = "姓名: " + Name + "  生命：" + life;
					enemies.splice(j,1);
					enemy.parent.removeChild(enemy);
					continue;
				}
			}
			
			// move bullet in reverse order
			for(var i:int = bullets.length - 1; i>=0; i--)
			{
				//bullet
				bullet = bullets[i];
				if(!bullet)
					continue;
				bullet.update();
				
				if(bullet.x < 0 || bullet.x > stage.stageWidth || bullet.y < 0 || bullet.y > stage.stageHeight)
				{
					bullets.splice(i, 1);
					bullet.parent.removeChild(bullet);
					continue;
				}
				
				for(var k:int = enemies.length - 1; k>=0; k--)
				{
					enemy = enemies[k];
					if(bullet.hitTestObject(enemy))
					{ 
						  	bullets.splice(i, 1);
						  	bullet.parent.removeChild(bullet);
						  	if (enemy.updateHealth(-1) == 0)
						  	{
							 	 enemies.splice(k, 1);
								  enemy.parent.removeChild(enemy);
						 	 }
							break;
					 }
				}
			}
			if(global_time % frame == 0)
			{
				enemy = new Enemy(1,5, -1.5, 0);
				enemy.x = mid_x;
				enemy.y = Math.random() * stage.stageWidth;
				if(enemy.y == mid_y)
					enemy.y -= 30;
				enemies.push(enemy);
				addChildAt(enemy,0);
			}
		}
		
		/*************************************
		Turret
		*************************************/
		private function createTurretPlaceholder():Sprite
		{
			var placeholder:Sprite = new Sprite();
			var g:Graphics = placeholder.graphics;
			g.beginFill(0xCE7822);
			g.drawCircle(0,0,20);
			g.endFill();
			
			placeholder.addEventListener(MouseEvent.MOUSE_OVER, showGhostTurret, false, 0, true);
			placeholder.addEventListener(MouseEvent.MOUSE_OUT, hideGhostTurret, false, 0, true);
			placeholder.addEventListener(MouseEvent.CLICK, addTurret, false, 0, true);
			return placeholder;
		}
		
		private function addTurret(e:MouseEvent):void
		{
			var target_placeholder:Sprite = e.currentTarget as Sprite;
			var turret:Turret2 = new Turret2();
			turret.x = target_placeholder.x;
			turret.y = target_placeholder.y;
			addChild(turret);
			turrets.push(turret);
			e.stopPropagation();
			target_placeholder.removeEventListener(MouseEvent.MOUSE_OVER, showGhostTurret);
			target_placeholder.removeEventListener(MouseEvent.MOUSE_OUT, hideGhostTurret);
			target_placeholder.removeEventListener(MouseEvent.CLICK, addTurret);
		}
		
		private function addTurret_show(target_placeholder:Sprite):void
		{
			var turret:Turret2 = new Turret2();
			turret.x = target_placeholder.x;
			turret.y = target_placeholder.y;
			addChild(turret);
			turrets.push(turret);
			target_placeholder.removeEventListener(MouseEvent.MOUSE_OVER, showGhostTurret);
			target_placeholder.removeEventListener(MouseEvent.MOUSE_OUT, hideGhostTurret);
			target_placeholder.removeEventListener(MouseEvent.CLICK, addTurret);
		}
		
		private function showGhostTurret(e:MouseEvent = null):void
		{
			var target_placeholder:Sprite = e.currentTarget as Sprite;
			ghost_turret.x = target_placeholder.x;
			ghost_turret.y = target_placeholder.y;
			ghost_turret.visible = true;
		}
		
		private function hideGhostTurret(e:MouseEvent = null):void
		{
			ghost_turret.visible = false;
		}
		
		
		/*************************************
		shoot
		*************************************/
		
		private function shoot(turret:Turret2, enemy:Enemy):void
		{
			var angle:Number = Math.atan2(enemy.y - turret.y, enemy.x - turret.x) / Math.PI * 180;
			turret.rotation = angle;
			var new_bullet:Bullet = new Bullet(angle);
			new_bullet.x = turret.x + Math.cos(turret.rotation * Math.PI / 180) * 25;
			new_bullet.y = turret.y + Math.sin(turret.rotation * Math.PI / 180) * 25;
			bullets.push(new_bullet);
			addChild(new_bullet);
		}

		public function clear_listener()
		{
			var i:int;
			var turret:Turret2;
			var enemy:Enemy;
			var bullet:Bullet;
			var placeholder:Sprite;
			stage.removeEventListener(Event.ENTER_FRAME, gameLoop);
			for (i = turrets.length - 1; i >=0; i-- )
			{
				turret = turrets[i];
				turret.clear_listener();
				turret.parent.removeChild(turret);
			}
			
			for(i = enemies.length - 1; i>=0; i--)
			{
				enemy = enemies[i];
				enemy.parent.removeChild(enemy);
			}
			
			for(i = bullets.length - 1; i>=0; i--)
			{
				bullet = bullets[i];
				bullet.parent.removeChild(bullet);
			}
			
			for(i = placeholders.length - 1; i>=0; i--)
			{
				placeholder = placeholders[i];
				placeholder.parent.removeChild(placeholder);
			}
			turrets = null;
			enemies = null;
			bullets = null;
			placeholders = null;
			this.parent.removeChild(this);
		}
	}
	
}
