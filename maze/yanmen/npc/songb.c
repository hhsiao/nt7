// Modified by lonely@NT
#include <ansi.h>
#include <room.h>
inherit NPC;
mapping *first_name=({
([      "name":"孫",      "id":"sun"    ]),
([      "name":"吳",      "id":"wu"     ]),
([      "name":"獨孤",    "id":"dugu"   ]),
([      "name":"賴",      "id":"lai"    ]),
([      "name":"林",      "id":"lin"    ]),
([      "name":"趙",      "id":"zhao"   ]),
([      "name":"任",      "id":"ren"    ]),
([      "name":"錢",      "id":"qian"   ]),
([      "name":"李",      "id":"li"     ]),
([      "name":"張",      "id":"zhang"  ]),
([      "name":"臧",      "id":"zang"   ]),
([      "name":"徐",      "id":"xu"     ]),
([      "name":"楊",      "id":"yang"   ]),
([      "name":"邱",      "id":"qiu"    ]),
([      "name":"舒",      "id":"shu"    ]),
([      "name":"葉",      "id":"ye"     ]),
([      "name":"劉",      "id":"liu"    ]),
([      "name":"周",      "id":"zhou"   ]),
([      "name":"楊",      "id":"yang"   ]),
([      "name":"王",      "id":"wang"   ]),
([      "name":"梁",      "id":"liang"  ]),
([      "name":"黃",      "id":"huang"  ]),
([      "name":"林",      "id":"lin"    ]),
([      "name":"陳",      "id":"chen"   ]),
([      "name":"謝",      "id":"xie"    ]),
([      "name":"魯",      "id":"lu"     ]),
([      "name":"何",      "id":"he"     ]),
([      "name":"曾",      "id":"zeng"   ]),
([      "name":"郭",      "id":"guo"    ]),
([      "name":"成",      "id":"cheng"  ]),
([      "name":"南宮",    "id":"nangong"  ]),
([      "name":"歐陽",    "id":"ouyang"   ]),
([      "name":"長孫",    "id":"zhangsun" ]),
([      "name":"慕容",    "id":"murong"   ]),
([      "name":"西門",    "id":"ximen"    ]),
([      "name":"公孫",    "id":"gongsun"  ]),
([      "name":"端木",    "id":"duanmu"  ]),
});

mapping *second_name=({
([      "name":"",      "id":""      ]),
([      "name":"風",    "id":"feng"  ]),
([      "name":"德",    "id":"de"    ]),
([      "name":"曉",    "id":"xiao"  ]),
([      "name":"富",    "id":"fu"    ]),
([      "name":"達",    "id":"da"    ]),
([      "name":"默",    "id":"mo"    ]),
([      "name":"玄",    "id":"xuan"  ]),
([      "name":"海",    "id":"hai"   ]),
([      "name":"自",    "id":"zi"    ]),
([      "name":"泰",    "id":"tai"   ]),
([      "name":"昭",    "id":"zhao"  ]),
([      "name":"",      "id":""      ]),
([      "name":"通",    "id":"tong"  ]),
([      "name":"耘",    "id":"yun"   ]),
([      "name":"奮",    "id":"fen"   ]),
([      "name":"宏",    "id":"hong"  ]),
([      "name":"榮",    "id":"rong"  ]),
([      "name":"鵬",    "id":"peng"  ]),
([      "name":"衝",    "id":"chong" ]),
([      "name":"灝",    "id":"hao"   ]),
([      "name":"思",    "id":"si"    ]),
([      "name":"理",    "id":"li"    ]),
([      "name":"剛",    "id":"gang"  ]),
([      "name":"武",    "id":"wu"    ]),
([      "name":"逸",    "id":"yi"    ]),
});
          
mapping *third_name=({
([      "name":"峰",    "id":"feng"  ]),
([      "name":"華",    "id":"hua"   ]),
([      "name":"奇",    "id":"qi"    ]),
([      "name":"歌",    "id":"ge"    ]),
([      "name":"旭",    "id":"xu"    ]),
([      "name":"發",    "id":"fa"    ]),
([      "name":"威",    "id":"wei"   ]),
([      "name":"暉",    "id":"hui"   ]),
([      "name":"城",    "id":"cheng" ]),
([      "name":"軒",    "id":"xuan"  ]),
([      "name":"勇",    "id":"yong"  ]),
([      "name":"泰",    "id":"tai"   ]),
([      "name":"在",    "id":"zai"   ]),
([      "name":"君",    "id":"jun"   ]),
([      "name":"軍",    "id":"jun"   ]),
([      "name":"凡",    "id":"fan"   ]),
([      "name":"偉",    "id":"wei"   ]),
([      "name":"帆",    "id":"fan"   ]),
([      "name":"雄",    "id":"xiong" ]),
([      "name":"濤",    "id":"tao"   ]),
([      "name":"波",    "id":"bo"    ]),
([      "name":"傑",    "id":"jie"   ]),
([      "name":"郎",    "id":"lang"  ]),
});                                     




