// This program is a part of NITAN MudLIB 
// redl 2013/9
//神器展覽室的作用，玩家無法拾取
#include <ansi.h> 
#include <room.h> 
inherit __DIR__"normal.c"; 

#define CREATE_INTERVAL 120             

int set_lv(object obj, int flag)
{
                if (!flag)
                {
                set("combat/MKS", 2100, obj);
                set("owner/redl", 21000000, obj);
                set("magic/imbue_ok", 1, obj);
                set("magic/blood", 21000, obj);
                set("ultimate/37", 1, obj);
                set("ultimate/39", 1, obj);
                set("enchase/flute", 9, obj);
                set("enchase/SN", 105, obj);
                IDENTIFY_D->identify_ultimate_ob(obj, 1);
                } else
                {
                set("combat/MKS", 2100, obj);
                set("owner/redl", 21000000, obj);
                set("magic/imbue_ok", 1, obj);
                set("magic/blood", 21000, obj);
                set("ultimate/37", 1, obj);
                set("ultimate/39", 1, obj);
                set("enchase/flute", 9, obj);
                set("enchase/SN", 121, obj);
                IDENTIFY_D->identify_ultimate_ob(obj, 1);
            }
        return 1;
}

int do_clear()
{
        object *inv;
        
                        inv = all_inventory();
                        if( sizeof(inv) > 0 ) {
                foreach( object ob2 in inv ) {
                        if( !ob2->is_character() ) {
                                        message_vision(append_color(NOR + CYN + "幾個機關人衝過來，把$N" + NOR + CYN + "快速" + (random(2) ? "裝進" : "掃到") + "垃圾袋裡。\n" + NOR, CYN), ob2);
                                        destruct(ob2); 
                        }
                }
                }
                
        return 1;
}

int create_item()
{
        int rnd, i = random(5) + 4;
        object ob;
        string msg = "";
        
        remove_call_out("create_item");
        remove_call_out("do_clear");
        while (i--) {
                ob = EQUIPMENT_D->create_dynamic("", 60, 600);
        //      rnd = random(100);
//              //if (sscanf(base_name(ob), "/clone/tessera/%*s")) rnd = 100;//排除寶石
//              if (rnd<1) {
//                      CHANNEL_D->channel_broadcast("wiz", "太古" + base_name(ob) + "\n");
//                      set_lv(ob, 1);
//                      msg = HIK "黑白兩色照耀天地，太古洪荒" + (random(2) ? "氣息" : "味道") + "讓人窒息...\n";
//              }
//              else if (rnd<10) {
//                      CHANNEL_D->channel_broadcast("wiz", "遠古" + base_name(ob) + "\n");
//                      set_lv(ob, 0);
//                      msg = HIY "數顆流星疾射而過，遠古蠻荒" + (random(2) ? "氣息" : "味道") + "四散飄逸...\n";
//              }
                ob->move(this_object());
                message_vision(msg + HIC + (random(2) ? "哐啷" : "噹地") + "~" + (random(2) ? "~" : "") + "~一聲，" + 
                                                                                     ob->name() + NOR + HIC + (random(2) ? "從天而降" : "掉下來") + 
                                                                                     "，" + (random(2) ? "差點" : "險些") + 
                                                                                      (random(2) ? "砸到你頭上" : "落到雲海下") + 
                                                                                      "，樓裡" + (random(2) ? "傳來" : "響起") + 
                                                                                      (random(2) ? "幾句" : "兩人的") + 
                                                                                      (random(2) ? "叫罵" : "吵架聲") + "。\n" + NOR, 
                                                                             ob);
        }
        rnd = CREATE_INTERVAL / 2 + random(CREATE_INTERVAL / 2);
        call_out("do_clear", rnd * 9 / 10);
        call_out("create_item", rnd);
        return 1;
}

void create()
{
        set("short", "天宮寶樓");
        set("long", 
"這是雲端之上的一坪絕地，常年不見風雨雷電，只有日月靜靜地\n"
"輪番流轉。中央是座七層的木質樓閣，據說那上面是為天神打造神器\n"
"的處所，樓裡隱約有打鐵和畫符的聲音可聞。\n"
);
                set("exits",([ /* sizeof() == 1 */
                        "out" : __DIR__"teleport",
                ]));

        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_magic", 1); 
        set("no_sleep_room", 1); 
        //set("no_get", 1);
        set("max_carry_user" ,16);
        set("max_carry_exit" ,"out");
        
        setup();
        call_out("create_item", 3);
}

int do_action(string arg)
{
        string action = query_verb();
        object ob, me = this_player();
        
        if (action=="get") {
                if (!arg || arg=="" || arg=="all") {
                                tell_object(me, NOR "你到底想拿什麼？\n" NOR);
                                return -1;
                        }
                        
                        ob = present(arg, this_object());
                        if (!ob || !objectp(ob)) {
                                        tell_object(me, NOR "附近沒有這樣東西。\n" NOR);
                                        return -1;
                        }
                        if (!sscanf(base_name(ob), "/inherit/template/armor/%*s") && !sscanf(base_name(ob), "/inherit/template/weapon/%*s")) {
                                        tell_object(me, NOR "這樣東西拿不起來。\n" NOR);
                                        return -1;
                        }
                        
                        if (sscanf(base_name(ob), "/inherit/template/weapon/%*s") ||
                                sscanf(base_name(ob), "/inherit/template/armor/finger%*s") ||
                                sscanf(base_name(ob), "/inherit/template/armor/hands%*s")
                                ) {
                                if (query("teleport/tweapon", me) < 1) {
                                        tell_object(me, NOR "你還沒有購買天宮寶樓武器兌換券，指令<ntstore buy tweapon>。\n" NOR);
                                        return -1;
                                }
                                if (ob->move(me)) {
                                        addn("teleport/tweapon", -1, me);
                                        addn("teleport/log/tweapon", 1, me);
                                        message_vision(NOR "$N手疾眼快，飛快把$n" NOR "搶在手裡。\n" NOR, me, ob);
                                } else {
                                        tell_object(me, NOR "你身上超重了？\n" NOR);
                                }
                                return 1;
                        }
                        
                        if (sscanf(base_name(ob), "/inherit/template/armor/%*s")) {
                                if (query("teleport/tarmor", me) < 1) {
                                        tell_object(me, NOR "你還沒有購買天宮寶樓防具兌換券，指令<ntstore buy tarmor>。\n" NOR);
                                        return -1;
                                }
                                if (ob->move(me)) {
                                        addn("teleport/tarmor", -1, me);
                                        addn("teleport/log/tarmor", 1, me);
                                        message_vision(NOR "$N手疾眼快，飛快把$n" NOR "搶在手裡。\n" NOR, me, ob);
                                } else {
                                        tell_object(me, NOR "你身上超重了？\n" NOR);
                                }
                                return 1;
                        }
                }
                
        return 0;
}

void init()
{
        object me = this_player();
        
        if ( wiz_level(me) < 7 ) add_action("do_action", "");
        
        return ::init();
}


