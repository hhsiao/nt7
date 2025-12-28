// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 


string look_picture(object me)
{
        if (query("redl/gethomerune", me)<3) {
                add_action("do_kou", "kou");
        return HIC "\n"
        
NOR MAG"╭♀︿☆╮"RED" ╭★︿♂╮" "\n"
NOR MAG"{/ ． ．\\}"RED" {/ ． ．\\}" "\n"
NOR MAG" ( (oo) ) "RED"  ( (oo) )" "\n"
NOR MAG" ︶︶︶︶ "RED"  ︶︶︶︶" "\n"

"\n" NOR "你發現畫上的兩頭豬似乎可以摳(kou)動...\n" NOR;
        } else {
        return HIC "\n"
        
NOR MAG"╭♀︿☆╮"RED" ╭★︿♂╮" "\n"
NOR MAG"{/ ． ．\\}"RED" {/ ． ．\\}" "\n"
NOR MAG" ( (oo) ) "RED"  ( (oo) )" "\n"
NOR MAG" ︶︶︶︶ "RED"  ︶︶︶︶" "\n" NOR;
                }
}


void create()
{
        set("short", "後殿");
        set("long", 
"這裡是化樂天后殿，正中壁龕上供著一副"CYN"畫"NOR"。兩旁牆上鑲嵌了各十二\n"
"顆夜明珠，珠子狀如牛眼，伸縮浮沉不定，大放光華，猶如傳說中的定海\n"
"神珠。整個殿內青煙繚繞，異香撲鼻。\n"
);
//         set("outdoors", "chengdu");
        set("exits",([ /* sizeof() == 1 */
                "north" : __DIR__"private_room/houyuan",
                "south" : __DIR__"private_room/dadian",
                "east"   : __DIR__"cangku",
                                "west"   : __DIR__"prison",
        ]));

        set("item_desc", ([
                "畫": (: look_picture :),
                "hua": (: look_picture :),
                "picture": (: look_picture :),
        ]) );

                set("no_rideto", 1);
                set("no_flyto", 1);
        
        setup();
}

int do_kou()
{
        object me = this_player();
        
        if (!query_temp("can_enterredlroom", me) && query("id", me) != "redl" && query("couple/couple_id", me) != "redl") return notify_fail("傀儡將軍對著你嘿嘿嘿奸笑了幾聲。\n");
        
        if (me->is_busy()) {
                tell_object(me, "你先忙完手裡的事再說吧！\n");
                return 1;
        }
        me->start_busy(1);
        
        set_temp("has_kouredlpig", random(2), me);
        
        message_vision(NOR "$N伸出食指和中指，緩緩插進" +((query_temp("has_kouredlpig", me) ? MAG+"紫豬"+NOR : RED+"紅豬"+NOR))+ "的兩個鼻孔裡摳了摳。\n" NOR, me);
        
        if ( !query_temp("has_kouredl", me) && !random(12) ) {
                message_vision(YEL "只見畫上的" +((query_temp("has_kouredlpig", me) ? MAG+"紫豬"+NOR : RED+"紅豬"+NOR))+ YEL + "舒服地打了個噴嚏，噼裡啪啦一堆珠寶噴在$N臉上。\n" NOR, me);
                if (random(2)) new("/clone/tessera/fdiamond")->move(me);
                if (random(2)) new("/clone/tessera/femerald")->move(me);
                if (random(2)) new("/clone/tessera/fsapphire")->move(me);
                if (random(2)) new("/clone/tessera/fruby")->move(me);
                if (random(2)) new("/clone/tessera/ftopaz")->move(me);
                set_temp("has_kouredl", 1, me);//不quit後第二次再獲邀請來這裡，是不能再有效果的了       
                addn("redl/gethomerune", 1, me);
                message_vision(CYN + (query_temp("has_kouredlpig", me) ? MAG+"紫豬"+NOR : RED+"紅豬"+NOR) + CYN + "對著$N眨眨眼，一副「幹得好！！」的神情。\n" + NOR, me);
                message_vision(CYN + (!query_temp("has_kouredlpig", me) ? MAG+"紫豬"+NOR : RED+"紅豬"+NOR) + CYN + "看都不看$N一眼，哼了一聲，高高的把頭揚了起來。\n" + NOR, me);
        }
        return 1;
}


