//redl 2014
#include <ansi.h> 
inherit __DIR__"normal.c"; 

void create()
{
        set("short", "九老洞");
        set("long", @LONG
這是九老洞裡的最深處，深窈無比神秘難測。你走進來一看，大
吃一驚。數不清的吸血蝙蝠在半空中盤旋，往中央的一座巨大的血池
裡哺血。洞裡隱隱傳來風雷之聲。
LONG );
        /*set("objects", ([
             __DIR__"npc/bianfu1" : 10,
        ]));*/

        set("no_protect", 1); 
        set("n_time", 180);  
        set("n_npc", 1);  
        set("n_max_npc", 3); 
        set("s_npc", "/d/emei/xue/npc/boss3");

                set("stop_run", 1);
                set("du_time", time());
        setup();
        set("n_npc", 0);  
        set("n_max_npc", 0); 
}

void heart_beat()
{
        object enemy;
        object *enemies, *obs;
        mapping my;
        int itmp, kar, zy_n;
                
                if (query("du_time") < time()) {
                        
                        set("du_time", time() + 10);
                        
                        enemies = filter_array(all_inventory(this_object()), (: playerp($1) :));
                        if (arrayp(enemies) && sizeof(enemies)) {
                                set("n_visitor", 0);
                        } else {
                                addn("n_visitor", 1);
                                if (query("n_visitor") > 99) {
                                        destruct(this_object());
                                        return;
                                }
                        }
                
                                obs = filter_array(all_inventory(this_object()),
                           (: $1->is_character() &&
                           query("id", $1) == "xixue bianfu"
                           :));
                           
                        if (arrayp(obs) && sizeof(obs) > 0) {//有蝙蝠
                                
                                enemies = filter_array(all_inventory(this_object()),
                           (: playerp($1) //&&
                           :));
        
                        if (arrayp(enemies) && sizeof(enemies)) {foreach (enemy in enemies) {
                                my = enemy->query_entire_dbase();
                                
                                itmp = my["max_qi"] / 60; 
                                if (itmp < 1000000) itmp = 1000000;
                                my["eff_qi"] -= itmp; 
                                if (my["qi"] > my["eff_qi"]) my["qi"] = my["eff_qi"];
                                
                                itmp = my["max_jing"] / 60; 
                                if (itmp < 500000) itmp = 500000;
                                my["eff_jing"] -= itmp; 
                                if (my["jing"] > my["eff_jing"]) my["jing"] = my["eff_jing"];
                                
                                tell_object(enemy, BGRN + HIR + "蝙蝠噴出一口濃煙，你中毒了。\n" + NOR);
                                if (my["jing"] < 1 || my["qi"] < 1) {
                                        my["qi"] = my["eff_qi"] = -1;
                                        my["jing"] = my["eff_jing"] = -1;
                                        set_temp("die_reason", NOR + "被九老洞的蝙蝠毒死了" + NOR, enemy);
                                }
                                }
                        }
                        }

                                obs = filter_array(all_inventory(this_object()),
                           (: $1->is_character() &&
                           query("id", $1) == "zheng yin"
                           :));
                           
                        if (arrayp(obs) && (zy_n = sizeof(obs)) > 0) {//有鄭隱
                                if (zy_n > 11) zy_n = 11;
                                enemies = filter_array(all_inventory(this_object()),
                           (: $1->is_character() && living($1) && 
                           query("id", $1) != "zheng yin" &&
                           query("id", $1) != "xixue bianfu"
                           :));
        
                        if (arrayp(enemies) && sizeof(enemies)) {foreach (enemy in enemies) {
                                        kar = enemy->query_kar();
                                        if (random(kar) >= zy_n) continue;
                                        
                                my = enemy->query_entire_dbase();
                                
                                itmp = my["max_qi"] / 2 + 1; 
                                if (itmp < 60000000) itmp = 60000000;
                                my["eff_qi"] -= itmp; 
                                if (my["qi"] > my["eff_qi"]) my["qi"] = my["eff_qi"];
                                
                                itmp = my["max_jing"] / 2 + 1; 
                                if (itmp < 30000000) itmp = 30000000;
                                my["eff_jing"] -= itmp; 
                                if (my["jing"] > my["eff_jing"]) my["jing"] = my["eff_jing"];
                                
                                message_vision(NOR + BLINK + YEL + "一條" + NOR + BLINK + HIR + "血影" + NOR + BLINK + YEL + 
                                        "躍起往$N" + NOR + BLINK + YEL + "一撲，$N" + NOR + BLINK + YEL + "的半邊身體“轟”地一下炸開，氣息奄奄。\n" + NOR, enemy);
                                if (my["jing"] < 1 || my["qi"] < 1) {
                                        my["qi"] = my["eff_qi"] = -1;
                                        my["jing"] = my["eff_jing"] = -1;
                                        set_temp("die_reason", NOR + "被鄭隱的血影神光奪舍而亡了" + NOR, enemy);
                                        enemy->die();
                                }
                                }
                        }
                        }

                }
        
        return ::heart_beat();
}

