// This program is a part of NITAN MudLIB
// redl 2015/10
#include <ansi.h>
#include <room.h>
inherit BUILD_ROOM;

void create()
{
        set("short","不周山．587米");
        set("long", "這裡是不周山，相傳不周山是人界唯一能夠到達天界的路徑，\n"
"只可惜不周山終年寒冷，長年飄雪，非凡夫俗子所能徒步到達。傳\n"
"言曾有凡人為見神仙一面而隻身上山，但卻未曾見其返鄉。\n");
        set("outdoors", "yangzhou");
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("no_rideto", 1);
        set("no_flyto", 1);
        set("no_magic", 1);
        set("no_user_kill", 1);
        set("no_sleep_room", 1);
        set("exits",(["down":__DIR__"bzs_4","up":__DIR__"bzs_6"]));setup();
}

int do_look(string arg)
{
        object me = this_player();
        if ( arg && arg=="up" ) {
                        tell_object(me, NOR "你凝聚目力望過去，只見雲霧飄渺。\n" NOR);
                        return -1;
        }
        return 0;
}

int valid_leave(object me, string dir)
{
                if (dir=="up") {
                        if ( file_size(query("exits/up") + ".c") < 1 )
                                return notify_fail(NOR "一個聲音喝止你：你是從山腳拜上來的嗎？\n" NOR);
                }

        return ::valid_leave(me, dir);
}

int init()
{
        add_action("do_look", "look");
}
