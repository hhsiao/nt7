// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <room.h>
inherit CREATE_CHAT_ROOM;

int is_chat_room() { return 1; }
int do_hy(string arg);
int do_pick(string arg);

void create()
{
        set("short", NOR HIW "民工" HIK "棚" NOR);
        set("long", @LONG
這是沒有建造工作室的巫師的臨時住處，這裡的設備非常簡單，只有
一些常用物品。
LONG );

        set("exits", ([ /* sizeof() == 1 */
                "north" : "/u/redl/tianshenzoulang",
                "south" : "/d/wizard/wizard_room",
                "up" : __DIR__"check",
        ]));

          set("objects", ([
//          "/u/mud/charm.c":1,
      "/kungfu/class/misc/haigui":1,
          ]));
        set("valid_startroom", 1);
        //set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && ! wizardp(me))
                return notify_fail("那裡只有巫師才能進去。\n");

        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_hy","hy");
        add_action("do_pick","pick");
}
int do_hy(string arg)
{
        object obj;
        object me = this_player();
        if(! arg || arg == "")
            return notify_fail("請輸入要還陽者的id？\n");
        obj = find_player(arg);
        if(!obj)
            return notify_fail("沒有這個人。\n");

        obj->move("/d/death/gate");
        tell_object(me,obj->name()+"已經被送往白無常處復活！\n");

      return 1;
}
int do_pick(string arg)
{
        object ob;
        object me = this_player();
        if(!wizardp(me) && query("id",me)!="mud")
            return notify_fail("不要再別人家裡亂翻東西！\n");
        ob = new("/u/mud/charm");
        ob->move(me);
        return 1;
}
