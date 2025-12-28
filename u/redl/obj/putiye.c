// This program is a part of NITAN MudLIB 
// redl 2013/1/1 
#include <armor.h>
#include <ansi.h>

inherit EARRING;

#define OWNER_ID "juice,guoxiang,kelly,unable,ruby,"    //指定玩家的裝備
#define TIME_INTERVAL 10
#define BONUS_DELAY 720         //每小時結5顆ptz，一天120，給盲人添點兒綠意


int is_redl_room(object room)
{
        if (base_name(room) == "/u/redl/workroom") return 1;
        return 0;
}

void jieguozi()//准許讓他把這寶物借予普通玩家賞玩，讓他覺得自己有存在感
{
        object own = environment(this_object());
        int i = query("guozi_step");
        
        if (objectp(own) && !is_redl_room(own)) {
                
                if (playerp(own)) {
                        i -= TIME_INTERVAL;
                        if (i<1) {
                                message_vision(NOR + YEL + "只見" + query("name") + NOR + YEL + "上，花瓣零落，露出一枚晶瑩透綠的果實。\n$N伸手輕輕摘下果實，得到了一顆" + HIG + "菩提子" + NOR + YEL + "！\n" + NOR, own);
                                new("/clone/gift/puti-zi")->move(own);
                        }
                        else if (i==30) tell_object(own, NOR + YEL + "你看見" + query("name") + NOR + YEL + "上，菩提花開始漸漸凋謝……\n" + NOR);
                        else if (i==120) tell_object(own, NOR + YEL + "你看見" + query("name") + NOR + YEL + "上，花苞慢慢長大，變成了豔麗的紅花。\n" + NOR);
                        else if (i==360) tell_object(own, NOR + YEL + "你看見" + query("name") + NOR + YEL + "上，嫩黃色的花骨朵長出來了。\n" + NOR);
                        else if (i==640) tell_object(own, NOR + YEL + "你看見" + query("name") + NOR + YEL + "上，悄悄鑽出了一點嫩黃色。\n" + NOR);
                        if (i<1) set("guozi_step", BONUS_DELAY);
                                else set("guozi_step", i);
                }

                if (strsrch(OWNER_ID, query("id", own)+",")<0) {
                        addn("chk_own", TIME_INTERVAL);
                        if (query("chk_own") > 180 * TIME_INTERVAL) {//借出，或者丟失超過半小時
//                              message_vision(NOR + query("name") + NOR + CYN + "輕輕一顫，化為一道青煙消失了！\n" + NOR, own);
//                              own = find_player();
//                              if (playerp(own)) {
//                                      tell_object(own, NOR + CYN + "只見一縷青煙往你迎面撲來，原來是" + query("name") + NOR + CYN + "飛到懷裡來了！\n" + NOR);
//                                      this_object()->move(own);
//                              } else {
                                        destruct(this_object());
//                                      return;
//                              }
                        }
                } else set("chk_own", 0);
        
        }
        
        call_out("jieguozi", TIME_INTERVAL);
}

void create()
{
        set_name(HIG "菩提葉·三仙" NOR, ({ "puti ye", "puti", "ye" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long", HIG "這是一枚曾經生長在佛祖證道的菩提樹上的樹葉，象徵著如海的智慧和胸懷廣闊。\n" NOR);
                set("value", 50000000);
                set("material", "gold");
                set("armor_prop/str", 300);
                set("armor_prop/int", 300);
                set("armor_prop/con", 300);
                set("armor_prop/dex", 300);
                set("armor_prop/armor", 50000);
                set("armor_prop/armor1", 50000);
                set("armor_prop/damage", 25000);
                set("armor_prop/damage1", 25000);
                set("armor_prop/unarmed_damage", 25000);
                set("armor_prop/attack", 2000);
                set("armor_prop/defense", 2000);
                                set("armor_prop/research_times", 3000);
                set("armor_prop/research_effect", 800);
                set("armor_prop/practice_times", 3000);
                set("armor_prop/practice_effect", 800);
                set("armor_prop/learn_times", 3000);
                set("armor_prop/learn_effect", 800);
                set("armor_prop/derive_times", 1500);
                set("armor_prop/derive_effect", 800);
                set("armor_prop/full_self", 20);
                set("armor_prop/reduce_poison", 40);
                //set("armor_prop/add_locked", 10);
                //set("armor_prop/avoid_locked", 20);
                set("armor_prop/fatal_blow", 20);
                set("armor_prop/add_skill", 380);
                set("armor_prop/avoid_die", 35);
                set("armor_prop/avoid_blind", 90);
                set("armor_prop/ap_power", 100);
                set("armor_prop/dp_power", 150);
                set("armor_prop/da_power", 50);
                set("armor_prop/avoid_busy", 30);
                set("armor_prop/reduce_busy", 30);
                set("guozi_step", BONUS_DELAY);
        }
        setup();
        call_out("jieguozi", TIME_INTERVAL);
}        

int query_autoload()
{
        return 1;
}


int wear()
{
        object me = this_player();
        if (strsrch(OWNER_ID, query("id", me)+",")<0) {
                tell_object(me, NOR + "特殊物品，你戴不上這枚葉子...\n" + NOR);//不許普通玩家非法穿戴變態屬性的物品
                return -1;
        }
        if (::wear()) {
                message_vision(YEL + "$N輕輕捻起一枚" + NOR + query("name") + NOR + YEL + "插在頭髮上。\n" + NOR, me);
                return 1;
        }
}


// 
// //get()
//      mapping ob; 
//      object *obs;
//      obs = all_inventory(); 
//      if (sizeof(obs) > 0) 
//      { 
//              if (arrayp(query_temp("objects"))) 
//                      obs -= query_temp("objects"); 
//              //obs = filter_array(obs, (: ! living($1) && clonep($1) && ! $1->is_character() :)); 
//              obs = filter_array(obs, (: ! $1->is_user() :)); //要驅逐寵物的幫助，只能留下玩家自己
//              if (sizeof(obs) > 0) 
//              { 
//                      obs = obs[0..<1]; 
//                      foreach (ob in obs) destruct(ob); 
//              } 
//      } 
        


