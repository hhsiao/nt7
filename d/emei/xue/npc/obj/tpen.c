// This program is a part of NITAN MudLIB 
// redl 2014
// 寶物
#include <armor.h>
#include <ansi.h>
inherit F_NOCLONE;

inherit MYHEART;

int query_autoload() { return 0; }
int is_artifacts() { return 1; }

int is_container() { return 1; }

void create()
{
        
        set_name(HIR "蝠" NOR WHT "鼠" NOR YEL "聚寶盆" NOR, ({ "jubao pen", "pen" }));
        set("long", HIC "這是隻銅盆，上面雕刻著“蝠鼠吊金錢”圖，長期戴上會有大收穫。\n" HIK "(下線丟失，無法保存)\n" NOR);
        set_weight(99999);
        set_max_encumbrance(99999);
                set("unit", "只");
                set("value", 100);
                set("material", "gold");

//                set("no_give", 1);
//                set("no_drop", 1);
//                set("no_get", 1);
//                set("no_uget", 1);
                set("no_steal", 1);
                set("no_sell", 1);
                set("no_beg", 1);
                set("no_put", 1);
                set("no_store", 1);
                set("no_pawn", 1);
                //set("maze_item", 1);//不能give
                set("unique", 1);//已避免分解
                                set("quality_level", 6);
                                
                                set("wear_msg", NOR CYN "$N" NOR CYN "輕輕抱起$n" NOR CYN "掛在腰間。\n"); 
                                set("remove_msg", NOR CYN "$N" NOR CYN "把$n" NOR CYN "從腰帶上解了下來。\n"); 
                
                set("armor_prop/kar", 15);
                set("armor_prop/add_skill", 20);
                set("armor_prop/max_neili", 180000); 
                set("armor_prop/max_jingli", 100000); 
                
                                set_heart_beat(211);
                        setup();
}        


void heart_beat()
{
        object me = this_object();
        object ob, room, owner = environment();
        int rnd;
        
        if (!owner || !owner->is_character() || !query("equipped") || 
                !playerp(owner) || !(room = environment(owner)) || !room->is_room()) {
                        return;
        }

        rnd = random(1000);
        if (rnd < 2) {
                ob = new("/u/redl/npc/obj/penny");
        } else if (rnd < 70) {
                ob = new("/clone/gift/jiuzhuan");
        } else {
                ob = new("/clone/money/yuanbao");
        }

                if (ob->move(me)) {
                        if (rnd<60)
                                message_vision(NOR "\n$N" NOR "腰上的$n" NOR "一震，結出" + query("name", ob) + NOR "。\n\n" NOR, owner, me);
                        else 
                                tell_object(owner, NOR "\n你腰上的" + query("name", me) + NOR "一震，結出" + query("name", ob) + NOR "。\n\n" NOR);
                } else {
                        tell_object(owner, NOR "你的" + query("name", me) + NOR + "已經裝不下" + query("name", ob) + NOR "了。\n");
                        destruct(ob);
                }

}



