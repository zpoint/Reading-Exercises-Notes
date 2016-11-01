package  {
	
	import flash.display.Sprite;
	import flash.display.MovieClip;
	import flash.display.Graphics;
	import flash.events.Event;
	import flash.events.MouseEvent;
	import flash.text.TextField;
	import flash.display.Shape;
	import Turret;
	import Turret2;
	import Bullet;
	import Enemy;
	import Map_2;
	import fl.motion.MotionEvent;
	
	
	public class Main_L2 extends Sprite
	{
		private var map:Map_2;
		private var ghost_turret:Turret2;
		private var turrets:Array = new Array();
		private var bullets:Array = new Array();
		private var enemies:Array = new Array();
		private var placeholders:Array = new Array();
		private var placeholder_turret_order:Array = new Array();
		private var candidates_turret:Array = new Array();
		private var turret_arg:Array = new Array();
		
		private var global_time:Number = 0;

		private var menu:Shape = new Shape();
		private var menu_txt:TextField = new TextField();
		public var life:int = 10;
		
		
		public var pass:Boolean = false;
		public var level:int = 2;
		
		public var Name:String = "Username";
		public var ghost_shape:String = "default";
		public var turr_arg_shape_position:int = 6; 
		
		private var add_money_txt:TextField;
		public var wave:int = 5;
		private var wave_current:int = 1;
		private var enemy_count:int = 0;
		private var enemy_wave:int = 10;
		
		private var mid_x:Number;
		private var mid_y:Number;
		//FPS = 30, 3 seconds ===> 30 * 3 = 90
		private var frame:int = 110;
		/************************************
		 buttons[0] ==> money, 
		 buttons[1] ==> array turrets, 
		 buttons[2]==> array placeholder_turret_order, 
		 buttons[3] ==> array turret_arg
		 buttons[4] ==> candidates_turret.button_circle;
		*************************************/
		public var buttons:Array = new Array();
		//public var money:int = 20; change it to button[0]
		
		public function Main_L2(username) :void
		{
			// constructor code
			Name = username;
			addEventListener(Event.ADDED_TO_STAGE, init);
		}
		
		private function init(e:Event) :void
		{
			//initial money
			buttons.push(50);
			buttons.push(turrets);
			buttons.push(placeholder_turret_order);
			buttons.push(turret_arg);
			buttons.push(false);
			
			turret_arg.push(buttons);
			turret_arg.push(30);  //reloade time (FPS)
			turret_arg.push(80);  // range
			turret_arg.push(false); //rect
			turret_arg.push(false);  //mouse
			turret_arg.push(false); //big
			turret_arg.push("default"); //current shape
			
			
			map = new Map_2(stage);
			mid_x = stage.stageWidth / 2;
			mid_y = stage.stageHeight / 2;
			var placeholder1:Sprite = createTurretPlaceholder();
			placeholder1.x = mid_x + 50;
			placeholder1.y = mid_y + 43;
			
			var placeholder2:Sprite = createTurretPlaceholder();
			placeholder2.x = placeholder1.x;
			placeholder2.y = mid_y - 53;
			
			var placeholder3:Sprite = createTurretPlaceholder();
			placeholder3.x = placeholder1.x - 98;
			placeholder3.y = mid_y + 43 ;
			
			var placeholder4:Sprite = createTurretPlaceholder();
			placeholder4.x = placeholder2.x - 98;
			placeholder4.y =  mid_y - 53;
			
			var placeholder5:Sprite = createTurretPlaceholder();
			placeholder5.x = placeholder4.x - 98;
			placeholder5.y = mid_y - 53;
			
			var placeholder6:Sprite = createTurretPlaceholder();
			placeholder6.x =placeholder5.x - 98;
			placeholder6.y = mid_y - 53 + 96;
			
			var placeholder7:Sprite = createTurretPlaceholder();
			placeholder7.x =placeholder6.x - 98;
			placeholder7.y = mid_y - 53;
			
			var placeholder8:Sprite = createTurretPlaceholder();
			placeholder8.x =mid_x + 50 + 98;
			placeholder8.y = mid_y - 53 + 96;
			
			var placeholder9:Sprite = createTurretPlaceholder();
			placeholder9.x =placeholder8.x  + 98;
			placeholder9.y = mid_y - 53;
			
			var placeholder10:Sprite = createTurretPlaceholder();
			placeholder10.x =placeholder9.x  + 98;
			placeholder10.y = mid_y - 53 + 96;
			
			var placeholder11:Sprite = createTurretPlaceholder();
			placeholder11.x =placeholder3.x;
			placeholder11.y = placeholder3.y + 80;
			
			var placeholder12:Sprite = createTurretPlaceholder();
			placeholder12.x = placeholder2.x;
			placeholder12.y = placeholder11.y + 80;
			
			var placeholder13:Sprite = createTurretPlaceholder();
			placeholder13.x = placeholder2.x;
			placeholder13.y = placeholder2.y - 80;
			
			var placeholder14:Sprite = createTurretPlaceholder();
			placeholder14.x = placeholder3.x;
			placeholder14.y = placeholder13.y - 80;
			
			addChild(placeholder1);
			placeholders.push(placeholder1);
			addChild(placeholder2);
			placeholders.push(placeholder2);
			addChild(placeholder3);
			placeholders.push(placeholder3);
			addChild(placeholder4);
			placeholders.push(placeholder4);
			addChild(placeholder5);
			placeholders.push(placeholder5);
			addChild(placeholder6);
			placeholders.push(placeholder6);
			addChild(placeholder7);
			placeholders.push(placeholder7);
			addChild(placeholder8);
			placeholders.push(placeholder8);
			addChild(placeholder9);
			placeholders.push(placeholder9);
			addChild(placeholder10);
			placeholders.push(placeholder10);
			addChild(placeholder11);
			placeholders.push(placeholder11);
			addChild(placeholder12);
			placeholders.push(placeholder12);
			addChild(placeholder13);
			placeholders.push(placeholder13);
			addChild(placeholder14);
			placeholders.push(placeholder14);
			
			
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
			menu_txt.text = "姓名: " + Name + "   生命：" + life + "   金钱: " + buttons[0] + "    剩余敌人:" + wave_current + "/" + wave + "    LV " + level;
			addChild(menu_txt);
			addChildAt(menu,0);
			
			//candidate
			var turret_candidate1:Turret2 = new Turret2(buttons);
			turret_candidate1.x = stage.stageWidth - 590;
			turret_candidate1.y = stage.stageHeight - 30;
			addChild(turret_candidate1);
			
			var turret_candidate2:Turret2 = new Turret2(buttons,30,80,true);
			turret_candidate2.x = turret_candidate1.x + 70;
			turret_candidate2.y = turret_candidate1.y;
			addChild(turret_candidate2);
			
			var turret_candidate3:Turret2 = new Turret2(buttons,30,80,false,false,true);
			turret_candidate3.x = turret_candidate2.x + 80;
			turret_candidate3.y = turret_candidate2.y - 5;
			addChild(turret_candidate3);
			
			var turret_candidate4:Turret2 = new Turret2(buttons,30,80,false,true,false);
			turret_candidate4.x = turret_candidate3.x + 80;
			turret_candidate4.y = turret_candidate2.y;
			addChild(turret_candidate4);
			
			
			
			//create an invisible turret
			ghost_turret = new Turret2();
			ghost_turret.alpha = 0.5;
			ghost_turret.mouseEnabled = false;
			ghost_turret.mouseChildren = false;
			ghost_turret.visible = false;
			addChild(ghost_turret);
			
			//create an invisible Money add Shape
			add_money_txt = new TextField();
			add_money_txt.width = 150;
			add_money_txt.height = 50;
			add_money_txt.textColor = 0x1C1C1C;
			add_money_txt.visible = false;
			addChild(add_money_txt);
			
			
			//shoot
			//stage.addEventListener(MouseEvent.CLICK, shoot);
			
			//gameloop
			stage.addEventListener(Event.ENTER_FRAME, gameLoop);
			removeEventListener(Event.ADDED_TO_STAGE,init);
			
		}
		
		
		private function gameLoop(e:Event):void
		{
			//Timer
			global_time++;
			
			var turret:Turret;
			var bullet:Bullet;
			var enemy:Enemy;
			var damage:int; // for bullet
			
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
				if(enemy.x < 0 || enemy.y > stage.stageHeight)
				{
					life--;
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
						  	if (enemy.updateHealth(0-bullet.bullet_damage) <= 0)
						  	{
							 	  //show money txt
								  add_money_txt.x = enemy.x;
								  add_money_txt.y = enemy.y;
								  add_money_txt.text = "$" + enemy.money;
								  if(add_money_txt.visible == false)
								   	add_money_txt.visible = true;
								  buttons[0] += enemy.money;
								 enemies.splice(k, 1);
								  enemy.parent.removeChild(enemy);
						 	 }
							break;
					 }
				}
			}
			
			switch(wave_current)
			{
				case 1:
				{
					if(global_time % frame == 0)
						{
							if(enemy_count >= enemy_wave)
							{
								//wait for the enemies to be elimated
								if(enemies.length > 0)
									break;
								else
								{
									//no enemies left on the screen
									//set to top layer
									this.setChildIndex(add_money_txt, this.numChildren-1);
									//move to wave2
									enemy_count = 0;
									wave_current++;
									global_time = 0;
									frame -= 10; // 90 - 10 / 30 seconds per monster
									/******************
									enemies of next wave
									*******************/
									enemy_wave += 10;
								}
							}
							else
							{
								enemy_count++;
								if(Math.random() > 0.5)
								{
									enemy = new Enemy(1, 5, -1, 0);
									enemy.x = stage.stageWidth;
									enemy.y = mid_y - 3;
								}
								else
								{
									enemy = new Enemy(1, 5, 0, 1);
									enemy.x = mid_x + 3;
									enemy.y = 0;
								}
								enemies.push(enemy);
								addChildAt(enemy,0);
							}
						}
					break;
				}
				
				case 2:
				{
					if(global_time <= 300)
					{
						add_money_txt.y = stage.stageHeight / 2;
						add_money_txt.x = stage.stageWidth / 2;
						add_money_txt.text = "距离第:"+ wave_current + "/" + wave + "波还有" + int((300 - global_time) / 30) + "秒！";
					}
					else
					{
						if(global_time % frame == 0)
						{
							if(enemy_count >= enemy_wave)
							{
								//wave 3
								if(enemies.length > 0)
									break;
								else
								{
									//wave 3
									enemy_count = 0;
									wave_current++;
									global_time = 0;
									frame -= 5; // 90 - 10 - 5 seconds per monster
									enemy_wave = 3;
								}
							}
							else
							{
								enemy_count++;
								if(Math.random() > 0.5)
								{
									enemy = new Enemy(2, 7, -1.2, 0);
									enemy.x = stage.stageWidth;
									enemy.y = mid_y - 3;
								}
								else
								{
									enemy = new Enemy(2, 7, 0, 1.2);
									enemy.x = mid_x + 3;
									enemy.y = 0;
								}
								enemies.push(enemy);
								addChildAt(enemy,0);
							}
						}
					}
					
					break;
				}
				
				case 3:
				{
					if(global_time <= 300)
					{
						add_money_txt.y = stage.stageHeight / 2;
						add_money_txt.x = stage.stageWidth / 2;
						add_money_txt.text = "距离第:"+ wave_current + "/" + wave + "波还有" + int((300 - global_time) / 30) + "秒！";
					}
					else
					{
						if(global_time % frame == 0)
						{
							if(enemy_count >= enemy_wave)
							{
								//wave 4
								if(enemies.length > 0)
									break;
								else
								{
									//wave 4
									enemy_count = 0;
									wave_current++;
									global_time = 0;
									frame -= 5; // 90- 10 - 5 - 5 seconds per monster
									enemy_wave = 20;
								}
							}
							else
							{
								enemy_count++;
								if(Math.random() > 0.5)
								{
									if(enemy_count == 0)
										enemy = new Enemy(50, 50, -0.2, 0);
									else
										enemy = new Enemy(3, 7.5, -1.25, 0);
									enemy.x = stage.stageWidth;
									enemy.y = mid_y - 3;
								}
								else
								{
									if(enemy_count == 0)
										enemy = new Enemy(50, 50, 0, 0.2);
									else
										enemy = new Enemy(3, 7.5, 0, 1.25);
									enemy.x = mid_x + 3;
									enemy.y = 0;
								}
								enemies.push(enemy);
								addChildAt(enemy,0);
							}
						}
					}
					break;
				}
				
				case 4:
				{
					if(global_time <= 300)
					{
						add_money_txt.y = stage.stageHeight / 2;
						add_money_txt.x = stage.stageWidth / 2;
						add_money_txt.text = "距离第:"+ wave_current + "/" + wave + "波还有" + int((300 - global_time) / 30) + "秒！";
					}
					else
					{
						if(global_time % frame == 0)
						{
							if(enemy_count >= enemy_wave)
							{
								//wave 5
								if(enemies.length > 0)
									break;
								else
								{
									//wave 5
									enemy_count = 0;
									wave_current++;
									global_time = 0;
									frame -= 5; // 90- 10 - 5 - 5 - 5 seconds per monster
									enemy_wave += 10;
								}
							}
							else
							{
								enemy_count++;
								if(Math.random() > 0.5)
								{
									enemy = new Enemy(4, 10, -1.3, 0);
									enemy.x = stage.stageWidth;
									enemy.y = mid_y - 3;
								}
								else
								{
									enemy = new Enemy(4, 10, 0, 1.3);
									enemy.x = mid_x + 3;
									enemy.y = 0;
								}
								enemies.push(enemy);
								addChildAt(enemy,0);
							}
						}
					}
					break;
				}
				
				case 5:
				{
					if(global_time <= 300)
					{
						add_money_txt.y = stage.stageHeight / 2;
						add_money_txt.x = stage.stageWidth / 2;
						add_money_txt.text = "距离第:"+ wave_current + "/" + wave + "波还有" + int((300 - global_time) / 30) + "秒！";
					}
					else
					{
						if(global_time % frame == 0)
						{
							if(enemy_count >= enemy_wave)
							{
								//wave next
								if(enemies.length > 0)
									break;
								else
								{
									pass = true;
								}
							}
							else
							{
								enemy_count++;
								if(Math.random() > 0.5)
								{
									enemy = new Enemy(6, 12, -1.4, 0);
									enemy.x = stage.stageWidth;
									enemy.y = mid_y - 3;
								}
								else
								{
									enemy = new Enemy(6, 12, 0, 1.4);
									enemy.x = mid_x + 3;
									enemy.y = 0;
								}
								enemies.push(enemy);
								addChildAt(enemy,0);
							}
						}
					}
					break;
				}
				
				
				
			}
			
			menu_txt.text = "姓名: " + Name + "   生命：" + life + "   金钱: " + buttons[0] + "    剩余敌人:" + (enemy_wave - enemy_count) + "/" + enemy_wave + "    LV " + level;
		}
		
		/*************************************
		Turret
		*************************************/
		private function createTurretPlaceholder():Sprite
		{
			var placeholder:Sprite = new Sprite();
			var g:Graphics = placeholder.graphics;
			g.beginFill(0xB0E2FF);
			g.drawCircle(0,0,20);
			g.endFill();
			placeholder.alpha = 0.3;
			
			placeholder.addEventListener(MouseEvent.MOUSE_OVER, showGhostTurret, false, 0, true);
			placeholder.addEventListener(MouseEvent.MOUSE_OUT, hideGhostTurret, false, 0, true);
			placeholder.addEventListener(MouseEvent.CLICK, addTurret, false, 0, true);
			return placeholder;
		}
		
		private function addTurret(e:MouseEvent):void
		{
			var target_placeholder:Sprite = e.currentTarget as Sprite;
			var turret:Turret = new Turret(turret_arg[0],turret_arg[1],turret_arg[2],turret_arg[3],turret_arg[4],turret_arg[5]);
			if(buttons[0] < turret.money)
			{
				if(add_money_txt.visible == false)
					add_money_txt.visible = true;
				this.setChildIndex(add_money_txt, this.numChildren-1);
				add_money_txt.text = "金钱不足！,还差 $" + (turret.money - buttons[0]);
				add_money_txt.x = target_placeholder.x;
				add_money_txt.y = target_placeholder.y;
			}
			else
			{
				buttons[0] -= turret.money;
				turret.x = target_placeholder.x;
				turret.y = target_placeholder.y;
				addChild(turret);
				turrets.push(turret);
				placeholder_turret_order.push(target_placeholder);
				e.stopPropagation();
				
				//target_placeholder.removeEventListener(MouseEvent.MOUSE_OVER, showGhostTurret);
				//target_placeholder.removeEventListener(MouseEvent.MOUSE_OUT, hideGhostTurret);
				//target_placeholder.removeEventListener(MouseEvent.CLICK, addTurret);
				target_placeholder.mouseEnabled = false;
				target_placeholder.mouseChildren = false;
			}
		}
		
		private function showGhostTurret(e:MouseEvent = null):void
		{
			var target_placeholder:Sprite = e.currentTarget as Sprite;
			if(turret_arg[turr_arg_shape_position] != ghost_shape)
			{
				ghost_turret.clear_listener();
				ghost_turret.parent.removeChild(ghost_turret);
				ghost_turret = new Turret2(turret_arg[0],turret_arg[1],turret_arg[2],turret_arg[3],turret_arg[4],turret_arg[5]);
				ghost_turret.alpha = 0.5;
				ghost_turret.mouseEnabled = false;
				ghost_turret.mouseChildren = false;
				ghost_turret.visible = false;
				ghost_shape = turret_arg[turr_arg_shape_position];
				addChild(ghost_turret);
				
			}
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
		
		private function shoot(turret:Turret, enemy:Enemy):void
		{
			var angle:Number = Math.atan2(enemy.y - turret.y, enemy.x - turret.x) / Math.PI * 180;
			if(!turret.mouse)
				turret.rotation = angle;
			else
				angle = turret.rotation;
			var new_bullet:Bullet = new Bullet(angle,turret.bullet_speed,turret.bullet_damage);
			new_bullet.x = turret.x + Math.cos(turret.rotation * Math.PI / 180) * 25;
			new_bullet.y = turret.y + Math.sin(turret.rotation * Math.PI / 180) * 25;
			bullets.push(new_bullet);
			addChild(new_bullet);
		}
		
		public function clear_listener()
		{
			var i:int;
			var turret:Turret;
			var enemy:Enemy;
			var bullet:Bullet;
			var placeholder:Sprite;
			map.map_shape.parent.removeChild(map.map_shape);
			stage.removeEventListener(Event.ENTER_FRAME, gameLoop);
			
			ghost_turret.clear_listener();
			ghost_turret.parent.removeChild(ghost_turret);
			
			add_money_txt.parent.removeChild(add_money_txt);
			menu_txt.parent.removeChild(menu_txt);
			
			
			for (i = turrets.length - 1; i >=0; i-- )
			{
				turret = turrets[i];
				turret.clear_listener();
				turret.parent.removeChild(turret);
				turrets[i] = null;
			}
			
			for(i = enemies.length - 1; i>=0; i--)
			{
				enemy = enemies[i];
				enemy.parent.removeChild(enemy);
				enemies[i] = null;
			}
			
			for(i = bullets.length - 1; i>=0; i--)
			{
				bullet = bullets[i];
				bullet.parent.removeChild(bullet);
				bullets[i] = null;
			}

			for(i = placeholders.length - 1; i>=0; i--)
			{
				placeholder = placeholders[i];
				placeholder.removeEventListener(MouseEvent.MOUSE_OVER, showGhostTurret);
				placeholder.removeEventListener(MouseEvent.MOUSE_OUT, hideGhostTurret);
				placeholder.removeEventListener(MouseEvent.CLICK, addTurret);
				placeholder.parent.removeChild(placeholder);
				placeholders[i] = null;
			}
			
			for(i = candidates_turret.length - 1; i >=0; i--)
				candidates_turret[i].clear_listener();
			
			ghost_turret = null;
			turrets = null;
			enemies = null;
			bullets = null;
			placeholders = null;
			this.parent.removeChild(this);

		}


	}
	
}
