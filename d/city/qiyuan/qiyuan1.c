//棋苑

#include <ansi.h>
inherit  ROOM;

string look_string();

void  create  ()
{
    set  ("short",  "棋苑");
        set("long", @LONG
棋苑共分四個大間，是手談休棲的好地方。這裡的南北和西三個
方向各有一間棋室，在每個棋室的門外都貼著[1；33m請勿打擾棋局[2；37；0m的牌子，
在房間中央的柱子上還貼著一張下棋指南(help)。
LONG );

  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("no_beg",1);         
    set("item_desc", ([
    "help" : ( : look_string : ),
    ]));

    set("exits",  ([
    "east"  :  __DIR__"qiyuan2",
    "south"  :  __DIR__"qiyuan3",
    "north"  :  __DIR__"qiyuan4",
    "west" : "/d/city/kedian4",
    ]));

     set("objects",  ([
    __DIR__"cch"  :  1,
    ]));
   setup();
}

string look_string()
{
        string  msg  =  "歡迎到棋苑來下棋！\n"  +
"
在這裡您可以下圍棋或五子棋，以下是下棋的步驟：
一、先找好對手，然後分別用  sit black  和  sit white  入座；
二、使用 new 開始一盤新的棋局：new [-5] [-b(numbers)] [-h(numbers)]
    其中 -5  代表下五子棋，不選即為下圍棋；
      　 -b  指定所用棋盤的大小；
         -h  指定讓子的數目；
　　例如：
　　圍棋 new
    讓九子圍棋：new -h9
    十五乘十五的五子棋：new -5 -b15
三、使用 play 輪流走棋
    例如 play d4 等等。
四、使用 refresh 觀看棋盤。
五、使用 leave 離開棋盤。
六、使用 pass 棄子認輸。
七、使用 undo 悔棋。目前只提供五子棋的悔棋功能。

";
        return  msg;
}

int valid_leave(object me, string dir)
{
        object room;
        mapping exit;

        exit=query("exits", environment(me));

        if ( dir == "south" || dir == "north" || dir == "west" ) {
                if( !( room = find_object(exit[dir])) )
                       room = load_object(exit[dir]);
                if( room && query_temp("action", room) == 1 )
                       return notify_fail("那間棋室已經有人開始下棋了，請勿打擾\n");
                }

        return ::valid_leave(me, dir);
}