string *degree_desc=({
       HIC "裨將" NOR,
       HIY "佐將" NOR,
       HIY "副將" NOR,
       HIR "將軍" NOR,
       HIR "提督" NOR,
       HIR "總督" NOR,
       MAG "兵部侍郎" NOR,
       MAG "兵部尚書" NOR,
       HIB "鎮北節度使" NOR,
});                            


void attack_over(object me);
void attack_begin(object me,object target,object room,
object env,string dir);
int get_exp_rate();
int get_level(int exp);   
void create()
{
        int rate,lvl,ratio,basic_radio,skill,nl,exp;
        string id,idf;
        string name;  
        int index;

        index=random(sizeof(first_name));
        name=first_name[index]["name"];
        id=first_name[index]["id"];
        idf=id; 

        index=random(sizeof(second_name));
        name+=second_name[index]["name"];
        id+=" "+second_name[index]["id"];

        index=random(sizeof(third_name));
        name+=third_name[index]["name"];
        id+=third_name[index]["id"];

        set_name(name,({id,idf}) );

        set("gender", "男性");
        set("age", random(20) + 20);
        set("str", 160);
        set("dex", 160);
        set("con", 160);

        set("long", "這是一名大宋將軍，正威風凜凜地巡視著自己的隊伍。\n");

        set("int", 30);
        set("str", 30+random(20));
        set("con", 20+random(20));
        set("dex", 20+random(20));
        set("age", 20+random(30));
        set("per", 15+random(15)); 
        set("age", 20+random(30));
        set("per", 15+random(15));                                         
        set("no_get",1);
        ratio=80+random(40);
        rate=get_exp_rate();
        exp=(random(rate)+1)*(random(rate)+1)*100000;    
        if(exp < 1000000) exp =1000000;
        skill=get_level(exp);
        if(skill<200)    skill=200;   
        set("combat_exp",exp/100*ratio);
        nl=skill*10+exp/1000;
        set("max_neili",nl*ratio/100);
        set("neili",query("max_neili")*3/2); 
        set("max_jingli",skill*20*ratio/100);
        set("jingli",query("max_jingli"));
        basic_radio=skill/100;
        set("max_qi",(query("max_neili")*ratio/200+1000*basic_radio));
        set("qi",query("max_qi"));
        set("eff_qi",query("max_qi"));
        set("max_jing",query("max_jingli")*ratio/300+400*basic_radio);
        set("eff_jing",query("max_jing"));
        set("jiali",skill/2); 
        set("food",500);
        set("water",500);
        set_skill("taiji-shengong", skill);
        set_skill("wuhu-duanmendao", skill);
        set_skill("tiyunzong", skill);
        set_skill("taiji-quan", skill);
        set_skill("unarmed",skill);
        set_skill("force",skill);
        set_skill("dodge", skill);
        set_skill("blade", skill);
        set_skill("parry", skill);
        set_skill("arrow", skill*2/3);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("blade", "wuhu-duanmendao");   
  
        set_temp("zuji_quest/party","song"); 
        set("no_cleanup",1);  
        set("start_time",time());
        add_temp("apply/armor",400);
        add_temp("apply/damage",100);
        setup();
        lvl=(query("str")+skill/10)/10-1;
        if( lvl > 8 ) lvl = 8;
        lvl = lvl - 2;
        if( lvl < 3 ) lvl = 3;
        carry_object("/quest/zhuzao/weapon/bow/bow"+lvl);
        carry_object("/quest/zhuzao/weapon/bow/bow"+lvl);
        carry_object("/quest/zhuzao/weapon/bow/bow"+lvl);
        carry_object("/quest/zhuzao/weapon/bow/bow"+lvl);
        carry_object(__DIR__"obj/wandao");
        carry_object(__DIR__"obj/wandao");
        carry_object(__DIR__"obj/wandao")->wield();
        carry_object(__DIR__"obj/tiejia")->wear();   
        carry_object(__DIR__"obj/pifeng")->wear();  
}


int get_level(int exp)
{
  int level=0;
  do {
      level++;
     } while(level*level*level<(exp*10));

  return level;
}

int get_exp_rate()
{
     object *ulist;
     int i,max_exp=1000000,exp_rate=6;
     ulist  =  users();
     i = sizeof(ulist);
     while (i-- )
     {
         if ( !environment(ulist[i]) ) continue;
         if ( wizardp(ulist[i]) ) continue;

         if ((int)ulist[i]->query("combat_exp") > max_exp)
         max_exp=(int)ulist[i]->query("combat_exp");
     }

     do{
         exp_rate++;
       } while(exp_rate*exp_rate<max_exp/100000);

     return (exp_rate*6/5);
}

void change_ob()
{ 
  int jungong;
  string temp;
  object ling;

  jungong=4+random( query("combat_exp")/5000000 + 1);
  if( jungong > 12 ) jungong = 12;
  set("title",degree_desc[jungong-4]);
  set("degree_jungong",jungong);
  add("eff_qi",jungong*2000);
  set("qi",query("eff_qi"));
  set_temp("zuji_quest/group",jungong);

/*
  temp=read_file("quest/quest_jun/song/master",1,1);
  ling=new(__DIR__"obj/lingjian");
  ling->set("owner", query("id"));
  ling->set("master", temp);
  ling->move(this_object());
  ling->check_me(this_object());
*/
  call_out("check_me",2,this_object());    
  return;
}