void bborn()
{
        if (!query("flag_bborn")) set("flag_bborn", 0);
        addn("flag_bborn", 1);
        switch (query("flag_bborn")) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                        tell_room(this_object(), NOR HIR "血池" NOR + (random(2) ? "中血浪翻滾，一具透明的軀體在裡面沉浮。\n" : "裡冒著氣泡，咕嚕咕嚕地像開水沸了一般。\n") + NOR);
                        break;
                case 7:
                case 8:
                        break;
                case 9:
                        tell_room(this_object(), NOR HIR "血池" NOR "突然沉寂下來。\n" NOR);
                        break;
                case 10:
                case 11:
                case 12:
                case 13:
                        break;
                case 14:
                        tell_room(this_object(), NOR CYN "在囂張的狂笑中，" HIR "血池" NOR CYN  "裡那道身影漸漸冒出水面，透明地站在你的面前。\n" NOR);
                        break;
                case 15:
                        tell_room(this_object(), NOR CYN "透明的影子越來越真實...\n" NOR);
                        break;
                case 16:
                        tell_room(this_object(), NOR CYN "影子的五官漸漸可辨，是個英俊男子。\n" NOR);
                        break;
                case 17:
                        new("/d/emei/xue/npc/boss5")->move(this_object(), 1);
                        break;
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                        break;
                default:
            set("n_npc", 1);  
                set("n_max_npc", 3); 
                        return;
        }
        
        remove_call_out("bborn");
        call_out("bborn", 1);           
}

int pour_in(string arg) 
{ 
        object enemy;
        object *enemies, *obs;
        object ob, me = this_player();
        string msg, myname = query("name", me);

        if (!arg || arg != "god blood in pool") {
                tell_object(me, NOR"你要往池子裡倒什麼？"HIK "(pour god blood in pool)\n"NOR);  
                return 1;
        }

        ob = query_temp("handing", me);
        if (!ob || base_name(ob)!="/clone/fam/etc/prize5") {
                tell_object(me, NOR"你手裡沒有拿(hand)著神聖血清！\n"NOR);  
                return 1;
        }
        
        if (query("pour_time") > 2) {
                tell_object(me, NOR HIR"血池"NOR"裡已經充分盛滿了！\n"NOR);  
                return 1;
        }

        message_vision(NOR YEL + "$N" + NOR YEL "掏出一瓶" + query("name", ob) + NOR YEL "擰開蓋子，往" HIR "血池" NOR YEL "裡一倒..\n" NOR, me);
        addn("pour_time", 1);
        destruct(ob);

                        enemies = filter_array(all_inventory(this_object()),
                           (: $1->is_character() &&
                           query("id", $1) == "zheng yin"
                :));

        if (arrayp(enemies) && sizeof(enemies)) {
                tell_room(this_object(), NOR YEL + "面前" + chinese_number((sizeof(enemies))) + "個" + NOR + HIC + "鄭隱" + NOR YEL + "捂住臉慘叫一聲，護體血光猛地顫抖搖曳。\n" NOR);    
                enemies->die(me);//群死
        } else if (!query("flag_bborn")) {
                bborn();
        }
        
        if (query("pour_time") > 2) {
                tell_object(me, NOR BLINK HIR"\n血池"NOR BLINK HIY"開始劇烈震動，整個空間即將崩潰。\n\n"NOR);  
                                obs = filter_array(all_inventory(this_object()),
                           (: $1->is_character() &&
                           query("id", $1) == "zheng yin"
                           :));
                        if (!arrayp(obs) || !sizeof(obs)) {//沒鄭隱了
                                        if (random(3)) ob = new(__DIR__"npc/obj/tpen");
                                                else ob = new(__DIR__"npc/obj/tjsfan");
                                CHANNEL_D->channel_broadcast("rumor", NOR + MAG + "聽說" + myname + NOR + MAG + "燒乾血池發現了" + query("name", ob) + NOR + MAG + "。\n" NOR);
                                ob->move(this_object(), 1);
                        }
                call_out("kick_out_all", 15);
        set("n_npc", 0);  
        set("n_max_npc", 0); 
                        enemies = filter_array(all_inventory(this_object()),
                           (: $1->is_character() &&
                           query("id", $1) == "xixue bianfu"
                :));
                        if (arrayp(enemies) && sizeof(enemies)) {
                                foreach (enemy in enemies) {
                                        destruct(enemy);
                        }
                        }
        }
        return 1;  
} 

void init()
{
        object me = this_player();
        if (!playerp(me)) return;
        if( wiz_level(me) < 2 )
                if (query("jldong/enter_time", me) > time()) {
                        tell_object(me, NOR CYN "\n你腳步一空，筆直掉入一個洞穴裡，\n你尖叫著繼續往下掉落，風聲在耳邊呼嘯而過...\n定睛一看，你已經來到了洞外。\n\n" NOR); 
                        me->move("/d/emei/jldongnei");
                        return;
                }
        //set("jldong/enter_time", time() + 86400 * 3 / 2, me);
        set("jldong/enter_time", time() + 86400, me);
        me->start_busy(3);
        tell_object(me, NOR CYN "\n你腳步一空，筆直掉入一個洞穴裡，\n眼見四周無路，你在想往那座" HIR "血池" NOR CYN "裡倒(pour)點什麼？\n或者……乾脆快點騎馬離開這裡吧。\n\n" NOR); 
        add_action("pour_in", ({ "pour"})); 
        return ::init();
}

void kick_out_all()
{
        object enemy;
        object *enemies;
        if (!query("kickout_time")) {
                set("kickout_time", 31);
        }
        addn("kickout_time", -1);
        if (query("kickout_time") < 1) {
                destruct(this_object());
        } else {
                remove_call_out("kick_out_all");
                call_out("kick_out_all", 1);            
                tell_room(this_object(), NOR HIY "(銷燬剩餘) " + chinese_number(query("kickout_time")) + " 秒！\n" NOR);
        }
}

