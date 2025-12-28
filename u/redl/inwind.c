// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create()
{
        set("short", "天地間");
        set("long", 
"流嵐曼舞，嫵媚千重。踏雲隨風，逍遙蒼穹。\n"
);

                set("no_fight", 1); 
                set("no_magic", 1); 
                set("no_rideto", 1);
                set("no_flyto", 1);
        
        setup();
}

void init()
{
                object me = this_player();
                if (playerp(me)) {
                        me->start_busy(3);
                        call_out("do_sui", 1, me); 
                }
}


int do_sui(object me)
{
                if (!query_temp("can_redlinwind", me)) set_temp("can_redlinwind", 1, me);
                if (query_temp("can_redlinwind", me) < 12) {
                        addn_temp("can_redlinwind", 1, me);
                message_vision(YEL "$N的影子越來越遠，隨著清風徐徐往遠處飄去...\n" NOR, me);
                me->move(__DIR__"inwind");
                } else {
                        delete_temp("can_redlinwind", me);
                        me->stop_busy();
                message_vision(YEL "$N的思緒還在飄飄蕩蕩之中，突然腳下一震，$N睜目一看...\n" NOR, me);
                me->move(__DIR__"lake");
                tell_object(me, YEL "清風將你緩緩託到湖邊放下，注視著眼前這一切，你久久不想挪動腳步。\n" NOR);
                }
                return 1;
}


