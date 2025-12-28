// File(/data/room/xigua/shufang.c) of xigua's room
// Create by LUBAN written by Doing Lu

#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "書房");
	set ("long", @LONG
這裡是水果攤的主人西瓜讀書寫字的地方，乾淨明亮。文房四寶
整整齊齊的擺在桌子上面。有時西瓜也在這裡簽發(sign)一些邀請客
人的請柬。 
LONG );

        set("exits", ([
                "east" : __DIR__"jusuo",
        ]));

        set("sleep_room", 1);
        setup();

        set("room_owner", "西瓜");
        set("room_name", "水果攤");
        set("room_id", "sgt");
        set("room_owner_id", "xigua");
        set("room_position", "碎石小道");
}

void init()
{
        add_action("do_sign", "sign");
}

int do_sign()
{
        object ob;
        object me;

        me = this_player();

            if (! is_room_owner(me))
                    return notify_fail("你又不是這兒的主人，亂搞"
                                       "什麼？\n");

        if (me->is_busy())
                return notify_fail("你現在還忙著呢。\n");

        message_vision("$N抽過一張紙，拿起筆來，在上面畫符似"
                       "的寫了些東西。\n", me);
        tell_object(me, "你寫好一份手諭。\n");

        ob = new("/d/room/roomobj/pass");
        ob->set_name(HIW+query("name", me)+"手諭"NOR,
                     ({ "pass", query("room_owner_id") + " pass" }));
        ob->set("long","一張由"+query("name",me)+"親筆簽發的"+
                     "手諭，憑藉它你可以進出" + query("room_name") +
                     "。\n");
        ob->move(me);
        me->start_busy(4 + random(4));
        return 1;
}