void die()
{
        message_vision("$N率領的宋軍將士寡不敵眾，不幸"
        +HIR"全軍覆沒"NOR"！\n",this_object());
        destruct(this_object());
        return;
}

void check_me(object me)
{
       object *ob,obb,env,room;
       string *dirs,dir,temp;
       mapping exits;
       int group,i;

       if( !objectp(me) ) return;


       group = ( me->query("eff_qi") - me->query("max_qi") ) / 2000; 
       if( group < 1 ) group=1;     
       me->set("qi",me->query("eff_qi"));
       me->set_temp("zuji_quest/group",(group+1));
       env=environment(me);

       if( !living(me) )
       {
        remove_call_out("check_me");
        call_out("check_me",1,me); 
        return;
       }       

       ob = all_inventory(env);
       if( sizeof(ob)>0 && !me->query_temp("zuji_quest/attack") )
       {
         for(i=0;i<sizeof(ob);i++)
         {
          obb=ob[i];
          if( !obb->is_character() ) continue; 
          if(obb->query_temp("zuji/party") == "qidan" )
          {
            message_vision(HIC"$N大聲下令道：騎兵準備！一排排騎兵列出整齊"
            +"的方陣，\n陽光下的大宋軍刀閃閃發光——突擊！！"
            +"$N一聲令下，\n萬馬齊鳴，大宋騎兵開始了可怕的衝鋒！！\n"NOR,me);  

            me->set_temp("zuji_quest/attack",1);
            me->set_temp("zuji_quest/attacking",1);
            call_out("attack_over",10,me);
            attack_begin(me,obb,env,env,dir);                    
            break; 
            remove_call_out("check_me");
            call_out("check_me",1,me);
            return;
           }
          } 
        }

       if( mapp(exits = env->query("exits"))
           && !me->query_temp("zuji_quest/attack")
           && me->query("qi") > me->query_temp("zuji_quest/group")*200
           && me->query("jing") > me->query_temp("zuji_quest/group")*100 )
       {
         dirs = keys(exits);
         for(i=0; i<sizeof(dirs); i++)
         if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
         dirs[i] = 0;
         dirs -= ({ 0 });
         if( mapp(exits) ) dir=dirs[random(sizeof(dirs))];
         if (!room=find_object(exits[dir])) room=load_object(exits[dir]);

         if (room)  
         {
           ob = all_inventory(room);
           if( sizeof(ob)>0 )
           {
            for(i=0;i<sizeof(ob);i++)
            {
             obb=ob[i];
             if( !obb->is_character() ) continue;
          if(obb->query_temp("zuji/party") == "qidan" )
             {
               message_vision(HIC"$N大聲下令道：弓箭手準備！一排排利箭在陽"
               +"光下閃閃發光——射擊！！\n$N一聲令下，萬弩齊發！\n"NOR,me);  
               me->set_temp("zuji_quest/attack",1);
               me->set_temp("zuji_quest/attacking",1);

               call_out("attack_over",10,me);
               attack_begin(me,obb,room,env,dir);                    
               break; 
               remove_call_out("check_me");
               call_out("check_me",1,me);
               return;
              }
             } 
           }
         }
       }

       if( !me->query_temp("zuji_quest/attack") )
       me->delete_temp("zuji_quest/attacking");

       remove_call_out("check_me");
       call_out("check_me",1,me);
       return;
}      


void attack_begin(object me,object target,object room,object env,string dir)
{
       object weapon,bow,blade,weapon2,*ilist;
       int i;

       weapon=me->query_temp("weapon");
       if(weapon) weapon->unequip();

       blade=present("wan dao",me);
       ilist=all_inventory(me);
       for(i=0;i<sizeof(ilist);i++)
       {
           if( ilist[i]->query("is_bow") )
           {
               bow = ilist[i];
               break;
           }
       }

       if( env == room ) weapon2 = blade;
       else weapon2 = bow;
       if( weapon2 )
       weapon2->wield();
       for(i=0;i<me->query_temp("zuji_quest/group");i++)
       {
          if( objectp(target) && weapon2->query("equipped") && weapon2->query("is_bow") )
              weapon2->do_shoot(target->query("id"),me,weapon2,room,dir,1);  
          else
          if( room == env && objectp(target) )
          {
           message_vision(HIC"$N指揮的大宋鐵騎，萬馬奔騰，"
                  +"如狂風驟雨般朝$n發起了衝擊！！\n"NOR,me,target);  
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0); 
          } else break;
       }
       return;
}

void attack_over(object me)
{
      if( objectp(me) )
      {
        message_vision(HIB"$N手中軍刀一揮，大宋騎兵攻勢一緩，重新"
        +"開始列陣，準備發起新一輪的衝擊！！\n"NOR,me); 
        me->delete_temp("zuji_quest/attack");
      }
      return;
}      
